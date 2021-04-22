#! /usr/bin/env python3

import argparse
from util.n64 import rominfo
from util.n64 import find_code_length

parser = argparse.ArgumentParser(description="Create a splat config from a rom (currently only n64 .z64 roms supported)")
parser.add_argument("rom", help="path to a .z64 rom")


def main(rom_path):
    rom = rominfo.get_info(rom_path)
    basename = rom.name.replace(" ", "").lower()

    header = \
"""name: {0} ({1})
basename: {2}
options:
  find_file_boundaries: True
  compiler: IDO
  platform: n64
  base_dir: .
  target_path: baserom.z64
""".format(rom.name.title(), rom.get_country_name(), basename)

    with open(rom_path, "rb") as f:
      fbytes = f.read()

    first_section_end = find_code_length.run(fbytes, 0x1000, rom.entry_point)

    segments = \
"""segments:
  - name: header
    type: header
    start: 0x0
  - name: boot
    type: bin
    start: 0x40
  - name: main
    type: code
    start: 0x1000
    vram: 0x{:X}
    subsegments:
      - [0x1000, asm]
  - type: bin
    start: 0x{:X}
  - [0x{:X}]
""".format(rom.entry_point, first_section_end, rom.size)

    outstr = header + segments

    outname = rom.name.replace(" ", "").lower()
    with open(outname + ".yaml", "w", newline="\n") as f:
        f.write(outstr)

if __name__ == "__main__":
    args = parser.parse_args()
    main(args.rom)
