from util.n64.Mio0decompress import Mio0Decompressor

from segtypes.common.decompressor import CommonSegDecompressor


class N64SegMio0(CommonSegDecompressor):
    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs)
        self.decompressor = Mio0Decompressor()
        self.compression_type = "Mio0"
