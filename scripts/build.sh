#!/usr/bin/env bash
set -euo pipefail

# Optional: pass a generator, e.g. ./scripts/build.sh "Unix Makefiles"
GEN=${1:-}

# Nice-to-have: export compile_commands.json for clangd
cmake -S . -B build ${GEN:+-G "$GEN"} -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -DCMAKE_BUILD_TYPE=Debug
cmake --build build -j
