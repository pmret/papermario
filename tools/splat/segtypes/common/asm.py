from segtypes.common.codesubsegment import CommonSegCodeSubsegment
from typing import Optional
from pathlib import Path

from util import options


class CommonSegAsm(CommonSegCodeSubsegment):
    def out_path(self) -> Optional[Path]:
        return options.get_asm_path() / self.dir / f"{self.name}.s"

    def scan(self, rom_bytes: bytes):
        if self.rom_start != "auto" and self.rom_end != "auto" and self.rom_start != self.rom_end:
            self.funcs_text = self.disassemble_code(rom_bytes, options.get("asm_endlabels", False))

    def get_file_header(self):
        return []

    def split(self, rom_bytes: bytes):
        if not self.rom_start == self.rom_end:
            out_path = self.out_path()
            if out_path:
                out_path.parent.mkdir(parents=True, exist_ok=True)

                out_lines = self.get_file_header()
                for func in self.funcs_text:
                    out_lines.extend(self.funcs_text[func][0])
                    out_lines.append("")

                self.split_write(out_path, out_lines)

    def split_write(self, out_path, out_lines):
        with open(out_path, "w", newline="\n") as f:
            f.write("\n".join(out_lines))
