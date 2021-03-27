from segtypes.n64.ci8 import N64SegCi8

class N64SegCi4(N64SegCi8):
    @staticmethod
    def parse_image(data, width, height, flip_h=False, flip_v=False):
        img_data = bytearray()

        for i in range(width * height // 2):
            img_data.append(data[i] >> 4)
            img_data.append(data[i] & 0xF)

        return img_data

    def max_length(self):
        return self.width * self.height // 2
