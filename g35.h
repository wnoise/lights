#ifndef G35_H
#define G35_H
const int ADDRESS_BITS = 6;
const int INTENSITY_BITS = 8;
const int COLOR_BITS = 4;

struct g35_pixel
{
    unsigned intensity:INTENSITY_BITS;
    unsigned blue:COLOR_BITS;
    unsigned green:COLOR_BITS;
    unsigned red:COLOR_BITS;
};

struct g35_packet
{
    g35_packet(unsigned address, g35_pixel p)
        : address(address)
        , p(p)
    {}
    unsigned address:ADDRESS_BITS;
    g35_pixel p;
};

// This actually turns an abstract packet
// into a sequence of high and low pulses
// of the right times.
struct g35_packet_sender
{
    int state;
    int get_next_level(g35_packet p);
    int get_level(g35_packet p, int time);
    static const unsigned START_STATES = 1;
    static const unsigned ADDRESS_STATES = 3 * ADDRESS_BITS;
    static const unsigned INTENSITY_STATES = 3 * INTENSITY_BITS;
    static const unsigned BLUE_STATES = 3 * COLOR_BITS;
    static const unsigned GREEN_STATES = 3 * COLOR_BITS;
    static const unsigned RED_STATES = 3 * COLOR_BITS;
    static const unsigned END_STATES = 3;
};
#endif
