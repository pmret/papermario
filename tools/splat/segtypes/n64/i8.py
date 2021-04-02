from segtypes.n64.i4 import N64SegI4

class N64SegI8(N64SegI4):
    @staticmethod
    def parse_image(data, width, height, flip_h=False, flip_v=False):
        return data

    def max_length(self):
        return self.width * self.height
