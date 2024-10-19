#ifndef GAMEPAD
#define GAMEPAD

#include <cstdint>
#include "gpio_output_config.h"

#define GAMEPAD_MASK_UP     (1U << 0)
#define GAMEPAD_MASK_DOWN   (1U << 1)
#define GAMEPAD_MASK_LEFT   (1U << 2)
#define GAMEPAD_MASK_RIGHT  (1U << 3)
#define GAMEPAD_MASK_B1     (1U << 4)
#define GAMEPAD_MASK_B2     (1U << 5)
#define GAMEPAD_MASK_B3     (1U << 7)
#define GAMEPAD_MASK_B4     (1U << 8)
#define GAMEPAD_MASK_L1     (1U << 9)
#define GAMEPAD_MASK_R1     (1U << 10)
#define GAMEPAD_MASK_L2     (1U << 11)
#define GAMEPAD_MASK_R2     (1U << 12)
#define GAMEPAD_MASK_S1     (1U << 13)
#define GAMEPAD_MASK_S2     (1U << 14)
#define GAMEPAD_MASK_L3     (1U << 15)
#define GAMEPAD_MASK_R3     (1U << 16)
#define GAMEPAD_MASK_A1     (1U << 17)
#define GAMEPAD_MASK_A2     (1U << 18)

const uint32_t buttonMasks[] =
{
    GAMEPAD_MASK_UP,
	GAMEPAD_MASK_DOWN,
	GAMEPAD_MASK_LEFT,
	GAMEPAD_MASK_RIGHT,
	GAMEPAD_MASK_B1,
	GAMEPAD_MASK_B2,
	GAMEPAD_MASK_B3,
	GAMEPAD_MASK_B4,
	GAMEPAD_MASK_L1,
	GAMEPAD_MASK_R1,
	GAMEPAD_MASK_L2,
	GAMEPAD_MASK_R2,
	GAMEPAD_MASK_S1,
	GAMEPAD_MASK_S2,
	GAMEPAD_MASK_L3,
	GAMEPAD_MASK_R3,
	GAMEPAD_MASK_A1,
	GAMEPAD_MASK_A2
};

static uint32_t gamepadState = {0};

static int gpioPinOutConfig[] = {
    GPIO_PIN_OUT_UP,
    GPIO_PIN_OUT_DOWN,
    GPIO_PIN_OUT_LEFT,
    GPIO_PIN_OUT_RIGHT,
    GPIO_PIN_OUT_B1,
    GPIO_PIN_OUT_B2,
    GPIO_PIN_OUT_B3,
    GPIO_PIN_OUT_B4,
    GPIO_PIN_OUT_L1,
    GPIO_PIN_OUT_R1,
    GPIO_PIN_OUT_L2,
    GPIO_PIN_OUT_R2,
    GPIO_PIN_OUT_S1,
    GPIO_PIN_OUT_S2,
    GPIO_PIN_OUT_L3,
    GPIO_PIN_OUT_R3,
    GPIO_PIN_OUT_A1,
    GPIO_PIN_OUT_A2
};

static std::map<ButtonAction, int32_t> gpioPinOutMap = {
    { BUTTON_PRESS_DPAD_UP,     (1U << GPIO_PIN_OUT_UP)},
    { BUTTON_PRESS_DPAD_DOWN,   (1U << GPIO_PIN_OUT_DOWN)},
    { BUTTON_PRESS_DPAD_LEFT,   (1U << GPIO_PIN_OUT_LEFT)},
    { BUTTON_PRESS_DPAD_RIGHT,  (1U << GPIO_PIN_OUT_RIGHT)},
    { BUTTON_PRESS_B1,          (1U << GPIO_PIN_OUT_B1)},
    { BUTTON_PRESS_B2,          (1U << GPIO_PIN_OUT_B2)},
    { BUTTON_PRESS_B3,          (1U << GPIO_PIN_OUT_B3)},
    { BUTTON_PRESS_B4,          (1U << GPIO_PIN_OUT_B4)},
    { BUTTON_PRESS_L1,          (1U << GPIO_PIN_OUT_L1)},
    { BUTTON_PRESS_R1,          (1U << GPIO_PIN_OUT_R1)},
    { BUTTON_PRESS_L2,          (1U << GPIO_PIN_OUT_L2)},
    { BUTTON_PRESS_R2,          (1U << GPIO_PIN_OUT_R2)},
    { BUTTON_PRESS_S1,          (1U << GPIO_PIN_OUT_S1)},
    { BUTTON_PRESS_S2,          (1U << GPIO_PIN_OUT_S2)},
    { BUTTON_PRESS_L3,          (1U << GPIO_PIN_OUT_L3)},
    { BUTTON_PRESS_R3,          (1U << GPIO_PIN_OUT_R3)},
    { BUTTON_PRESS_A1,          (1U << GPIO_PIN_OUT_A1)},
    { BUTTON_PRESS_A2,          (1U << GPIO_PIN_OUT_A2)}
};

static inline void setOutputPins() {
    for(size_t i = 0; i < 18; i++) {
        if(isValidSelectorPin(gpioPinOutConfig[i])) {
            gpio_init(gpioPinOutConfig[i]);
            gpio_set_dir(gpioPinOutConfig[i], GPIO_OUT);
            rp2040GPI0Pins[gpioPinOutConfig[i]].gpioState = GpioState::RESERVED;
        }
    }
}

#endif