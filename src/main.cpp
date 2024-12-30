// Pico Includes
#include "pico/stdlib.h"
#include "hardware/adc.h"
#include <iostream>

#include "GpioManager.h"
#include "Gamepad.h"

// Config
#include "CD74HC4067SM96_input_00_config.h"
#include "CD74HC4067SM96_input_01_config.h"
#include "CD74HC4067SM96_input_gpio_selector.h"
#include "CD74HC4067SM96_output_00_config.h"
#include "CD74HC4067SM96_output_01_config.h"
#include "CD74HC4067SM96_output_gpio_selector.h"

// Drivers
#include "CD74HC4067SM96.h"

#define ADC_TRIGGER_THRESHOLD 3000

int main() {
    // Debug
    // stdio_init_all();

    // Initialize GPIO
    adc_init();

    // Initialize GPIO: Input DEMUX
    CD74HC4067SM96 INPUT_00 = CD74HC4067SM96(CD74HC4067SM96_00_SIGNAL, GPIO_SELECTOR_INPUT_00, GPIO_SELECTOR_INPUT_01, GPIO_SELECTOR_INPUT_02, GPIO_SELECTOR_INPUT_03, CD74HC4067SM96_INPUT_00_MAPPING);
    CD74HC4067SM96 INPUT_01 = CD74HC4067SM96(CD74HC4067SM96_INPUT_01_SIGNAL, GPIO_SELECTOR_INPUT_01, GPIO_SELECTOR_INPUT_01, GPIO_SELECTOR_INPUT_02, GPIO_SELECTOR_INPUT_03, CD74HC4067SM96_INPUT_01_MAPPING);
    
    // Initialize GPIO: Output MUX
    CD74HC4067SM96 OUTPUT_00 = CD74HC4067SM96(CD74HC4067SM96_OUTPUT_00_SIGNAL, GPIO_SELECTOR_OUTPUT_01, GPIO_SELECTOR_OUTPUT_01, GPIO_SELECTOR_OUTPUT_02, GPIO_SELECTOR_OUTPUT_03, CD74HC4067SM96_OUTPUT_00_MAPPING);
    CD74HC4067SM96 OUTPUT_01 = CD74HC4067SM96(CD74HC4067SM96_OUTPUT_01_SIGNAL, GPIO_SELECTOR_OUTPUT_01, GPIO_SELECTOR_OUTPUT_01, GPIO_SELECTOR_OUTPUT_02, GPIO_SELECTOR_OUTPUT_03, CD74HC4067SM96_OUTPUT_01_MAPPING);

    while(true) {
        gamepadState = {INT32_MAX};

        for(size_t i = 0; i < CD74HC4067SM96_NUM_CHANNELS; i++) {
                if(CD74HC4067SM96_00_ENABLED && INPUT_00.readChannel(i) > ADC_TRIGGER_THRESHOLD) {
                    gpio_put(GPIO_TEST_00, true);
                } else {
                    gpio_put(GPIO_TEST_00, false);
                }

                if(CD74HC4067SM96_INPUT_01_ENABLED && INPUT_01.readChannel(i) > ADC_TRIGGER_THRESHOLD) {
                    gpio_put(GPIO_TEST_01, true);
                } else {
                    gpio_put(GPIO_TEST_01, false);
                }
        }

        gpio_clr_mask(~gamepadState);
        gpio_set_mask(gamepadState);
    }
}