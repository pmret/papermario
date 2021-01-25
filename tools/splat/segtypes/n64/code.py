from re import split
from capstone import *
from capstone.mips import *

from collections import OrderedDict
from segtypes.n64.segment import N64Segment
import os
from pathlib import Path, PurePath
from ranges import Range, RangeDict
import re
import sys
from util import floats


STRIP_C_COMMENTS_RE = re.compile(
    r'//.*?$|/\*.*?\*/|\'(?:\\.|[^\\\'])*\'|"(?:\\.|[^\\"])*"',
    re.DOTALL | re.MULTILINE
)

C_FUNC_RE = re.compile(
    r"^(static\s+)?[^\s]+\s+([^\s(]+)\(([^;)]*)\)[^;]+?{",
    re.MULTILINE
)

def strip_c_comments(text):
    def replacer(match):
        s = match.group(0)
        if s.startswith("/"):
            return " "
        else:
            return s
    return re.sub(STRIP_C_COMMENTS_RE, replacer, text)


def get_funcs_defined_in_c(c_file):
    with open(c_file, "r") as f:
        text = strip_c_comments(f.read())

    return set(m.group(2) for m in C_FUNC_RE.finditer(text))


def parse_segment_files(segment, segment_class, seg_start, seg_end, seg_name, seg_vram):
    prefix = seg_name if seg_name.endswith("/") else f"{seg_name}_"

    ret = []
    prev_start = -1

    if "files" in segment:
        for i, split_file in enumerate(segment["files"]):
            if type(split_file) is dict:
                start = split_file["start"]
                end = split_file["end"]
                name = None if "name" not in split_file else split_file["name"]
                subtype = split_file["type"]
            else:
                start = split_file[0]
                end = seg_end if i == len(segment["files"]) - 1 else segment["files"][i + 1][0]
                name = None if len(split_file) < 3 else split_file[2]
                subtype = split_file[1]

            if start < prev_start:
                print(f"Error: Code segment {seg_name} has files out of ascending rom order (0x{prev_start:X} followed by 0x{start:X})")
                sys.exit(1)

            if not name:
                name = N64SegCode.get_default_name(start) if seg_name == N64SegCode.get_default_name(seg_start) else f"{prefix}{start:X}"

            vram = seg_vram + (start - seg_start)

            fl = {"start": start, "end": end, "name": name, "vram": vram, "subtype": subtype}

            ret.append(fl)
            prev_start = start
    else:
        fl = {"start": seg_start, "end": seg_end,
              "name": seg_name, "vram": seg_vram, "subtype": "asm"}
        ret.append(fl)

    return ret


