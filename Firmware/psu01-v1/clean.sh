#!/bin/bash
set -e
docker run --rm --user $(id -u):$(id -g) -v "$(pwd)":/work -w /work stm32-tools:latest \
  make -C build clean