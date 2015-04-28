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
    g35_packet packet;
    int time;
    int get_next_level();
    int get_level(int time);
    static const unsigned RESET_TIME = 3;
    static const unsigned ADDRESS_TIME = 3 * ADDRESS_BITS;
    static const unsigned INTENSITY_TIME = 3 * INTENSITY_BITS;
    static const unsigned BLUE_TIME = 3 * COLOR_BITS;
    static const unsigned GREEN_TIME = 3 * COLOR_BITS;
    static const unsigned RED_TIME = 3 * COLOR_BITS;
};
#endif
