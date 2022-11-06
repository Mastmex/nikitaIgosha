#include "defines.h"
#include <fstream>
#include "TV.h"

modes cur1, cur2;

Room_Light rm1, rm2;
TV tv;

void init()
{
    cur1 = modes::off;
    cur2 = modes::off;
    tv = false;
}

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
    }
}

void get_tv_state()
{
    tv = update_tv();
}

void downgrade(modes &r)
{
    if (r == modes::on)
        r = modes::downscaled_med;
    if (r == modes::med || r == modes::downscaled_off)
        r = modes::downscaled_off;
}

void check_tv_state()
{
    if (tv)
        downgrade(cur1);
}

int main()
{
    init();
    while (true)
    {
        import();
    }
}