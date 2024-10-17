add_library(CD74HC4067SM96 
    CD74HC4067SM96.cpp
)

include_directories(
    ${CMAKE_HOME_DIRECTORY}/helpers
)

target_include_directories(CD74HC4067SM96 INTERFACE .)

target_link_libraries(CD74HC4067SM96
    pico_stdlib
    hardware_adc
)