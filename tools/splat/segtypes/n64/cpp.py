from segtypes.n64.c import N64SegC
from util import options

class N64SegCpp(N64SegC):
    def out_path(self):
        return options.get_src_path() / self.dir / f"{self.name}.cpp"
