from segtypes.n64.rgba16 import N64SegRgba16

class N64SegRgba32(N64SegRgba16):
    @staticmethod
    def parse_image(data, width, height, flip_h=False, flip_v=False):
        return data

    def max_length(self):
        return self.width * self.height * 4
