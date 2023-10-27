from pathlib import Path
from typing import Optional

from util import options, symbols, log

from segtypes.common.codesubsegment import CommonSegCodeSubsegment
from segtypes.common.group import CommonSegGroup

from disassembler_section import make_data_section


class CommonSegData(CommonSegCodeSubsegment, CommonSegGroup):
    @staticmethod
    def is_data() -> bool:
        return True

    def asm_out_path(self) -> Path:
        typ = self.type
        if typ.startswith("."):
            typ = typ[1:]

        return options.opts.data_path / self.dir / f"{self.name}.{typ}.s"

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
            return self.asm_out_path()

    def scan(self, rom_bytes: bytes):
        CommonSegGroup.scan(self, rom_bytes)

        if self.rom_start is not None and self.rom_end is not None:
            self.disassemble_data(rom_bytes)

    def split(self, rom_bytes: bytes):
        super().split(rom_bytes)

        if self.type.startswith(".") and not options.opts.disassemble_all:
            return

        if self.spim_section is None or not self.should_self_split():
            return

        path = self.asm_out_path()

        path.parent.mkdir(parents=True, exist_ok=True)

        self.print_file_boundaries()

        with path.open("w", newline="\n") as f:
            f.write('.include "macro.inc"\n\n')
            preamble = options.opts.generated_s_preamble
            if preamble:
                f.write(preamble + "\n")

            f.write(f".section {self.get_linker_section()}")
            section_flags = self.get_section_flags()
            if section_flags:
                f.write(f', "{section_flags}"')
            f.write("\n\n")

            f.write(self.spim_section.disassemble())

    def should_self_split(self) -> bool:
        return options.opts.is_mode_active("data")

    def should_scan(self) -> bool:
        return True

    def should_split(self) -> bool:
        return True

    def cache(self):
        return [CommonSegCodeSubsegment.cache(self), CommonSegGroup.cache(self)]

    def get_linker_section(self) -> str:
        return ".data"

    def get_linker_entries(self):
        return CommonSegCodeSubsegment.get_linker_entries(self)

    def disassemble_data(self, rom_bytes):
        if not isinstance(self.rom_start, int):
            log.error(
                f"Segment '{self.name}' (type '{self.type}') requires a rom_start. Got '{self.rom_start}'"
            )

        # Supposedly logic error, not user error
        assert isinstance(self.rom_end, int), self.rom_end

        # Supposedly logic error, not user error
        segment_rom_start = self.get_most_parent().rom_start
        assert isinstance(segment_rom_start, int), segment_rom_start

        if not isinstance(self.vram_start, int):
            log.error(
                f"Segment '{self.name}' (type '{self.type}') requires a vram address. Got '{self.vram_start}'"
            )

        self.spim_section = make_data_section(
            self.rom_start,
            self.rom_end,
            self.vram_start,
            self.name,
            rom_bytes,
            segment_rom_start,
            self.get_exclusive_ram_id(),
        )

        assert self.spim_section is not None

        # Set rodata string encoding
        # First check the global configuration
        if options.opts.data_string_encoding is not None:
            self.spim_section.get_section().stringEncoding = (
                options.opts.data_string_encoding
            )

        # Then check the per-segment configuration in case we want to override the global one
        if self.str_encoding is not None:
            self.spim_section.get_section().stringEncoding = self.str_encoding

        self.spim_section.analyze()
        self.spim_section.set_comment_offset(self.rom_start)

        rodata_encountered = False

        for symbol in self.spim_section.get_section().symbolList:
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
                        "Please note the real start of the rodata section may be way before this point."
                    )
                    if symbol.contextSym.vromAddress is not None:
                        print(f"      - [0x{symbol.contextSym.vromAddress:X}, rodata]")
