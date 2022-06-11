from util import options
from segtypes.common.code import CommonSegCode
import spimdisasm
import rabbitizer

from segtypes.segment import Segment
from util.symbols import Symbol
from util import symbols


# abstract class for c, asm, data, etc
class CommonSegCodeSubsegment(Segment):
    double_mnemonics = [
        rabbitizer.InstrId.cpu_ldc1,
        rabbitizer.InstrId.cpu_sdc1,
    ]
    word_mnemonics = [
        rabbitizer.InstrId.cpu_addiu,
        rabbitizer.InstrId.cpu_sw,
        rabbitizer.InstrId.cpu_lw,
    ]
    float_mnemonics = [
        rabbitizer.InstrId.cpu_lwc1,
        rabbitizer.InstrId.cpu_swc1,
    ]
    short_mnemonics = [
        rabbitizer.InstrId.cpu_addiu,
        rabbitizer.InstrId.cpu_lh,
        rabbitizer.InstrId.cpu_sh,
        rabbitizer.InstrId.cpu_lhu,
    ]
    byte_mnemonics = [
        rabbitizer.InstrId.cpu_lb,
        rabbitizer.InstrId.cpu_sb,
        rabbitizer.InstrId.cpu_lbu,
    ]

    @property
    def needs_symbols(self) -> bool:
        return True

    def get_linker_section(self) -> str:
        return ".text"

    def scan_code(self, rom_bytes, is_asm=False):
        self.text_section = spimdisasm.mips.sections.SectionText(
            symbols.spim_context,
            self.rom_start,
            self.rom_end,
            self.vram_start,
            self.name,
            rom_bytes,
            self.get_most_parent().rom_start,
            self.get_exclusive_ram_id(),
        )

        for symbol_list in self.seg_symbols.values():
            symbols.add_symbol_to_spim_section(self.text_section, symbol_list[0])

        for sym in symbols.all_symbols:
            if sym.user_declared:
                symbols.add_symbol_to_spim_section(self.text_section, sym)

        self.text_section.isHandwritten = is_asm

        self.text_section.analyze()
        self.text_section.setCommentOffset(self.rom_start)

        for func in self.text_section.symbolList:
            assert isinstance(func, spimdisasm.mips.symbols.SymbolFunction)

            self.process_insns(func)

        # Process jumptable labels and pass them to spimdisasm
        self.gather_jumptable_labels(rom_bytes)
        for jtbl_label_vram in self.parent.jtbl_glabels_to_add:
            sym = self.create_symbol(
                jtbl_label_vram, True, type="jtbl_label", define=True
            )
            sym.type = "jtbl_label"
            symbols.add_symbol_to_spim_section(self.text_section, sym)

    def process_insns(
        self,
        func_spim: spimdisasm.mips.symbols.SymbolFunction,
    ):
        assert isinstance(self.parent, CommonSegCode)
        assert func_spim.vram is not None
        assert func_spim.vramEnd is not None
        self.parent: CommonSegCode = self.parent

        symbols.create_symbol_from_spim_symbol(
            self.get_most_parent(), func_spim.contextSym
        )

        # Gather symbols found by spimdisasm and create those symbols in splat's side
        for referenced_vram in func_spim.instrAnalyzer.referencedVrams:
            context_sym = self.text_section.getSymbol(
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

                context_sym = self.text_section.getSymbol(
                    sym_address, tryPlusOffset=False
                )
                if context_sym is not None:
                    sym = symbols.create_symbol_from_spim_symbol(
                        self.get_most_parent(), context_sym
                    )

                    if any(
                        insn.uniqueId in mnemonics
                        for mnemonics in (
                            self.double_mnemonics,
                            self.word_mnemonics,
                            self.float_mnemonics,
                            self.short_mnemonics,
                            self.byte_mnemonics,
                        )
                    ):
                        self.update_access_mnemonic(sym, insn)

                    if self.parent:
                        self.parent.check_rodata_sym(func_spim.vram, sym)

    def update_access_mnemonic(self, sym: Symbol, insn: rabbitizer.Instruction):
        if not sym.access_mnemonic:
            sym.access_mnemonic = insn.uniqueId
        elif sym.access_mnemonic in self.double_mnemonics:
            return
        elif (
            sym.access_mnemonic in self.float_mnemonics
            and insn.uniqueId in self.double_mnemonics
        ):
            sym.access_mnemonic = insn.uniqueId
        elif sym.access_mnemonic == rabbitizer.InstrId.cpu_addiu:
            sym.access_mnemonic = insn.uniqueId
        elif sym.access_mnemonic in self.short_mnemonics:
            return
        elif sym.access_mnemonic in self.byte_mnemonics:
            return
        else:
            sym.access_mnemonic = insn.uniqueId

    def print_file_boundaries(self):
        if not options.find_file_boundaries():
            return

        for in_file_offset in self.text_section.fileBoundaries:
            if (in_file_offset % 16) != 0:
                continue

            if not self.parent.reported_file_split:
                self.parent.reported_file_split = True

                # Look up for the last function in this boundary
                func_addr = 0
                for func in self.text_section.symbolList:
                    funcOffset = func.inFileOffset - self.text_section.inFileOffset
                    if in_file_offset == funcOffset:
                        break
                    func_addr = func.vram

                print(
                    f"Segment {self.name}, function at vram {func_addr:X} ends with extra nops, indicating a likely file split."
                )
                print(
                    "File split suggestions for this segment will follow in config yaml format:"
                )
            print(f"      - [0x{self.rom_start+in_file_offset:X}, asm]")

    def gather_jumptable_labels(self, rom_bytes):
        # TODO: use the seg_symbols for this
        # jumptables = [j.type == "jtbl" for j in self.seg_symbols]
        for jumptable in self.parent.jumptables:
            start, end = self.parent.jumptables[jumptable]
            rom_offset = self.rom_start + jumptable - self.vram_start

            if rom_offset <= 0:
                return

            while rom_offset:
                word = rom_bytes[rom_offset : rom_offset + 4]
                word_int = int.from_bytes(word, options.get_endianess())
                if word_int >= start and word_int <= end:
                    self.parent.jtbl_glabels_to_add.add(word_int)
                else:
                    break

                rom_offset += 4

    def should_scan(self) -> bool:
        return (
            options.mode_active("code")
            and self.rom_start != "auto"
            and self.rom_end != "auto"
        )

    def should_split(self) -> bool:
        return self.extract and options.mode_active("code")
