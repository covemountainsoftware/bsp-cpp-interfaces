cmake_minimum_required(VERSION 3.16)
project(bsp-cpp-interfaces)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 11)

add_library(bsp-cpp-interfaces INTERFACE
        include/character_device.hpp
)

target_include_directories(bsp-cpp-interfaces INTERFACE
        include/
)
