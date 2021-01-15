from segtypes.rgba16 import N64SegRgba16

class N64SegRgba32(N64SegRgba16):
    def parse_image(self, data):
        return data

    def max_length(self):
        if self.compressed: return None
        return self.width * self.height * 4
