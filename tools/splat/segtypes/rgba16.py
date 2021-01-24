import os
from segtypes.segment import N64Segment
from pathlib import Path
from util import Yay0decompress
import png
from math import ceil
from util.color import unpack_color


class N64SegRgba16(N64Segment):
    def __init__(self, segment, next_segment, options):
        super().__init__(segment, next_segment, options)

        if type(segment) is dict:
            self.compressed = segment.get("compressed", False)
            self.width = segment["width"]
            self.height = segment["height"]
            self.flip = segment.get("flip", "noflip")
        elif len(segment) < 5:
            self.error("missing parameters")
        else:
            self.compressed = False
            self.width = segment[3]
            self.height = segment[4]
            self.flip = "noflip"

    @property
    def flip_vertical(self):
        return self.flip == "both" or self.flip.startswith("v") or self.flip == "y"

    @property
    def flip_horizontal(self):
        return self.flip == "both" or self.flip.startswith("h") or self.flip == "x"

    def iter_image_indexes(self, bytes_per_x=1, bytes_per_y=1):
        w = int(self.width * bytes_per_x)
        h = int(self.height * bytes_per_y)

        xrange = range(w - ceil(bytes_per_x), -1, -ceil(bytes_per_x)
                       ) if self.flip_horizontal else range(0, w, ceil(bytes_per_x))
        yrange = range(h - ceil(bytes_per_y), -1, -ceil(bytes_per_y)
                       ) if self.flip_vertical else range(0, h, ceil(bytes_per_y))

        for y in yrange:
            for x in xrange:
                yield x, y, (y * w) + x

    def should_run(self):
        return super().should_run() or "img" in self.options["modes"]

    def split(self, rom_bytes, base_path):
        out_dir = self.create_parent_dir(base_path + "/img", self.name)
        path = os.path.join(out_dir, os.path.basename(self.name) + ".png")

        data = rom_bytes[self.rom_start: self.rom_end]
        if self.compressed:
            data = Yay0decompress.decompress_yay0(data)

        w = self.png_writer()
        with open(path, "wb") as f:
            w.write_array(f, self.parse_image(data))

        self.log(f"Wrote {self.name} to {path}")

    def png_writer(self):
        return png.Writer(self.width, self.height, greyscale=False, alpha=True)

    def parse_image(self, data):
        img = bytearray()

        for x, y, i in self.iter_image_indexes(2, 1):
            img += bytes(unpack_color(data[i:]))

        return img

    def max_length(self):
        if self.compressed:
            return None
        return self.width * self.height * 2

    def get_ld_files(self):
        ext = f".{self.type}.png"
        if self.compressed:
            ext += ".Yay0"

        return [("img", f"{self.name}{ext}", ".data", self.rom_start)]
