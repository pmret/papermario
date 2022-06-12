from segtypes.common.codesubsegment import CommonSegCodeSubsegment
from typing import Optional
from pathlib import Path

from util import options


class CommonSegAsm(CommonSegCodeSubsegment):
    def out_path(self) -> Optional[Path]:
        return options.get_asm_path() / self.dir / f"{self.name}.s"

    def scan(self, rom_bytes: bytes):
        if (
            self.rom_start != "auto"
            and self.rom_end != "auto"
            and self.rom_start != self.rom_end
        ):
            self.scan_code(rom_bytes, is_asm=True)

    def get_file_header(self):
        return []

    def split(self, rom_bytes: bytes):
        if not self.rom_start == self.rom_end:
            out_path = self.out_path()
            if out_path:
                out_path.parent.mkdir(parents=True, exist_ok=True)

                self.print_file_boundaries()

                with open(out_path, "w", newline="\n") as f:
                    for line in self.get_file_header():
                        f.write(line + "\n")
                    f.write(self.text_section.disassemble())
