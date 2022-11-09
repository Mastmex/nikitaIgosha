#pragma once
#include <fstream>

TV update_tv()
{
    int c;
    std::ifstream tv("tv.tv");
    c = tv.get();
    tv.close();
    std::ofstream("tv.tv", std::ios::out | std::ios::trunc);
    if (c == '1')
        return true;
    else
        return false;
}