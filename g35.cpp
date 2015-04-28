#include "g35.h"

static int get_level_from(unsigned data, unsigned time_in_field)
{
    unsigned bitnumber = time_in_field / 3;
    unsigned portion = time_in_field % 3;
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
    int level = get_level(time);
    ++time;
    return level;
}

int g35_packet_sender::get_level(int time)
{
    if (time < RESET_TIME)
        return 0;
    time -= RESET_TIME;
    if (time < ADDRESS_TIME) {
        return get_level_from(packet.address, time);
    }
    time -= ADDRESS_TIME;
    if (time < INTENSITY_TIME) {
        return get_level_from(packet.p.intensity, time);
    }
    time -= INTENSITY_TIME;
    if (time < BLUE_TIME) {
        return get_level_from(packet.p.blue, time);
    }
    time -= BLUE_TIME;
    if (time < GREEN_TIME) {
        return get_level_from(packet.p.green, time);
    }
    time -= GREEN_TIME;
    if (time < RED_TIME) {
        return get_level_from(packet.p.red, time);
    }
    time -= RED_TIME;
    // End of packet.
    return -1;
}
