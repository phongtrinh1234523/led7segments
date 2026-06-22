#include "led7.h"

static const uint8_t digit_pattern[10] = {
    0x3F, // 0
    0x06, // 1
    0x5B, // 2
    0x4F, // 3
    0x66, // 4
    0x6D, // 5
    0x7D, // 6
    0x07, // 7
    0x7F, // 8
    0x6F  // 9
};

void init(control *led, led7portpin a,
                        led7portpin b,
                        led7portpin c,
                        led7portpin d,
                        led7portpin e,
                        led7portpin f,
                        led7portpin g,
                        led_type type)
{
    led->type = type;
    led->seg[0] = a;
    led->seg[1] = b;
    led->seg[2] = c;
    led->seg[3] = d;
    led->seg[4] = e;
    led->seg[5] = f;
    led->seg[6] = g;
}

void display(control *led, uint8_t num) {
    if (num > 9) {
        return;
    }

    uint8_t pattern = digit_pattern[num];

    for (uint8_t i = 0; i < 7; i++) {
        GPIO_PinState state = (pattern >> i) & 0x01 ? 1 : 0;


        if (led->type == anode) {
            state = (state == 1) ? 0 : 1;
        }
        HAL_GPIO_WritePin(led->seg[i].port, led->seg[i].pin, state);
    }
}
