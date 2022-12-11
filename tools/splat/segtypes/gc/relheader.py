from util import options

from segtypes.common.header import CommonSegHeader


class RelSegHeader(CommonSegHeader):
    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs)

        if isinstance(self.yaml, dict):
            self.version: int = self.yaml.get("version", 0)

    def parse_header(self, rel_bytes):
        header_lines = []
        header_lines.append(".section .data\n")

        # Module ID
        header_lines.append(self.get_line("word", rel_bytes[0x00:0x04], "Module ID"))

        # Next module (filled at runtime)
        header_lines.append(self.get_line("word", rel_bytes[0x04:0x08], "Next Module"))
        # Last module (filled at runtime)
        header_lines.append(self.get_line("word", rel_bytes[0x08:0x0C], "Last Module"))

        # Section count
        header_lines.append(
            self.get_line("word", rel_bytes[0x0C:0x10], "Section Count")
        )
        # Section table offset
        header_lines.append(
            self.get_line("word", rel_bytes[0x10:0x14], "Section Table Offset")
        )

        # Module name offset (might be null)
        header_lines.append(
            self.get_line("word", rel_bytes[0x14:0x18], "Module Name Offset")
        )
        # Module name length
        header_lines.append(
            self.get_line("word", rel_bytes[0x18:0x1C], "Module Name Length")
        )

        # REL format version
        header_lines.append(
            self.get_line("word", rel_bytes[0x1C:0x20], "REL Format Version")
        )

        # BSS size
        header_lines.append(self.get_line("word", rel_bytes[0x20:0x24], "BSS Size"))

        # Relocation table offset
        header_lines.append(
            self.get_line("word", rel_bytes[0x24:0x28], "Relocation Table Offset")
        )
        # Import table offset
        header_lines.append(
            self.get_line("word", rel_bytes[0x28:0x2C], "Import Table Offset")
        )
        # Import table size
        header_lines.append(
            self.get_line("word", rel_bytes[0x2C:0x30], "Import Table Size")
        )

        # Prolog section index
        header_lines.append(
            self.get_line("byte", rel_bytes[0x30:0x31], "Prolog Section Index")
        )
        # Epilog section index
        header_lines.append(
            self.get_line("byte", rel_bytes[0x31:0x32], "Epilog Section Index")
        )
        # Unresolved section index
        header_lines.append(
            self.get_line("byte", rel_bytes[0x32:0x33], "Unresolved Section Index")
        )
        # BSS section index (filled at runtime)
        header_lines.append(
            self.get_line("byte", rel_bytes[0x33:0x34], "BSS Section Index")
        )

        # Prolog function offset
        header_lines.append(
            self.get_line("word", rel_bytes[0x34:0x38], "Prolog Function Offset")
        )
        # Epilog function offset
        header_lines.append(
            self.get_line("word", rel_bytes[0x38:0x3C], "Epilog Function Offset")
        )
        # Unresolved function offset
        header_lines.append(
            self.get_line("word", rel_bytes[0x3C:0x40], "Unresolved Function Offset")
        )

        # Version 1 is only 0x40 bytes long
        if self.version <= 1:
            return header_lines

        # Alignment constraint
        header_lines.append(
            self.get_line("word", rel_bytes[0x40:0x44], "Alignment Constraint")
        )
        # BSS alignment constraint
        header_lines.append(
            self.get_line("word", rel_bytes[0x44:0x48], "BSS Alignment Constraint")
        )

        # Version 2 is only 0x48 bytes long
        if self.version <= 2:
            return header_lines

        # Fix size
        header_lines.append(self.get_line("word", rel_bytes[0x48:0x4C], "Fix Size"))

        return header_lines
