#ifndef PIN_HANDLER_H
#define PIN_HANDLER_H
#include "g35.h"

struct lightstring;

struct pin_handler
{
    pin_handler(lightstring *s, unsigned pin)
    : s(s)
    , pin(pin)
    {}
    lightstring * const s;
    const unsigned pin;
    g35_packet_sender sender;
    g35_packet * packet;
    void setbit(void);
};
#endif
