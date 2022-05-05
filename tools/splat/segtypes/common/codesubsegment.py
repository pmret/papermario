from dataclasses import dataclass
from typing import List, Optional
import typing
from util import options
from segtypes.common.code import CommonSegCode
from collections import OrderedDict
import re

from capstone import (
    Cs,
    CS_ARCH_MIPS,
    CS_MODE_MIPS64,
    CS_MODE_BIG_ENDIAN,
    CS_MODE_MIPS32,
    CS_MODE_LITTLE_ENDIAN,
    CsInsn,
)
from capstone.mips import *

from segtypes.segment import Segment
from util.compiler import SN64
from util.symbols import Instruction, Symbol
from util import log

# abstract class for c, asm, data, etc
class CommonSegCodeSubsegment(Segment):
    double_mnemonics = ["ldc1", "sdc1"]
    word_mnemonics = ["addiu", "sw", "lw", "jtbl"]
    float_mnemonics = ["lwc1", "swc1"]
    short_mnemonics = ["addiu", "lh", "sh", "lhu"]
    byte_mnemonics = ["lb", "sb", "lbu"]
    reg_numbers = {
        "$zero": "$0",
        "$at": "$1",
        "$v0": "$2",
        "$v1": "$3",
        "$a0": "$4",
        "$a1": "$5",
        "$a2": "$6",
        "$a3": "$7",
        "$t0": "$8",
        "$t1": "$9",
        "$t2": "$10",
        "$t3": "$11",
        "$t4": "$12",
        "$t5": "$13",
        "$t6": "$14",
        "$t7": "$15",
        "$s0": "$16",
        "$s1": "$17",
        "$s2": "$18",
        "$s3": "$19",
        "$s4": "$20",
        "$s5": "$21",
        "$s6": "$22",
        "$s7": "$23",
        "$t8": "$24",
        "$t9": "$25",
        "$k0": "$26",
        "$k1": "$27",
        "$gp": "$28",
        "$sp": "$sp",
        "$fp": "$30",
        "$ra": "$31",
    }

    if options.get_endianess() == "big":
        capstone_mode = CS_MODE_MIPS64 | CS_MODE_BIG_ENDIAN
    else:
        capstone_mode = CS_MODE_MIPS32 | CS_MODE_LITTLE_ENDIAN

    md = Cs(CS_ARCH_MIPS, capstone_mode)
    md.detail = False
    md.skipdata = True

    @property
    def needs_symbols(self) -> bool:
        return True

    def get_linker_section(self) -> str:
        return ".text"

    @staticmethod
    def is_nops(insns: List[CsInsn]) -> bool:
        for insn in insns:
            if insn.mnemonic != "nop":
                return False
        return True

    @staticmethod
    def is_branch_insn(mnemonic):
        return (
            mnemonic.startswith("b")
            and not mnemonic.startswith("binsl")
            and not mnemonic == "break"
        ) or mnemonic == "j"

    @staticmethod
    def replace_reg_names(op_str):
        for regname, regnum in CommonSegCodeSubsegment.reg_numbers.items():
            op_str = op_str.replace(regname, regnum)
        return op_str

    def scan_code(self, rom_bytes, is_asm=False):
        insns: List[CsInsn] = [
            insn
            for insn in CommonSegCodeSubsegment.md.disasm(
                rom_bytes[self.rom_start : self.rom_end], self.vram_start
            )
        ]

        self.funcs: typing.OrderedDict[int, Symbol] = self.process_insns(
            insns, self.rom_start, is_asm=is_asm
        )

        # TODO: set these in creation
        for func in self.funcs.values():
            func.define = True
            func.local_only = True
            func.size = len(func.insns) * 4

        self.determine_symbols()

    def split_code(self, rom_bytes):
        self.gather_jumptable_labels(rom_bytes)
        return self.add_labels()

    def process_insns(
        self, insns: List[CsInsn], rom_addr, is_asm=False
    ) -> typing.OrderedDict[int, Symbol]:
        assert isinstance(self.parent, CommonSegCode)
        self.parent: CommonSegCode = self.parent

        ret: typing.OrderedDict[int, Symbol] = OrderedDict()

        end_func = False
        start_new_func = True
        labels = []

        big_endian = options.get_endianess() == "big"

        # Collect labels
        for insn in insns:
            if self.is_branch_insn(insn.mnemonic):
                op_str_split = insn.op_str.split(" ")
                branch_target = op_str_split[-1]
                branch_addr = int(branch_target, 0)
                labels.append((insn.address, branch_addr))

        # Main loop
        for i, insn in enumerate(insns):
            mnemonic = insn.mnemonic
            op_str = insn.op_str

            # If this is non-zero, disasm size insns
            hard_size = 0

            if start_new_func:
                func: Symbol = self.parent.create_symbol(insn.address, type="func")
                start_new_func = False

            if func.size > 4:
                hard_size = func.size / 4

            if options.get_compiler() == SN64:
                op_str = self.replace_reg_names(op_str)

            if mnemonic == "move":
                # Let's get the actual instruction out
                idx = 3 if big_endian else 0
                opcode = insn.bytes[idx] & 0b00111111

                if options.get_compiler() == SN64:
                    op_str += ", $0"
                else:
                    op_str += ", $zero"

                if opcode == 37:
                    mnemonic = "or"
                elif opcode == 45:
                    mnemonic = "daddu"
                elif opcode == 33:
                    mnemonic = "addu"
                else:
                    print("INVALID INSTRUCTION " + str(insn), opcode)
            elif mnemonic == "jal":
                jal_addr = int(op_str, 0)
                jump_func = self.parent.create_symbol(
                    jal_addr, type="func", reference=True
                )
                op_str = jump_func.name
            elif self.is_branch_insn(insn.mnemonic):
                op_str_split = op_str.split(" ")
                branch_target = op_str_split[-1]
                branch_target_int = int(branch_target, 0)

                label_sym = self.parent.get_symbol(
                    branch_target_int, type="label", reference=True, local_only=True
                )

                if label_sym:
                    label_name = label_sym.name
                else:
                    self.parent.labels_to_add.add(branch_target_int)
                    label_name = f".L{branch_target[2:].upper()}"

                op_str = " ".join(op_str_split[:-1] + [label_name])
            elif mnemonic in ["mtc0", "mfc0", "mtc2", "mfc2"]:
                idx = 2 if big_endian else 1
                rd = (insn.bytes[idx] & 0xF8) >> 3
                op_str = op_str.split(" ")[0] + " $" + str(rd)
            elif (
                mnemonic == "break"
                and op_str in ["6", "7"]
                and options.get_compiler() == SN64
                and not is_asm
            ):
                # SN64's assembler expands div to have break if dividing by zero
                # However, the break it generates is different than the one it generates with `break N`
                # So we replace break instrutions for SN64 with the exact word that the assembler generates when expanding div
                if op_str == "6":
                    mnemonic = ".word 0x0006000D"
                    op_str = ""
                elif op_str == "7":
                    mnemonic = ".word 0x0007000D"
                    op_str = ""
            elif (
                mnemonic in ["div", "divu"]
                and options.get_compiler() == SN64
                and not is_asm
            ):
                # SN64's assembler also doesn't like assembling `div $0, a, b` with .set noat active
                # Removing the $0 fixes this issue
                if op_str.startswith("$0, "):
                    op_str = op_str[4:]

            func.insns.append(Instruction(insn, mnemonic, op_str, rom_addr))
            rom_addr += 4

            size_remaining = hard_size - len(func.insns) if hard_size > 0 else 0

            if mnemonic == "jr":
                # Record potential jtbl jumps
                if op_str not in ["$ra", "$31"]:
                    self.parent.jtbl_jumps[insn.address] = op_str

                keep_going = False
                for label in labels:
                    if (label[0] > insn.address and label[1] <= insn.address) or (
                        label[0] <= insn.address and label[1] > insn.address
                    ):
                        keep_going = True
                        break
                if not keep_going and not size_remaining:
                    end_func = True
                    continue

            # Stop here if a size was specified and we have disassembled up to the size
            if hard_size > 0 and size_remaining == 0:
                end_func = True

            if i < len(insns) - 1 and self.parent.get_symbol(
                insns[i + 1].address, local_only=True, type="func", dead=False
            ):
                end_func = True

            if end_func:
                if (
                    self.is_nops(insns[i:])
                    or i < len(insns) - 1
                    and insns[i + 1].mnemonic != "nop"
                ):
                    end_func = False
                    start_new_func = True
                    ret[func.vram_start] = func

        # Add the last function (or append nops to the previous one)
        if not self.is_nops([insn.instruction for insn in func.insns]):
            ret[func.vram_start] = func
        else:
            next(reversed(ret.values())).insns.extend(func.insns)

        return ret

    def update_access_mnemonic(self, sym, mnemonic):
        if not sym.access_mnemonic:
            sym.access_mnemonic = mnemonic
        elif sym.access_mnemonic == "addiu":
            sym.access_mnemonic = mnemonic
        elif sym.access_mnemonic in self.double_mnemonics:
            return
        elif (
            sym.access_mnemonic in self.float_mnemonics
            and mnemonic in self.double_mnemonics
        ):
            sym.access_mnemonic = mnemonic
        elif sym.access_mnemonic in self.short_mnemonics:
            return
        elif sym.access_mnemonic in self.byte_mnemonics:
            return
        else:
            sym.access_mnemonic = mnemonic

    # Determine symbols
    def determine_symbols(self):
        hi_lo_max_distance = options.hi_lo_max_distance()

        for func_addr in self.funcs:
            func = self.funcs[func_addr]
            func_end_addr = func.insns[-1].instruction.address + 4

            possible_jtbl_jumps = [
                (k, v)
                for k, v in self.parent.jtbl_jumps.items()
                if k >= func_addr and k < func_end_addr
            ]
            possible_jtbl_jumps.sort(key=lambda x: x[0])

            for i in range(len(func.insns)):
                hi_insn: CsInsn = func.insns[i].instruction

                # Ensure the first item in the list is always ahead of where we're looking
                while (
                    len(possible_jtbl_jumps) > 0
                    and possible_jtbl_jumps[0][0] < hi_insn.address
                ):
                    del possible_jtbl_jumps[0]

                # Find gp relative reads and writes e.g  lw $a1, 0x670($gp)
                if hi_insn.op_str.endswith("($gp)"):
                    gp_base = options.get_gp()
                    if gp_base is None:
                        log.error(
                            "gp_value not set in yaml, can't calculate %gp_rel reloc value for "
                            + hi_insn.op_str
                        )

                    op_split = hi_insn.op_str.split(", ")
                    gp_offset = op_split[1][:-5]  # extract the 0x670 part
                    if len(gp_offset) == 0:
                        gp_offset = 0
                    else:
                        gp_offset = int(gp_offset, 16)
                    symbol_addr = gp_base + gp_offset

                    sym = self.parent.create_symbol(
                        symbol_addr, offsets=True, reference=True
                    )
                    offset = symbol_addr - sym.vram_start
                    offset_str = f"+0x{offset:X}"

                    if self.parent:
                        self.parent.check_rodata_sym(func_addr, sym)

                    self.update_access_mnemonic(sym, hi_insn.mnemonic)

                    func.insns[i].is_gp = True
                    func.insns[i].hi_lo_sym = sym
                    func.insns[i].sym_offset_str = offset_str
                # All hi/lo pairs start with a lui
                elif hi_insn.mnemonic == "lui":
                    op_split = hi_insn.op_str.split(", ")
                    hi_reg = op_split[0]

                    if not op_split[1].startswith("0x"):
                        continue

                    lui_val = int(op_split[1], 0)

                    # Assumes all luis are going to load from 0x80000000 or higher (maybe false)
                    if lui_val >= 0x8000:
                        # Iterate over the next few instructions to see if we can find a matching lo
                        for j in range(
                            i + 1, min(i + hi_lo_max_distance, len(func.insns))
                        ):
                            lo_insn = func.insns[j].instruction

                            s_op_split = lo_insn.op_str.split(", ")

                            if lo_insn.mnemonic == "lui" and hi_reg == s_op_split[0]:
                                break

                            if lo_insn.mnemonic in ["addiu", "ori"]:
                                lo_reg = s_op_split[-2]
                            else:
                                lo_reg = s_op_split[-1][
                                    s_op_split[-1].rfind("(") + 1 : -1
                                ]

                            if hi_reg == lo_reg:
                                if lo_insn.mnemonic not in [
                                    "addiu",
                                    "lw",
                                    "sw",
                                    "lh",
                                    "sh",
                                    "lhu",
                                    "lb",
                                    "sb",
                                    "lbu",
                                    "lwc1",
                                    "swc1",
                                    "ldc1",
                                    "sdc1",
                                ]:
                                    break

                                # Match!
                                reg_ext = ""

                                # I forgot what this is doing
                                junk_search = re.search(r"[\(]", s_op_split[-1])
                                if junk_search is not None:
                                    if junk_search.start() == 0:
                                        break
                                    s_str = s_op_split[-1][: junk_search.start()]
                                    reg_ext = s_op_split[-1][junk_search.start() :]
                                else:
                                    s_str = s_op_split[-1]

                                if options.get_compiler() == SN64:
                                    reg_ext = CommonSegCodeSubsegment.replace_reg_names(
                                        reg_ext
                                    )

                                symbol_addr = (lui_val * 0x10000) + int(s_str, 0)

                                sym: Optional[Symbol] = None
                                offset_str = ""

                                # If the symbol is likely in the rodata section
                                if (
                                    not self.parent.text_follows_rodata
                                    and symbol_addr > func_addr
                                ) or (
                                    self.parent.text_follows_rodata
                                    and symbol_addr < func_addr
                                ):
                                    # Sanity check that the symbol is within this segment's vram
                                    if (
                                        self.parent.vram_end
                                        and symbol_addr < self.parent.vram_end
                                    ):
                                        # If we've seen possible jumps to a jumptable and this symbol isn't too close to the end of the function
                                        if (
                                            len(possible_jtbl_jumps) > 0
                                            and func_end_addr - lo_insn.address >= 0x30
                                        ):
                                            for jump in possible_jtbl_jumps:
                                                if jump[1] == s_op_split[0]:
                                                    dist_to_jump = (
                                                        possible_jtbl_jumps[0][0]
                                                        - lo_insn.address
                                                    )
                                                    if dist_to_jump <= 16:
                                                        sym = self.parent.create_symbol(
                                                            symbol_addr,
                                                            reference=True,
                                                            type="jtbl",
                                                            local_only=True,
                                                        )

                                                        self.parent.jumptables[
                                                            symbol_addr
                                                        ] = (func_addr, func_end_addr)
                                                        break

                                if not sym:
                                    sym = self.parent.create_symbol(
                                        symbol_addr, offsets=True, reference=True
                                    )
                                    offset = symbol_addr - sym.vram_start
                                    if offset != 0:
                                        offset_str = f"+0x{offset:X}"

                                if self.parent:
                                    self.parent.check_rodata_sym(func_addr, sym)

                                self.update_access_mnemonic(sym, lo_insn.mnemonic)

                                func.insns[i].is_hi = True
                                func.insns[i].hi_lo_sym = sym
                                func.insns[i].sym_offset_str = offset_str

                                func.insns[j].is_lo = True
                                func.insns[j].hi_lo_sym = sym
                                func.insns[j].sym_offset_str = offset_str
                                func.insns[j].hi_lo_reg = reg_ext
                                break

    def add_labels(self):
        ret = {}

        function_macro = options.get_asm_function_macro()
        data_macro = options.get_asm_data_macro()

        for func_addr in self.funcs:
            func_text = []
            func = self.funcs[func_addr]

            # Add function label
            func_text.append(f"{function_macro} {func.name}")

            if options.get_compiler() == SN64:
                func_text.append(f".ent {func.name}")
                func_text.append(f"{func.name}:")

            indent_next = False

            mnemonic_ljust = options.mnemonic_ljust()
            rom_addr_padding = options.rom_address_padding()

            for insn in func.insns:
                insn_addr = insn.instruction.address
                # Add a label if we need one
                if insn_addr in self.parent.jtbl_glabels_to_add:
                    func_text.append(f"{data_macro} L{insn_addr:X}_{insn.rom_addr:X}")
                elif insn_addr in self.parent.labels_to_add:
                    self.parent.labels_to_add.remove(insn_addr)
                    func_text.append(".L{:X}:".format(insn_addr))

                if rom_addr_padding:
                    rom_str = "{0:0{1}X}".format(insn.rom_addr, rom_addr_padding)
                else:
                    rom_str = "{:X}".format(insn.rom_addr)

                if options.get_compiler() == SN64:
                    asm_comment = ""
                else:
                    asm_comment = "/* {} {:X} {} */".format(
                        rom_str, insn_addr, insn.instruction.bytes.hex().upper()
                    )

                if insn.is_hi:
                    assert insn.hi_lo_sym
                    op_str = ", ".join(
                        insn.op_str.split(", ")[:-1]
                        + [f"%hi({insn.hi_lo_sym.name}{insn.sym_offset_str})"]
                    )
                elif insn.is_lo:
                    assert insn.hi_lo_sym
                    op_str = ", ".join(
                        insn.op_str.split(", ")[:-1]
                        + [
                            f"%lo({insn.hi_lo_sym.name}{insn.sym_offset_str}){insn.hi_lo_reg}"
                        ]
                    )
                elif insn.is_gp:
                    op_str = ", ".join(
                        insn.op_str.split(", ")[:-1]
                        + [f"%gp_rel({insn.hi_lo_sym.name}{insn.sym_offset_str})($gp)"]
                    )
                else:
                    op_str = insn.op_str

                if self.is_branch_insn(insn.instruction.mnemonic):
                    branch_addr = int(insn.instruction.op_str.split(",")[-1].strip(), 0)
                    if branch_addr in self.parent.jtbl_glabels_to_add:
                        label_str = f"L{branch_addr:X}_{self.ram_to_rom(branch_addr):X}"
                        op_str = ", ".join(insn.op_str.split(", ")[:-1] + [label_str])

                insn_text = insn.mnemonic
                if indent_next:
                    indent_next = False
                    insn_text = " " + insn_text

                asm_insn_text = "  {}{}".format(
                    insn_text.ljust(mnemonic_ljust), op_str
                ).rstrip()

                func_text.append(asm_comment + asm_insn_text)

                if (
                    insn.instruction.mnemonic != "branch"
                    and insn.instruction.mnemonic.startswith("b")
                    or insn.instruction.mnemonic.startswith("j")
                ):
                    indent_next = True

            end_label = options.get_asm_end_label()

            if end_label:
                func_text.append(f"{end_label} {func.name}")

            ret[func_addr] = (func_text, func.rom)

            if options.find_file_boundaries():
                # If this is not the last function in the file
                if func_addr != list(self.funcs.keys())[-1]:

                    # Find where the function returns
                    jr_pos: Optional[int] = None
                    for i, insn in enumerate(reversed(func.insns)):
                        if (
                            insn.instruction.mnemonic == "jr"
                            and insn.instruction.op_str in ["$ra", "$31"]
                        ):
                            jr_pos = i
                            break

                    # If there is more than 1 nop after the return
                    if (
                        jr_pos is not None
                        and jr_pos > 1
                        and self.is_nops(
                            [insn.instruction for insn in func.insns[-jr_pos + 1 :]]
                        )
                    ):
                        new_file_addr = func.insns[-1].rom_addr + 4
                        if (new_file_addr % 16) == 0:
                            if not self.parent.reported_file_split:
                                self.parent.reported_file_split = True
                                print(
                                    f"Segment {self.name}, function at vram {func_addr:X} ends with extra nops, indicating a likely file split."
                                )
                                print(
                                    "File split suggestions for this segment will follow in config yaml format:"
                                )
                            print(f"      - [0x{new_file_addr:X}, asm]")

        return ret

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
