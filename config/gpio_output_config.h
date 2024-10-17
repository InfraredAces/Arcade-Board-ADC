#ifndef GAMEPAD_CONFIG
#define GAMEPAD_CONFIG

// Main Output Pin Mapping Configuration
                                // GP2040 | Xinput | Switch  | PS3/4/5  | Dinput | Arcade |
#define GPIO_PIN_OUT_UP     00  // UP     | UP     | UP      | UP       | UP     | UP     |
#define GPIO_PIN_OUT_DOWN   01  // DOWN   | DOWN   | DOWN    | DOWN     | DOWN   | DOWN   |
#define GPIO_PIN_OUT_RIGHT  02  // RIGHT  | RIGHT  | RIGHT   | RIGHT    | RIGHT  | RIGHT  |
#define GPIO_PIN_OUT_LEFT   03  // LEFT   | LEFT   | LEFT    | LEFT     | LEFT   | LEFT   |
#define GPIO_PIN_OUT_B1     04  // B1     | A      | B       | Cross    | 2      | K1     |
#define GPIO_PIN_OUT_B2     05  // B2     | B      | A       | Circle   | 3      | K2     |
#define GPIO_PIN_OUT_B3     06  // B3     | X      | Y       | Square   | 1      | P1     |
#define GPIO_PIN_OUT_B4     07  // B4     | Y      | X       | Triangle | 4      | P2     |
#define GPIO_PIN_OUT_L1     08  // L1     | LB     | L       | L1       | 5      | P4     |
#define GPIO_PIN_OUT_R1     09  // R1     | RB     | R       | R1       | 6      | P3     |
#define GPIO_PIN_OUT_L2     10  // L2     | LT     | ZL      | L2       | 7      | K4     |
#define GPIO_PIN_OUT_R2     11  // R2     | RT     | ZR      | R2       | 8      | K3     |
#define GPIO_PIN_OUT_S1     12  // S1     | Back   | Minus   | Select   | 9      | Coin   |
#define GPIO_PIN_OUT_S2     13  // S2     | Start  | Plus    | Start    | 10     | Start  |
#define GPIO_PIN_OUT_L3     14  // L3     | LS     | LS      | L3       | 11     | LS     |
#define GPIO_PIN_OUT_R3     15  // R3     | RS     | RS      | R3       | 12     | RS     |
#define GPIO_PIN_OUT_A1     16  // A1     | Guide  | Home    | PS       | 13     | ~      |
#define GPIO_PIN_OUT_A2     17  // A2     | ~      | Capture | ~        | 14     | ~      |

#endif