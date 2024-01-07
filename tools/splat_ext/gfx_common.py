from splat.segtypes.n64.gfx import N64SegGfx


class N64SegGfx_common(N64SegGfx):
    def format_sym_name(self, sym):
        return f"N({sym.name[7:]})"
