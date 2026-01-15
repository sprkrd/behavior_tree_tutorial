#!/usr/bin/bash

set -x
cmake . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build --parallel `nproc`
