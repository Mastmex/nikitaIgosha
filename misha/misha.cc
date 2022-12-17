#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <windows.h>

bool dat;
bool master;
bool on;
bool signa;

void init()
{
    on = true;
    master = false;
    dat = false;
    signa = false;
}

void check_move()
{
    int m;
    std::string g;
    std::ifstream("mv.mv") >> g;
    m = atoi(g.c_str());
    if (m && on)
        dat = true;
}

void dat_off()
{
    if (on && dat)
        Sleep(7000);
    int m;
    std::string g;
    std::ifstream("off.off") >> g;
    m = atoi(g.c_str());
    if (m)
    {
        master = true;
        on = false;
        signa = false;
    }
}

void sig()
{
    if (on && !master && dat)
        signa = true;
}

void get_info()
{
    std::cout << "Movemetn detected? ---- " << dat << "\n";
    std::cout << "Is this master? ---- " << master << "\n";
    std::cout << "Is detector turned on? ---- " << on << "\n";
    std::cout << "Is alarm activated? ---- " << signa << "\n";
}

int main()
{
    init();
    while (1)
    {
        check_move();
        dat_off();
        sig();
        get_info();
        system("pause");
    }
}