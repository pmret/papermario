#!/usr/bin/env python3

from sys import argv, stderr
from math import floor, ceil
from glob import glob
import png  # type: ignore


def unpack_color(s):
    r = (s >> 11) & 0x1F
    g = (s >> 6) & 0x1F
    b = (s >> 1) & 0x1F
    a = (s & 1) * 0xFF

    r = ceil(0xFF * (r / 31))
    g = ceil(0xFF * (g / 31))
    b = ceil(0xFF * (b / 31))

    return r, g, b, a


def pack_color(r, g, b, a):
    r = r >> 3
    g = g >> 3
    b = b >> 3
    a = a >> 7

    return (r << 11) | (g << 6) | (b << 1) | a


def rgb_to_intensity(r, g, b):
    return round(r * 0.2126 + g * 0.7152 + 0.0722 * b)


def iter_in_groups(iterable, n, fillvalue=None):
    from itertools import zip_longest

    args = [iter(iterable)] * n
    return zip_longest(*args, fillvalue=fillvalue)


def reversed_if(iterator, cond):
    if cond:
        return reversed(list(iterator))
    else:
        return iterator


class Converter:
    def __init__(self, mode, infile, flip_x: bool = False, flip_y: bool = False):
        self.mode = mode
        self.infile = infile
        self.flip_x = flip_x
        self.flip_y = flip_y

        assert self.flip_x == False, "flip_x is not supported"

        self.warned = False

    def warn(self, msg):
        if not self.warned:
            self.warned = True
            print(self.infile + ": warning: " + msg, file=stderr)

    def convert(self):
        out_bytes = bytearray()
        out_width = 0
        out_height = 0
        img = png.Reader(self.infile)

        if self.mode == "rgba32":
            (out_width, out_height, data, info) = img.asRGBA()
            for row in reversed_if(data, self.flip_y):
                out_bytes += row
        elif self.mode == "rgba16":
            (out_width, out_height, data, info) = img.asRGBA()
            for row in reversed_if(data, self.flip_y):
                for rgba in iter_in_groups(row, 4):
                    if rgba[3] not in (0, 0xFF):
                        self.warn("alpha mask mode but translucent pixels used")

                    color = pack_color(*rgba)
                    out_bytes += color.to_bytes(2, byteorder="big")
        elif self.mode == "ci8":
            (out_width, out_height, data, info) = img.read()
            for row in reversed_if(data, self.flip_y):
                out_bytes += row
        elif self.mode == "ci4":
            (out_width, out_height, data, info) = img.read()
            for row in reversed_if(data, self.flip_y):
                for a, b in iter_in_groups(row, 2):
                    byte = (a << 4) | b
                    byte = byte & 0xFF
                    out_bytes += byte.to_bytes(1, byteorder="big")
        elif self.mode == "palette":
            img.preamble(True)
            palette = img.palette(alpha="force")

            for rgba in palette:
                if rgba[3] not in (0, 0xFF):
                    self.warn("alpha mask mode but translucent pixels used")

                color = pack_color(*rgba)
                out_bytes += color.to_bytes(2, byteorder="big")
        elif self.mode == "ia4":
            (out_width, out_height, data, info) = img.asRGBA()
            for row in reversed_if(data, self.flip_y):
                for c1, c2 in iter_in_groups(iter_in_groups(row, 4), 2):
                    i1 = rgb_to_intensity(*c1[:3])
                    a1 = c1[3]

                    i2 = rgb_to_intensity(*c2[:3])
                    a2 = c2[3]

                    i1 = i1 >> 5
                    i2 = i2 >> 5

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
                    out_bytes += byte.to_bytes(1, byteorder="big")
        elif self.mode == "ia8":
            (out_width, out_height, data, info) = img.asRGBA()
            for row in reversed_if(data, self.flip_y):
                for rgba in iter_in_groups(row, 4):
                    i = rgb_to_intensity(*rgba[:3])
                    a = rgba[3]

                    i = floor(15 * (i / 0xFF))
                    a = floor(15 * (a / 0xFF))

                    if rgba[0] != rgba[1] != rgba[2]:
                        self.warn("grayscale mode but image is not")

                    byte = (i << 4) | a
                    out_bytes += byte.to_bytes(1, byteorder="big")
        elif self.mode == "ia16":
            (out_width, out_height, data, info) = img.asRGBA()
            for row in reversed_if(data, self.flip_y):
                for rgba in iter_in_groups(row, 4):
                    i = rgb_to_intensity(*rgba[:3])
                    a = rgba[3]

                    if rgba[0] != rgba[1] != rgba[2]:
                        self.warn("grayscale mode but image is not")

                    out_bytes += bytes((i, a))
        elif self.mode == "i4":
            (out_width, out_height, data, info) = img.asRGBA()
            for row in reversed_if(data, self.flip_y):
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
                    out_bytes += byte.to_bytes(1, byteorder="big")
        elif self.mode == "i8":
            (out_width, out_height, data, info) = img.asRGBA()
            for row in reversed_if(data, self.flip_y):
                for rgba in iter_in_groups(row, 4):
                    if rgba[3] != 0xFF or rgba[3] != 0xFF:
                        self.warn("discarding alpha channel")
                    if rgba[0] != rgba[1] != rgba[2]:
                        self.warn("grayscale mode but image is not")

                    i = rgb_to_intensity(*rgba[:3])
                    out_bytes += i.to_bytes(1, byteorder="big")
        elif self.mode == "party":
            (out_width, out_height, data, info) = img.read()
            img.preamble(True)
            palette = img.palette(alpha="force")

            # palette
            for rgba in palette:
                if rgba[3] not in (0, 0xFF):
                    self.warn("alpha mask mode but translucent pixels used")

                color = pack_color(*rgba)
                out_bytes += color.to_bytes(2, byteorder="big")

            # ci 8
            for row in reversed_if(data, self.flip_y):
                out_bytes += row

            out_bytes += b"\0\0\0\0\0\0\0\0\0\0"  # padding
        elif self.mode == "bg":
            (out_width, out_height, data, info) = img.read()
            img.preamble(True)
            palettes = [img.palette(alpha="force")]

            for palettepath in glob(self.infile.split(".")[0] + ".*.png"):
                pal = png.Reader(palettepath)
                pal.preamble(True)
                palettes.append(pal.palette(alpha="force"))

            baseaddr = 0x80200000  # gBackgroundImage
            headers_len = 0x10 * len(palettes)
            palettes_len = 0x200 * len(palettes)

            # header (struct BackgroundHeader)
            for i, palette in enumerate(palettes):
                out_bytes += (baseaddr + palettes_len + headers_len).to_bytes(4, byteorder="big")  # raster offset
                out_bytes += (baseaddr + headers_len + 0x200 * i).to_bytes(4, byteorder="big")  # palette offset
                out_bytes += (12).to_bytes(2, byteorder="big")  # startX
                out_bytes += (20).to_bytes(2, byteorder="big")  # startY
                out_bytes += (out_width).to_bytes(2, byteorder="big")  # width
                out_bytes += (out_height).to_bytes(2, byteorder="big")  # height

            for palette in palettes:
                # palette
                for rgba in palette:
                    if rgba[3] not in (0, 0xFF):
                        self.warn("alpha mask mode but translucent pixels used")

                    color = pack_color(*rgba)
                    out_bytes += color.to_bytes(2, byteorder="big")

            # ci 8
            for row in reversed_if(data, self.flip_y):
                out_bytes += row
        else:
            print("unsupported mode", file=stderr)
            exit(1)

        return (out_bytes, out_width, out_height)


if __name__ == "__main__":
    if len(argv) < 4:
        print("usage: build.py MODE INFILE OUTFILE [--flip-x] [--flip-y]")
        exit(1)

    mode = argv[1]
    infile = argv[2]
    outfile = argv[3]

    flip_x = "--flip-x" in argv
    flip_y = "--flip-y" in argv

    (out_bytes, out_width, out_height) = Converter(mode, infile, flip_x, flip_y).convert()
    with open(argv[3], "wb") as f:
        f.write(out_bytes)
