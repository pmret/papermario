from segtypes.common.asm import CommonSegAsm


class CommonSegHasm(CommonSegAsm):
    def split(self, rom_bytes: bytes):
        if not self.rom_start == self.rom_end:
            out_path = self.out_path()
            if out_path and not out_path.exists():
                out_path.parent.mkdir(parents=True, exist_ok=True)

                self.print_file_boundaries()

                with open(out_path, "w", newline="\n") as f:
                    for line in self.get_file_header():
                        f.write(line + "\n")
                    f.write(self.text_section.disassemble())
