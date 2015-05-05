#ifndef PIN_HANDLER_H
#define PIN_HANDLER_H
struct lightstring;

struct pin_handler
{
    pin_handler(lightstring *s, unsigned pin)
    : s(s)
    , pin(pin)
    {}
    const lightstring *s;
    const unsigned pin;
    void setbit(void);
};
#endif
