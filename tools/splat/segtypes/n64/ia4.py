from segtypes.n64.rgba16 import N64SegRgba16
import png
from math import ceil
from util import iter

class N64SegIa4(N64SegRgba16):
    @staticmethod
    def get_writer(width, height):
        return png.Writer(width, height, greyscale=True, alpha=True)

    @staticmethod
    def parse_image(data, width, height, flip_h=False, flip_v=False):
        img = bytearray()

        for x, y, i in iter.iter_image_indexes(width, height, 0.5, 1, flip_h, flip_v):
            b = data[i]

            h = (b >> 4) & 0xF
            l = b & 0xF

            i1 = (h >> 1) & 0xF
            a1 = (h & 1) * 0xFF
            i1 = ceil(0xFF * (i1 / 7))

            i2 = (l >> 1) & 0xF
            a2 = (l & 1) * 0xFF
            i2 = ceil(0xFF * (i2 / 7))

            img += bytes((i1, a1, i2, a2))

        return img

    def max_length(self):
        return self.width * self.height // 2
