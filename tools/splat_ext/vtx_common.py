from splat.segtypes.n64.vtx import N64SegVtx


class N64SegVtx_common(N64SegVtx):
    def format_sym_name(self, sym):
        return f"N({sym.name[7:]})"
