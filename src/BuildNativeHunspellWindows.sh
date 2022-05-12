#!/bin/bash

rm -rf build

cmake -DCMAKE_VERBOSE_MAKEFILE:BOOL=ON -DCMAKE_EXPORT_COMPILE_COMMANDS:BOOL=TRUE -DCMAKE_TOOLCHAIN_FILE=../WindowsMingwX64Toolchain.cmake -DNATIVE_LIBRARY_NAME=hunspell-windows-x64 -SHunspellNative -Bbuild/HunspellNativeX64
cmake -DCMAKE_VERBOSE_MAKEFILE:BOOL=ON -DCMAKE_EXPORT_COMPILE_COMMANDS:BOOL=TRUE -DCMAKE_TOOLCHAIN_FILE=../WindowsMingwX86Toolchain.cmake -DNATIVE_LIBRARY_NAME=hunspell-windows-x86 -SHunspellNative -Bbuild/HunspellNativeX86

cmake --build build/HunspellNativeX64 --config Release
cmake --build build/HunspellNativeX86 --config Release

cp build/HunspellNativeX64/hunspell-windows-x64.dll NHunspell/HunspellNative/
cp build/HunspellNativeX86/hunspell-windows-x86.dll NHunspell/HunspellNative/

# cp /usr/lib/gcc/x86_64-w64-mingw32/9.3-win32/libquadmath-0.dll NHunspell/HunspellNative/
# cp /usr/lib/gcc/x86_64-w64-mingw32/9.3-win32/libatomic-1.dll NHunspell/HunspellNative/
# cp /usr/lib/gcc/x86_64-w64-mingw32/9.3-win32/libgcc_s_seh-1.dll NHunspell/HunspellNative/
# cp /usr/lib/gcc/x86_64-w64-mingw32/9.3-win32/libgomp-1.dll NHunspell/HunspellNative/
# cp /usr/lib/gcc/x86_64-w64-mingw32/9.3-win32/libssp-0.dll NHunspell/HunspellNative/
# cp /usr/lib/gcc/x86_64-w64-mingw32/9.3-win32/libstdc++-6.dll NHunspell/HunspellNative/
