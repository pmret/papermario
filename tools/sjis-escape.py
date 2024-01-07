#!/usr/bin/env python3

import argparse
import sys


def is_sjis_2byte(c):
    return (c >= 0x81 and c <= 0x9F) or (c >= 0xE0 and c <= 0xFC)


parser = argparse.ArgumentParser(description="")
parser.add_argument("infile", nargs="?", type=argparse.FileType("rb"), default=sys.stdin.buffer)
parser.add_argument("outfile", nargs="?", type=argparse.FileType("wb"), default=sys.stdout.buffer)

args = parser.parse_args()


def main():
    for line in args.infile:
        newline = bytearray()
        i = 0
        lsize = len(line)
        while i < lsize:
            c = line[i]
            if is_sjis_2byte(c):
                i += 1
                c2 = line[i]
                newline += "\\x{:02x}\\x{:02x}".format(c, c2).encode("ascii")
            else:
                newline.append(c)
            i += 1
        args.outfile.write(newline)


if __name__ == "__main__":
    main()
