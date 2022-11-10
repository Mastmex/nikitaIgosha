#include "defines.h"
#include <fstream>
#include <stdlib.h>
#include <iostream>
#include <string>
year yr;
int tp, wt;
bool cond, warm, hyd; /// Кондиционер, обогреватель, увлажнитель
/// @brief Получение информации о годе
void get_current_season(std::ifstream fd)
{
    char r;
    r = fd.get();
    if (r == '0')
        yr = year::summer;
    if (r == '1')
        yr == year::winter;
    fd.close();
}
/// @brief Установить начальную информацию
void init()
{
    get_current_season(std::ifstream("sz.sz"));
    cond = false;
    warm = false;
    hyd = false;
}
/// @brief Ролучить текущее значение температуры
void get_tp()
{
    std::string g;
    std::ifstream("tp.tp") >> g;
    tp = atoi(g.c_str());
}
/// @brief Получить текущее значение влажности
void get_hym()
{
    std::string g;
    std::ifstream("hy.hy") >> g;
    wt = atoi(g.c_str());
}
/// @brief Включить или выключить обогреватель и кондиционер в зависимости от температуры
void set_tp()
{
    if (yr == year::summer)
    {
        if (tp < 22)
        {
            warm = true;
            cond = false;
        }
        if (tp >= 22 && tp <= 25)
        {
            warm = false;
            cond = false;
        }
        if (tp > 25)
        {
            warm = false;
            cond = true;
        }
    }
    if (yr == year::winter)
    {
        if (tp < 20)
        {
            warm = true;
            cond = false;
        }
        if (tp >= 20 && tp <= 22)
        {
            warm = false;
            cond = false;
        }
        if (tp > 22)
        {
            warm = false;
            cond = true;
        }
    }
}
/// @brief Включить или выключить увлажнитель в зависимости от влажности
void set_hd()
{
    if (yr == year::summer)
    {
        if (wt <= 50)
            hyd = true;
        if (wt >= 70)
            hyd = false;
    }
    if (yr == year::winter)
    {
        if (wt <= 40)
            hyd = true;
        if (wt >= 55)
            hyd = false;
    }
}
/// @brief Debug only: Получить информацию о текущем состоянии устройств и температуры/влажности
void show_info()
{
    std::cout << "Current temperatue = " << tp << "\n";
    std::cout << "Current hydration = " << wt << "\n";
    std::cout << "Current state of conditioner: " << (cond == true ? "On" : "Off") << "\n";
    std::cout << "Current state of warmer: " << (warm == true ? "On" : "Off") << "\n";
    std::cout << "Current state of hydrator: " << (hyd == true ? "On" : "Off") << "\n";
}

int main()
{
    init();
    while (true)
    {
        get_tp();
        get_hym();
        set_tp();
        set_hd();
        show_info();
        system("pause");
    }
}