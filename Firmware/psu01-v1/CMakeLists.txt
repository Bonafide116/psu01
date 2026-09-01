cmake_minimum_required(VERSION 3.20)
project(l432kc_bringup C ASM)

add_executable(bringup
    src/startup.c
    src/main.c
    src/drivers/gpio.c
)
target_include_directories(bringup PRIVATE inc)
target_compile_options(bringup PRIVATE -Wall -O0 -g)