from segtypes.n64.img import N64SegImg
import png
from util import iter
from util import log
from util import options
from util.color import unpack_color

# TODO: move common behaviour to N64ImgSegment and have all image segments extend that instead
class N64SegRgba16(N64SegImg):
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
