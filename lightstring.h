#ifndef LIGHTSTRING_H
#define LIGHTSTRING_H
#include "g35.h"
#include "framebuffer.h"

struct lightstring
{
    lightstring(framebuffer *f, unsigned pin, unsigned size, gridlocation *path)
        : f(f)
        , pin(pin)
        , size(size)
        , path(path)
        , pending_packet(0,{})
        {
        }
    const int pin;
    const int size;
    const gridlocation * const path;
    int current_index;
    int initialized;
    g35_packet pending_packet;
    framebuffer *f;

    unsigned address_from_index(unsigned index) { return index; }
    g35_packet * next_packet();
    g35_packet initial_packet();
    g35_packet regular_packet();
    gridlocation location_from_index(unsigned index) { return path[index]; }
    g35_pixel pixel_from_framebuffer_location(gridlocation l);
};
#endif
