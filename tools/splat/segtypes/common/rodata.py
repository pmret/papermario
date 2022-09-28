import spimdisasm

from segtypes.common.data import CommonSegData
from util import symbols, options


class CommonSegRodata(CommonSegData):
    def get_linker_section(self) -> str:
        return ".rodata"

    def disassemble_data(self, rom_bytes):
        assert isinstance(self.rom_start, int)
        assert isinstance(self.rom_end, int)

        segment_rom_start = self.get_most_parent().rom_start
        assert isinstance(segment_rom_start, int)

        self.spim_section = spimdisasm.mips.sections.SectionRodata(
            symbols.spim_context,
            self.rom_start,
            self.rom_end,
            self.vram_start,
            self.name,
            rom_bytes,
            segment_rom_start,
            self.get_exclusive_ram_id(),
        )

        self.spim_section.analyze()
        self.spim_section.setCommentOffset(self.rom_start)

        for symbol in self.spim_section.symbolList:
            symbols.create_symbol_from_spim_symbol(
                self.get_most_parent(), symbol.contextSym
            )

    def split(self, rom_bytes: bytes):
        # Disassemble the file itself
        super().split(rom_bytes)

        if options.opts.migrate_rodata_to_functions:
            if self.spim_section and (
                not self.type.startswith(".") or self.partial_migration
            ):
                path_folder = options.opts.data_path / self.dir
                path_folder.parent.mkdir(parents=True, exist_ok=True)

                for rodataSym in self.spim_section.symbolList:
                    if not rodataSym.isRdata():
                        continue

                    path = path_folder / f"{rodataSym.getName()}.s"
                    with open(path, "w", newline="\n") as f:
                        f.write('.include "macro.inc"\n\n')
                        f.write(".section .rodata\n\n")
                        f.write(rodataSym.disassemble())
