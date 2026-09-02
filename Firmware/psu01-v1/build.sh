#!/bin/bash
set -e
TARGET=psu01-v1
docker run --rm --user $(id -u):$(id -g) -v "$(pwd)":/work -w /work stm32-tools:latest \
  bash -c "cmake -B build -S . -DCMAKE_TOOLCHAIN_FILE=toolchain-arm-none-eabi.cmake -G 'Unix Makefiles' && make -C build && arm-none-eabi-size build/$TARGET"