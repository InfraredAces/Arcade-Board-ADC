cmake_minimum_required(VERSION 3.13)

set(PROJECT_NAME HallEffectSwitchADC) # <-- PROJECT_Name Project Here

# initialize the SDK based on PICO_SDK_PATH
# note: this must happen before project()
include(pico_sdk_import.cmake)

if (PICO_SDK_VERSION_STRING VERSION_LESS "1.5.0")
    message(FATAL_ERROR "Raspberry Pi Pico SDK version 1.5.0 (or later) required. Your version is ${PICO_SDK_VERSION_STRING}")
endif()

# Uncomment the next line for an unoptimized build for debugging. Use in conjunction with the Debug build type.
# set(PICO_DEOPTIMIZED_DEBUG 1)

project(${PROJECT_NAME} C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Initialize the Raspberry Pi Pico SDK
pico_sdk_init()

add_executable(${PROJECT_NAME}
    src/main.cpp
)

target_include_directories(${PROJECT_NAME} PUBLIC
  helpers
  drivers/CD74HC4067SM96
  config/CD74HC4067SM96

)

target_link_libraries(${PROJECT_NAME}
    pico_stdlib
    CD74HC4067SM96
)

add_subdirectory(drivers)
add_subdirectory(libs)

pico_add_extra_outputs(${PROJECT_NAME})

# Set up files for the release packages
install(FILES
${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}.uf2
    DESTINATION .
)

if (NOT (DEFINED ENV(CI)) AND (EXISTS ${CMAKE_SOURCE_DIR}/modules/Custom.cmake))
  message(STATUS "Found custom script.")
	include(${CMAKE_SOURCE_DIR}/modules/Custom.cmake)
endif()