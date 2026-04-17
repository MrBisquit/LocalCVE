@echo off

REM Windows build script for LocalCVE (BATCH script)
REM ---------------------------------------------------------
REM Options:
REM     build_win.bat Debug/Release "path/to/vcpkg/toolchain/file.cmake"
REM Example:
REM     build_win.bat Debug "path/to/vcpkg/toolchain/file.cmake"

if not exist "build" (
    echo build does not exist, creating...
    mkdir build
)

if not %2 == Debug if not %2 == Release (
    echo %2 is not a valid option
    exit /B 1
)

cd build

if %2 == Debug (
    echo Building with Debug configuration

    cmake .. -G "Ninja" -DCMAKE_TOOLCHAIN_FILE="%3" -DCMAKE_C_COMPILER=clang -DCMAKE_CXX_COMPILER=clang++ -DVCPKG_TARGET_TRIPLET=x64-mingw-static
    cmake --build . --config Debug
) else if %2 == Release (
    echo Building with Release configuration

    cmake .. -G "Ninja" -DCMAKE_TOOLCHAIN_FILE="%3" -DCMAKE_C_COMPILER=clang -DCMAKE_CXX_COMPILER=clang++ -DVCPKG_TARGET_TRIPLET=x64-mingw-static
    cmake --build . --config Release
)

cd ..