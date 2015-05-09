#include <stdint.h>

#include "core_pins.h"
#include "IntervalTimer.h"

#include "g35.h"
#include "lightstring.h"
#include "framebuffer.h"
#include "pin_handler.h"

static gridlocation string0[48] =
{
	{ 5, 0 },  { 5, 1 },  { 5, 2 },  { 5, 3 },  { 5, 4 },  { 5, 5 },  { 5, 6 },  { 5, 7 },  { 4, 7 },  { 4, 6 },  { 4, 5 },  { 4, 4 },  { 4, 3 },  { 4, 2 },  { 4, 1 },  { 4, 0 },  { 3, 0 },  { 3, 1 },  { 3, 2 },  { 3, 3 },  { 3, 4 },  { 3, 5 },  { 3, 6 },  { 3, 7 },  { 2, 7 },  { 2, 6 },  { 2, 5 },  { 2, 4 },  { 2, 3 },  { 2, 2 },  { 2, 1 },  { 2, 0 },  { 1, 0 },  { 1, 1 },  { 1, 2 },  { 1, 3 },  { 1, 4 },  { 1, 5 },  { 1, 6 },  { 1, 7 },  { 0, 7 },  { 0, 6 },  { 0, 5 },  { 0, 4 },  { 0, 3 },  { 0, 2 },  { 0, 1 },  { 0, 0 },
};
static gridlocation string1[50] =
{
	{ 6, 0 },  { 6, 1 },  { 6, 2 },  { 6, 3 },  { 6, 4 },  { 6, 5 },  { 6, 6 },  { 6, 7 },  { 6, 8 },  { 6, 9 },  { 6, 10 },  { 6, 11 },  { 6, 12 },  { 6, 13 },  { 5, 13 },  { 5, 12 },  { 5, 11 },  { 5, 10 },  { 5, 9 },  { 5, 8 },  { 4, 8 },  { 4, 9 },  { 4, 10 },  { 4, 11 },  { 4, 12 },  { 4, 13 },  { 3, 13 },  { 3, 12 },  { 3, 11 },  { 3, 10 },  { 3, 9 },  { 3, 8 },  { 2, 8 },  { 2, 9 },  { 2, 10 },  { 2, 11 },  { 2, 12 },  { 2, 13 },  { 1, 13 },  { 1, 12 },  { 1, 11 },  { 1, 10 },  { 1, 9 },  { 1, 8 },  { 0, 8 },  { 0, 9 },  { 0, 10 },  { 0, 11 },  { 0, 12 },  { 0, 13 },
};
static gridlocation string2[50] =
{
	{ 7, 0 },  { 7, 1 },  { 7, 2 },  { 7, 3 },  { 7, 4 },  { 7, 5 },  { 7, 6 },  { 7, 7 },  { 7, 8 },  { 7, 9 },  { 7, 10 },  { 7, 11 },  { 7, 12 },  { 7, 13 },  { 6, 13 },  { 6, 12 },  { 6, 11 },  { 6, 10 },  { 6, 9 },  { 6, 8 },  { 5, 8 },  { 5, 9 },  { 5, 10 },  { 5, 11 },  { 5, 12 },  { 5, 13 },  { 4, 13 },  { 4, 12 },  { 4, 11 },  { 4, 10 },  { 4, 9 },  { 4, 8 },  { 3, 8 },  { 3, 9 },  { 3, 10 },  { 3, 11 },  { 3, 12 },  { 3, 13 },  { 2, 13 },  { 2, 12 },  { 2, 11 },  { 2, 10 },  { 2, 9 },  { 2, 8 },  { 1, 8 },  { 1, 9 },  { 1, 10 },  { 1, 11 },  { 1, 12 },  { 1, 13 },
};
static gridlocation string3[48] =
{
	{ 8, 0 },  { 8, 1 },  { 8, 2 },  { 8, 3 },  { 8, 4 },  { 8, 5 },  { 8, 6 },  { 8, 7 },  { 7, 7 },  { 7, 6 },  { 7, 5 },  { 7, 4 },  { 7, 3 },  { 7, 2 },  { 7, 1 },  { 7, 0 },  { 6, 0 },  { 6, 1 },  { 6, 2 },  { 6, 3 },  { 6, 4 },  { 6, 5 },  { 6, 6 },  { 6, 7 },  { 5, 7 },  { 5, 6 },  { 5, 5 },  { 5, 4 },  { 5, 3 },  { 5, 2 },  { 5, 1 },  { 5, 0 },  { 4, 0 },  { 4, 1 },  { 4, 2 },  { 4, 3 },  { 4, 4 },  { 4, 5 },  { 4, 6 },  { 4, 7 },  { 3, 7 },  { 3, 6 },  { 3, 5 },  { 3, 4 },  { 3, 3 },  { 3, 2 },  { 3, 1 },  { 3, 0 },
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
    for (int i = 0; i < 4; ++i)
    {
        h[i].setbit();
    }
}

static IntervalTimer t;

void start_timer(void)
{
    t.begin(timer_interrupt, g35_packet_sender::MICROSECONDS_PER_STATE);
}

