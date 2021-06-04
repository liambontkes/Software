#include "firmware/boards/robot_stm32h7/io/chicker.h"
#include "firmware/app/logger/logger.h"

#include <stdlib.h>

typedef struct BreakBeam
{
    GpioPin_t* read_pin;
} BreakBeam_t;

/**
 * Breakbeam state should be "discovered" in two different ways:
 *  1. whenever the breakbeam is broken, an interrupt should be triggered
 *  2. create a function to poll the breakbeam GPIO pin for it's current status (for robot diagnostics)
 * The interrupt should trigger a callback function when auto_chip and auto_kick are enabled
 *
 * @return
 */
BreakBeam_t *io_break_beam_create(GpioPin_t *read_pin)
{
    BreakBeam_t* break_beam = (BreakBeam_t*)malloc(sizeof(BreakBeam_t));

    break_beam->read_pin = read_pin;

    io_gpio_pin_setActive(break_beam->read_pin);

    return break_beam;
}

void io_chicker_kick(float speed_m_per_s)
{
    // TODO (#2080) implement this
}

void io_chicker_chip(float distance_m)
{
    // TODO (#2080) implement this
}

void io_chicker_enable_auto_kick(float speed_m_per_s)
{
    // TODO (#2080) implement this
}

void io_chicker_enable_auto_chip(float distance_m)
{
    // TODO (#2080) implement this
}

void io_chicker_disable_auto_kick()
{
    // TODO (#2080) implement this
}

void io_chicker_disable_auto_chip()
{
    // TODO (#2080) implement this
}

bool io_get_breakbeam()
{

    return 0;
}
