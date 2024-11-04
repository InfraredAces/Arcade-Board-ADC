add_library(sma_filter sma_filter.cpp)
target_link_libraries(sma_filter PUBLIC PicoPeripherals)
target_include_directories(sma_filter INTERFACE .)
target_include_directories(sma_filter PUBLIC . PicoPeripherals)
