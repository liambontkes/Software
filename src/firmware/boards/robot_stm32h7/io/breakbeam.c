#include "breakbeam.h"

#include "firmware/app/logger/logger.h"

#include <stdlib.h>

typedef struct Breakbeam
{
    GpioPin_t* breakbeam_pin;
} Breakbeam_t;

Breakbeam_t* io_breakbeam_create(GpioPin_t* breakbeam_pin)
{
    Breakbeam_t* breakbeam = (Breakbeam_t*)malloc(sizeof(Breakbeam_t));

    breakbeam->breakbeam_pin = breakbeam_pin;

    // TODO setup IRQ on breakbeam_pin.

    return breakbeam;
}

void io_breakbeam_destroy(Breakbeam_t* breakbeam)
{
    free(breakbeam);
}

bool io_breakbeam_get_state(Breakbeam_t* breakbeam)
{
    return io_gpio_pin_getState(breakbeam->breakbeam_pin);
}
