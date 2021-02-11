from capstone import *
from capstone.mips import *

from collections import OrderedDict
from segtypes.n64.segment import N64Segment
from segtypes.segment import Segment
from segtypes.n64.palette import N64SegPalette
from segtypes.n64.ci4 import N64SegCi4
import png
import os
from pathlib import Path, PurePath
import re
import sys
from util import floats
from util.symbol import Symbol

double_mnemonics = ["ldc1", "sdc1"]
word_mnemonics = ["addiu", "sw", "lw", "jtbl"]
float_mnemonics = ["lwc1", "swc1"]
short_mnemonics = ["addiu", "lh", "sh", "lhu"]
byte_mnemonics = ["lb", "sb", "lbu"]

class Subsegment():
    def __init__(self, start, end, name, type, vram, args):
        self.rom_start = start
        self.rom_end = end
        self.size = self.rom_end - self.rom_start
        self.name = name
        self.vram_start = vram
        self.vram_end = vram + self.size
        self.type = type
        self.args = args

        # TODO maybe move to a better place
        if self.type in [".bss", "bss"]:
            self.rom_start = 0
            self.rom_end = 0
            self.size = self.args[0]
            self.vram_end = self.vram_start + self.size

    def contains_vram(self, addr):
        return self.vram_start <= addr < self.vram_end

    def get_out_subdir(self, options):
        if self.type in ["c", ".data", ".rodata", ".bss"]:
            return "src"
        elif self.type in ["asm", "hasm", "header"]:
            return "asm"
        elif self.type == "bin":
            return options.get("assets_dir", "bin")
        elif self.type in ["i4", "i8", "ia4", "ia8", "ia16", "rgba16", "rgba32", "ci4", "ci8", "palette"]:
            return options.get("assets_dir", "img")
        return self.type

    def get_ld_obj_type(self, section_name):
        if self.type in "c":
            return ".text"
        elif self.type in ["bin", ".data", "data", "i4", "i8", "ia4", "ia8", "ia16", "rgba16", "rgba32", "ci4", "ci8", "palette"]:
            return ".data"
        elif self.type in [".rodata", "rodata"]:
            return ".rodata"
        elif self.type in [".bss", "bss"]:
            return ".bss"
        return section_name

    def get_ext(self):
        if self.type in ["c", ".data", ".rodata", ".bss"]:
            return "c"
        elif self.type in ["asm", "hasm", "header"]:
            return "s"
        elif self.type == "bin":
            return "bin"
        elif self.type in ["i4", "i8", "ia4", "ia8", "ia16", "rgba16", "rgba32", "ci4", "ci8"]:
            return "png"
        elif self.type == "palette":
            return "pal.png"
        return self.type

    def should_run(self, options):
        return self.type in options["modes"] or "all" in options["modes"]

    def get_generic_out_path(self, base_path, options):
        return os.path.join(
            base_path,
            self.get_out_subdir(options),
            self.name + "." + self.get_ext()
        )

    def split_inner(self, segment, rom_bytes, base_path, generic_out_path):
        pass

    def split(self, segment, rom_bytes, base_path):
        if self.should_run(segment.options) and not self.name.startswith("."):
            self.split_inner(segment, rom_bytes, base_path, self.get_generic_out_path(base_path, segment.options))

    @staticmethod
    def get_subclass(typ):
        if typ in ["data", ".data", "rodata", ".rodata"]:
            return DataSubsegment
        elif typ in ["bss", ".bss"]:
            return BssSubsegment
        elif typ == "bin":
            return BinSubsegment
        elif typ in ["c", "asm", "hasm"]:
            return CodeSubsegment
        elif typ == "palette":
            return PaletteSubsegment
        else:
            return Subsegment