class N64SegCode(N64Segment):
    def __init__(self, segment, next_segment, options):
        super().__init__(segment, next_segment, options)
        self.files = parse_segment_files(segment, self.__class__, self.rom_start, self.rom_end, self.name, self.vram_addr)
        self.is_overlay = segment.get("overlay", False)
        self.labels_to_add = set()
        self.jtbl_glabels = set()
        self.glabels_to_add = set()
        self.special_labels = {}
        self.undefined_syms_to_add = set()
        self.glabels_added = {}
        self.all_functions = {}
        self.provided_symbols = {}
        self.c_labels_to_add = set()
        self.ld_section_name = "." + segment.get("ld_name", f"text_{self.rom_start:X}")
        self.symbol_ranges = RangeDict()
        self.detected_syms = {}
        self.reported_file_split = False
        self.jtbl_jumps = {}
        self.jumptables = {}

    @staticmethod
    def get_default_name(addr):
        return f"code_{addr:X}"

    def get_func_name(self, addr):
        return self.provided_symbols.get(addr, f"func_{addr:X}")

    def get_unique_func_name(self, func_addr, rom_addr):
        func_name = self.get_func_name(func_addr)

        if self.is_overlay and (func_addr >= self.vram_addr) and (func_addr <= self.vram_addr + self.rom_end - self.rom_start):
            return func_name + "_{:X}".format(rom_addr)
        return func_name

    def add_glabel(self, ram_addr, rom_addr):
        func = self.get_unique_func_name(ram_addr, rom_addr)
        self.glabels_to_add.discard(func)
        self.glabels_added[ram_addr] = func
        if not self.is_overlay:
            self.all_functions[ram_addr] = func
        return "glabel " + func

    def get_asm_header(self):
        ret = []

        ret.append(".include \"macro.inc\"")
        ret.append("")
        ret.append("# assembler directives")
        ret.append(".set noat      # allow manual use of $at")
        ret.append(".set noreorder # don't insert nops after branches")
        ret.append(".set gp=64     # allow use of 64-bit general purpose registers")
        ret.append("")
        ret.append(".section .text, \"ax\"")
        ret.append("")

        return ret

    def get_gcc_inc_header(self):
        ret = []
        ret.append(".set noat      # allow manual use of $at")
        ret.append(".set noreorder # don't insert nops after branches")
        ret.append("")

        return ret

    @staticmethod
    def is_nops(insns):
        for insn in insns:
            if insn.mnemonic != "nop":
                return False
        return True

    @staticmethod
    def is_branch_insn(mnemonic):
        return (mnemonic.startswith("b") and not mnemonic.startswith("binsl") and not mnemonic == "break") or mnemonic == "j"

    def process_insns(self, insns, rom_addr):
        ret = OrderedDict()

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
                jump_func = self.get_func_name(jal_addr)
                if (
                    jump_func.startswith("func_")
                    and self.is_overlay
                    and jal_addr >= self.vram_addr
                    and jal_addr <= (self.vram_addr + self.rom_end - self.rom_start)
                ):
                    func_loc = self.rom_start + jal_addr - self.vram_addr
                    jump_func += "_{:X}".format(func_loc)

                if jump_func not in self.provided_symbols.values():
                    self.glabels_to_add.add(jump_func)
                op_str = jump_func
            elif self.is_branch_insn(insn.mnemonic):
                op_str_split = op_str.split(" ")
                branch_target = op_str_split[-1]
                branch_target_int = int(branch_target, 0)
                label = ""

                if branch_target_int in self.special_labels:
                    label = self.special_labels[branch_target_int]
                else:
                    self.labels_to_add.add(branch_target_int)
                    label = ".L" + branch_target[2:].upper()

                op_str = " ".join(op_str_split[:-1] + [label])
            elif mnemonic == "mtc0" or mnemonic == "mfc0":
                rd = (insn.bytes[2] & 0xF8) >> 3
                op_str = op_str.split(" ")[0] + " $" + str(rd)

            func.append((insn, mnemonic, op_str, rom_addr))
            rom_addr += 4

            if mnemonic == "jr":
                # Record potential jtbl jumps
                if op_str != "$ra":
                    self.jtbl_jumps[insn.address] = op_str

                keep_going = False
                for label in labels:
                    if (label[0] > insn.address and label[1] <= insn.address) or (label[0] <= insn.address and label[1] > insn.address):
                        keep_going = True
                        break
                if not keep_going:
                    end_func = True
                    continue

            if i < len(insns) - 1 and self.get_func_name(insns[i + 1].address) in self.c_labels_to_add:
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

    def get_file_for_addr(self, addr):
        for fl in self.files:
            if addr >= fl["vram"] and addr < fl["vram"] + fl["end"] - fl["start"]:
                return fl
        return None

    def store_symbol_access(self, addr, mnemonic):
        # Don't overwrite useful info with addiu
        if addr in self.detected_syms and self.detected_syms[addr] != "addiu":
            return

        self.detected_syms[addr] = mnemonic

    def get_symbol_name(self, addr, rom_addr, funcs=None):
        if funcs and addr in funcs:
            return self.get_unique_func_name(addr, rom_addr)
        if addr in self.all_functions:
            return self.all_functions[addr] # todo clean up funcs vs all_functions
        if addr in self.provided_symbols:
            return self.provided_symbols[addr]
        if addr in self.jumptables:
            return f"jtbl_{addr:X}_{rom_addr:X}"
        if addr in self.symbol_ranges:
            ret = self.symbol_ranges.get(addr)
            offset = addr - self.symbol_ranges.getrange(addr).start
            if offset != 0:
                ret += f"+0x{offset:X}"
            return ret

        return f"D_{addr:X}"

    # Determine symbols
    def determine_symbols(self, funcs, rom_addr):
        ret = {}

        for func_addr in funcs:
            func = funcs[func_addr]
            func_end_addr = func[-1][0].address + 4

            possible_jtbl_jumps = [(k, v) for k, v in self.jtbl_jumps.items() if k >= func_addr and k < func_end_addr]
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
                        for j in range(i + 1, min(i + 6, len(func))):
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
                                symbol_name = self.get_symbol_name(symbol_addr, symbol_addr - next(iter(funcs)) + rom_addr, funcs)
                                symbol_tag = s_insn.mnemonic

                                vram_end = self.vram_addr + self.rom_end - self.rom_start
                                if symbol_addr > func_addr and symbol_addr < vram_end and len(possible_jtbl_jumps) > 0 and func_end_addr - s_insn.address >= 0x30:
                                    for jump in possible_jtbl_jumps:
                                        if jump[1] == s_op_split[0]:
                                            dist_to_jump = possible_jtbl_jumps[0][0] - s_insn.address
                                            if dist_to_jump <= 16:
                                                symbol_name = f"jtbl_{symbol_addr:X}_{self.ram_to_rom(symbol_addr):X}"
                                                symbol_tag = "jtbl"
                                                self.jumptables[symbol_addr] = (func_addr, func_end_addr)
                                                break

                                self.store_symbol_access(symbol_addr, symbol_tag)
                                symbol_file = self.get_file_for_addr(symbol_addr)

                                if not symbol_file or symbol_file["subtype"] == "bin":
                                    if "+" not in symbol_name:
                                        self.undefined_syms_to_add.add((symbol_name, symbol_addr))

                                func[i] += ("%hi({})".format(symbol_name),)
                                func[j] += ("%lo({}){}".format(symbol_name, reg_ext),)
                                break
            ret[func_addr] = func
        return ret

    def add_labels(self, funcs):
        ret = {}

        for func in funcs:
            func_text = []

            # Add function glabel
            rom_addr = funcs[func][0][3]
            func_text.append(self.add_glabel(func, rom_addr))

            indent_next = False

            mnemonic_ljust = self.options.get("mnemonic_ljust", 11)
            rom_addr_padding = self.options.get("rom_address_padding", None)

            for insn in funcs[func]:
                insn_addr = insn[0].address
                # Add a label if we need one
                if insn_addr in self.labels_to_add:
                    self.labels_to_add.remove(insn_addr)
                    func_text.append(".L{:X}:".format(insn_addr))
                if insn_addr in self.jtbl_glabels:
                    func_text.append(f"glabel L{insn_addr:X}_{insn[3]:X}")

                if rom_addr_padding:
                    rom_str = "{0:0{1}X}".format(insn[3], rom_addr_padding)
                else:
                    rom_str = "{:X}".format(insn[3])

                asm_comment = "/* {} {:X} {} */".format(rom_str, insn_addr, insn[0].bytes.hex().upper())

                if len(insn) > 4:
                    op_str = ", ".join(insn[2].split(", ")[:-1] + [insn[4]])
                else:
                    op_str = insn[2]

                insn_text = insn[1]
                if indent_next:
                    indent_next = False
                    insn_text = " " + insn_text

                asm_insn_text = "  {}{}".format(insn_text.ljust(mnemonic_ljust), op_str).rstrip()

                func_text.append(asm_comment + asm_insn_text)

                if insn[0].mnemonic != "branch" and insn[0].mnemonic.startswith("b") or insn[0].mnemonic.startswith("j"):
                    indent_next = True

            ret[func] = (func_text, rom_addr)

            if self.options.get("find_file_boundaries"):
                # If this is not the last function in the file
                if func != list(funcs.keys())[-1]:

                    # Find where the function returns
                    jr_pos = None
                    for i, insn in enumerate(reversed(funcs[func])):
                        if insn[0].mnemonic == "jr" and insn[0].op_str == "$ra":
                            jr_pos = i
                            break

                    # If there is more than 1 nop after the return
                    if jr_pos and jr_pos > 1 and self.is_nops([i[0] for i in funcs[func][-jr_pos + 1:]]):
                        new_file_addr = funcs[func][-1][3] + 4
                        if (new_file_addr % 16) == 0:
                            if not self.reported_file_split:
                                self.reported_file_split = True
                                print(f"Segment {self.name}, function at vram {func:X} ends with extra nops, indicating a likely file split.")
                                print("File split suggestions for this segment will follow in config yaml format:")
                            print(f"      - [0x{new_file_addr:X}, asm]")

        return ret

    def should_run(self):
        possible_subtypes = ["c", "asm", "hasm", "bin", "data", "rodata"]
        subtypes = set(f["subtype"] for f in self.files)

        return super().should_run() or (st in self.options["modes"] and st in subtypes for st in possible_subtypes)

    def is_valid_ascii(self, bytes):
        if len(bytes) < 8:
            return False

        num_empty_bytes = 0
        for b in bytes:
            if b == 0:
                num_empty_bytes += 1

        empty_ratio = num_empty_bytes / len(bytes)
        if empty_ratio > 0.2:
            return False

        return True

    def get_symbols_for_file(self, split_file):
        vram_start = split_file["vram"]
        vram_end = split_file["vram"] + split_file["end"] - split_file["start"]

        return [(s, self.detected_syms[s]) for s in self.detected_syms if s >= vram_start and s <= vram_end]

    def disassemble_symbol(self, sym_bytes, sym_type):
        if sym_type == "jtbl":
            sym_str = ".word "
        else:
            sym_str = f".{sym_type} "

        if sym_type == "double":
            slen = 8
        elif sym_type in ["float", "word", "jtbl"]:
            slen = 4
        elif sym_type == "short":
            slen = 2
        else:
            slen = 1

        i = 0
        while i < len(sym_bytes):
            adv_amt = min(slen, len(sym_bytes) - i)
            bits = int.from_bytes(sym_bytes[i : i + adv_amt], "big")

            if sym_type == "jtbl":
                if bits == 0:
                    byte_str = "0"
                else:
                    rom_addr = self.ram_to_rom(bits)

                    if rom_addr:
                        byte_str = f"L{bits:X}_{rom_addr:X}"
                    else:
                        byte_str = f"0x{bits:X}"
            else:
                byte_str = self.provided_symbols.get(bits, '0x{0:0{1}X}'.format(bits, 2 * slen))

            if sym_type in ["float", "double"]:
                if sym_type == "float":
                    float_str = floats.format_f32_imm(bits)
                else:
                    float_str = floats.format_f64_imm(bits)

                # Fall back to .word if we see weird float values
                # todo cut the symbol in half maybe where we see the first nan or something
                if "e-" in float_str or "nan" in float_str:
                    return self.disassemble_symbol(sym_bytes, "word")
                else:
                    byte_str = float_str

            sym_str += byte_str

            i += adv_amt

            if i < len(sym_bytes):
                sym_str += ", "

        return sym_str

    def disassemble_data(self, split_file, rom_bytes):
        rodata_encountered = split_file["subtype"] == "rodata"
        ret = ".include \"macro.inc\"\n\n"
        ret += f'.section .{split_file["subtype"]}'

        syms = self.get_symbols_for_file(split_file)
        syms.sort(key=lambda x:x[0])

        if len(syms) == 0:
            self.warn("No symbol accesses detected for " + split_file["name"] + "; the output will most likely be an ugly blob")

        # check beginning
        if syms[0][0] != split_file["vram"]:
            syms.insert(0, (split_file["vram"], None))

        # add end
        vram_end = split_file["vram"] + split_file["end"] - split_file["start"]
        if syms[-1][0] != vram_end:
            syms.append((vram_end, None))

        for i in range(len(syms) - 1):
            mnemonic = syms[i][1]
            start = syms[i][0]
            end = syms[i + 1][0]
            sym_rom_start = start - split_file["vram"] + split_file["start"]
            sym_rom_end = end - split_file["vram"] + split_file["start"]
            sym_name = self.get_symbol_name(start, sym_rom_start)
            sym_str = f"\n\nglabel {sym_name}\n"
            sym_bytes = rom_bytes[sym_rom_start : sym_rom_end]

            # .ascii
            if self.is_valid_ascii(sym_bytes) and mnemonic == "addiu":
            # mnemonic thing may be too picky, we'll see
                try:
                    ascii_str = sym_bytes.decode("EUC-JP")
                    ascii_str = ascii_str.replace("\\", "\\\\")
                    ascii_str = ascii_str.replace("\x00", "\\0")
                    sym_str += f'.ascii "{ascii_str}"'
                    ret += sym_str
                    continue
                except:
                    pass

            # Fallback to raw data
            if mnemonic == "jtbl":
                stype = "jtbl"
            elif len(sym_bytes) % 8 == 0 and mnemonic in ["ldc1", "sdc1"]:
                stype = "double"
            elif len(sym_bytes) % 4 == 0 and mnemonic in ["addiu", "sw", "lw", "jtbl"]:
                stype = "word"
            elif len(sym_bytes) % 4 == 0 and mnemonic in ["lwc1", "swc1"]:
                stype = "float"
            elif len(sym_bytes) % 2 == 0 and mnemonic in ["addiu", "lh", "sh", "lhu"]:
                stype = "short"
            else:
                stype = "byte"
            
            if not rodata_encountered and mnemonic == "jtbl":
                rodata_encountered = True
                ret += "\n\n\n.section .rodata"

            sym_str += self.disassemble_symbol(sym_bytes, stype)
            ret += sym_str

        ret += "\n"

        return ret

    def get_c_preamble(self):
        ret = []

        preamble = self.options.get("generated_c_preamble", "#include \"common.h\"")
        ret.append(preamble)
        ret.append("")

        return ret

    def gather_jumptable_labels(self, section_vram, section_rom, rom_bytes):
        for jumptable in self.jumptables:
            start, end = self.jumptables[jumptable]
            rom_offset = section_rom + jumptable - section_vram

            if rom_offset <= 0:
                return

            while (rom_offset):
                word = rom_bytes[rom_offset : rom_offset + 4]
                word_int = int.from_bytes(word, "big")
                if word_int >= start and word_int <= end:
                    self.jtbl_glabels.add(word_int)
                else:
                    break

                rom_offset += 4


    def split(self, rom_bytes, base_path):
        md = Cs(CS_ARCH_MIPS, CS_MODE_MIPS64 + CS_MODE_BIG_ENDIAN)
        md.detail = True
        md.skipdata = True

        for split_file in self.files:
            file_type = split_file["subtype"]

            if file_type in ["asm", "hasm", "c"]:
                if self.type not in self.options["modes"] and "all" not in self.options["modes"]:
                    continue

                if split_file["start"] == split_file["end"]:
                    continue

                out_dir = self.create_split_dir(base_path, "asm")

                rom_addr = split_file["start"]

                insns = [insn for insn in md.disasm(rom_bytes[split_file["start"]: split_file["end"]], split_file["vram"])]

                funcs = self.process_insns(insns, rom_addr)
                funcs = self.determine_symbols(funcs, rom_addr)
                self.gather_jumptable_labels(self.vram_addr, self.rom_start, rom_bytes)
                funcs_text = self.add_labels(funcs)

                if file_type == "c":
                    c_path = os.path.join(
                        base_path, "src", split_file["name"] + "." + self.get_ext(split_file["subtype"]))

                    if os.path.exists(c_path):
                        defined_funcs = get_funcs_defined_in_c(c_path)
                    else:
                        defined_funcs = set()

                    out_dir = self.create_split_dir(
                        base_path, os.path.join("asm", "nonmatchings"))

                    for func in funcs_text:
                        func_name = self.get_unique_func_name(
                            func, funcs_text[func][1])

                        if func_name not in defined_funcs:
                            if self.options.get("compiler", "IDO") == "GCC":
                                out_lines = self.get_gcc_inc_header()
                            else:
                                out_lines = []
                            out_lines.extend(funcs_text[func][0])
                            out_lines.append("")

                            outpath = Path(os.path.join(
                                out_dir, split_file["name"], func_name + ".s"))
                            outpath.parent.mkdir(parents=True, exist_ok=True)

                            with open(outpath, "w", newline="\n") as f:
                                f.write("\n".join(out_lines))
                            self.log(f"Disassembled {func_name} to {outpath}")

                    # Creation of c files
                    if not os.path.exists(c_path):  # and some option is enabled
                        c_lines = self.get_c_preamble()

                        for func in funcs_text:
                            func_name = self.get_unique_func_name(func, funcs_text[func][1])
                            if self.options.get("compiler", "IDO") == "GCC":
                                c_lines.append("INCLUDE_ASM(s32, \"{}\", {});".format(split_file["name"], func_name))
                            else:
                                outpath = Path(os.path.join(out_dir, split_file["name"], func_name + ".s"))
                                rel_outpath = os.path.relpath(outpath, base_path)
                                c_lines.append(f"#pragma GLOBAL_ASM(\"{rel_outpath}\")")
                            c_lines.append("")

                        Path(c_path).parent.mkdir(parents=True, exist_ok=True)
                        with open(c_path, "w") as f:
                            f.write("\n".join(c_lines))
                        print(f"Wrote {split_file['name']} to {c_path}")

                else:
                    out_lines = self.get_asm_header()
                    for func in funcs_text:
                        out_lines.extend(funcs_text[func][0])
                        out_lines.append("")

                    outpath = Path(os.path.join(out_dir, split_file["name"] + ".s"))
                    outpath.parent.mkdir(parents=True, exist_ok=True)

                    with open(outpath, "w", newline="\n") as f:
                        f.write("\n".join(out_lines))

            elif file_type in ["data", "rodata"] and (file_type in self.options["modes"] or "all" in self.options["modes"]):
                out_dir = self.create_split_dir(base_path, os.path.join("asm", "data"))

                outpath = Path(os.path.join(out_dir, split_file["name"] + f".{file_type}.s"))
                outpath.parent.mkdir(parents=True, exist_ok=True)

                file_text = self.disassemble_data(split_file, rom_bytes)
                if file_text:
                    with open(outpath, "w", newline="\n") as f:
                        f.write(file_text)

            elif file_type == "bin" and ("bin" in self.options["modes"] or "all" in self.options["modes"]):
                out_dir = self.create_split_dir(base_path, "bin")

                bin_path = os.path.join(
                    out_dir, split_file["name"] + "." + self.get_ext(split_file["subtype"]))
                Path(bin_path).parent.mkdir(parents=True, exist_ok=True)
                with open(bin_path, "wb") as f:
                    f.write(rom_bytes[split_file["start"]: split_file["end"]])

    @staticmethod
    def get_subdir(subtype):
        if subtype in ["c", ".data", ".rodata", ".bss"]:
            return "src"
        elif subtype in ["asm", "hasm", "header"]:
            return "asm"
        return subtype

    @staticmethod
    def get_ext(subtype):
        if subtype in ["c", ".data", ".rodata", ".bss"]:
            return "c"
        elif subtype in ["asm", "hasm", "header"]:
            return "s"
        elif subtype == "bin":
            return "bin"
        return subtype

    @staticmethod
    def get_ld_obj_type(subtype, section_name):
        if subtype in "c":
            return ".text"
        elif subtype in ["bin", ".data", "data"]:
            return ".data"
        elif subtype in [".rodata", "rodata"]:
            return ".rodata"
        elif subtype == ".bss":
            return ".bss"
        return section_name

    def get_ld_files(self):
        def transform(split_file):
            subdir = self.get_subdir(split_file["subtype"])
            obj_type = self.get_ld_obj_type(split_file["subtype"], ".text")
            ext = self.get_ext(split_file['subtype'])
            start = split_file["start"]

            return subdir, f"{split_file['name']}.{ext}", obj_type, start

        return [transform(file) for file in self.files]

    def get_ld_section_name(self):
        path = PurePath(self.name)
        name = path.name if path.name != "" else path.parent

        return f"code_{name}"
