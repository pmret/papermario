from segtypes.n64.ia4 import N64SegIa4

class N64SegIa8(N64SegIa4):
    def parse_image(self, data):
        return data

    def max_length(self):
        return self.width * self.height * 2
