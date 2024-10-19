// Pico Includes
#include "pico/stdlib.h"
#include "hardware/adc.h"
#include <iostream>

#include "GpioManager.h"
#include "Gamepad.h"

// Config
#include "CD74HC4067SM96_00_config.h"
#include "CD74HC4067SM96_01_config.h"
#include "CD74HC4067SM96_02_config.h"
#include "CD74HC4067SM96_03_config.h"
#include "CD74HC4067SM96_gpio_selector.h"
#include "gpio_output_config.h"

// Drivers
#include "CD74HC4067SM96.h"

#define ADC_TRIGGER_THRESHOLD 3000

int main() {
    // Debug
    // stdio_init_all();

    // Initialize GPIO
    adc_init();
    setOutputPins();
    CD74HC4067SM96 MUX_00 = CD74HC4067SM96(CD74HC4067SM96_00_SIGNAL, GPIO_SELELECTOR_00, GPIO_SELELECTOR_01, GPIO_SELELECTOR_02, GPIO_SELELECTOR_03);
    CD74HC4067SM96 MUX_01 = CD74HC4067SM96(CD74HC4067SM96_01_SIGNAL, GPIO_SELELECTOR_01, GPIO_SELELECTOR_01, GPIO_SELELECTOR_02, GPIO_SELELECTOR_03);
    CD74HC4067SM96 MUX_02 = CD74HC4067SM96(CD74HC4067SM96_02_SIGNAL, GPIO_SELELECTOR_01, GPIO_SELELECTOR_01, GPIO_SELELECTOR_02, GPIO_SELELECTOR_03);
    CD74HC4067SM96 MUX_03 = CD74HC4067SM96(CD74HC4067SM96_03_SIGNAL, GPIO_SELELECTOR_01, GPIO_SELELECTOR_01, GPIO_SELELECTOR_02, GPIO_SELELECTOR_03);

    while(true) {
        gamepadState = {INT32_MAX};

        for(size_t i = 0; i < CD74HC4067SM96_NUM_CHANNELS; i++) {
                if(CD74HC4067SM96_00_ENABLED && MUX_00.readChannel(i) > ADC_TRIGGER_THRESHOLD) {
                    gamepadState = gamepadState & ~gpioPinOutMap[CD74HC4067SM96_00_MAPPING[i]] ;
                }

                if(CD74HC4067SM96_01_ENABLED && MUX_01.readChannel(i) > ADC_TRIGGER_THRESHOLD) {
                    gamepadState = gamepadState & ~gpioPinOutMap[CD74HC4067SM96_01_MAPPING[i]] ;
                }

                if(CD74HC4067SM96_02_ENABLED && MUX_02.readChannel(i) > ADC_TRIGGER_THRESHOLD) {
                    gamepadState = gamepadState & ~gpioPinOutMap[CD74HC4067SM96_02_MAPPING[i]] ;
                }

                if(CD74HC4067SM96_03_ENABLED && MUX_03.readChannel(i) > ADC_TRIGGER_THRESHOLD) {
                    gamepadState = gamepadState & ~gpioPinOutMap[CD74HC4067SM96_03_MAPPING[i]] ;
                }
        }

        gpio_clr_mask(~gamepadState);
        gpio_set_mask(gamepadState);
    }
}