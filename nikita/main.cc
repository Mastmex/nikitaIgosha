#include "defines.h"
#include <fstream>
#include "TV.h"
#include "voice.h"

modes cur1, cur2;

Room_Light rm1, rm2;
TV tv;

int vs;
/// @brief Начальная инициализация переменных
void init()
{
    cur1 = modes::off;
    cur2 = modes::off;
    tv = false;
}
/// @brief Применение значений внутренних переменных к силе освещения
void import()
{
    switch (cur1)
    {
    case modes::off:
        rm1 = 0;
        break;
    case modes::med:
        rm1 = 512;
        break;
    case modes::on:
        rm1 = 1023;
        break;
    case modes::downscaled_off:
        rm1 = 0;
        break;
    case modes::downscaled_med:
        rm1 = 512;
        break;
    }

    switch (cur2)
    {
    case modes::off:
        rm2 = 0;
        break;
    case modes::med:
        rm2 = 512;
        break;
    case modes::on:
        rm2 = 1023;
        break;
    case modes::downscaled_off:
        rm1 = 0;
        break;
    case modes::downscaled_med:
        rm1 = 512;
        break;
    }
}
/// @brief Получение информации о том, включен телевизор или нет
void get_tv_state()
{
    tv = update_tv();
}
/// @brief Функция для понижения силы света от телевизора
/// @param r Выбор комнаты для понижения
void downgrade(modes &r)
{
    if (r == modes::on || r == modes::downscaled_med)
        r = modes::downscaled_med;
    if (r == modes::med || r == modes::downscaled_off)
        r = modes::downscaled_off;
}
/// @brief Применение информации о состоянии телевизора
void check_tv_state()
{
    if (tv)
        downgrade(cur1);
}
/// @brief Получение последней голосовой команды
void get_voice_state()
{
    vs = update_voice();
}
/// @brief Установить состояние света согласно команды
void set_voice_state()
{
    if (vs == 0)
    {
        cur1 = modes::off;
        cur2 = modes::off;
    }
    if (vs == 1)
    {
        cur1 = modes::med;
        cur2 = modes::med;
    }
    if (vs == 2)
    {
        cur1 = modes::on;
        cur2 = modes::on;
    }
}
/// @brief Debug only - вывод информации о состоянии света
void show_info()
{
    std::cout << "Current state of light 1 = " << rm1 << "\n";
    std::cout << "Current state of light 2 = " << rm2 << "\n";
}
int main()
{
    init();
    while (true)
    {
        import();
        get_tv_state();
        check_tv_state();
        get_voice_state();
        set_voice_state();
        show_info();
        system("pause");
    }
}