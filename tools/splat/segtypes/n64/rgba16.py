import os
from segtypes.n64.segment import N64Segment
import png
from util import iter
from util import options
from util.color import unpack_color
import sys

class N64SegRgba16(N64Segment):
    def __init__(self, segment, next_segment):
        super().__init__(segment, next_segment)

        if type(segment) is dict:
            self.width = segment["width"]
            self.height = segment["height"]
            self.flip = segment.get("flip", "noflip")
        elif len(segment) < 5:
            self.error("missing parameters")
        else:
            self.width = segment[3]
            self.height = segment[4]
            self.flip = "noflip"

        if self.max_length():
            expected_len = int(self.max_length())
            actual_len = self.rom_end - self.rom_start
            if actual_len > expected_len and actual_len - expected_len > self.subalign:
                print(f"Error: {self.name} should end at 0x{self.rom_start + expected_len:X}, but it ends at 0x{self.rom_end:X}\n(hint: add a 'bin' segment after it)")
                sys.exit(1)

    @property
    def flip_vertical(self):
        return self.flip == "both" or self.flip.startswith("v") or self.flip == "y"

    @property
    def flip_horizontal(self):
        return self.flip == "both" or self.flip.startswith("h") or self.flip == "x"

    def should_run(self):
        return super().should_run() or options.mode_active("img")

    def split(self, rom_bytes, base_path):
        out_dir = self.create_parent_dir(base_path + "/" + options.get("assets_dir", "img"), self.name)
        path = os.path.join(out_dir, os.path.basename(self.name) + ".png")

        data = rom_bytes[self.rom_start: self.rom_end]

        w = self.__class__.get_writer(self.width, self.height)
        with open(path, "wb") as f:
            w.write_array(f, self.parse_image(data, self.width, self.height, self.flip_horizontal, self.flip_vertical))

        self.log(f"Wrote {self.name} to {path}")

    @staticmethod
    def get_writer(width, height):
        return png.Writer(width, height, greyscale=False, alpha=True)

    @staticmethod
    def parse_image(data, width, height, flip_h=False, flip_v=False):
        img = bytearray()

        for x, y, i in iter.iter_image_indexes(width, height, 2, 1, flip_h, flip_v):
            img += bytes(unpack_color(data[i:]))

        return img

    def max_length(self):
        return self.width * self.height * 2

    def get_ld_files(self):
        ext = f".{self.type}.png"

        return [(options.get("assets_dir", "img"), f"{self.name}{ext}", ".data", self.rom_start)]
