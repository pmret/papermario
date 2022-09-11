from segtypes.common.code import CommonSegCode
from segtypes.common.codesubsegment import CommonSegCodeSubsegment
from segtypes.common.group import CommonSegGroup
from pathlib import Path
from typing import List, Optional
import rabbitizer
from util.symbols import Symbol
from util import floats, options


class CommonSegData(CommonSegCodeSubsegment, CommonSegGroup):
    def out_path(self) -> Optional[Path]:
        if self.type.startswith("."):
            if self.sibling:
                # C file
                return self.sibling.out_path()
            else:
                # Implied C file
                return options.get_src_path() / self.dir / f"{self.name}.c"
        else:
            # ASM
            return options.get_data_path() / self.dir / f"{self.name}.{self.type}.s"

    def scan(self, rom_bytes: bytes):
        CommonSegGroup.scan(self, rom_bytes)

        if super().should_scan():
            self.file_text = self.disassemble_data(rom_bytes)
        else:
            self.file_text = None

    def split(self, rom_bytes: bytes):
        CommonSegGroup.split(self, rom_bytes)

        if not self.type.startswith(".") and self.file_text:
            path = self.out_path()

            if path:
                path.parent.mkdir(parents=True, exist_ok=True)

                with open(path, "w", newline="\n") as f:
                    f.write(self.file_text)

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

    # Check symbols marked as jump tables to be valid
    def check_jtbls(self, rom_bytes, syms: List[Symbol]):
        endianness = options.get_endianess()

        for i, sym in enumerate(syms):
            if sym.type == "jtbl":
                start = self.get_most_parent().ram_to_rom(syms[i].vram_start)
                assert isinstance(start, int)
                end = self.get_most_parent().ram_to_rom(syms[i + 1].vram_start)
                sym_bytes = rom_bytes[start:end]

                b = 0
                last_bits = 0
                while b < len(sym_bytes):
                    bits = int.from_bytes(sym_bytes[b : b + 4], endianness)

                    if (
                        last_bits != 0
                        and bits != 0
                        and abs(last_bits - bits) > 0x100000
                    ):
                        new_sym_rom_start = start + b
                        new_sym_ram_start = self.get_most_parent().rom_to_ram(
                            new_sym_rom_start
                        )
                        assert sym.rom is not None
                        assert new_sym_ram_start is not None
                        sym.given_size = new_sym_rom_start - sym.rom

                        # It turns out this isn't a valid jump table, so create a new symbol where it breaks
                        syms.insert(
                            i + 1,
                            self.create_symbol(
                                new_sym_ram_start, True, define=True, local_only=True
                            ),
                        )
                        return False

                    if bits != 0:
                        last_bits = bits
                    b += 4

        return True

    def get_symbols(self, rom_bytes) -> List[Symbol]:
        symset = set()
        endian = options.get_endianess()

        # Find inter-data symbols
        assert isinstance(self.rom_start, int) and isinstance(self.rom_end, int)
        for i in range(self.rom_start, self.rom_end, 4):
            bits = int.from_bytes(rom_bytes[i : i + 4], endian)
            if self.contains_vram(bits):
                symset.add(
                    self.create_symbol(
                        bits, in_segment=True, define=True, local_only=True
                    )
                )

        for symbol_addr in self.seg_symbols:
            for symbol in self.seg_symbols[symbol_addr]:
                if not symbol.dead and self.contains_vram(symbol.vram_start):
                    symset.add(symbol)

        ret: List[Symbol] = list(symset)
        ret.sort(key=lambda s: s.vram_start)

        # Ensure we start at the beginning
        if len(ret) == 0 or ret[0].vram_start != self.vram_start:
            ret.insert(
                0,
                self.create_symbol(
                    self.vram_start, in_segment=True, define=True, local_only=True
                ),
            )

        # Make a dummy symbol here that marks the end of the previous symbol's disasm range
        assert self.vram_end is not None
        ret.append(Symbol(self.vram_end))

        while True:
            valid = self.check_jtbls(rom_bytes, ret)
            if valid:
                break

        return ret

    def are_null(chars):
        for b in chars:
            if b != "\x00":
                return False
        return True

    @staticmethod
    def is_valid_ascii(bytes):
        null_char = "\x00"
        valid_chars = (
            "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890[]():%!#=-_ "
        )
        invalid_chars = ""
        duplicate_limit = 10

        last_char = 0
        true_end = None
        consecutive_duplicates = 0
        valid_count = 0

        if len(bytes) <= 4 or bytes[0] == 0:
            return False

        try:
            chars = bytes.decode("EUC-JP")
        except:
            return False

        if len(chars) <= 4:
            return False

        for i, c in enumerate(chars):
            # Ensure null bytes are only at the end of ascii strings
            # TODO: if we find null bytes in the middle, break this into multiple strings ?
            if c == null_char:
                if true_end is None:
                    if CommonSegData.are_null(chars[i:]):
                        true_end = i
                    else:
                        pass
                        # return False

            # Ensure we're not seeing a ton of the same character in a row
            if last_char == c:
                consecutive_duplicates += 1
                if consecutive_duplicates >= duplicate_limit and last_char != null_char:
                    return False
            else:
                consecutive_duplicates = 0

            if c in valid_chars:
                valid_count += 1
            elif c in invalid_chars:
                return False

            last_char = c

        # Ensure the number of valid characters is sufficient
        if true_end is not None:
            # If there are more than 16 null chars at the end, something is afoot
            if len(chars) - true_end > 16:
                return False
            end = true_end
        else:
            end = len(chars)

        valid_ratio = valid_count / end
        if valid_ratio >= 0.75:
            return True

        return False

    # TODO if we see a new function's jtbl, split it
    def is_valid_jtbl(self, sym: Symbol, bytes) -> bool:
        min_jtbl_len = 16

        if len(bytes) % 4 != 0:
            return False

        # Jump tables must have at least 3 labels
        if len(bytes) < min_jtbl_len:
            return False

        most_parent = self.get_most_parent()
        assert isinstance(most_parent, CommonSegCode)

        # Grab the first word and see if its value is an address within a function
        word = int.from_bytes(bytes[0:4], options.get_endianess())
        jtbl_func: Optional[Symbol] = self.get_most_parent().get_func_for_addr(word)

        if not jtbl_func:
            return False

        # A label of a jump table shouldn't point to the start of the function
        if word == jtbl_func.vram_start:
            return False

        for i in range(4, len(bytes), 4):
            word = int.from_bytes(bytes[i : i + 4], options.get_endianess())

            # If the word doesn't contain an address in the current function, this isn't a valid jump table
            if not jtbl_func.contains_vram(word):
                # Allow jump tables that are of a minimum length and end in 0s
                if i < min_jtbl_len or any(b != 0 for b in bytes[i:]):
                    return False

            # A label of a jump table shouldn't point to the start of the function
            if word == jtbl_func.vram_start:
                return False

        # Mark this symbol as a jump table and record the jump table for later
        sym.type = "jtbl"
        most_parent.jumptables[sym.vram_start] = (
            jtbl_func.vram_start,
            jtbl_func.vram_end,
        )
        return True

    def disassemble_symbol(self, sym_bytes, sym_type):
        endian = options.get_endianess()
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
                # ascii_str = ascii_str.rstrip("\x00")
                ascii_str = ascii_str.replace("\\", "\\\\")  # escape back slashes
                ascii_str = ascii_str.replace('"', '\\"')  # escape quotes
                ascii_str = ascii_str.replace("\x00", "\\0")
                ascii_str = ascii_str.replace("\n", "\\n")

                sym_str += f'"{ascii_str}"'
                return sym_str
            except:
                return self.disassemble_symbol(sym_bytes, "word")

        i = 0
        while i < len(sym_bytes):
            adv_amt = min(slen, len(sym_bytes) - i)
            bits = int.from_bytes(sym_bytes[i : i + adv_amt], endian)

            if sym_type == "jtbl":
                if bits == 0:
                    byte_str = "0"
                else:
                    sym = self.get_symbol(bits, True)
                    if sym is not None:
                        byte_str = sym.name
                    else:
                        byte_str = f"0x{bits:X}"
            elif slen == 4 and bits >= 0x80000000:
                sym = self.get_symbol(bits, reference=True)
                if sym and sym.type not in ["label", "jtbl"]:
                    byte_str = sym.name
                else:
                    byte_str = "0x{0:0{1}X}".format(bits, 2 * slen)
            else:
                byte_str = "0x{0:0{1}X}".format(bits, 2 * slen)

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

    def disassemble_data(self, rom_bytes):
        rodata_encountered = "rodata" in self.type
        ret = '.include "macro.inc"\n\n'
        ret += f".section {self.get_linker_section()}"

        if self.size == 0:
            return None

        syms = self.get_symbols(rom_bytes)

        for i in range(len(syms) - 1):
            mnemonic = syms[i].access_mnemonic
            sym = self.create_symbol(
                syms[i].vram_start, in_segment=True, define=True, local_only=True
            )

            dis_start = self.get_most_parent().ram_to_rom(syms[i].vram_start)
            dis_end = self.get_most_parent().ram_to_rom(syms[i + 1].vram_start)
            assert dis_start is not None and dis_end is not None
            sym_len = dis_end - dis_start

            if self.type == "bss":
                disasm_str = f".space 0x{sym_len:X}"
            else:
                sym_bytes = rom_bytes[dis_start:dis_end]

                # Checking if the mnemonic is addiu may be too picky - we'll see
                if (
                    self.is_valid_ascii(sym_bytes)
                    and mnemonic == rabbitizer.InstrId.cpu_addiu
                ):
                    stype = "ascii"
                elif sym.type == "jtbl":
                    stype = "jtbl"
                elif self.is_valid_jtbl(sym, sym_bytes):
                    stype = "jtbl"
                elif (
                    len(sym_bytes) % 8 == 0
                    and mnemonic in CommonSegCodeSubsegment.double_mnemonics
                ):
                    stype = "double"
                elif (
                    len(sym_bytes) % 4 == 0
                    and mnemonic in CommonSegCodeSubsegment.float_mnemonics
                ):
                    stype = "float"
                elif (
                    len(sym_bytes) % 4 == 0
                    and sym.vram_start % 4 == 0
                    and (
                        mnemonic in CommonSegCodeSubsegment.word_mnemonics
                        or not mnemonic
                    )
                ):
                    stype = "word"
                elif (
                    len(sym_bytes) % 2 == 0
                    and sym.vram_start % 2 == 0
                    and (
                        mnemonic in CommonSegCodeSubsegment.short_mnemonics
                        or not mnemonic
                    )
                ):
                    stype = "short"
                else:
                    stype = "byte"

                # If we're starting from a weird place, make sure our container size is correct
                if dis_start % 4 != 0 and stype != "byte" and sym_len > 1:
                    stype = "short"
                if dis_start % 2 != 0:
                    stype = "byte"

                # Hint to the user that we are now in the .rodata section and no longer in the .data section (assuming rodata follows data)
                if (
                    not rodata_encountered
                    and stype == "jtbl"
                    and self.get_most_parent().rodata_follows_data
                ):
                    rodata_encountered = True
                    ret += "\n\n\n.section .rodata"

                disasm_str = self.disassemble_symbol(sym_bytes, stype)

            sym.disasm_str = disasm_str
            name_str = f"\n\n{options.get_asm_data_macro()} {sym.name}\n"
            ret += name_str + disasm_str

        ret += "\n"

        return ret
