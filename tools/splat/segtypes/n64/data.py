from segtypes.n64.codesubsegment import N64SegCodeSubsegment
from pathlib import Path
from typing import Dict, Optional
from util.symbols import Symbol
from util import floats, options

class N64SegData(N64SegCodeSubsegment):
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
            return options.get_asm_path() / "data" / self.dir / f"{self.name}.{self.type}.s"

    def scan(self, rom_bytes: bytes):
        self.file_text = self.disassemble_data(rom_bytes)

    def split(self, rom_bytes: bytes):
        if self.file_text:
            path = self.out_path()
            
            if path:
                path.parent.mkdir(parents=True, exist_ok=True)

                with open(path, "w", newline="\n") as f:
                    f.write(self.file_text)

    def get_linker_section(self) -> str:
        return ".data"

    def get_symbols(self, rom_bytes):
        symset = set()

        # Find inter-data symbols
        for i in range(self.rom_start, self.rom_end, 4):
            bits = int.from_bytes(rom_bytes[i : i + 4], "big")
            if self.contains_vram(bits):
                symset.add(self.parent.get_symbol(bits, create=True, define=True, local_only=True))

        for symbol_addr in self.seg_symbols:
            for symbol in self.seg_symbols[symbol_addr]:
                if not symbol.dead and self.contains_vram(symbol.vram_start):
                    symset.add(symbol)

        ret = list(symset)
        ret.sort(key=lambda s:s.vram_start)

        # Ensure we start at the beginning
        if len(ret) == 0 or ret[0].vram_start != self.vram_start:
            ret.insert(0, self.parent.get_symbol(self.vram_start, create=True, define=True, local_only=True))

        # Make a dummy symbol here that marks the end of the previous symbol's disasm range
        ret.append(Symbol(self.vram_end))

        return ret

    def are_null(chars):
        for b in chars:
            if b != '\x00':
                return False
        return True

    @staticmethod
    def is_valid_ascii(bytes):
        null_char = '\x00'
        valid_chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890[]():%!#=-_ "
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
                    if N64SegData.are_null(chars[i:]):
                        true_end = i
                    else:
                        pass
                        #return False

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
                # ascii_str = ascii_str.rstrip("\x00")
                ascii_str = ascii_str.replace("\x00", "\\0")
                ascii_str = ascii_str.replace("\n", "\\n")

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
                    rom_addr = self.parent.ram_to_rom(bits)

                    if rom_addr:
                        byte_str = f"L{bits:X}_{rom_addr:X}"
                    else:
                        byte_str = f"0x{bits:X}"
            elif slen == 4 and bits >= 0x80000000:
                sym = self.parent.get_symbol(bits, reference=True)
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
    
    def disassemble_data(self, rom_bytes):
        rodata_encountered = "rodata" in self.type
        ret = ".include \"macro.inc\"\n\n"
        ret += f'.section {self.get_linker_section()}'

        if self.size == 0:
            return None

        syms = self.get_symbols(rom_bytes)

        for i in range(len(syms) - 1):
            mnemonic = syms[i].access_mnemonic
            sym = self.parent.get_symbol(syms[i].vram_start, create=True, define=True, local_only=True)
            
            sym_str = f"\n\nglabel {sym.name}\n"
            dis_start = self.parent.ram_to_rom(syms[i].vram_start)
            dis_end = self.parent.ram_to_rom(syms[i + 1].vram_start)
            sym_len = dis_end - dis_start

            if self.type == "bss":
                ret += f".space 0x{sym_len:X}"
            else:
                sym_bytes = rom_bytes[dis_start : dis_end]

                # Checking if the mnemonic is addiu may be too picky - we'll see
                if self.is_valid_ascii(sym_bytes) and mnemonic == "addiu":
                    stype = "ascii"
                elif syms[i].type == "jtbl":
                    stype = "jtbl"
                elif len(sym_bytes) % 8 == 0 and mnemonic in N64SegCodeSubsegment.double_mnemonics:
                    stype = "double"
                elif len(sym_bytes) % 4 == 0 and mnemonic in N64SegCodeSubsegment.float_mnemonics:
                    stype = "float"
                elif len(sym_bytes) % 4 == 0 and sym.vram_start % 4 == 0 and (mnemonic in N64SegCodeSubsegment.word_mnemonics or not mnemonic):
                    stype = "word"
                elif len(sym_bytes) % 2 == 0 and sym.vram_start % 2 == 0 and (mnemonic in N64SegCodeSubsegment.short_mnemonics or not mnemonic):
                    stype = "short"
                else:
                    stype = "byte"

                # If we're starting from a weird place, make sure our container size is correct
                if dis_start % 4 != 0 and stype != "byte" and sym_len > 1:
                    stype = "short"
                if dis_start % 2 != 0:
                    stype = "byte"

                if not rodata_encountered and mnemonic == "jtbl":
                    rodata_encountered = True
                    ret += "\n\n\n.section .rodata"

                sym_str += self.disassemble_symbol(sym_bytes, stype)
                sym.disasm_str = sym_str
                ret += sym_str

        ret += "\n"

        return ret
