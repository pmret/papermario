from segtypes.ia4 import N64SegIa4

class N64SegIa8(N64SegIa4):
    def parse_image(self, data):
        return data

    def max_length(self):
        if self.compressed: return None
        return self.width * self.height * 2
