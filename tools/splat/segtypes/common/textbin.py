from pathlib import Path
from typing import Optional, TextIO

from util import log, options

from segtypes.common.segment import CommonSegment


class CommonSegTextbin(CommonSegment):
    @staticmethod
    def is_text() -> bool:
        return True

    def get_linker_section(self) -> str:
        return ".text"

    def get_section_flags(self) -> Optional[str]:
        return "ax"

    def out_path(self) -> Optional[Path]:
        return options.opts.data_path / self.dir / f"{self.name}.s"

    def bin_path(self) -> Path:
        typ = self.type
        if typ.startswith("."):
            typ = typ[1:]

        return options.opts.asset_path / self.dir / f"{self.name}.{typ}.bin"

    def write_bin(self, rom_bytes):
        binpath = self.bin_path()
        binpath.parent.mkdir(parents=True, exist_ok=True)

        assert isinstance(self.rom_start, int)
        assert isinstance(self.rom_end, int)

        binpath.write_bytes(rom_bytes[self.rom_start : self.rom_end])

        self.log(f"Wrote {self.name} to {binpath}")

    def write_asm_contents(self, rom_bytes, f: TextIO):
        binpath = self.bin_path()
        asm_label = options.opts.asm_function_macro
        if not self.is_text():
            asm_label = options.opts.asm_data_macro

        assert isinstance(self.rom_start, int)
        assert isinstance(self.rom_end, int)

        f.write(f".section {self.get_linker_section()}")
        section_flags = self.get_section_flags()
        if section_flags:
            f.write(f', "{section_flags}"')
        f.write("\n\n")

        # Check if there's a symbol at this address
        sym = None
        vram = self.rom_to_ram(self.rom_start)
        if vram is not None:
            sym = self.get_symbol(vram, in_segment=True)

        if sym is not None:
            f.write(f"{asm_label} {sym.name}\n")
            sym.defined = True

        f.write(f'.incbin "{binpath}"\n')

        if sym is not None:
            if self.is_text() and options.opts.asm_end_label != "":
                f.write(f"{options.opts.asm_end_label} {sym.name}\n")

            if sym.given_name_end is not None:
                if (
                    sym.given_size is None
                    or sym.given_size == self.rom_end - self.rom_start
                ):
                    f.write(f"{asm_label} {sym.given_name_end}\n")

    def split(self, rom_bytes):
        if self.rom_end is None:
            log.error(
                f"segment {self.name} needs to know where it ends; add a position marker [0xDEADBEEF] after it"
            )

        self.write_bin(rom_bytes)

        s_path = self.out_path()
        assert s_path is not None
        s_path.parent.mkdir(parents=True, exist_ok=True)

        with s_path.open("w") as f:
            f.write('.include "macro.inc"\n\n')
            preamble = options.opts.generated_s_preamble
            if preamble:
                f.write(preamble + "\n")

            self.write_asm_contents(rom_bytes, f)

            # We check against CommonSegTextbin instead of the specific type because the other incbins inherit from this class
            if isinstance(self.data_sibling, CommonSegTextbin):
                f.write("\n")
                self.data_sibling.write_asm_contents(rom_bytes, f)

            if isinstance(self.rodata_sibling, CommonSegTextbin):
                f.write("\n")
                self.rodata_sibling.write_asm_contents(rom_bytes, f)

    def should_scan(self) -> bool:
        return self.rom_start is not None and self.rom_end is not None

    def should_split(self) -> bool:
        return (
            self.extract and self.should_scan()
        )  # only split if the segment was scanned first
