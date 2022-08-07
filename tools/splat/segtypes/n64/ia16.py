from segtypes.n64.ia4 import N64SegIa4
from util import iter


class N64SegIa16(N64SegIa4):
    @staticmethod
    def parse_image(data, width, height, flip_h=False, flip_v=False):
        img = bytearray()

        for x, y, i in iter.iter_image_indexes(width, height, 2, 1, flip_h, flip_v):
            i1 = data[i]
            a1 = data[i + 1]
            img += bytes((i1, a1))

        return img

    def max_length(self):
        return self.width * self.height * 2
