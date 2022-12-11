from util import options

from segtypes.common.header import CommonSegHeader


class DolSegHeader(CommonSegHeader):
    def parse_header(self, dol_bytes):
        header_lines = []
        header_lines.append(".section .data\n")

        # Text file offsets
        for i in range(0x00, 0x1C, 4):
            header_lines.append(
                self.get_line("word", dol_bytes[i : i + 4], f"Text {i / 4} Offset")
            )
        # Data file offsets
        for i in range(0x1C, 0x48, 4):
            header_lines.append(
                self.get_line("word", dol_bytes[i : i + 4], f"Data {i / 4} Offset")
            )

        # Text RAM addresses
        for i in range(0x48, 0x64, 4):
            header_lines.append(
                self.get_line(
                    "word",
                    dol_bytes[i : i + 4],
                    f"Text {(i - 0x48) / 4} Address",
                )
            )
        # Data RAM addresses
        for i in range(0x64, 0x90, 4):
            header_lines.append(
                self.get_line(
                    "word",
                    dol_bytes[i : i + 4],
                    f"Data {(i - 0x64) / 4} Address",
                )
            )

        # Text file sizes
        for i in range(0x90, 0xAC, 4):
            header_lines.append(
                self.get_line(
                    "word",
                    dol_bytes[i : i + 4],
                    f"Text {(i - 0x90) / 4} Size",
                )
            )
        # Data file sizes
        for i in range(0xAC, 0xD8, 4):
            header_lines.append(
                self.get_line(
                    "word",
                    dol_bytes[i : i + 4],
                    f"Data {(i - 0xAC) / 4} Size",
                )
            )

        # BSS RAM address
        header_lines.append(self.get_line("word", dol_bytes[0xD8:0xDC], "BSS Address"))
        # BSS size
        header_lines.append(self.get_line("word", dol_bytes[0xDC:0xE0], "BSS Size"))

        # Entry point
        header_lines.append(self.get_line("word", dol_bytes[0xE0:0xE4], "Entry Point"))

        return header_lines
