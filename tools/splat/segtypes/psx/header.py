from segtypes.common.header import CommonSegHeader
from pathlib import Path
from util import options


class PsxSegHeader(CommonSegHeader):
    # little endian so reverse words, TODO: use struct.unpack("<i",...) ?

    def parse_header(self, rom_bytes):
        header_lines = []
        header_lines.append(f".section .data\n")
        header_lines.append(self.get_line("ascii", rom_bytes[0x00:0x08], "magic number"))
        header_lines.append(self.get_line("word", rom_bytes[0x08:0x0C], "pad"))
        header_lines.append(self.get_line("word", rom_bytes[0x0C:0x10], "pad"))
        header_lines.append(self.get_line("word", rom_bytes[0x10:0x14][::-1], ".data start"))
        header_lines.append(self.get_line("word", rom_bytes[0x14:0x18], "pad"))
        header_lines.append(self.get_line("word", rom_bytes[0x18:0x1C][::-1], ".text start"))
        header_lines.append(self.get_line("word", rom_bytes[0x1C:0x20][::-1], ".text size"))
        header_lines.append(self.get_line("word", rom_bytes[0x20:0x24], "pad"))
        header_lines.append(self.get_line("word", rom_bytes[0x24:0x28], "pad"))
        header_lines.append(self.get_line("word", rom_bytes[0x28:0x2C], "pad"))
        header_lines.append(self.get_line("word", rom_bytes[0x2C:0x30], "pad"))
        header_lines.append(self.get_line("word", rom_bytes[0x30:0x34][::-1], "$sp start"))
        header_lines.append(self.get_line("word", rom_bytes[0x34:0x38], "pad"))
        header_lines.append(self.get_line("word", rom_bytes[0x38:0x3C], "pad"))
        header_lines.append(self.get_line("word", rom_bytes[0x3C:0x40], "pad"))
        header_lines.append(self.get_line("word", rom_bytes[0x40:0x44], "pad"))
        header_lines.append(self.get_line("word", rom_bytes[0x44:0x48], "pad"))
        header_lines.append(self.get_line("word", rom_bytes[0x48:0x4C], "pad"))
        header_lines.append(self.get_line("ascii", rom_bytes[0x4C:self.rom_end], "Sony Inc"))

        header_lines.append("")

        return header_lines
