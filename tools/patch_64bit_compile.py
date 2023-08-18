#!/usr/bin/env python3

import argparse, struct, sys

if __name__ == "__main__":
    parser = argparse.ArgumentParser()

    parser.add_argument("file", help="file to patch")
    args = parser.parse_args()

    with open(args.file, "r+b") as f:
        magic = struct.unpack(">I", f.read(4))[0]
        if magic != 0x7F454C46:
            print("Error: Not an ELF file")
            sys.exit(1)

        f.seek(36)
        flags = struct.unpack(">I", f.read(4))[0]
        if flags & 0xF0000000 == 0x20000000:  # test for mips3
            # patch it
            flags |= 0x00000100  # set EF_MIPS_32BITMODE
            f.seek(36)
            f.write(struct.pack(">I", flags))
