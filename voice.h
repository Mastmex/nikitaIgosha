#pragma once
#include <fstream>
#include "defines.h"

int update_voice()
{
    Word wd;
    std::fstream("voice.voice") >> wd;
    std::ofstream("voice.voice", std::ios::out | std::ios::trunc);
    if (wd == "off")
        return 0;
    if (wd == "half")
        return 1;
    if (wd == "full")
        return 2;
}
