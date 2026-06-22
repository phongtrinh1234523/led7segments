#ifndef LED_7
#define LED_7

#include <main.h>

typedef struct {
    GPIO_TypeDef *port;
    uint16_t pin;
} led7portpin;

typedef enum {
    anode,
    cathode,
} led_type;

typedef struct {
    led7portpin seg[7];
    led_type type;
} control;

void init(control *led, led7portpin a,
                        led7portpin b,
                        led7portpin c,
                        led7portpin d,
                        led7portpin e,
                        led7portpin f,
                        led7portpin g,
                        led_type type);
void display(control *led, uint8_t num);
#endif