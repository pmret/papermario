from pathlib import Path
from typing import Optional

from util import log, options

from segtypes.common.textbin import CommonSegTextbin


class CommonSegDatabin(CommonSegTextbin):
    @staticmethod
    def is_text() -> bool:
        return False

    @staticmethod
    def is_data() -> bool:
        return True

    def get_linker_section(self) -> str:
        return ".data"

    def get_section_flags(self) -> Optional[str]:
        return "wa"

    def split(self, rom_bytes):
        if self.rom_end is None:
            log.error(
                f"segment {self.name} needs to know where it ends; add a position marker [0xDEADBEEF] after it"
            )

        self.write_bin(rom_bytes)

        if self.sibling is None:
            # textbin will write the incbin instead

            s_path = self.out_path()
            assert s_path is not None
            s_path.parent.mkdir(parents=True, exist_ok=True)

            with s_path.open("w") as f:
                f.write('.include "macro.inc"\n\n')
                preamble = options.opts.generated_s_preamble
                if preamble:
                    f.write(preamble + "\n")

                self.write_asm_contents(rom_bytes, f)
