#!/usr/bin/env bash

# Linux build script for LocalCVE (SHELL script)
# -------------------------------------------------------
# Options:
#   build_linux.sh Debug/Release
# Example:
#   build_linux.sh Debug

set -e

if [ "$1" != "Debug" ] && [ "$1" != "Release" ]; then
    echo "$1 must be either Debug or Release"
    exit 1
fi

if [ ! -d "build" ]; then
    echo "Creating build path at build"
    mkdir -p "build" || { echo "Failed to create directory at build"; exit 1; }
fi

cd "build" || exit 1

if [ "$1" = "Debug" ]; then
    echo "Building with Debug configuration"

    cmake .. -DCMAKE_BUILD_TYPE=Debug
    cmake --build . -- -j$(nproc)
elif [ "$1" = "Release" ]; then
    echo "Building with Release configuration"

    cmake .. -DCMAKE_BUILD_TYPE=Release
    cmake --build . -- -j$(nproc)
fi

cd ..