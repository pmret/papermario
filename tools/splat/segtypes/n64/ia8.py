from segtypes.n64.ia4 import N64SegIa4
from math import ceil

class N64SegIa8(N64SegIa4):
    def parse_image(self, data):
        img = bytearray()

        for x, y, i in self.iter_image_indexes():
            b = data[i]

            i = (b >> 4) & 0xF
            a = b & 0xF

            i = ceil(0xFF * (i / 15))
            a = ceil(0xFF * (a / 15))

            img += bytes((i, a))

        return img

    def max_length(self):
        return self.width * self.height
