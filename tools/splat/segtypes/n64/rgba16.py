from segtypes.n64.img import N64SegImg
import png
from util import iter
from util import log
from util import options
from util.color import unpack_color

# TODO: move common behaviour to N64ImgSegment and have all image segments extend that instead
class N64SegRgba16(N64SegImg):
    def __init__(self, segment, rom_start, rom_end):
        super().__init__(segment, rom_start, rom_end)

        if type(segment) is dict:
            self.width = segment["width"]
            self.height = segment["height"]
            self.flip = segment.get("flip", "noflip")
        elif len(segment) < 5:
            log.error("missing parameters")
        else:
            self.width = segment[3]
            self.height = segment[4]
            self.flip = "noflip"

        if self.max_length():
            expected_len = int(self.max_length())
            actual_len = self.rom_end - self.rom_start
            if actual_len > expected_len and actual_len - expected_len > self.subalign:
                log.error(f"Error: {self.name} should end at 0x{self.rom_start + expected_len:X}, but it ends at 0x{self.rom_end:X}\n(hint: add a 'bin' segment after it)")

    @property
    def flip_vertical(self):
        return self.flip == "both" or self.flip.startswith("v") or self.flip == "y"

    @property
    def flip_horizontal(self):
        return self.flip == "both" or self.flip.startswith("h") or self.flip == "x"

    def should_split(self):
        return super().should_split() or options.mode_active("img")

    def split(self, rom_bytes):
        path = self.out_path()
        path.parent.mkdir(parents=True, exist_ok=True)

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
