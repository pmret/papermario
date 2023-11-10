#!/bin/bash

set -e

mkdir -p build
echo "Building..."
export PATH=/gcc-2.7.2:$PATH
COMPILER_PATH=/gcc-2.7.2 /gcc-2.7.2/gcc -v -G0 -mgp32 -mfp32 -mips3 main.c -c -o build/main.o
COMPILER_PATH=/gcc-2.7.2 /gcc-2.7.2/gcc -G0 -mgp32 -mfp32 -mips3 header.s -c -o build/header.o
COMPILER_PATH=/gcc-2.7.2 /gcc-2.7.2/gcc -G0 -mgp32 -mfp32 -mips3 handwritten.s -c -o build/handwritten.o
COMPILER_PATH=/gcc-2.7.2 /gcc-2.7.2/gcc -G0 -mgp32 -mfp32 -mips3 dummy_ipl3.s -c -o build/dummy_ipl3.o
mips-linux-gnu-strip -N dummy_symbol_name build/*.o
echo "Linking..."
mips-linux-gnu-ld -Map build/basic_app.map -T basic_app.ld -o build/basic_app.elf
echo "Dumping bin..."
mips-linux-gnu-objcopy build/basic_app.elf -O binary build/basic_app.bin --pad-to=0x1140 --gap-fill=0xFF
