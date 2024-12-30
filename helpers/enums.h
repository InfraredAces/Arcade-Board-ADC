#ifndef _ENUMS_H_
#define _ENUMS_H_

enum ButtonAction {
    NONE                        = 0,
    BUTTON_PRESS_DPAD_UP        = 1,
    BUTTON_PRESS_DPAD_DOWN      = 2,
    BUTTON_PRESS_DPAD_LEFT      = 3,
    BUTTON_PRESS_DPAD_RIGHT     = 4,
    BUTTON_PRESS_LS_UP          = 5,
    BUTTON_PRESS_LS_DOWN        = 6,
    BUTTON_PRESS_LS_LEFT        = 7,
    BUTTON_PRESS_LS_RIGHT       = 8,
    BUTTON_PRESS_RS_UP          = 9,
    BUTTON_PRESS_RS_DOWN        = 10,
    BUTTON_PRESS_RS_LEFT        = 11,
    BUTTON_PRESS_RS_RIGHT       = 12,
    BUTTON_PRESS_B1             = 13,
    BUTTON_PRESS_B2             = 14,
    BUTTON_PRESS_B3             = 15,
    BUTTON_PRESS_B4             = 16,
    BUTTON_PRESS_L1             = 17,
    BUTTON_PRESS_R1             = 18,
    BUTTON_PRESS_L2             = 19,
    BUTTON_PRESS_R2             = 20,
    BUTTON_PRESS_S1             = 21,
    BUTTON_PRESS_S2             = 22,
    BUTTON_PRESS_A1             = 23,
    BUTTON_PRESS_A2             = 24,
    BUTTON_PRESS_L3             = 25,
    BUTTON_PRESS_R3             = 26,
    ANALOG_DIRECTION_LS_X_NEG   = 27,
    ANALOG_DIRECTION_LS_X_POS   = 28,
    ANALOG_DIRECTION_LS_Y_NEG   = 29,
    ANALOG_DIRECTION_LS_Y_POS   = 30,
    ANALOG_DIRECTION_RS_X_NEG   = 31,
    ANALOG_DIRECTION_RS_X_POS   = 32,
    ANALOG_DIRECTION_RS_Y_NEG   = 33,
    ANALOG_DIRECTION_RS_Y_POS   = 34,
    ANALOG_TRIGGER_L2           = 35,
    ANALOG_TRIGGER_R2           = 36


};

enum GpioState {
    RESERVED = 0,
    AVAILABLE = 1,
    MUX_SELECTOR = 2
};

enum GpioType {
    DIGITAL = 0,
    ANALOG = 1
};

#endif