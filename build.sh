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

export PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin
unset CPATH
unset C_INCLUDE_PATH
unset CPLUS_INCLUDE_PATH

CMAKE_ARGS="
	-DCMAKE_C_COMPILER=/usr/bin/clang
	-DCMAKE_CXX_COMPILER=/usr/bin/clang++
"

cd "build" || exit 1

if [ "$1" = "Debug" ]; then
    echo "Building with Debug configuration"

    cmake .. -DCMAKE_BUILD_TYPE=Debug $CMAKE_ARGS
    cmake --build . -- -j$(nproc)
elif [ "$1" = "Release" ]; then
    echo "Building with Release configuration"

    cmake .. -DCMAKE_BUILD_TYPE=Release $CMAKE_ARGS
    cmake --build . -- -j$(nproc)
fi

cd ..