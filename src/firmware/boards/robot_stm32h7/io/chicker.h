#pragma once

#include <stdbool.h>

#include "firmware/boards/robot_stm32h7/io/gpio_pin.h"

typedef struct BreakBeam BreakBeam_t;

BreakBeam_t* io_break_beam_create(GpioPin_t* read_pin);

void io_chicker_kick(float speed_m_per_s);
void io_chicker_chip(float distance_m);
void io_chicker_enable_auto_kick(float speed_m_per_s);
void io_chicker_enable_auto_chip(float distance_m);
void io_chicker_disable_auto_kick();
void io_chicker_disable_auto_chip();
bool io_get_breakbeam();