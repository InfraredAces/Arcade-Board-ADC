#ifndef _GPIO_MANAGER_H_
#define _GPIO_MANAGER_H_

#include "pico/stdlib.h"
#include "enums.h"

#define ADC_PIN_OFFSET 26;

struct GpioPin {
    GpioState gpioState = GpioState::AVAILABLE;
    GpioType gpioType;
};

static GpioPin rp2040GPI0Pins[30];

static inline bool isValidPin(int32_t pin) {
    int32_t numBank0GPIOS = sizeof(rp2040GPI0Pins);
    return pin >= 0 && 
        pin < numBank0GPIOS &&
        rp2040GPI0Pins[pin].gpioState == GpioState::AVAILABLE;
}

static inline bool isValidSelectorPin(int32_t pin) {
    return isValidPin(pin) || rp2040GPI0Pins[pin].gpioState == GpioState::MUX_SELECTOR;
}

static inline bool isValidADCPin(int32_t pin) {
    // return isValidPin(pin) && rp2040GPI0Pins[pin].gpioType == GpioType::ANALOG;
    return isValidPin(pin) && pin >= 26 && pin <= 29;
}

#endif