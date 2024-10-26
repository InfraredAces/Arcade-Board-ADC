// Pico Includes
#include "pico/stdlib.h"
#include "hardware/adc.h"
#include <iostream>

#include "GpioManager.h"

// Config
#include "CD74HC4067SM96_00_config.h"
#include "CD74HC4067SM96_01_config.h"
#include "CD74HC4067SM96_02_config.h"
#include "CD74HC4067SM96_03_config.h"
#include "CD74HC4067SM96_gpio_selector.h"

// Drivers
#include "CD74HC4067SM96.h"

#define ADC_TRIGGER_THRESHOLD 3000
#define GPIO_TEST_00 15
#define GPIO_TEST_01 16

int main() {

    // Initialize GPIO
    adc_init();
    CD74HC4067SM96 MUX_00 = CD74HC4067SM96(CD74HC4067SM96_00_SIGNAL, GPIO_SELELECTOR_00, GPIO_SELELECTOR_01, GPIO_SELELECTOR_02, GPIO_SELELECTOR_03, CD74HC4067SM96_00_MAPPING);
    CD74HC4067SM96 MUX_01 = CD74HC4067SM96(CD74HC4067SM96_01_SIGNAL, GPIO_SELELECTOR_01, GPIO_SELELECTOR_01, GPIO_SELELECTOR_02, GPIO_SELELECTOR_03, CD74HC4067SM96_01_MAPPING);
    CD74HC4067SM96 MUX_02 = CD74HC4067SM96(CD74HC4067SM96_02_SIGNAL, GPIO_SELELECTOR_01, GPIO_SELELECTOR_01, GPIO_SELELECTOR_02, GPIO_SELELECTOR_03, CD74HC4067SM96_02_MAPPING);
    CD74HC4067SM96 MUX_03 = CD74HC4067SM96(CD74HC4067SM96_03_SIGNAL, GPIO_SELELECTOR_01, GPIO_SELELECTOR_01, GPIO_SELELECTOR_02, GPIO_SELELECTOR_03, CD74HC4067SM96_03_MAPPING);

    while(true) {
        for(size_t i = 0; i < CD74HC4067SM96_NUM_CHANNELS; i++) {
                if(CD74HC4067SM96_00_ENABLED && MUX_00.readChannel(i) > ADC_TRIGGER_THRESHOLD) {
                    gpio_put(GPIO_TEST_00, true);
                } else {
                    gpio_put(GPIO_TEST_00, false);
                }

                if(CD74HC4067SM96_01_ENABLED && MUX_01.readChannel(i) > ADC_TRIGGER_THRESHOLD) {
                    gpio_put(GPIO_TEST_01, true);
                } else {
                    gpio_put(GPIO_TEST_01, false);
                }
        }
    }
}