import spimdisasm

from segtypes.common.codesubsegment import CommonSegCodeSubsegment
from segtypes.common.group import CommonSegGroup
from pathlib import Path
from typing import Optional
from util import options, symbols


class CommonSegData(CommonSegCodeSubsegment, CommonSegGroup):
    def out_path(self) -> Optional[Path]:
        if self.type.startswith("."):
            if self.sibling:
                # C file
                return self.sibling.out_path()
            else:
                # Implied C file
                return options.opts.src_path / self.dir / f"{self.name}.c"
        else:
            # ASM
            return options.opts.data_path / self.dir / f"{self.name}.{self.type}.s"

    def scan(self, rom_bytes: bytes):
        CommonSegGroup.scan(self, rom_bytes)

        if super().should_scan():
            self.disassemble_data(rom_bytes)

    def split(self, rom_bytes: bytes):
        super().split(rom_bytes)

        if (
            not self.type.startswith(".")
            and self.spim_section
            and self.should_self_split()
        ):
            path = self.out_path()

            if path:
                path.parent.mkdir(parents=True, exist_ok=True)

                self.print_file_boundaries()

                with open(path, "w", newline="\n") as f:
                    f.write('.include "macro.inc"\n\n')
                    f.write(f".section {self.get_linker_section()}\n\n")

                    f.write(self.spim_section.disassemble())

    def should_self_split(self) -> bool:
        return options.opts.is_mode_active("data")

    def should_split(self) -> bool:
        return True

    def should_scan(self) -> bool:
        return True

    def cache(self):
        return [CommonSegCodeSubsegment.cache(self), CommonSegGroup.cache(self)]

    def get_linker_section(self) -> str:
        return ".data"

    def get_linker_entries(self):
        return CommonSegCodeSubsegment.get_linker_entries(self)

    def disassemble_data(self, rom_bytes):
        assert isinstance(self.rom_start, int)
        assert isinstance(self.rom_end, int)

        segment_rom_start = self.get_most_parent().rom_start
        assert isinstance(segment_rom_start, int)

        self.spim_section = spimdisasm.mips.sections.SectionData(
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

        rodata_encountered = False

        for symbol in self.spim_section.symbolList:
            symbols.create_symbol_from_spim_symbol(
                self.get_most_parent(), symbol.contextSym
            )

            # Hint to the user that we are now in the .rodata section and no longer in the .data section (assuming rodata follows data)
            if not rodata_encountered and self.get_most_parent().rodata_follows_data:
                if symbol.contextSym.isJumpTable():
                    rodata_encountered = True
                    print(
                        f"Data segment {self.name}, symbol at vram {symbol.contextSym.vram:X} is a jumptable, indicating the start of the rodata section _may_ be near here."
                    )
                    print(
                        f"Please note the real start of the rodata section may be way before this point."
                    )
                    if symbol.contextSym.vromAddress is not None:
                        print(f"      - [0x{symbol.contextSym.vromAddress:X}, rodata]")
