cmake_minimum_required(VERSION 3.20)
project(l432kc_bringup C ASM)

add_executable(psu01-v1
    src/startup.c
    src/main.c
    src/drivers/gpio.c
)
target_include_directories(psu01-v1 PRIVATE inc)
target_compile_options(psu01-v1 PRIVATE -Wall -Wextra -O0 -g)