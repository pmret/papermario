from segtypes.rgba16 import N64SegRgba16
import png
from math import ceil

class N64SegI4(N64SegRgba16):
    def png_writer(self):
        return png.Writer(self.width, self.height, greyscale = True)

    def parse_image(self, data):
        img = bytearray()

        for x, y, i in self.iter_image_indexes(0.5, 1):
            b = data[i]

            i1 = (b >> 4) & 0xF
            i2 = b & 0xF

            i1 = ceil(0xFF * (i1 / 15))
            i2 = ceil(0xFF * (i2 / 15))

            img += bytes((i1, i2))

        return img

    def max_length(self):
        if self.compressed: return None
        return self.width * self.height // 2
