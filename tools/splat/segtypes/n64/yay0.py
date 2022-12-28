from util.n64.Yay0decompress import Yay0Decompressor

from segtypes.common.decompressor import CommonSegDecompressor


class N64SegYay0(CommonSegDecompressor):
    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs)
        self.decompressor = Yay0Decompressor()
        self.compression_type = "Yay0"
