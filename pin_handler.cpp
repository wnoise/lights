#include <stdint.h>

#include "core_pins.h"

#include "pin_handler.h"
#include "lightstring.h"

void pin_handler::setbit(void)
{
    if (!packet) {
        packet = s->next_packet();
    }
    int level = sender.get_next_level(*packet);
    if (level < 0) {
        packet = nullptr;
        // TODO: Unnecessary delay betwwen packets.
        return;
    }
    uint8_t val = level;
    digitalWriteFast(pin, val);
}
