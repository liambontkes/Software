#pragma once

#include "firmware/boards/robot_stm32h7/io/gpio_pin.h"
#include <stdbool.h>

void io_chicker_kick(float speed_m_per_s);
void io_chicker_chip(float distance_m);
void io_chicker_enable_auto_kick(float speed_m_per_s);
void io_chicker_enable_auto_chip(float distance_m);
void io_chicker_disable_auto_kick();
void io_chicker_disable_auto_chip();
bool io_breakbeam_get_state(GpioPin_t* breakbeam_pin);
