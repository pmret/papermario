#!/usr/bin/env bash
INPUT="$(realpath "$1")"
OUTPUT="$(realpath "$3")"
cd /home/alex/papermario
tools/build/cc/gcc/gcc -w -Iver/us/build/include -Iinclude -Isrc -Iassets/us -D_LANGUAGE_C -D_FINALROM -DVERSION=us -DF3DEX_GBI_2 -D_MIPS_SZLONG=32 -nostdinc -c -G0 -O2 -fno-common -B tools/build/cc/gcc/ -Wuninitialized -Wmissing-braces -Wimplicit -Wredundant-decls -Wstrict-prototypes -DPERMUTER -fforce-addr "$INPUT" -o "$OUTPUT"