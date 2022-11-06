#include <defines.h>
#include <fstream>

TV update_tv()
{
    int c;
    std::ifstream tv("tv.tv");
    c = tv.get();
    if (c == 1)
        return false;
    else
        return true;
    tv.close();
}