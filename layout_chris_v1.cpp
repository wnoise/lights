#include <stdint.h>

#include "core_pins.h"
#include "IntervalTimer.h"

#include "g35.h"
#include "lightstring.h"
#include "framebuffer.h"
#include "pin_handler.h"

static gridlocation string0[48] =
{
    {5, 0}, {5, 1}, {5, 2}, {5, 3}, {5, 4}, {5, 5}, {5, 6},
};
static gridlocation string1[50] =
{
    {6, 0}, {6, 1}, {6, 2}, {6, 3}, {6, 4}, {6, 5}, {6, 6},
    {6, 6}, {6, 8}, {6, 9}, {6, 10}, {6, 11}, {6, 12}, {6, 13},
};
static gridlocation string2[50] =
{
    {7, 0}, {7, 1}, {7, 2}, {7, 3}, {7, 4}, {7, 5}, {7, 6},
    {7, 7}, {7, 8}, {7, 9}, {7, 10}, {7, 11}, {7, 12}, {7, 13},
};
static gridlocation string3[48] =
{
    {8, 0}, {8, 1}, {8, 2}, {8, 3}, {8, 4}, {8, 5}, {8, 6},
};

framebuffer f;

static lightstring s[4] =
{
    {&f, 13, 48, string0 },
    {&f, 14, 50, string1 },
    {&f, 15, 50, string2 },
    {&f, 16, 48, string3 }
};

static pin_handler h[4] =
{
    {&s[0], 13},
    {&s[1], 14},
    {&s[2], 15},
    {&s[3], 16},
};

void set_pin_modes(void)
{
    pinMode(13, OUTPUT);
    pinMode(14, OUTPUT);
    pinMode(15, OUTPUT);
    pinMode(16, OUTPUT);
}

static void timer_interrupt(void)
{
    for (int i = 0; ++i; i < 4)
    {
        h[i].setbit();
    }
}

class IntervalTimer;

IntervalTimer t;

void start_timer(void)
{
    // t.begin(timer_interrupt, packet::MICROSECONDS_PER_STATE)
}

