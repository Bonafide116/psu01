set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR arm)

set(CMAKE_C_COMPILER arm-none-eabi-gcc)
set(CMAKE_CXX_COMPILER arm-none-eabi-g++)
set(CMAKE_ASM_COMPILER arm-none-eabi-gcc)

set(CMAKE_C_FLAGS "-ffile-prefix-map=/work=. -mcpu=cortex-m4 -mthumb -mfloat-abi=soft")
set(CMAKE_EXE_LINKER_FLAGS "-mcpu=cortex-m4 -mthumb -T${CMAKE_SOURCE_DIR}/linker/STM32L432KC.ld -nostdlib")

# Cross-compiling: CMake can't run a test binary on the build host, so tell it not to try
set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)
