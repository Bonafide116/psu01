#!/bin/bash
set -e
docker run --rm -it --user $(id -u):$(id -g) --network host \
  -v "$(pwd)":/work -w /work stm32-tools:latest \
  gdb-multiarch -x .gdbinit build/bringup