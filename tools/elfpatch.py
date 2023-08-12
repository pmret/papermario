#!/usr/bin/env python3
#
#   Patch with 32-bit mode for ELF files so LD doesn't cry
#

import struct, sys

if __name__ == '__main__':
    if len(sys.argv) != 2:
        print(f"{sys.argv[0]} elf_file")
        sys.exit(1)

    with open(sys.argv[1], 'r+b') as f:
        magic = struct.unpack('>I', f.read(4))[0]
        if magic != 0x7F454C46:
            print('Error: Not an ELF file')
            sys.exit(1)

        f.seek(36)
        f.write(struct.pack('>I', 0x20000101))
