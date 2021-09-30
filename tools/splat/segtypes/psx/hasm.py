from segtypes.psx.asm import PsxSegAsm


class PsxSegHasm(PsxSegAsm):
    def split_write(self, out_path, out_lines):
        if not out_path.exists():
            with open(out_path, "w", newline="\n") as f:
                f.write("\n".join(out_lines))
