FROM ubuntu:23.04

RUN apt update && apt install -y --no-install-recommends git ca-certificates make cmake gcc g++ gcc-arm-none-eabi libnewlib-arm-none-eabi libstdc++-arm-none-eabi-newlib python3 python3-venv nodejs npm clang

RUN git clone https://github.com/raspberrypi/pico-sdk.git
RUN cd pico-sdk && git submodule update --init

ENV PICO_SDK_PATH=/pico-sdk

