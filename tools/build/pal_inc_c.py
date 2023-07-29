#!/usr/bin/env python3

from sys import argv
import struct

if __name__ == "__main__":
    infile, outfile, cname = argv[1:]

    with open(outfile, "w") as f:
        f.write(f"unsigned short {cname}[] = {{ ")

        with open(infile, "rb") as i:
            while short := i.read(2):
                color = struct.unpack(">H", short)[0]
                f.write(f"0x{color:04X}, ")

        f.write("};\n")