class CodeSubsegment(Subsegment):
    md = Cs(CS_ARCH_MIPS, CS_MODE_MIPS64 + CS_MODE_BIG_ENDIAN)
    md.detail = True
    md.skipdata = True

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
        return re.sub(CodeSubsegment.STRIP_C_COMMENTS_RE, replacer, text)

    @staticmethod
    def get_funcs_defined_in_c(c_file):
        with open(c_file, "r") as f:
            text = CodeSubsegment.strip_c_comments(f.read())

        return set(m.group(2) for m in CodeSubsegment.C_FUNC_RE.finditer(text))

    @staticmethod
    def get_asm_header():
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

    def split_inner(self, segment, rom_bytes, base_path, generic_out_path):
        if not self.rom_start == self.rom_end:
            asm_out_dir = Segment.create_split_dir(base_path, "asm")

            rom_addr = self.rom_start

            insns = [insn for insn in CodeSubsegment.md.disasm(rom_bytes[self.rom_start : self.rom_end], self.vram_start)]

            funcs = segment.process_insns(insns, rom_addr)

            # TODO: someday make func a subclass of symbol and store this disasm info there too
            for func in funcs:
                segment.get_symbol(func, type="func", create=True, define=True, local_only=True)

            funcs = segment.determine_symbols(funcs)
            segment.gather_jumptable_labels(rom_bytes)
            funcs_text = segment.add_labels(funcs)

            if self.type == "c":
                if os.path.exists(generic_out_path):
                    defined_funcs = CodeSubsegment.get_funcs_defined_in_c(generic_out_path)
                    segment.mark_c_funcs_as_defined(defined_funcs)
                else:
                    defined_funcs = set()

                asm_out_dir = Segment.create_split_dir(base_path, os.path.join("asm", "nonmatchings"))

                for func in funcs_text:
                    func_name = segment.get_symbol(func, type="func", local_only=True).name

                    if func_name not in defined_funcs:
                        segment.create_c_asm_file(funcs_text, func, asm_out_dir, self, func_name)

                if not os.path.exists(generic_out_path) and segment.options.get("create_new_c_files", True):
                    segment.create_c_file(funcs_text, self, asm_out_dir, base_path, generic_out_path)
            else:
                out_lines = self.get_asm_header()
                for func in funcs_text:
                    out_lines.extend(funcs_text[func][0])
                    out_lines.append("")

                outpath = Path(os.path.join(asm_out_dir, self.name + ".s"))
                outpath.parent.mkdir(parents=True, exist_ok=True)

                with open(outpath, "w", newline="\n") as f:
                    f.write("\n".join(out_lines))

class DataSubsegment(Subsegment):
    def split_inner(self, segment, rom_bytes, base_path, generic_out_path):
        if not self.type.startswith("."):
            asm_out_dir = Segment.create_split_dir(base_path, os.path.join("asm", "data"))

            outpath = Path(os.path.join(asm_out_dir, self.name + f".{self.type}.s"))
            outpath.parent.mkdir(parents=True, exist_ok=True)

            file_text = segment.disassemble_data(self, rom_bytes)
            if file_text:
                with open(outpath, "w", newline="\n") as f:
                    f.write(file_text)

class BssSubsegment(DataSubsegment):
    def __init__(self, start, end, name, type, vram, args):
        super().__init__(start, end, name, type, vram, args)
        self.size = self.args[0]
        self.vram_end = self.vram_start + self.size

class BinSubsegment(Subsegment):
    def split_inner(self, segment, rom_bytes, base_path, generic_out_path):
        Path(generic_out_path).parent.mkdir(parents=True, exist_ok=True)
        with open(generic_out_path, "wb") as f:
            f.write(rom_bytes[self.rom_start : self.rom_end])

class PaletteSubsegment(Subsegment):
    def should_run(self, options):
        return super().should_run(options) or "img" in options["modes"]

    def split_inner(self, segment, rom_bytes, base_path, generic_out_path):
        img_bytes = rom_bytes[self.rom_start : self.rom_end]

        palette = N64SegPalette.parse_palette(img_bytes)
        segment.palettes[self.name] = palette

