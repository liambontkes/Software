#pragma once

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wsign-conversion"
#include "firmware/boards/robot_stm32h7/Drivers/STM32H7xx_HAL_Driver/Inc/stm32h7xx_hal.h"
#include <stdbool.h>
#pragma GCC diagnostic pop

/**
 * Struct for a GPIO Input Pin
 */
typedef struct GpioInputPin GpioInputPin_t;

/**
 * Struct for a GPIO Output Pin
 */
typedef struct GpioOutputPin GpioOutputPin_t;

/**
 * A GPIO pin being "Active High" or "Active Low" simply determines whether high or low
 * voltage corresponds to 1. So for example, "Active High" means that a high voltage
 * corresponds to 1, a low voltage corresponds to 0.
 */
typedef enum
{
    ACTIVE_HIGH,
    ACTIVE_LOW
} GpioPinActiveState;

///**
// * Create a GPIO pin
// *
// * Please note, the GPIO handler/pin must be configured before being passed to this
// * function. Setting it up in CubeMX should be sufficient.
// *
// * @param gpio_handler A GPIO handler which this pin is contained in. This must be kept
// *                     alive for the duration of the created GPIO pin object.
// * @param gpio_pin_index The index within the GPIO handler for this pin
// * @param active_state The active state of this pin
// *
// * @return An initialized GPIO pin, initially set to be inactive (0). Ownership of the
// *         returned pointer is taken by the caller.
// */
//GpioPin_t* io_gpio_pin_create(GPIO_TypeDef* gpio_handler, uint16_t gpio_pin_index,
//                              GpioPinActiveState active_state);

/**
 * Create a GPIO Input Pin
 *
 * The GPIO handler/pin must be configured before being passed to this function. Setting
 * it up in CubeMX should be sufficient.
 *
 * @param gpio_handler A GPIO handler which this pin is contained in. This must be kept
 *                     alive for the duration of the created GPIO pin object.
 * @param gpio_pin_index The index within the GPIO handler for this pin.
 * @return An initialized GPIO input pin. Ownership of the return pin is taken by the
 *         caller.
 */
GpioInputPin_t* io_gpio_input_pin_create(GPIO_TypeDef* gpio_handler, uint16_t gpio_pin_index);

/**
 * Create a GPIO Output Pin
 *
 * The GPIO handler/pin must be configured before being passed to this function. Setting
 * it up in CubeMX should be sufficient.
 *
 * @param gpio_handler A GPIO handler which this pin is contained in. This must be kept
 *                     alive for the duration of the created GPIO pin object.
 * @param gpio_pin_index This index within the GPIO handler for this pin.
 * @param active_state The active state of this pin.
 * @return An initialized GPIO pin, initially set to be inactive (0). Ownership of the
 *         returned pointer is taken by the caller.
 */
GpioOutputPin_t* io_gpio_output_pin_create(GPIO_TypeDef* gpio_handler, uint16_t gpio_pin_index,
                                          GpioPinActiveState active_state);

/**
 * Destroys the given GPIO input pin
 * @param gpio_input_pin The GPIO input pin to destroy.
 */
void io_gpio_input_pin_destroy(GpioInputPin_t* gpio_input_pin);

/**
 * Destroys the given GPIO output pin.
 *
 * @param gpio_output_pin The GPIO output pin to destroy.
 */
void io_gpio_output_pin_destroy(GpioOutputPin_t* gpio_output_pin);

/**
 * Set the given GPIO pin to be active (1)
 * @param gpio_pin
 */
void io_gpio_pin_setActive(GpioOutputPin_t* gpio_output_pin);

/**
 * Set the given GPIO pin to be inactive (0)
 * @param gpio_pin
 */
void io_gpio_pin_setInactive(GpioOutputPin_t* gpio_output_pin);

/**
 * Gets the state of the given GPIO pin
 * @param gpio_pin
 * @return active (1) inactive (0)
 */
bool io_gpio_pin_get(GpioInputPin_t* gpio_input_pin);