#include "layout_chris_v1.h"

int main()
{
    set_pin_modes();
    start_timer();
    unsigned count;
    while (1) {
        for (unsigned i = 0; i < f.ROWS; ++i)
        {
            for (unsigned j = 0; j < f.COLS; ++j)
            {
                f.grid[i][j] = g35_pixel {200U, count%16, i, j};
                ++count;
            }
        }
    }
}
