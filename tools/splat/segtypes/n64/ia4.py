from segtypes.n64.rgba16 import N64SegRgba16
import png
from math import ceil

class N64SegIa4(N64SegRgba16):
    def png_writer(self):
        return png.Writer(self.width, self.height, greyscale = True, alpha = True)

    def parse_image(self, data):
        img = bytearray()

        for x, y, i in self.iter_image_indexes(0.5, 1):
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
        if self.compressed: return None
        return self.width * self.height // 2
