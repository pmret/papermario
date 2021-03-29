from segtypes.n64.ia4 import N64SegIa4
from segtypes.n64.rgba16 import N64SegRgba16
from math import ceil

class N64SegIa8(N64SegIa4):
    @staticmethod
    def parse_image(data, width, height, flip_h=False, flip_v=False):
        img = bytearray()

        for x, y, i in N64SegRgba16.iter_image_indexes(width, height, flip_h=flip_h, flip_v=flip_v):
            b = data[i]

            i = (b >> 4) & 0xF
            a = b & 0xF

            i = ceil(0xFF * (i / 15))
            a = ceil(0xFF * (a / 15))

            img += bytes((i, a))

        return img

    def max_length(self):
        return self.width * self.height
