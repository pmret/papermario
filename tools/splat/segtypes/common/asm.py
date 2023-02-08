from pathlib import Path
from typing import Optional

from util import options

from segtypes.common.codesubsegment import CommonSegCodeSubsegment


class CommonSegAsm(CommonSegCodeSubsegment):
    @staticmethod
    def is_text() -> bool:
        return True

    def out_path(self) -> Optional[Path]:
        return options.opts.asm_path / self.dir / f"{self.name}.s"

    def scan(self, rom_bytes: bytes):
        if (
            self.rom_start is not None
            and self.rom_end is not None
            and self.rom_start != self.rom_end
        ):
            self.scan_code(rom_bytes)

    def get_file_header(self):
        return []

    def split(self, rom_bytes: bytes):
        if not self.rom_start == self.rom_end and self.spim_section is not None:
            out_path = self.out_path()
            if out_path:
                out_path.parent.mkdir(parents=True, exist_ok=True)

                self.print_file_boundaries()

                with open(out_path, "w", newline="\n") as f:
                    for line in self.get_file_header():
                        f.write(line + "\n")
                    f.write(self.spim_section.disassemble())
