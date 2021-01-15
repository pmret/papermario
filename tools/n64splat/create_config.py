#! /usr/bin/env python3

from capstone import *
from capstone.mips import *

import argparse
from util import rominfo
from segtypes.code import N64SegCode

parser = argparse.ArgumentParser(description="Create a splat config from a rom")
parser.add_argument("rom", help="path to a .z64 rom")


def main(rom_path):
    rom = rominfo.get_info(rom_path)
    basename = rom.name.replace(" ", "").lower()

    header = \
"""name: {0} ({1})
basename: {2}
options:
  find_file_boundaries: True
  compiler: "IDO"
""".format(rom.name.title(), rom.get_country_name(), basename)

    with open(rom_path, "rb") as f:
      fbytes = f.read()

    rom_addr = 0x1000

    md = Cs(CS_ARCH_MIPS, CS_MODE_MIPS64 + CS_MODE_BIG_ENDIAN)
    for insn in md.disasm(fbytes[rom_addr:], rom.entry_point):
        rom_addr += 4

    segments = \
"""segments:
  - name: header
    type: header
    start: 0x0
    vram: 0
    files:
      - [0x0, header, header]
  - name: boot
    type: bin
    start: 0x40
  - name: main
    type: code
    start: 0x1000
    vram: 0x{:X}
    files:
      - [0x1000, asm]
  - type: bin
    start: 0x{:X}
  - [0x{:X}]
""".format(rom.entry_point, rom_addr, rom.size)

    outstr = header + segments

    outname = rom.name.replace(" ", "").lower()
    with open(outname + ".yaml", "w", newline="\n") as f:
        f.write(outstr)

if __name__ == "__main__":
    args = parser.parse_args()
    main(args.rom)
