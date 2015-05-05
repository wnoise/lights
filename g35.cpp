#include "g35.h"

static int get_level_from(unsigned data, unsigned state_in_field)
{
    unsigned bitnumber = state_in_field / 3;
    unsigned portion = state_in_field % 3;
    unsigned bitvalue = (data >> bitnumber) & 1;
    switch (portion) {
        case 0:
            return 1;
        case 1:
            return bitvalue;
        case 2:
            return 0;
    }
}

int g35_packet_sender::get_next_level()
{
    int level = get_level(state);
    ++state;
    return level;
}

int g35_packet_sender::get_level(int state)
{
    if (state < START_STATES)
        return 0;
    state -= START_STATES;
    if (state < ADDRESS_STATES) {
        return get_level_from(packet.address, state);
    }
    state -= ADDRESS_STATES;
    if (state < INTENSITY_STATES) {
        return get_level_from(packet.p.intensity, state);
    }
    state -= INTENSITY_STATES;
    if (state < BLUE_STATES) {
        return get_level_from(packet.p.blue, state);
    }
    state -= BLUE_STATES;
    if (state < GREEN_STATES) {
        return get_level_from(packet.p.green, state);
    }
    state -= GREEN_STATES;
    if (state < RED_STATES) {
        return get_level_from(packet.p.red, state);
    }
    state -= RED_STATES;
    // End of packet.
    return -1;
}
