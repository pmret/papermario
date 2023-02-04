import spimdisasm
from util import options, symbols, log

from segtypes.common.data import CommonSegData


class CommonSegBss(CommonSegData):
    def get_linker_section(self) -> str:
        return ".bss"

    @staticmethod
    def is_noload() -> bool:
        return True

    def disassemble_data(self, rom_bytes: bytes):
        if not isinstance(self.rom_start, int):
            log.error(
                f"Segment '{self.name}' (type '{self.type}') requires a rom_start. Got '{self.rom_start}'"
            )

        # Supposedly logic error, not user error
        assert isinstance(self.rom_end, int), f"{self.name} {self.rom_end}"

        # Supposedly logic error, not user error
        segment_rom_start = self.get_most_parent().rom_start
        assert isinstance(segment_rom_start, int), f"{self.name} {segment_rom_start}"

        if not isinstance(self.vram_start, int):
            log.error(
                f"Segment '{self.name}' (type '{self.type}') requires a vram address. Got '{self.vram_start}'"
            )

        next_subsegment = self.parent.get_next_subsegment_for_ram(self.vram_start)
        if next_subsegment is None:
            bss_end = self.get_most_parent().vram_end
        else:
            bss_end = next_subsegment.vram_start
        assert isinstance(bss_end, int), f"{self.name} {bss_end}"

        self.spim_section = spimdisasm.mips.sections.SectionBss(
            symbols.spim_context,
            self.rom_start,
            self.rom_end,
            self.vram_start,
            bss_end,
            self.name,
            segment_rom_start,
            self.get_exclusive_ram_id(),
        )

        self.spim_section.analyze()
        self.spim_section.setCommentOffset(self.rom_start)

        for spim_sym in self.spim_section.symbolList:
            symbols.create_symbol_from_spim_symbol(
                self.get_most_parent(), spim_sym.contextSym
            )

    def should_scan(self) -> bool:
        return options.opts.is_mode_active("code") and self.vram_start is not None
