#!/usr/bin/env bash
set -euo pipefail

# Build directory
mkdir -p build

# Compile student code + tests
# Note: adjust filenames if requirements change
g++ -std=c++17 -O2 -Wall -Wextra -pedantic \
    -I. \
    tests/test_parking_meter.cpp ParkingMeter.cpp \
    -lgtest -lgtest_main -pthread \
    -o build/parking_meter_tests

# Run tests with gtest output (XML for parsing)
./build/parking_meter_tests --gtest_output=xml:build/gtest_results.xml
