from segtypes.common.header import CommonSegHeader
from pathlib import Path
from util import options

class N64SegHeader(CommonSegHeader):
    def parse_header(self, rom_bytes):
        encoding = options.get("header_encoding", "ASCII")

        header_lines = []
        header_lines.append(f".section .data\n")
        header_lines.append(self.get_line("word", rom_bytes[0x00:0x04], "PI BSB Domain 1 register"))
        header_lines.append(self.get_line("word", rom_bytes[0x04:0x08], "Clockrate setting"))
        header_lines.append(self.get_line("word", rom_bytes[0x08:0x0C], "Entrypoint address"))
        header_lines.append(self.get_line("word", rom_bytes[0x0C:0x10], "Revision"))
        header_lines.append(self.get_line("word", rom_bytes[0x10:0x14], "Checksum 1"))
        header_lines.append(self.get_line("word", rom_bytes[0x14:0x18], "Checksum 2"))
        header_lines.append(self.get_line("word", rom_bytes[0x18:0x1C], "Unknown 1"))
        header_lines.append(self.get_line("word", rom_bytes[0x1C:0x20], "Unknown 2"))

        if encoding != "word":
            header_lines.append(".ascii \"" + rom_bytes[0x20:0x34].decode(encoding).strip().ljust(20) + "\" /* Internal name */")
        else:
            for i in range(0x20, 0x34, 4):
                header_lines.append(self.get_line("word", rom_bytes[i:i+4], "Internal name"))

        header_lines.append(self.get_line("word", rom_bytes[0x34:0x38], "Unknown 3"))
        header_lines.append(self.get_line("word", rom_bytes[0x38:0x3C], "Cartridge"))
        header_lines.append(self.get_line("ascii", rom_bytes[0x3C:0x3E], "Cartridge ID"))
        header_lines.append(self.get_line("ascii", rom_bytes[0x3E:0x3F], "Country code"))
        header_lines.append(self.get_line("byte", rom_bytes[0x3F:0x40], "Version"))
        header_lines.append("")

        return header_lines
