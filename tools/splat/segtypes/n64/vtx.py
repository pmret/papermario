"""
N64 Vtx struct splitter
Dumps out Vtx as a .inc.c file.

Originally written by Mark Street (https://github.com/mkst)
"""

import re
import struct
from typing import Optional
from pathlib import Path
from util.log import error

from util import options
from segtypes.n64.codesubsegment import N64SegCodeSubsegment

class N64SegVtx(N64SegCodeSubsegment):
    def __init__(self, rom_start, rom_end, type, name, vram_start, extract,
                 given_subalign, given_is_overlay, given_dir, args = [], yaml = {}):
        super().__init__(rom_start, rom_end, type, name, vram_start, extract,
                         given_subalign, given_is_overlay, given_dir, args, yaml)
        self.file_text = None

    def get_linker_section(self) -> str:
        return '.data'

    def out_path(self) -> Path:
        return options.get_asset_path() / self.dir / f"{self.name}.vtx.inc.c"

    def scan(self, rom_bytes: bytes):
        self.file_text = self.disassemble_data(rom_bytes)

    def disassemble_data(self, rom_bytes):
        vertex_data = rom_bytes[self.rom_start:self.rom_end]
        segment_length = len(vertex_data)
        if (segment_length) % 16 != 0:
            error(f"Error: Vtx segment {self.name} length ({segment_length}) is not a multiple of 16!")

        lines = []
        preamble = options.get_generated_c_premble()
        lines.append(preamble)
        lines.append("")

        vertex_count = segment_length // 16
        cname = re.sub(r"[^0-9a-zA-Z_]", "_", self.name)
        lines.append(f"Vtx {cname}[{vertex_count}] = {{")

        for vtx in struct.iter_unpack(">hhhHhhBBBB", vertex_data):
            x, y, z, flg, t, c, r, g, b, a = vtx
            vtx_string = f"    {{{{{{ {x:5}, {y:5}, {z:5} }}, {flg}, {{ {t:5}, {c:5} }}, {{ {r:3}, {g:3}, {b:3}, {a:3} }}}}}},"
            if flg != 0:
                self.warn(f"Non-zero flag found in vertex data {self.name}!")
            lines.append(vtx_string)

        lines.append("};")

        # enforce newline at end of file
        lines.append("")
        return "\n".join(lines)

    def split(self, rom_bytes: bytes):
        if self.file_text and self.out_path():
            self.out_path().parent.mkdir(parents=True, exist_ok=True)
                
            with open(self.out_path(), "w", newline="\n") as f:
                f.write(self.file_text)

    def should_scan(self) -> bool:
        return options.mode_active("vtx") and self.rom_start != "auto" and self.rom_end != "auto"
    
    def should_split(self) -> bool:
        return self.extract and options.mode_active("vtx")