from segtypes.common.segment import CommonSegment
from pathlib import Path
from util import options

class CommonSegHeader(CommonSegment):
    def should_split(self):
        return self.extract and options.mode_active("code")

    @staticmethod
    def get_line(typ, data, comment):
        if typ == "ascii":
            text = data.decode("ASCII").strip()
            text = text.replace("\x00", "\\0")  # escape NUL chars
            dstr = "\"" + text + "\""
        else: # .word, .byte
            dstr = "0x" + data.hex().upper()

        dstr = dstr.ljust(20 - len(typ))

        return f".{typ} {dstr} /* {comment} */"

    def out_path(self) -> Path:
        return options.get_asm_path() / self.dir / f"{self.name}.s"

    def parse_header(self, rom_bytes):
        return []

    def split(self, rom_bytes):
        header_lines = self.parse_header(rom_bytes)

        src_path = self.out_path()
        src_path.parent.mkdir(parents=True, exist_ok=True)
        with open(src_path, "w", newline="\n") as f:
            f.write("\n".join(header_lines))
        self.log(f"Wrote {self.name} to {src_path}")

    @staticmethod
    def get_default_name(addr):
        return "header"