class N64SegCode(N64Segment):
    palettes = {}

    def parse_subsegments(self, segment_yaml):
        prefix = self.name if self.name.endswith("/") else f"{self.name}_"

        ret = []
        prev_start = -1

        if "subsections" not in segment_yaml:
            print(f"Error: Code segment {self.name} is missing a 'subsections' field")
            sys.exit(2)

        for i, subsection_yaml in enumerate(segment_yaml["subsections"]):
            if type(subsection_yaml) is dict:
                start = subsection_yaml["start"]
                end = subsection_yaml["end"]
                name = subsection_yaml.get("name", None)
                typ = subsection_yaml["type"]
                args = subsection_yaml.get("args", [])
            else:
                start = subsection_yaml[0]
                end = self.rom_end if i == len(segment_yaml["subsections"]) - 1 else segment_yaml["subsections"][i + 1][0]
                name = None if len(subsection_yaml) < 3 else subsection_yaml[2]
                typ = subsection_yaml[1]
                args = subsection_yaml[3:]

            if start < prev_start:
                print(f"Error: Code segment {self.name} contains subsections which are out of ascending rom order (0x{prev_start:X} followed by 0x{start:X})")
                sys.exit(1)

            if not name:
                name = self.get_default_name(start) if self.name == self.get_default_name(self.rom_start) else f"{prefix}{start:X}"
            elif self.name.endswith("/"):
                name = self.name + name

            vram = self.rom_to_ram(start)

            subsegment_class = Subsegment.get_subclass(typ)

            ret.append(subsegment_class(start, end, name, typ, vram, args))
            prev_start = start

        return ret

    def __init__(self, segment, next_segment, options):
        super().__init__(segment, next_segment, options)
        self.subsegments = self.parse_subsegments(segment)
        self.is_overlay = segment.get("overlay", False)
        self.all_symbols = ()
        self.seg_symbols = {} # Symbols known to be in this segment
        self.ext_symbols = {} # Symbols not in this segment but also not from other overlapping ram address ranges
        self.symbol_ranges = []

        self.reported_file_split = False
        self.labels_to_add = set()
        self.jtbl_glabels_to_add = set()
        self.jtbl_jumps = {}
        self.jumptables = {}

    @staticmethod
    def get_default_name(addr):
        return f"code_{addr:X}"

    def get_ld_files(self):
        def transform(sub):
            subdir = sub.get_out_subdir(self.options)
            obj_type = sub.get_ld_obj_type(".text")
            ext = sub.get_ext()

            return subdir, f"{sub.name}.{ext}", obj_type, sub.rom_start

        return [transform(file) for file in self.subsegments]

    def get_ld_section_name(self):
        path = PurePath(self.name)
        name = path.name if path.name != "" else path.parent

        return f"code_{name}"

    def retrieve_symbol(self, d, k, t):
        if k not in d:
            return None

        if t:
            items = [s for s in d[k] if s.type == t or s.type == "unknown"]
        else:
            items = d[k]

        if len(items) > 1:
            pass #print(f"Trying to retrieve {k:X} from symbol dict but there are {len(items)} entries to pick from - picking the first")
        if len(items) == 0:
            return None
        return items[0]

    def retrieve_symbol_from_ranges(self, vram, rom=None):
        rom_matches = []
        ram_matches = []

        for symbol in self.symbol_ranges:
            if symbol.contains_vram(vram):
                if symbol.rom and rom and symbol.contains_rom(rom):
                    rom_matches.append(symbol)
                else:
                    ram_matches.append(symbol)

        ret = rom_matches + ram_matches

        if len(ret) > 0:
            return ret[0]
        else:
            return None

    def get_symbol(self, addr, type=None, create=False, define=False, reference=False, offsets=False, local_only=False):
        ret = None
        rom = None

        in_segment = self.contains_vram(addr)

        if in_segment:
            # If the vram address is within this segment, we can calculate the symbol's rom address
            rom = self.ram_to_rom(addr)
            ret = self.retrieve_symbol(self.seg_symbols, addr, type)
        elif not local_only:
            ret = self.retrieve_symbol(self.ext_symbols, addr, type)

        # Search for symbol ranges
        if not ret and offsets:
            ret = self.retrieve_symbol_from_ranges(addr, rom)

        # Create the symbol if it doesn't exist
        if not ret and create:
            ret = Symbol(addr, rom=rom, type=type)
            self.all_symbols.append(ret)

            if in_segment:
                if self.is_overlay:
                    ret.set_in_overlay()
                if addr not in self.seg_symbols:
                    self.seg_symbols[addr] = []
                self.seg_symbols[addr].append(ret)
            elif not local_only:
                if addr not in self.ext_symbols:
                    self.ext_symbols[addr] = []
                self.ext_symbols[addr].append(ret)

        if ret:
            if define:
                ret.defined = True
            if reference:
                ret.referenced = True

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
                jump_func = self.get_symbol(jal_addr, type="func", create=True, reference=True)
                op_str = jump_func.name
            elif self.is_branch_insn(insn.mnemonic):
                op_str_split = op_str.split(" ")
                branch_target = op_str_split[-1]
                branch_target_int = int(branch_target, 0)
                label = ""

                label = self.get_symbol(branch_target_int, type="label", reference=True, local_only=True)

                if label:
                    label_name = label.name
                else:
                    self.labels_to_add.add(branch_target_int)
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
                    self.jtbl_jumps[insn.address] = op_str

                keep_going = False
                for label in labels:
                    if (label[0] > insn.address and label[1] <= insn.address) or (label[0] <= insn.address and label[1] > insn.address):
                        keep_going = True
                        break
                if not keep_going:
                    end_func = True
                    continue

            if i < len(insns) - 1 and self.get_symbol(insns[i + 1].address, local_only=True, type="func"):
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
        for sub in self.subsegments:
            if sub.contains_vram(addr):
                return sub
        return None

    def update_access_mnemonic(self, sym, mnemonic):
        if not sym.access_mnemonic:
            sym.access_mnemonic = mnemonic
        elif sym.access_mnemonic == "addiu":
            sym.access_mnemonic = mnemonic
        elif sym.access_mnemonic in double_mnemonics:
            return
        elif sym.access_mnemonic in float_mnemonics and mnemonic in double_mnemonics:
            sym.access_mnemonic = mnemonic
        elif sym.access_mnemonic in short_mnemonics:
            return
        elif sym.access_mnemonic in byte_mnemonics:
            return
        else:
            sym.access_mnemonic = mnemonic

    # Determine symbols
    def determine_symbols(self, funcs):
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

                                sym = None
                                offset_str = ""

                                if symbol_addr > func_addr and symbol_addr < self.vram_end and len(possible_jtbl_jumps) > 0 and func_end_addr - s_insn.address >= 0x30:
                                    for jump in possible_jtbl_jumps:
                                        if jump[1] == s_op_split[0]:
                                            dist_to_jump = possible_jtbl_jumps[0][0] - s_insn.address
                                            if dist_to_jump <= 16:
                                                sym = self.get_symbol(symbol_addr, create=True, reference=True, type="jtbl", local_only=True)
                                                self.jumptables[symbol_addr] = (func_addr, func_end_addr)
                                                break

                                if not sym:
                                    sym = self.get_symbol(symbol_addr, create=True, offsets=True, reference=True)
                                    offset = symbol_addr - sym.vram_start
                                    if offset != 0:
                                        offset_str = f"+0x{offset:X}"

                                self.update_access_mnemonic(sym, s_insn.mnemonic)

                                sym_label = sym.name + offset_str

                                func[i] += ("%hi({})".format(sym_label),)
                                func[j] += ("%lo({}){}".format(sym_label, reg_ext),)
                                break
            ret[func_addr] = func
        return ret

    def add_labels(self, funcs):
        ret = {}

        for func in funcs:
            func_text = []

            # Add function glabel
            rom_addr = funcs[func][0][3]
            sym = self.get_symbol(func, type="func", create=True, define=True, local_only=True)
            func_text.append(f"glabel {sym.name}")

            indent_next = False

            mnemonic_ljust = self.options.get("mnemonic_ljust", 11)
            rom_addr_padding = self.options.get("rom_address_padding", None)

            for insn in funcs[func]:
                insn_addr = insn[0].address
                # Add a label if we need one
                if insn_addr in self.labels_to_add:
                    self.labels_to_add.remove(insn_addr)
                    func_text.append(".L{:X}:".format(insn_addr))
                if insn_addr in self.jtbl_glabels_to_add:
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
        return True

    @staticmethod
    def is_valid_ascii(bytes):
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

    def get_symbols_for_file(self, sub):
        ret = []

        for symbol_addr in self.seg_symbols:
            for symbol in self.seg_symbols[symbol_addr]:
                if sub.contains_vram(symbol.vram_start):
                    ret.append(symbol)

        ret.sort(key=lambda s:s.vram_start)

        # Ensure we start at the beginning
        if len(ret) == 0 or ret[0].vram_start != sub.vram_start:
            ret.insert(0, self.get_symbol(sub.vram_start, create=True, define=True, local_only=True))

        # Make a dummy symbol here that marks the end of the previous symbol's disasm range
        ret.append(Symbol(sub.vram_end))

        return ret

    def disassemble_symbol(self, sym_bytes, sym_type):
        if sym_type == "jtbl":
            sym_str = ".word "
        else:
            sym_str = f".{sym_type} "

        if sym_type == "double":
            slen = 8
        elif sym_type == "short":
            slen = 2
        elif sym_type == "byte":
            slen = 1
        else:
            slen = 4

        if sym_type == "ascii":
            try:
                ascii_str = sym_bytes.decode("EUC-JP")
                ascii_str = ascii_str.replace("\\", "\\\\")
                ascii_str = ascii_str.replace("\x00", "\\0")
                sym_str += f'"{ascii_str}"'
                return sym_str
            except:
                return self.disassemble_symbol(sym_bytes, "word")

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
            elif slen == 4 and bits >= 0x80000000:
                sym = self.get_symbol(bits, reference=True)
                if sym:
                    byte_str = sym.name
                else:
                    byte_str = '0x{0:0{1}X}'.format(bits, 2 * slen)
            else:
                byte_str = '0x{0:0{1}X}'.format(bits, 2 * slen)

            if sym_type in ["float", "double"]:
                if sym_type == "float":
                    float_str = floats.format_f32_imm(bits)
                else:
                    float_str = floats.format_f64_imm(bits)

                # Fall back to .word if we see weird float values
                # TODO: cut the symbol in half maybe where we see the first nan or something
                if "e-" in float_str or "nan" in float_str:
                    return self.disassemble_symbol(sym_bytes, "word")
                else:
                    byte_str = float_str

            sym_str += byte_str

            i += adv_amt

            if i < len(sym_bytes):
                sym_str += ", "

        return sym_str

    def disassemble_data(self, sub, rom_bytes):
        rodata_encountered = sub.type == "rodata"
        ret = ".include \"macro.inc\"\n\n"
        ret += f'.section .{sub.type}'

        if sub.size == 0:
            return None

        syms = self.get_symbols_for_file(sub)

        for i in range(len(syms) - 1):
            mnemonic = syms[i].access_mnemonic
            sym = self.get_symbol(syms[i].vram_start, create=True, define=True, local_only=True)
            sym_str = f"\n\nglabel {sym.name}\n"
            dis_start = self.ram_to_rom(syms[i].vram_start)
            dis_end = self.ram_to_rom(syms[i + 1].vram_start)

            if sub.type == "bss":
                sym_len = dis_end - dis_start
                ret += f".space 0x{sym_len:X}"
            else:
                sym_bytes = rom_bytes[dis_start : dis_end]

                # Checking if the mnemonic is addiu may be too picky - we'll see
                if self.is_valid_ascii(sym_bytes) and mnemonic == "addiu":
                    stype = "ascii"
                elif syms[i].type == "jtbl":
                    stype = "jtbl"
                elif len(sym_bytes) % 8 == 0 and mnemonic in double_mnemonics:
                    stype = "double"
                elif len(sym_bytes) % 4 == 0 and mnemonic in float_mnemonics:
                    stype = "float"
                elif len(sym_bytes) % 4 == 0 and mnemonic in word_mnemonics or not mnemonic:
                    stype = "word"
                elif len(sym_bytes) % 2 == 0 and mnemonic in short_mnemonics:
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

    def gather_jumptable_labels(self, rom_bytes):
        # TODO: use the seg_symbols for this
        # jumptables = [j.type == "jtbl" for j in self.seg_symbols]
        for jumptable in self.jumptables:
            start, end = self.jumptables[jumptable]
            rom_offset = self.rom_start + jumptable - self.vram_start

            if rom_offset <= 0:
                return

            while (rom_offset):
                word = rom_bytes[rom_offset : rom_offset + 4]
                word_int = int.from_bytes(word, "big")
                if word_int >= start and word_int <= end:
                    self.jtbl_glabels_to_add.add(word_int)
                else:
                    break

                rom_offset += 4

    def mark_c_funcs_as_defined(self, c_funcs):
        for func_name in c_funcs:
            found = False
            for func_addr in self.seg_symbols:
                for symbol in self.seg_symbols[func_addr]:
                    if symbol.name == func_name:
                        symbol.defined = True
                        found = True
                        break
                if found:
                    break

    def create_c_asm_file(self, funcs_text, func, out_dir, sub, func_name):
        if self.options.get("compiler", "IDO") == "GCC":
            out_lines = self.get_gcc_inc_header()
        else:
            out_lines = []
        out_lines.extend(funcs_text[func][0])
        out_lines.append("")

        outpath = Path(os.path.join(out_dir, sub.name, func_name + ".s"))
        outpath.parent.mkdir(parents=True, exist_ok=True)

        with open(outpath, "w", newline="\n") as f:
            f.write("\n".join(out_lines))
        self.log(f"Disassembled {func_name} to {outpath}")

    def create_c_file(self, funcs_text, sub, asm_out_dir, base_path, c_path):
        c_lines = self.get_c_preamble()

        for func in funcs_text:
            func_name = self.get_symbol(func, type="func", local_only=True).name
            if self.options.get("compiler", "IDO") == "GCC":
                c_lines.append("INCLUDE_ASM(s32, \"{}\", {});".format(sub.name, func_name))
            else:
                asm_outpath = Path(os.path.join(asm_out_dir, sub.name, func_name + ".s"))
                rel_asm_outpath = os.path.relpath(asm_outpath, base_path)
                c_lines.append(f"#pragma GLOBAL_ASM(\"{rel_asm_outpath}\")")
            c_lines.append("")

        Path(c_path).parent.mkdir(parents=True, exist_ok=True)
        with open(c_path, "w") as f:
            f.write("\n".join(c_lines))
        print(f"Wrote {sub.name} to {c_path}")

    def split(self, rom_bytes, base_path):
        for sub in self.subsegments:
            sub.split(self, rom_bytes, base_path)

        # TODO hack for images: move at some point
        for sub in self.subsegments:
            if sub.type == "ci4" and (sub.should_run(self.options) or "img" in self.options["modes"]):
                generic_out_path = sub.get_generic_out_path(base_path, self.options)
                img_bytes = rom_bytes[sub.rom_start : sub.rom_end]

                width, height = sub.args
                palette = self.palettes[sub.name]
                image = N64SegCi4.parse_image(img_bytes, width, height)

                w = png.Writer(width, height, palette=palette)

                Path(generic_out_path).parent.mkdir(parents=True, exist_ok=True)
                with open(generic_out_path, "wb") as f:
                    w.write_array(f, image)

            # TODO other image types

        # TODO write orphaned palettes
