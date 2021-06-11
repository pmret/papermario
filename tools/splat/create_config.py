#! /usr/bin/env python3

import argparse
from util.n64 import rominfo, find_code_length

parser = argparse.ArgumentParser(description="Create a splat config from a ROM. "
                                             "Only n64 .z64 ROMs are supported")
parser.add_argument("rom", help="Path to a .z64 ROM")


def main(rom_path):
    rom = rominfo.get_info(rom_path)
    basename = rom.name.replace(" ", "").lower()

    header = f"""
name: {rom.name.title()} ({rom.get_country_name()})
sha1: {rom.sha1}
options:
  basename: {basename}
  target_path: {rom_path}
  base_path: .
  compiler: {rom.compiler}
  find_file_boundaries: True
  # platform: n64
  # undefined_funcs_auto_path: undefined_funcs_auto.txt
  # undefined_syms_auto_path: undefined_syms_auto.txt
  # symbol_addrs_path: symbol_addrs.txt
  # undefined_syms_path: undefined_syms.txt
  # asm_path: asm
  # src_path: src
  # build_path: build
  # extensions_path: tools/splat_ext
  # section_order: [.text, .data, .rodata, .bss]
""".lstrip()

    with open(rom_path, "rb") as f:
        fbytes = f.read()

    first_section_end = find_code_length.run(fbytes, 0x1000, rom.entry_point)

    segments = f"""
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
""".lstrip()

    with open(basename + ".yaml", "w", newline="\n") as f:
        f.write(header + segments)


if __name__ == "__main__":
    args = parser.parse_args()
    main(args.rom)
