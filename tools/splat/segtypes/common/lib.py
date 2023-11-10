from pathlib import Path
from typing import Optional

from util import log, options

from segtypes.linker_entry import LinkerEntry
from segtypes.n64.segment import N64Segment


class CommonSegLib(N64Segment):
    def __init__(
        self,
        rom_start: Optional[int],
        rom_end: Optional[int],
        type: str,
        name: str,
        vram_start: Optional[int],
        args: list,
        yaml,
    ):
        super().__init__(
            rom_start,
            rom_end,
            type,
            name,
            vram_start,
            args=args,
            yaml=yaml,
        )

        if isinstance(yaml, dict):
            log.error("Error: 'dict' not currently supported for 'lib' segment")
            return
        if len(args) < 1:
            log.error(f"Error: {self.name} is missing object file")
            return

        self.extract = False

        if len(args) > 1:
            self.object, self.section = args[0], args[1]
        else:
            self.object, self.section = args[0], ".text"

    def get_linker_section(self) -> str:
        return self.section

    def get_linker_entries(self):
        path = options.opts.lib_path / self.name

        object_path = Path(f"{path}.a:{self.object}.o")

        return [
            LinkerEntry(
                self,
                [path],
                object_path,
                self.get_linker_section_order(),
                self.get_linker_section_linksection(),
                self.is_noload(),
            )
        ]
