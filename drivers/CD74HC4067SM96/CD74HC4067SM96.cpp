#include "CD74HC4067SM96.h"
#include "GpioManager.h"
#include "hardware/adc.h"

CD74HC4067SM96::CD74HC4067SM96(uint8_t readPin, uint8_t s0, uint8_t s1, uint8_t s2, uint8_t s3, ButtonAction newButtonMapping[]) {

    if(isValidADCPin(readPin)) {
        _readPin = readPin;
        _adc_pin = _readPin - (uint8_t)ADC_PIN_OFFSET;
        adc_gpio_init(_readPin);
        rp2040GPI0Pins[_readPin].gpioState = GpioState::RESERVED;
    }
    
    if(isValidSelectorPin(s0)) {
        _s0 = s0;
        gpio_init(_s0);
        gpio_set_dir(_s0, GPIO_OUT);
        rp2040GPI0Pins[_s0].gpioState = GpioState::MUX_SELECTOR;
        bytes++;
    }

    if(isValidSelectorPin(s1)) { 
        _s1 = s1;
        gpio_init(_s1);
        gpio_set_dir(_s1, GPIO_OUT);
        rp2040GPI0Pins[_s1].gpioState = GpioState::MUX_SELECTOR;
        bytes++;
    }

    if(isValidSelectorPin(s2)) {
        _s2 = s2;
        gpio_init(_s2);
        gpio_set_dir(_s2, GPIO_OUT);
        rp2040GPI0Pins[_s2].gpioState = GpioState::MUX_SELECTOR;
        bytes++;
    }
    if(isValidSelectorPin(s3)) {
        _s3 = s3;
        gpio_init(_s3);
        gpio_set_dir(_s3, GPIO_OUT);
        rp2040GPI0Pins[_s3].gpioState = GpioState::MUX_SELECTOR;
        bytes++;
    }

    for(size_t i = 0; i < CD74HC4067SM96_NUM_CHANNELS; i++) {
        channelActionMapping[i] = newButtonMapping[i];
    }
}

uint16_t CD74HC4067SM96::readChannel(uint8_t channel) {
    if(bytes > 0) { gpio_put(_s0, _g_channel_truth_table[channel][0]);}
    if(bytes > 1) { gpio_put(_s1, _g_channel_truth_table[channel][1]);}
    if(bytes > 2) { gpio_put(_s2, _g_channel_truth_table[channel][2]);}
    if(bytes > 3) { gpio_put(_s3, _g_channel_truth_table[channel][3]);}

    adc_select_input(_adc_pin);
    return adc_read();
}