#ifndef CD74HC4067SM96_H
#define CD74HC4067SM96_H

#include "pico/stdlib.h"
#include "enums.h"

#ifndef CD74HC4067SM96_NUM_CHANNELS
#define CD74HC4067SM96_NUM_CHANNELS 16
#endif

class CD74HC4067SM96
{
    public:
        CD74HC4067SM96(uint8_t readPin, uint8_t s0, uint8_t s1, uint8_t s2, uint8_t s3);
        uint16_t readChannel(uint8_t channel);
        uint8_t numChannels = 16;
    private:
        int channelActionMapping[16] = {
            ButtonAction::NONE, //  00
            ButtonAction::NONE, //  01
            ButtonAction::NONE, //  02
            ButtonAction::NONE, //  03
            ButtonAction::NONE, //  04
            ButtonAction::NONE, //  05
            ButtonAction::NONE, //  06
            ButtonAction::NONE, //  07
            ButtonAction::NONE, //  08
            ButtonAction::NONE, //  09
            ButtonAction::NONE, //  10
            ButtonAction::NONE, //  11
            ButtonAction::NONE, //  12
            ButtonAction::NONE, //  13
            ButtonAction::NONE, //  14
            ButtonAction::NONE  //  15
        };
        uint8_t _readPin;
        uint8_t _adc_pin;
        uint8_t _s0;
        uint8_t _s1;
        uint8_t _s2;
        uint8_t _s3;
        uint8_t bytes = 0;

        uint8_t _g_channel_truth_table[16][4] = {
        //  {s0, s1, s2, s3}  // channel
            { 0,  0,  0,  0}, // 00
            { 1,  0,  0,  0}, // 01
            { 0,  1,  0,  0}, // 02
            { 1,  1,  0,  0}, // 03
            { 0,  0,  1,  0}, // 04
            { 1,  0,  1,  0}, // 05
            { 0,  1,  1,  0}, // 06
            { 1,  1,  1,  0}, // 07
            { 0,  0,  0,  1}, // 08
            { 1,  0,  0,  1}, // 09
            { 0,  1,  0,  1}, // 10
            { 1,  1,  0,  1}, // 11
            { 0,  0,  1,  1}, // 12
            { 1,  0,  1,  1}, // 13
            { 0,  1,  1,  1}, // 14  
            { 1,  1,  1,  1}  // 15
        };
};

#endif