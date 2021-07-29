from segtypes.n64.rgba16 import N64SegRgba16
import png
from math import ceil
from util import iter

class N64SegI4(N64SegRgba16):
    @staticmethod
    def get_writer(width, height):
        return png.Writer(width, height, greyscale=True)

    @staticmethod
    def parse_image(data, width, height, flip_h=False, flip_v=False):
        img = bytearray()

        for x, y, i in iter.iter_image_indexes(width, height, 0.5, 1, flip_h, flip_v):
            b = data[i]

            i1 = (b >> 4) & 0xF
            i2 = b & 0xF

            i1 = ceil(0xFF * (i1 / 15))
            i2 = ceil(0xFF * (i2 / 15))

            img += bytes((i1, i2))

        return img

    def max_length(self):
        return self.width * self.height // 2
