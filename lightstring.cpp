#include "g35.h"
#include "lightstring.h"

g35_packet * lightstring::next_packet()
{
    if (!initialized) {
        pending_packet = initial_packet();
    } else {
        pending_packet = regular_packet();
    }
    return &pending_packet;
}

g35_packet lightstring::initial_packet()
{
    gridlocation xy = location_from_index(current_index);
    int address = address_from_index(current_index);
    g35_pixel p = pixel_from_framebuffer_location(xy);
    ++current_index;
    current_index %= size;
    initialized |= (current_index == 0);
    return g35_packet(address, p);
}

g35_packet lightstring::regular_packet()
{
    return initial_packet();
}

g35_pixel lightstring::pixel_from_framebuffer_location(gridlocation g)
{
    return f->get(g);
}
