#!/bin/bash

uname=`uname`

if [[ "$uname" == "Darwin" ]]; then
    echo "Downloading gcc/binutils for macOS"
    curl -L "https://github.com/pmret/gcc-papermario/releases/download/master/mac.tar.gz" | tar zx -C tools/build/cc/gcc
    curl -L "https://github.com/pmret/binutils-papermario/releases/download/master/mac.tar.gz" | tar zx -C tools/build/cc/GCC

    # 2.7.2
    curl -L "https://github.com/decompals/mips-gcc-2.7.2/releases/download/main/gcc-2.7.2-mac.tar.gz" | tar zx -C tools/build/cc/gcc2.7.2
    curl -L "https://github.com/decompals/mips-binutils-2.6/releases/download/main/binutils-2.6-mac.tar.gz" | tar zx -C tools/build/cc/gcc2.7.2

    echo "Downloading IDO 5.3 for macOS"
    curl -L "https://github.com/decompals/ido-static-recomp/releases/download/v0.2/ido-5.3-recomp-macos-latest.tar.gz" | tar zx -C tools/build/cc/ido5.3
    exit 0
fi

echo "Downloading gcc/binutils for Linux"
curl -L "https://github.com/pmret/gcc-papermario/releases/download/master/linux.tar.gz" | tar zx -C tools/build/cc/gcc
curl -L "https://github.com/pmret/binutils-papermario/releases/download/master/linux.tar.gz" | tar zx -C tools/build/cc/gcc

# 2.7.2
curl -L "https://github.com/decompals/mips-gcc-2.7.2/releases/download/main/gcc-2.7.2-linux.tar.gz" | tar zx -C tools/build/cc/gcc2.7.2
curl -L "https://github.com/decompals/mips-binutils-2.6/releases/download/main/binutils-2.6-linux.tar.gz" | tar zx -C tools/build/cc/gcc2.7.2

# EGCS
curl -L "https://github.com/decompals/mips-binutils-egcs-2.9.5/releases/latest/download/mips-binutils-egcs-2.9.5-linux.tar.gz" | tar zx -C tools/build/cc/egcs
curl -L "https://github.com/decompals/mips-gcc-egcs-2.91.66/releases/latest/download/mips-gcc-egcs-2.91.66-linux.tar.gz" | tar zx -C tools/build/cc/egcs

echo "Downloading IDO 5.3 for Linux"
curl -L "https://github.com/decompals/ido-static-recomp/releases/download/v0.2/ido-5.3-recomp-ubuntu-latest.tar.gz" | tar zx -C tools/build/cc/ido5.3
