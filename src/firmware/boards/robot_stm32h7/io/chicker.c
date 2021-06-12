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

bool io_breakbeam_get_state(GpioPin_t* breakbeam_pin)
{
    return io_gpio_pin_getState(breakbeam_pin);
}
