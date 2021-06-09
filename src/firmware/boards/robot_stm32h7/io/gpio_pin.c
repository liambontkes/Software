#include "firmware/boards/robot_stm32h7/io/gpio_pin.h"

#include <stdlib.h>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wsign-conversion"
#include "firmware/boards/robot_stm32h7/stm32h7xx_hal_conf.h"
#pragma GCC diagnostic pop

/**
 * Base GPIO pin struct
 */
typedef struct GpioPin GpioPin_t;

typedef struct GpioPin
{
    GPIO_TypeDef* gpio_handler;
    uint16_t gpio_pin_index;
} GpioPin_t;

typedef struct GpioInputPin
{
    GpioPin_t gpio_pin;
} GpioInputPin_t;

typedef struct GpioOutputPin
{
    GpioPin_t gpio_pin;
    GpioPinActiveState active_state;
} GpioOutputPin_t;

/**
 * Set raw HAL state for the given GPIO pin
 * @param gpio_pin The pin to set the state for
 * @param pin_state The state to set the pin to
 */
void io_gpio_pin_setHALPinState(GpioOutputPin_t* gpio_output_pin, GPIO_PinState pin_state);

GpioInputPin_t* io_gpio_input_pin_create(GPIO_TypeDef* gpio_handler, uint16_t gpio_pin_index)
{
    GpioInputPin_t* gpio_input_pin = (GpioInputPin_t*)malloc(sizeof(GpioInputPin_t));

    gpio_input_pin->gpio_pin.gpio_handler = gpio_handler;
    gpio_input_pin->gpio_pin.gpio_pin_index = gpio_pin_index;

    return gpio_input_pin;
}

GpioOutputPin_t* io_gpio_output_pin_create(GPIO_TypeDef* gpio_handler,
                                           uint16_t gpio_pin_index,
                                           GpioPinActiveState active_state)
{
    GpioOutputPin_t* gpio_output_pin = (GpioOutputPin_t*)malloc(sizeof(GpioOutputPin_t));

    gpio_output_pin->gpio_pin.gpio_handler = gpio_handler;
    gpio_output_pin->gpio_pin.gpio_pin_index = gpio_pin_index;
    gpio_output_pin->active_state = active_state;

    io_gpio_pin_setInactive(gpio_output_pin);

    return gpio_output_pin;
}

void io_gpio_pin_destroy(GpioPin_t* gpio_pin)
{
    free(gpio_pin);
}

void io_gpio_output_pin_setActive(GpioOutputPin_t* gpio_output_pin)
{
    switch (gpio_output_pin->active_state)
    {
        case ACTIVE_HIGH:
            io_gpio_pin_setHALPinState(gpio_output_pin, GPIO_PIN_SET);
            return;
        case ACTIVE_LOW:
            io_gpio_pin_setHALPinState(gpio_output_pin, GPIO_PIN_RESET);
            return;
    }
}

void io_gpio_pin_setInactive(GpioOutputPin_t* gpio_output_pin)
{
    switch (gpio_output_pin->active_state)
    {
        case ACTIVE_HIGH:
            io_gpio_pin_setHALPinState(gpio_output_pin, GPIO_PIN_RESET);
            return;
        case ACTIVE_LOW:
            io_gpio_pin_setHALPinState(gpio_output_pin, GPIO_PIN_SET);
            return;
    }
}

void io_gpio_pin_setHALPinState(GpioOutputPin_t* gpio_output_pin, GPIO_PinState pin_state)
{
    HAL_GPIO_WritePin(
        gpio_output_pin->gpio_pin.gpio_handler,
        gpio_output_pin->gpio_pin.gpio_pin_index, pin_state);
}

bool io_gpio_pin_get(GpioPin_t* gpio_pin)
{
    return HAL_GPIO_ReadPin(gpio_pin->gpio_handler, gpio_pin->gpio_pin_index);
}
