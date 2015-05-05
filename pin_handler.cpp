#include <stdint.h>

#include "core_pins.h"

#include "pin_handler.h"

void pin_handler::setbit(void)
{
    unsigned val;
    digitalWriteFast(pin, val);
}

