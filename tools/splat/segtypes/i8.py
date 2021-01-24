from segtypes.i4 import N64SegI4
from math import ceil

class N64SegI8(N64SegI4):
    def parse_image(self, data):
        return data

    def max_length(self):
        if self.compressed: return None
        return self.width * self.height
