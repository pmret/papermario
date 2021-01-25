import os
from segtypes.n64.segment import N64Segment
from pathlib import Path

class N64SegHeader(N64Segment):
    def should_run(self):
        return N64Segment.should_run(self) or "asm" in self.options["modes"]

    @staticmethod
    def get_line(typ, data, comment):
        if typ == "ascii":
            dstr = "\"" + data.decode("ASCII").strip() + "\""
        else: # .word, .byte
            dstr = "0x" + data.hex().upper()
        
        dstr = dstr.ljust(20 - len(typ))
        
        return f".{typ} {dstr} /* {comment} */"

    def split(self, rom_bytes, base_path):
        out_dir = self.create_split_dir(base_path, "asm")

        encoding = self.options.get("header_encoding", "ASCII")

        header_lines = []
        header_lines.append(f".section .{self.name}, \"a\"\n")
        header_lines.append(self.get_line("word", rom_bytes[0x00:0x04], "PI BSB Domain 1 register"))
        header_lines.append(self.get_line("word", rom_bytes[0x04:0x08], "Clockrate setting"))
        header_lines.append(self.get_line("word", rom_bytes[0x08:0x0C], "Entrypoint address"))
        header_lines.append(self.get_line("word", rom_bytes[0x0C:0x10], "Revision"))
        header_lines.append(self.get_line("word", rom_bytes[0x10:0x14], "Checksum 1"))
        header_lines.append(self.get_line("word", rom_bytes[0x14:0x18], "Checksum 2"))
        header_lines.append(self.get_line("word", rom_bytes[0x18:0x1C], "Unknown 1"))
        header_lines.append(self.get_line("word", rom_bytes[0x1C:0x20], "Unknown 2"))
        header_lines.append(".ascii \"" + rom_bytes[0x20:0x34].decode(encoding).strip().ljust(20) + "\" /* Internal name */")
        header_lines.append(self.get_line("word", rom_bytes[0x34:0x38], "Unknown 3"))
        header_lines.append(self.get_line("word", rom_bytes[0x38:0x3C], "Cartridge"))
        header_lines.append(self.get_line("ascii", rom_bytes[0x3C:0x3E], "Cartridge ID"))
        header_lines.append(self.get_line("ascii", rom_bytes[0x3E:0x3F], "Country code"))
        header_lines.append(self.get_line("byte", rom_bytes[0x3F:0x40], "Version"))
        header_lines.append("")

        s_path = os.path.join(out_dir, self.name + ".s")
        Path(s_path).parent.mkdir(parents=True, exist_ok=True)
        with open(s_path, "w", newline="\n") as f:
            f.write("\n".join(header_lines))
        self.log(f"Wrote {self.name} to {s_path}")


    def get_ld_section_name(self):
        return self.name


    def get_ld_files(self):
        return [("asm", f"{self.name}.s", ".data", self.rom_start)]


    @staticmethod
    def get_default_name(addr):
        return "header"
