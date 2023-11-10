from typing import Optional

import spimdisasm
import rabbitizer

from util import options, symbols, log

from segtypes import segment
from segtypes.common.code import CommonSegCode

from segtypes.segment import Segment

from disassembler_section import DisassemblerSection, make_text_section


# abstract class for c, asm, data, etc
class CommonSegCodeSubsegment(Segment):
    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs)

        vram = segment.parse_segment_vram(self.yaml)
        if vram is not None:
            self.vram_start = vram

        self.str_encoding: Optional[str] = (
            self.yaml.get("str_encoding", None) if isinstance(self.yaml, dict) else None
        )

        self.spim_section: Optional[DisassemblerSection] = None
        self.instr_category = rabbitizer.InstrCategory.CPU
        if options.opts.platform == "ps2":
            self.instr_category = rabbitizer.InstrCategory.R5900
        elif options.opts.platform == "psx":
            self.instr_category = rabbitizer.InstrCategory.R3000GTE

        self.detect_redundant_function_end: Optional[bool] = (
            self.yaml.get("detect_redundant_function_end", None)
            if isinstance(self.yaml, dict)
            else None
        )

    @property
    def needs_symbols(self) -> bool:
        return True

    def get_linker_section(self) -> str:
        return ".text"

    def scan_code(self, rom_bytes, is_hasm=False):
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

        self.spim_section = make_text_section(
            self.rom_start,
            self.rom_end,
            self.vram_start,
            self.name,
            rom_bytes,
            segment_rom_start,
            self.get_exclusive_ram_id(),
        )

        assert self.spim_section is not None

        self.spim_section.get_section().isHandwritten = is_hasm
        self.spim_section.get_section().instrCat = self.instr_category
        self.spim_section.get_section().detectRedundantFunctionEnd = (
            self.detect_redundant_function_end
        )

        self.spim_section.analyze()
        self.spim_section.set_comment_offset(self.rom_start)

        for func in self.spim_section.get_section().symbolList:
            assert isinstance(func, spimdisasm.mips.symbols.SymbolFunction)

            self.process_insns(func)

        # Process jumptable labels and pass them to spimdisasm
        self.gather_jumptable_labels(rom_bytes)
        for jtbl_label_vram in self.parent.jtbl_glabels_to_add:
            sym = self.create_symbol(
                jtbl_label_vram, True, type="jtbl_label", define=True
            )
            sym.type = "jtbl_label"
            symbols.add_symbol_to_spim_section(self.spim_section.get_section(), sym)

    def process_insns(
        self,
        func_spim: spimdisasm.mips.symbols.SymbolFunction,
    ):
        assert isinstance(self.parent, CommonSegCode)
        assert func_spim.vram is not None
        assert func_spim.vramEnd is not None
        assert self.spim_section is not None
        self.parent: CommonSegCode = self.parent

        symbols.create_symbol_from_spim_symbol(
            self.get_most_parent(), func_spim.contextSym
        )

        # Gather symbols found by spimdisasm and create those symbols in splat's side
        for referenced_vram in func_spim.instrAnalyzer.referencedVrams:
            context_sym = self.spim_section.get_section().getSymbol(
                referenced_vram, tryPlusOffset=False
            )
            if context_sym is not None:
                if context_sym.type == spimdisasm.common.SymbolSpecialType.jumptable:
                    self.parent.jumptables[referenced_vram] = (
                        func_spim.vram,
                        func_spim.vramEnd,
                    )
                symbols.create_symbol_from_spim_symbol(
                    self.get_most_parent(), context_sym
                )

        # Main loop
        for i, insn in enumerate(func_spim.instructions):
            instr_offset = i * 4

            # update pointer accesses from this function
            if instr_offset in func_spim.instrAnalyzer.symbolInstrOffset:
                sym_address = func_spim.instrAnalyzer.symbolInstrOffset[instr_offset]

                context_sym = self.spim_section.get_section().getSymbol(
                    sym_address, tryPlusOffset=False
                )
                if context_sym is not None:
                    sym = symbols.create_symbol_from_spim_symbol(
                        self.get_most_parent(), context_sym
                    )

                    if self.parent:
                        self.parent.check_rodata_sym(func_spim.vram, sym)

    def print_file_boundaries(self):
        if not self.show_file_boundaries or not self.spim_section:
            return

        assert isinstance(self.rom_start, int)

        for in_file_offset in self.spim_section.get_section().fileBoundaries:
            if (in_file_offset % 16) != 0:
                continue

            if not self.parent.reported_file_split:
                self.parent.reported_file_split = True

                # Look up for the last symbol in this boundary
                sym_addr = 0
                for sym in self.spim_section.get_section().symbolList:
                    symOffset = (
                        sym.inFileOffset - self.spim_section.get_section().inFileOffset
                    )
                    if in_file_offset == symOffset:
                        break
                    sym_addr = sym.vram

                print(
                    f"\nSegment {self.name}, symbol at vram {sym_addr:X} ends with extra nops, indicating a likely file split."
                )
                print(
                    "File split suggestions for this segment will follow in config yaml format:"
                )
            print(f"      - [0x{self.rom_start+in_file_offset:X}, {self.type}]")

    def gather_jumptable_labels(self, rom_bytes):
        assert isinstance(self.rom_start, int)
        assert isinstance(self.vram_start, int)

        # TODO: use the seg_symbols for this
        # jumptables = [j.type == "jtbl" for j in self.seg_symbols]
        for jumptable in self.parent.jumptables:
            start, end = self.parent.jumptables[jumptable]
            rom_offset = self.rom_start + jumptable - self.vram_start

            if rom_offset <= 0:
                return

            while rom_offset:
                word = rom_bytes[rom_offset : rom_offset + 4]
                word_int = int.from_bytes(word, options.opts.endianness)
                if word_int >= start and word_int <= end:
                    self.parent.jtbl_glabels_to_add.add(word_int)
                else:
                    break

                rom_offset += 4

    def should_scan(self) -> bool:
        return (
            options.opts.is_mode_active("code")
            and self.rom_start is not None
            and self.rom_end is not None
        )

    def should_split(self) -> bool:
        return (
            self.extract and options.opts.is_mode_active("code") and self.should_scan()
        )  # only split if the segment was scanned first
