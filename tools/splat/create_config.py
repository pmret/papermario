#! /usr/bin/env python3

import sys
import argparse
from pathlib import Path

from util.n64 import rominfo, find_code_length

parser = argparse.ArgumentParser(description="Create a splat config from an N64 ROM.")
parser.add_argument("rom", help="Path to a .z64/.n64 ROM")


def main(rom_path: Path):
    if not rom_path.exists():
        sys.exit(f"ROM file {rom_path} does not exist ({rom_path.absolute()})")
    if rom_path.is_dir():
        sys.exit(f"Path {rom_path} is a directory ({rom_path.absolute()})")
    rom_bytes = rominfo.read_rom(rom_path)

    rom = rominfo.get_info(rom_path, rom_bytes)
    basename = rom.name.replace(" ", "").lower()

    header = f"""\
name: {rom.name.title()} ({rom.get_country_name()})
sha1: {rom.sha1}
options:
  basename: {basename}
  target_path: {rom_path.with_suffix(".z64")}
  base_path: .
  compiler: {rom.compiler}
  find_file_boundaries: True
  header_encoding: {rom.header_encoding}
  # platform: n64
  # undefined_funcs_auto: True
  # undefined_funcs_auto_path: undefined_funcs_auto.txt
  # undefined_syms_auto: True
  # undefined_syms_auto_path: undefined_syms_auto.txt
  # symbol_addrs_path: symbol_addrs.txt
  # undefined_syms_path: undefined_syms.txt
  # asm_path: asm
  # src_path: src
  # build_path: build
  # extensions_path: tools/splat_ext
  # mips_abi_float_regs: o32
  # section_order: [".text", ".data", ".rodata", ".bss"]
  # auto_all_sections: [".data", ".rodata", ".bss"]
"""

    first_section_end = find_code_length.run(rom_bytes, 0x1000, rom.entry_point)

    segments = f"""\
segments:
  - name: header
    type: header
    start: 0x0
  - name: boot
    type: bin
    start: 0x40
  - name: main
    type: code
    start: 0x1000
    vram: 0x{rom.entry_point:X}
    subsegments:
      - [0x1000, asm]
  - type: bin
    start: 0x{first_section_end:X}
  - [0x{rom.size:X}]
"""

    out_file = f"{basename}.yaml"
    with open(out_file, "w", newline="\n") as f:
        print(f"Writing config to {out_file}")
        f.write(header)
        f.write(segments)


if __name__ == "__main__":
    args = parser.parse_args()
    main(Path(args.rom))
