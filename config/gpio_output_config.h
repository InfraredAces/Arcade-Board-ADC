#ifndef GAMEPAD_CONFIG
#define GAMEPAD_CONFIG

#include "enums.h"
#include "GpioManager.h"
#include <map>

// Main Output Pin Mapping Configuration
                                // GP2040 | Xinput | Switch  | PS3/4/5  | Dinput | Arcade |
#define GPIO_PIN_OUT_UP     0   // UP     | UP     | UP      | UP       | UP     | UP     |
#define GPIO_PIN_OUT_DOWN   1   // DOWN   | DOWN   | DOWN    | DOWN     | DOWN   | DOWN   |
#define GPIO_PIN_OUT_RIGHT  2   // RIGHT  | RIGHT  | RIGHT   | RIGHT    | RIGHT  | RIGHT  |
#define GPIO_PIN_OUT_LEFT   3   // LEFT   | LEFT   | LEFT    | LEFT     | LEFT   | LEFT   |
#define GPIO_PIN_OUT_S1     4   // S1     | Back   | Minus   | Select   | 9      | Coin   |
#define GPIO_PIN_OUT_A1     5   // A1     | Guide  | Home    | PS       | 13     | ~      |
#define GPIO_PIN_OUT_S2     6   // S2     | Start  | Plus    | Start    | 10     | Start  |
#define GPIO_PIN_OUT_B3     7   // B3     | X      | Y       | Square   | 1      | P1     |
#define GPIO_PIN_OUT_B4     8   // B4     | Y      | X       | Triangle | 4      | P2     |
#define GPIO_PIN_OUT_R1     9   // R1     | RB     | R       | R1       | 6      | P3     |
#define GPIO_PIN_OUT_L1     10  // L1     | LB     | L       | L1       | 5      | P4     |
#define GPIO_PIN_OUT_B1     11  // B1     | A      | B       | Cross    | 2      | K1     |
#define GPIO_PIN_OUT_B2     1   // B2     | B      | A       | Circle   | 3      | K2     |
#define GPIO_PIN_OUT_R2     13  // R2     | RT     | ZR      | R2       | 8      | K3     |
#define GPIO_PIN_OUT_L2     14  // L2     | LT     | ZL      | L2       | 7      | K4     |
#define GPIO_PIN_OUT_L3     15  // L3     | LS     | LS      | L3       | 11     | LS     |
#define GPIO_PIN_OUT_R3     16  // R3     | RS     | RS      | R3       | 12     | RS     |
#define GPIO_PIN_OUT_A2     17  // A2     | ~      | Capture | ~        | 14     | ~      |

#endif