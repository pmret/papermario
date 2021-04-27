from typing import Optional
from util import options
from segtypes.n64.code import N64SegCode
from collections import OrderedDict
import re

from capstone import Cs, CS_ARCH_MIPS, CS_MODE_MIPS64, CS_MODE_BIG_ENDIAN
from capstone.mips import *

from segtypes.segment import Segment

# abstract class for c, asm, data, etc
class N64SegCodeSubsegment(Segment):    
    double_mnemonics = ["ldc1", "sdc1"]
    word_mnemonics = ["addiu", "sw", "lw", "jtbl"]
    float_mnemonics = ["lwc1", "swc1"]
    short_mnemonics = ["addiu", "lh", "sh", "lhu"]
    byte_mnemonics = ["lb", "sb", "lbu"]

    md = Cs(CS_ARCH_MIPS, CS_MODE_MIPS64 + CS_MODE_BIG_ENDIAN)
    md.detail = True
    md.skipdata = True

    @property
    def needs_symbols(self) -> bool:
        return True

    def get_linker_section(self) -> str:
        return ".text"

    @staticmethod
    def is_nops(insns):
        for insn in insns:
            if insn.mnemonic != "nop":
                return False
        return True

    @staticmethod
    def is_branch_insn(mnemonic):
        return (mnemonic.startswith("b") and not mnemonic.startswith("binsl") and not mnemonic == "break") or mnemonic == "j"

    def disassemble_code(self, rom_bytes, addsuffix=False):
        insns = [insn for insn in N64SegCodeSubsegment.md.disasm(rom_bytes[self.rom_start : self.rom_end], self.vram_start)]

        funcs = self.process_insns(insns, self.rom_start)

        # TODO: someday make func a subclass of symbol and store this disasm info there too
        for func in funcs:
            self.parent.get_symbol(func, type="func", create=True, define=True, local_only=True)

        funcs = self.determine_symbols(funcs)
        self.gather_jumptable_labels(rom_bytes)
        return self.add_labels(funcs, addsuffix)

    def process_insns(self, insns, rom_addr):
        assert(isinstance(self.parent, N64SegCode))
        self.parent: N64SegCode = self.parent

        ret = OrderedDict()

        func_addr = None
        func = []
        end_func = False
        labels = []

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
            func_addr = insn.address if len(func) == 0 else func[0][0].address

            if mnemonic == "move":
                # Let's get the actual instruction out
                opcode = insn.bytes[3] & 0b00111111
                op_str += ", $zero"

                if opcode == 37:
                    mnemonic = "or"
                elif opcode == 45:
                    mnemonic = "daddu"
                elif opcode == 33:
                    mnemonic = "addu"
                else:
                    print("INVALID INSTRUCTION " + insn)
            elif mnemonic == "jal":
                jal_addr = int(op_str, 0)
                jump_func = self.parent.get_symbol(jal_addr, type="func", create=True, reference=True)
                op_str = jump_func.name
            elif self.is_branch_insn(insn.mnemonic):
                op_str_split = op_str.split(" ")
                branch_target = op_str_split[-1]
                branch_target_int = int(branch_target, 0)
                label = ""

                label = self.parent.get_symbol(branch_target_int, type="label", reference=True, local_only=True)

                if label:
                    label_name = label.name
                else:
                    self.parent.labels_to_add.add(branch_target_int)
                    label_name = f".L{branch_target[2:].upper()}"

                op_str = " ".join(op_str_split[:-1] + [label_name])
            elif mnemonic == "mtc0" or mnemonic == "mfc0":
                rd = (insn.bytes[2] & 0xF8) >> 3
                op_str = op_str.split(" ")[0] + " $" + str(rd)

            func.append((insn, mnemonic, op_str, rom_addr))
            rom_addr += 4

            if mnemonic == "jr":
                # Record potential jtbl jumps
                if op_str != "$ra":
                    self.parent.jtbl_jumps[insn.address] = op_str

                keep_going = False
                for label in labels:
                    if (label[0] > insn.address and label[1] <= insn.address) or (label[0] <= insn.address and label[1] > insn.address):
                        keep_going = True
                        break
                if not keep_going:
                    end_func = True
                    continue

            if i < len(insns) - 1 and self.parent.get_symbol(insns[i + 1].address, local_only=True, type="func", dead=False):
                end_func = True

            if end_func:
                if self.is_nops(insns[i:]) or i < len(insns) - 1 and insns[i + 1].mnemonic != "nop":
                    end_func = False
                    ret[func_addr] = func
                    func = []

        # Add the last function (or append nops to the previous one)
        if not self.is_nops([i[0] for i in func]):
            ret[func_addr] = func
        else:
            next(reversed(ret.values())).extend(func)

        return ret

    def update_access_mnemonic(self, sym, mnemonic):
        if not sym.access_mnemonic:
            sym.access_mnemonic = mnemonic
        elif sym.access_mnemonic == "addiu":
            sym.access_mnemonic = mnemonic
        elif sym.access_mnemonic in self.double_mnemonics:
            return
        elif sym.access_mnemonic in self.float_mnemonics and mnemonic in self.double_mnemonics:
            sym.access_mnemonic = mnemonic
        elif sym.access_mnemonic in self.short_mnemonics:
            return
        elif sym.access_mnemonic in self.byte_mnemonics:
            return
        else:
            sym.access_mnemonic = mnemonic

    # Determine symbols
    def determine_symbols(self, funcs):
        hi_lo_max_distance = options.get("hi_lo_max_distance", 6)
        ret = {}

        for func_addr in funcs:
            func = funcs[func_addr]
            func_end_addr = func[-1][0].address + 4

            possible_jtbl_jumps = [(k, v) for k, v in self.parent.jtbl_jumps.items() if k >= func_addr and k < func_end_addr]
            possible_jtbl_jumps.sort(key=lambda x:x[0])

            for i in range(len(func)):
                insn = func[i][0]

                # Ensure the first item in the list is always ahead of where we're looking
                while len(possible_jtbl_jumps) > 0 and possible_jtbl_jumps[0][0] < insn.address:
                    del possible_jtbl_jumps[0]

                if insn.mnemonic == "lui":
                    op_split = insn.op_str.split(", ")
                    reg = op_split[0]

                    if not op_split[1].startswith("0x"):
                        continue

                    lui_val = int(op_split[1], 0)
                    if lui_val >= 0x8000:
                        for j in range(i + 1, min(i + hi_lo_max_distance, len(func))):
                            s_insn = func[j][0]

                            s_op_split = s_insn.op_str.split(", ")

                            if s_insn.mnemonic == "lui" and reg == s_op_split[0]:
                                break

                            if s_insn.mnemonic in ["addiu", "ori"]:
                                s_reg = s_op_split[-2]
                            else:
                                s_reg = s_op_split[-1][s_op_split[-1].rfind("(") + 1: -1]


                            if reg == s_reg:
                                if s_insn.mnemonic not in ["addiu", "lw", "sw", "lh", "sh", "lhu", "lb", "sb", "lbu", "lwc1", "swc1", "ldc1", "sdc1"]:
                                    break

                                # Match!
                                reg_ext = ""

                                junk_search = re.search(
                                    r"[\(]", s_op_split[-1])
                                if junk_search is not None:
                                    if junk_search.start() == 0:
                                        break
                                    s_str = s_op_split[-1][:junk_search.start()]
                                    reg_ext = s_op_split[-1][junk_search.start():]
                                else:
                                    s_str = s_op_split[-1]

                                symbol_addr = (lui_val * 0x10000) + int(s_str, 0)

                                sym = None
                                offset_str = ""

                                if symbol_addr > func_addr and symbol_addr < self.parent.vram_end and len(possible_jtbl_jumps) > 0 and func_end_addr - s_insn.address >= 0x30:
                                    for jump in possible_jtbl_jumps:
                                        if jump[1] == s_op_split[0]:
                                            dist_to_jump = possible_jtbl_jumps[0][0] - s_insn.address
                                            if dist_to_jump <= 16:
                                                sym = self.parent.get_symbol(symbol_addr, create=True, reference=True, type="jtbl", local_only=True)

                                                self.parent.jumptables[symbol_addr] = (func_addr, func_end_addr)
                                                break

                                if not sym:
                                    sym = self.parent.get_symbol(symbol_addr, create=True, offsets=True, reference=True)
                                    offset = symbol_addr - sym.vram_start
                                    if offset != 0:
                                        offset_str = f"+0x{offset:X}"

                                if self.parent:
                                    self.parent.check_rodata_sym(func_addr, sym)

                                self.update_access_mnemonic(sym, s_insn.mnemonic)

                                sym_label = sym.name + offset_str

                                func[i] += ("%hi({})".format(sym_label),)
                                func[j] += ("%lo({}){}".format(sym_label, reg_ext),)
                                break
            ret[func_addr] = func
        return ret

    def add_labels(self, funcs, addsuffix):
        ret = {}

        for func in funcs:
            func_text = []

            # Add function glabel
            rom_addr = funcs[func][0][3]
            sym = self.parent.get_symbol(func, type="func", create=True, define=True, local_only=True)
            func_text.append(f"glabel {sym.name}")

            indent_next = False

            mnemonic_ljust = options.get("mnemonic_ljust", 11)
            rom_addr_padding = options.get("rom_address_padding", None)

            for insn in funcs[func]:
                insn_addr = insn[0].address
                # Add a label if we need one
                if insn_addr in self.parent.jtbl_glabels_to_add:
                    func_text.append(f"glabel L{insn_addr:X}_{insn[3]:X}")
                elif insn_addr in self.parent.labels_to_add:
                    self.parent.labels_to_add.remove(insn_addr)
                    func_text.append(".L{:X}:".format(insn_addr))

                if rom_addr_padding:
                    rom_str = "{0:0{1}X}".format(insn[3], rom_addr_padding)
                else:
                    rom_str = "{:X}".format(insn[3])

                asm_comment = "/* {} {:X} {} */".format(rom_str, insn_addr, insn[0].bytes.hex().upper())

                if len(insn) > 4:
                    op_str = ", ".join(insn[2].split(", ")[:-1] + [insn[4]])
                else:
                    op_str = insn[2]

                if self.is_branch_insn(insn[0].mnemonic):
                    branch_addr = int(insn[0].op_str.split(",")[-1].strip(), 0)
                    if branch_addr in self.parent.jtbl_glabels_to_add:
                        label_str = f"L{branch_addr:X}_{self.ram_to_rom(branch_addr):X}"
                        op_str = ", ".join(insn[2].split(", ")[:-1] + [label_str])

                insn_text = insn[1]
                if indent_next:
                    indent_next = False
                    insn_text = " " + insn_text

                asm_insn_text = "  {}{}".format(insn_text.ljust(mnemonic_ljust), op_str).rstrip()

                func_text.append(asm_comment + asm_insn_text)

                if insn[0].mnemonic != "branch" and insn[0].mnemonic.startswith("b") or insn[0].mnemonic.startswith("j"):
                    indent_next = True
            
            if addsuffix:            
                func_text.append(f"endlabel {sym.name}")

            ret[func] = (func_text, rom_addr)

            if options.get("find_file_boundaries"):
                # If this is not the last function in the file
                if func != list(funcs.keys())[-1]:

                    # Find where the function returns
                    jr_pos: Optional[int] = None
                    for i, insn in enumerate(reversed(funcs[func])):
                        if insn[0].mnemonic == "jr" and insn[0].op_str == "$ra":
                            jr_pos = i
                            break

                    # If there is more than 1 nop after the return
                    if jr_pos is not None and jr_pos > 1 and self.is_nops([i[0] for i in funcs[func][-jr_pos + 1:]]):
                        new_file_addr = funcs[func][-1][3] + 4
                        if (new_file_addr % 16) == 0:
                            if not self.parent.reported_file_split:
                                self.parent.reported_file_split = True
                                print(f"Segment {self.name}, function at vram {func:X} ends with extra nops, indicating a likely file split.")
                                print("File split suggestions for this segment will follow in config yaml format:")
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

            while (rom_offset):
                word = rom_bytes[rom_offset : rom_offset + 4]
                word_int = int.from_bytes(word, "big")
                if word_int >= start and word_int <= end:
                    self.parent.jtbl_glabels_to_add.add(word_int)
                else:
                    break

                rom_offset += 4

    def should_scan(self) -> bool:
        return options.mode_active("code")
    
    def should_split(self) -> bool:
        return self.extract and options.mode_active("code")
