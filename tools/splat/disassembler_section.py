from abc import ABC, abstractmethod
from typing import Optional

import spimdisasm

from util import options, symbols


class DisassemblerSection(ABC):
    @abstractmethod
    def disassemble(self):
        raise NotImplementedError("disassemble")

    @abstractmethod
    def analyze(self):
        raise NotImplementedError("analyze")

    @abstractmethod
    def set_comment_offset(self, rom_start: int):
        raise NotImplementedError("set_comment_offset")

    @abstractmethod
    def make_bss_section(
        self,
        rom_start,
        rom_end,
        vram_start,
        bss_end,
        name,
        segment_rom_start,
        exclusive_ram_id,
    ):
        raise NotImplementedError("make_bss_section")

    @abstractmethod
    def make_data_section(
        self,
        rom_start,
        rom_end,
        vram_start,
        name,
        rom_bytes,
        segment_rom_start,
        exclusive_ram_id,
    ):
        raise NotImplementedError("make_data_section")

    @abstractmethod
    def get_section(self):
        raise NotImplementedError("get_section")

    @abstractmethod
    def make_rodata_section(
        self,
        rom_start,
        rom_end,
        vram_start,
        name,
        rom_bytes,
        segment_rom_start,
        exclusive_ram_id,
    ):
        raise NotImplementedError("make_rodata_section")

    @abstractmethod
    def make_text_section(
        self,
        rom_start,
        rom_end,
        vram_start,
        name,
        rom_bytes,
        segment_rom_start,
        exclusive_ram_id,
    ):
        raise NotImplementedError("make_text_section")


class SpimdisasmDisassemberSection(DisassemblerSection):
    def __init__(self):
        self.spim_section: Optional[spimdisasm.mips.sections.SectionBase] = None

    def disassemble(self) -> str:
        assert self.spim_section is not None
        return self.spim_section.disassemble()

    def analyze(self):
        assert self.spim_section is not None
        self.spim_section.analyze()

    def set_comment_offset(self, rom_start: int):
        assert self.spim_section is not None
        self.spim_section.setCommentOffset(rom_start)

    def make_bss_section(
        self,
        rom_start: int,
        rom_end: int,
        vram_start: int,
        bss_end: int,
        name: str,
        segment_rom_start: int,
        exclusive_ram_id,
    ):
        self.spim_section = spimdisasm.mips.sections.SectionBss(
            symbols.spim_context,
            rom_start,
            rom_end,
            vram_start,
            bss_end,
            name,
            segment_rom_start,
            exclusive_ram_id,
        )

    def make_data_section(
        self,
        rom_start: int,
        rom_end: int,
        vram_start: int,
        name: str,
        rom_bytes: bytes,
        segment_rom_start: int,
        exclusive_ram_id,
    ):
        self.spim_section = spimdisasm.mips.sections.SectionData(
            symbols.spim_context,
            rom_start,
            rom_end,
            vram_start,
            name,
            rom_bytes,
            segment_rom_start,
            exclusive_ram_id,
        )

    def get_section(self) -> Optional[spimdisasm.mips.sections.SectionBase]:
        return self.spim_section

    def make_rodata_section(
        self,
        rom_start: int,
        rom_end: int,
        vram_start: int,
        name: str,
        rom_bytes: bytes,
        segment_rom_start: int,
        exclusive_ram_id,
    ):
        self.spim_section = spimdisasm.mips.sections.SectionRodata(
            symbols.spim_context,
            rom_start,
            rom_end,
            vram_start,
            name,
            rom_bytes,
            segment_rom_start,
            exclusive_ram_id,
        )

    def make_text_section(
        self,
        rom_start: int,
        rom_end: int,
        vram_start: int,
        name: str,
        rom_bytes: bytes,
        segment_rom_start: int,
        exclusive_ram_id,
    ):
        self.spim_section = spimdisasm.mips.sections.SectionText(
            symbols.spim_context,
            rom_start,
            rom_end,
            vram_start,
            name,
            rom_bytes,
            segment_rom_start,
            exclusive_ram_id,
        )


def make_disassembler_section() -> Optional[SpimdisasmDisassemberSection]:
    if options.opts.platform in ["n64", "psx", "ps2"]:
        return SpimdisasmDisassemberSection()

    raise NotImplementedError("No disassembler section for requested platform")
    return None


def make_text_section(
    rom_start: int,
    rom_end: int,
    vram_start: int,
    name: str,
    rom_bytes: bytes,
    segment_rom_start: int,
    exclusive_ram_id,
) -> DisassemblerSection:
    section = make_disassembler_section()
    assert section is not None
    section.make_text_section(
        rom_start,
        rom_end,
        vram_start,
        name,
        rom_bytes,
        segment_rom_start,
        exclusive_ram_id,
    )
    return section


def make_data_section(
    rom_start: int,
    rom_end: int,
    vram_start: int,
    name: str,
    rom_bytes: bytes,
    segment_rom_start: int,
    exclusive_ram_id,
) -> DisassemblerSection:
    section = make_disassembler_section()
    assert section is not None
    section.make_data_section(
        rom_start,
        rom_end,
        vram_start,
        name,
        rom_bytes,
        segment_rom_start,
        exclusive_ram_id,
    )
    return section


def make_rodata_section(
    rom_start: int,
    rom_end: int,
    vram_start: int,
    name: str,
    rom_bytes: bytes,
    segment_rom_start: int,
    exclusive_ram_id,
) -> DisassemblerSection:
    section = make_disassembler_section()
    assert section is not None
    section.make_rodata_section(
        rom_start,
        rom_end,
        vram_start,
        name,
        rom_bytes,
        segment_rom_start,
        exclusive_ram_id,
    )
    return section


def make_bss_section(
    rom_start: int,
    rom_end: int,
    vram_start: int,
    bss_end: int,
    name: str,
    segment_rom_start: int,
    exclusive_ram_id,
) -> DisassemblerSection:
    section = make_disassembler_section()
    assert section is not None
    section.make_bss_section(
        rom_start,
        rom_end,
        vram_start,
        bss_end,
        name,
        segment_rom_start,
        exclusive_ram_id,
    )
    return section
