#include "firmware/boards/robot_stm32h7/io/chicker.h"

#include "firmware/app/logger/logger.h"

void io_chicker_kick(float speed_m_per_s)
{
    // TODO (#2080) implement this
}

void io_chicker_chip(float distance_m)
{
    // TODO (#2080) implement this
}

/**
 * Breakbeam state should be "discovered" in two different ways:
 *  1. whenever the breakbeam is broken, an interrupt should be triggered
 *  2. create a function to poll the breakbeam GPIO pin for it's current status (for robot diagnostics)
 * The interrupt should trigger a callback function when auto_chip and auto_kick are enabled
 *
 * @param speed_m_per_s
 */
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
