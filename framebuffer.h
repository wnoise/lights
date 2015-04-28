#ifndef FRAMEBUFFER_H
#define FRAMEBUFFER_H
#include "g35.h"

struct gridlocation
{
    unsigned x:4, y:4;
};

struct framebuffer {
    static const int ROWS=14;
    static const int COLS=14;
    g35_pixel grid[ROWS][COLS];
    inline g35_pixel get(gridlocation l)
    {
        return grid[l.x][l.y];
    }
};
#endif
