#!/usr/bin/env bash
set -euo pipefail
cmake -S . -B build ${1:+-G "$1"} # pass "MinGW Makefiles" on Windows
camke --build build -j
