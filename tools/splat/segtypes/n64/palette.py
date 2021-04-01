import os
import sys

from segtypes.n64.segment import N64Segment
from util import options
from util.color import unpack_color
from util.iter import iter_in_groups


class N64SegPalette(N64Segment):
    require_unique_name = False

    def __init__(self, segment, next_segment):
        super().__init__(segment, next_segment)

        # palette segments must be named as one of the following:
        #  1) same as the relevant ci4/ci8 segment name (max. 1 palette)
        #  2) relevant ci4/ci8 segment name + "." + unique palette name
        #  3) unique, referencing the relevant ci4/ci8 segment using `image_name`
        self.image_name = segment.get("image_name", self.name.split(
            ".")[0]) if type(segment) is dict else self.name.split(".")[0]

        if self.max_length():
            expected_len = int(self.max_length())
            actual_len = self.rom_end - self.rom_start
            if actual_len > expected_len and actual_len - expected_len > self.subalign:
                print(f"Error: {self.name} should end at 0x{self.rom_start + expected_len:X}, but it ends at 0x{self.rom_end:X}\n(hint: add a 'bin' segment after it)")
                sys.exit(1)

    def should_run(self):
        return super().should_run() or (
            options.mode_active("img") or
            options.mode_active("ci4") or
            options.mode_active("ci8") or
            options.mode_active("i4") or
            options.mode_active("i8") or
            options.mode_active("ia4") or
            options.mode_active("ia8") or
            options.mode_active("ia16")
        )

    def split(self, rom_bytes, base_path):
        out_dir = self.create_parent_dir(base_path + "/" + options.get("assets_dir", "img"), self.name)
        self.path = os.path.join(
            out_dir, os.path.basename(self.name) + ".png")

        data = rom_bytes[self.rom_start: self.rom_end]

        self.palette = N64SegPalette.parse_palette(data)

    @staticmethod
    def parse_palette(data):
        palette = []

        for a, b in iter_in_groups(data, 2):
            palette.append(unpack_color([a, b]))

        return palette

    def max_length(self):
        return 256 * 2

    def get_ld_files(self):
        ext = f".{self.type}.png"

        return [(options.get("assets_dir", "img"), f"{self.name}{ext}", ".data", self.rom_start)]
