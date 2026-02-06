#!/usr/bin/env bash
set -euo pipefail

# Install GoogleTest source (common on Ubuntu)
sudo apt-get update -y
sudo apt-get install -y cmake g++ make libgtest-dev

# Build gtest libraries if not already built
# Ubuntu often ships source at /usr/src/googletest
if [ -d /usr/src/googletest ]; then
    echo "[install_gtest] Building googletest from /usr/src/googletest..."
    pushd /usr/src/googletest >/dev/null
    sudo cmake -S . -B build
    sudo cmake --build build -j 2
    # Copy libraries to a standard location
    sudo cp build/lib/*.a /usr/lib/ || true
    popd >/dev/null
fi

echo "[install_gtest] Done."
