#! /usr/bin/python3

from sys import argv, stderr
from math import floor, ceil
from itertools import zip_longest
import png

def unpack_color(s):
    r = (s >> 11) & 0x1F
    g = (s >>  6) & 0x1F
    b = (s >>  1) & 0x1F
    a = (s &   1) * 0xFF

    r = ceil(0xFF * (r / 31))
    g = ceil(0xFF * (g / 31))
    b = ceil(0xFF * (b / 31))

    return r, g, b, a

def pack_color(r, g, b, a):
    r = floor(31 * (r / 255))
    g = floor(31 * (g / 255))
    b = floor(31 * (b / 255))

    s = round(a / 0xFF)
    s |= (r & 0x1F) << 11
    s |= (g & 0x1F) << 6
    s |= (b & 0x1F) << 1

    return s

def rgb_to_intensity(r, g, b):
    return round(r * 0.2126 + g * 0.7152 + 0.0722 * b)

def iter_in_groups(iterable, n, fillvalue=None):
    args = [iter(iterable)] * n
    return zip_longest(*args, fillvalue=fillvalue)



def reversed_if(iterator, cond):
    if cond:
        return reversed(list(iterator))
    else:
        return iterator

class Converter():
    def __init__(self, mode, infile, outfile, *argv):
        self.mode = mode
        self.infile = infile
        self.outfile = outfile
        self.flip_y = "--flip-y" in argv

        self.warned = False

    def warn(self, msg):
        if not self.warned:
            self.warned = True
            print(self.infile + ": warning: " + msg, file=stderr)

    def convert(self):
        img = png.Reader(self.infile)

        if self.mode == "rgba32":
            with open(self.outfile, "wb") as f:
                for row in reversed_if(img.asRGBA()[2], self.flip_y):
                    f.write(row)
        elif self.mode == "rgba16":
            with open(self.outfile, "wb") as f:
                for row in reversed_if(img.asRGBA()[2], self.flip_y):
                    for rgba in iter_in_groups(row, 4):
                        if rgba[3] not in (0, 0xFF):
                            self.warn("alpha mask mode but translucent pixels used")

                        color = pack_color(*rgba)
                        f.write(color.to_bytes(2, byteorder="big"))
        elif self.mode == "ci8":
            with open(self.outfile, "wb") as f:
                for row in reversed_if(img.read()[2], self.flip_y):
                    f.write(row)
        elif self.mode == "ci4":
            with open(self.outfile, "wb") as f:
                for row in reversed_if(img.read()[2], self.flip_y):
                    for a, b in iter_in_groups(row, 2):
                        byte = (a << 4) | b
                        byte = byte & 0xFF
                        f.write(byte.to_bytes(1, byteorder="big"))
        elif self.mode == "palette":
            img.preamble(True)
            palette = img.palette(alpha="force")

            with open(self.outfile, "wb") as f:
                for rgba in palette:
                    if rgba[3] not in (0, 0xFF):
                        self.warn("alpha mask mode but translucent pixels used")

                    color = pack_color(*rgba)
                    f.write(color.to_bytes(2, byteorder="big"))
        elif self.mode == "ia4":
            with open(self.outfile, "wb") as f:
                for row in reversed_if(img.asRGBA()[2], self.flip_y):
                    for c1, c2 in iter_in_groups(iter_in_groups(row, 4), 2):
                        i1 = rgb_to_intensity(*c1[:3])
                        a1 = c1[3]

                        i2 = rgb_to_intensity(*c2[:3])
                        a2 = c2[3]

                        i1 = floor(7 * (i1 / 0xFF))
                        i2 = floor(7 * (i2 / 0xFF))

                        if a1 not in (0, 0xFF) or a2 not in (0, 0xFF):
                            self.warn("alpha mask mode but translucent pixels used")
                        if c1[0] != c1[1] != c1[2]:
                            self.warn("grayscale mode but image is not")
                        if c2[0] != c2[1] != c2[2]:
                            self.warn("grayscale mode but image is not")

                        a1 = 1 if a1 > 128 else 0
                        a2 = 1 if a2 > 128 else 0

                        h = (i1 << 1) | a1
                        l = (i2 << 1) | a2

                        byte = (h << 4) | l
                        f.write(byte.to_bytes(1, byteorder="big"))
        elif self.mode == "ia8":
            with open(self.outfile, "wb") as f:
                for row in reversed_if(img.asRGBA()[2], self.flip_y):
                    for rgba in iter_in_groups(row, 4):
                        i = rgb_to_intensity(*rgba[:3])
                        a = rgba[3]

                        i = floor(15 * (i / 0xFF))
                        a = floor(15 * (a / 0xFF))

                        if rgba[0] != rgba[1] != rgba[2]:
                            self.warn("grayscale mode but image is not")

                        byte = (i << 4) | a
                        f.write(byte.to_bytes(1, byteorder="big"))
        elif self.mode == "ia16":
            with open(self.outfile, "wb") as f:
                for row in reversed_if(img.asRGBA()[2], self.flip_y):
                    for rgba in iter_in_groups(row, 4):
                        i = rgb_to_intensity(*rgba[:3])
                        a = rgba[3]

                        if rgba[0] != rgba[1] != rgba[2]:
                            self.warn("grayscale mode but image is not")

                        f.write(bytes((i, a)))
        elif self.mode == "i4":
            with open(self.outfile, "wb") as f:
                for row in reversed_if(img.asRGBA()[2], self.flip_y):
                    for c1, c2 in iter_in_groups(iter_in_groups(row, 4), 2):
                        if c1[3] != 0xFF or c2[3] != 0xFF:
                            self.warn("discarding alpha channel")

                        i1 = rgb_to_intensity(*c1[:3])
                        i2 = rgb_to_intensity(*c2[:3])

                        i1 = floor(15 * (i1 / 0xFF))
                        i2 = floor(15 * (i2 / 0xFF))

                        if c1[0] != c1[1] != c1[2]:
                            self.warn("grayscale mode but image is not")
                        if c2[0] != c2[1] != c2[2]:
                            self.warn("grayscale mode but image is not")

                        byte = (i1 << 4) | i2
                        f.write(byte.to_bytes(1, byteorder="big"))
        elif self.mode == "i8":
            with open(self.outfile, "wb") as f:
                for row in reversed_if(img.asRGBA()[2], self.flip_y):
                    for rgba in iter_in_groups(row, 4):
                        if rgba[3] != 0xFF or rgba[3] != 0xFF:
                            self.warn("discarding alpha channel")
                        if rgba[0] != rgba[1] != rgba[2]:
                            self.warn("grayscale mode but image is not")

                        i = rgb_to_intensity(*rgba[:3])
                        f.write(i.to_bytes(1, byteorder="big"))
        else:
            print("unsupported mode", file=stderr)
            exit(1)


if __name__ == "__main__":
    if len(argv) < 4:
        print("usage: build.py MODE INFILE OUTFILE [--flip-y]")
        exit(1)

    Converter(*argv[1:]).convert()
