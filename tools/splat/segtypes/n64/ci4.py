from segtypes.n64.ci8 import N64SegCi8

class N64SegCi4(N64SegCi8):
    def parse_image(self, data):
        img_data = bytearray()

        for i in range(self.width * self.height // 2):
            img_data.append(data[i] >> 4)
            img_data.append(data[i] & 0xF)

        return img_data

    def max_length(self):
        if self.compressed: return None
        return self.width * self.height // 2
