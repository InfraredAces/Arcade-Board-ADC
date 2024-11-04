# Hall Effect Switch ADC

This project is hardware and firmare designed to convert 0-3.3V analog input signals to digital output signals for gamepad controller boards. 

It is built with the intention of using Hall Effect keyboard switches with controller boards that typically only accept digital signals for gamepad inputs through 20 pin connectors. Such as

- [RP2040 Advanced Breakout Board](https://github.com/OpenStickCommunity/Hardware/tree/main/Boards/GP2040-CE%20Official%20Boards/RP2040%20Advanced%20Breakout%20Board/RP2040%20Advanced%20Breakout%20Board%20-%20Passthrough) ([GP2040-CE](https://gp2040-ce.info/))
-  Various Brook boards

## Project Setup

### Debian/Ubuntu

Set up Pico SDK

```shell
git clone https://github.com/raspberrypi/pico-sdk.git
RUN cd pico-sdk && git submodule update --init

# Set the PICO_SDK_PATH environment variable to where you just cloned the repo above.
export PICO_SDK_PATH=/path/to/pico-sdk
```

Install the toolchain needed to build Pico projects.

```shell
sudo apt update && apt install -y --no-install-recommends git ca-certificates make cmake gcc g++ gcc-arm-none-eabi libnewlib-arm-none-eabi libstdc++-arm-none-eabi-newlib python3 python3-venv nodejs npm clang
```

### VS Code + Dev Container (Docker)

Use Microsoft's [documentation](https://code.visualstudio.com/docs/devcontainers/tutorial) on running Visual Studio Code in a Docker container using the Dev Containers extension.

The Dockerfile included in the repo will be sufficient for building this project.

## Build Project

Run the following commands in the root of the repo.

```shell
mkdir build
cd build
cmake ..
make
```

## Customize Configuration

### GPIO Output

Edit the header file `config/gpio_output_config.h`

### Gamepad Input Mapping

Edit the configuration files below in `config/CD74HC4067SM96` depending on how many CD74HC4067SM96 you are using and which pins are being used specifically, both of the RP2040 and of the CD74HC4067SM96.

- `config/CD74HC4067SM96/CD74HC4067SM96_00_config.h`
- `config/CD74HC4067SM96/CD74HC4067SM96_01_config.h`
- `config/CD74HC4067SM96/CD74HC4067SM96_02_config.h`
- `config/CD74HC4067SM96/CD74HC4067SM96_03_config.h`

For each of the above configuration files, you will want to modify the following `#define` to prior to building the firmware.

- Set `CD74HC4067SM96_##_ENABLED` to `true` to enable that CD74HC4067SM96 module where `##` is the number of the CD74HC4067SM96 number (i.e. `CD74HC4067SM96_00_config` is CD74HC4067SM96 00)
- Set the Analog GPIO pin (GP26-GP29)
- Set a `ButtonAction` for each `CD74HC4067SM96_##_AA_ACTION` where `##` is the number of the CD74HC4067SM96 number and `AA`is the CD74HC4067SM96 (i.e. `CD74HC4067SM96_00_15_ACTION` is the pin 15 of CD74HC4067SM96 00)

#### ButtonActions

| ButtonAction            | GP2040 | Xinput | Switch  | PS3/4/5  | Dinput | Arcade |
|:------------------------|:-------|:-------|:--------|:---------|:-------|:-------|
| NONE                    | NONE   | NONE   | NONE    | NONE     | NONE   | NONE   |
| BUTTON_PRESS_DPAD_UP    | UP     | UP     | UP      | UP       | UP     | UP     |
| BUTTON_PRESS_DPAD_DOWN  | DOWN   | DOWN   | DOWN    | DOWN     | DOWN   | DOWN   |
| BUTTON_PRESS_DPAD_LEFT  | RIGHT  | RIGHT  | RIGHT   | RIGHT    | RIGHT  | RIGHT  |
| BUTTON_PRESS_DPAD_RIGHT | LEFT   | LEFT   | LEFT    | LEFT     | LEFT   | LEFT   |
| BUTTON_PRESS_LS_UP      |        |        |         |          |        |        |
| BUTTON_PRESS_LS_DOWN    |        |        |         |          |        |        |
| BUTTON_PRESS_LS_LEFT    |        |        |         |          |        |        |
| BUTTON_PRESS_LS_RIGHT   |        |        |         |          |        |        |
| BUTTON_PRESS_RS_UP      |        |        |         |          |        |        |
| BUTTON_PRESS_RS_DOWN    |        |        |         |          |        |        |
| BUTTON_PRESS_RS_LEFT    |        |        |         |          |        |        |
| BUTTON_PRESS_RS_RIGHT   |        |        |         |          |        |        |
| BUTTON_PRESS_B1         | B1     | A      | B       | Cross    | 2      | K1     |
| BUTTON_PRESS_B2         | B2     | B      | A       | Circle   | 3      | K2     |
| BUTTON_PRESS_B3         | B3     | X      | Y       | Square   | 1      | P1     |
| BUTTON_PRESS_B4         | B4     | Y      | X       | Triangle | 4      | P2     |
| BUTTON_PRESS_L1         | L1     | LB     | L       | L1       | 5      | P4     |
| BUTTON_PRESS_R1         | R1     | RB     | R       | R1       | 6      | P3     |
| BUTTON_PRESS_L2         | L2     | LT     | ZL      | L2       | 7      | K4     |
| BUTTON_PRESS_R2         | R2     | RT     | ZR      | R2       | 8      | K3     |
| BUTTON_PRESS_S1         | S1     | Back   | Minus   | Select   | 9      | Coin   |
| BUTTON_PRESS_S2         | S2     | Start  | Plus    | Start    | 10     | Start  |
| BUTTON_PRESS_A1         | A1     | Guide  | Home    | PS       | 13     | NONE   |
| BUTTON_PRESS_A2         | A2     | NONE   | Capture | NONE     | 14     | NONE   |
| BUTTON_PRESS_L3         | L3     | LS     | LS      | L3       | 11     | LS     |
| BUTTON_PRESS_R3         | R3     | RS     | RS      | R3       | 12     | RS     |

## Acknowledgements

- [GP2040-CE] - Inspiration for creating the project and making great gamepad firmware