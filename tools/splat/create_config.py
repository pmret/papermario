#! /usr/bin/env python3

import argparse
import sys
from pathlib import Path

from segtypes.gc.rarc import GcSegRarc
from util.gc import gcinfo

from util.n64 import find_code_length, rominfo

parser = argparse.ArgumentParser(
    description="Create a splat config from an N64 ROM or a GameCube disc image."
)
parser.add_argument("file", help="Path to a .z64/.n64 ROM or .iso/.gcm GameCube image")


def main(file_path: Path):
    if not file_path.exists():
        sys.exit(f"File {file_path} does not exist ({file_path.absolute()})")
    if file_path.is_dir():
        sys.exit(f"Path {file_path} is a directory ({file_path.absolute()})")

    # Check for N64 ROM
    if file_path.suffix.lower() == ".n64" or file_path.suffix.lower() == ".z64":
        create_n64_config(file_path)
        return

    file_bytes = file_path.read_bytes()

    # Check for GC disc image
    if int.from_bytes(file_bytes[0x1C:0x20], byteorder="big") == 0xC2339F3D:
        create_gc_config(file_path, file_bytes)


def create_n64_config(rom_path: Path):
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
  platform: n64
  # undefined_funcs_auto: True
  # undefined_funcs_auto_path: undefined_funcs_auto.txt
  # undefined_syms_auto: True
  # undefined_syms_auto_path: undefined_syms_auto.txt
  # symbol_addrs_path: symbol_addrs.txt
  # asm_path: asm
  # src_path: src
  # build_path: build
  # extensions_path: tools/splat_ext
  # mips_abi_float_regs: o32
  # section_order: [".text", ".data", ".rodata", ".bss"]
  # auto_all_sections: [".data", ".rodata", ".bss"]
  # libultra_symbols: True
  # hardware_regs: True
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

  - name: entry
    type: code
    start: 0x1000
    vram: 0x{rom.entry_point:X}
    subsegments:
      - [0x1000, hasm]

  - name: main
    type: code
    start: 0x{0x1000 + rom.entrypoint_info.entry_size:X}
    vram: 0x{rom.entry_point + rom.entrypoint_info.entry_size:X}
    follows_vram: entry
"""

    if rom.entrypoint_info.bss_size is not None:
        segments += f"""\
    bss_size: 0x{rom.entrypoint_info.bss_size:X}
"""

    segments += f"""\
    subsegments:
      - [0x{0x1000 + rom.entrypoint_info.entry_size:X}, asm]
"""

    if (
        rom.entrypoint_info.bss_size is not None
        and rom.entrypoint_info.bss_start_address is not None
    ):
        bss_start = rom.entrypoint_info.bss_start_address - rom.entry_point + 0x1000
        # first_section_end points to the start of data
        segments += f"""\
      - [0x{first_section_end:X}, data]
      - {{ start: 0x{bss_start:X}, type: bss, vram: 0x{rom.entrypoint_info.bss_start_address:08X} }}
"""
        # Point next segment to the detected end of the main one
        first_section_end = bss_start

    segments += f"""\

  - type: bin
    start: 0x{first_section_end:X}
    follows_vram: main
  - [0x{rom.size:X}]
"""

    out_file = f"{basename}.yaml"
    with open(out_file, "w", newline="\n") as f:
        print(f"Writing config to {out_file}")
        f.write(header)
        f.write(segments)


def create_gc_config(iso_path: Path, iso_bytes: bytes):
    gc = gcinfo.get_info(iso_path, iso_bytes)
    basename = gc.system_code + gc.game_code + gc.region_code + gc.publisher_code

    header = f"""\
name: \"{gc.name.title()} ({gc.get_region_name()})\"
system_code: {gc.system_code}
game_code: {gc.game_code}
region_code: {gc.region_code}
publisher_code: {gc.publisher_code}
sha1: {gc.sha1}
options:
  filesystem_path: filesystem
  basename: {basename}
  target_path: {iso_path.with_suffix(".iso")}
  base_path: .
  compiler: {gc.compiler}
  platform: gc
  # undefined_funcs_auto: True
  # undefined_funcs_auto_path: undefined_funcs_auto.txt
  # undefined_syms_auto: True
  # undefined_syms_auto_path: undefined_syms_auto.txt
  # symbol_addrs_path: symbol_addrs.txt
  # asm_path: asm
  # src_path: src
  # build_path: build
  # extensions_path: tools/splat_ext
  # section_order: [".text", ".data", ".rodata", ".bss"]
  # auto_all_sections: [".data", ".rodata", ".bss"]
"""

    segments = f"""\
segments:
  - name: filesystem
    type: fst
    path: filesystem/sys/fst.bin
  - name: bootinfo
    type: bootinfo
    path: filesystem/sys/boot.bin
  - name: bi2
    type: bi2
    path: filesystem/sys/bi2.bin
  - name: apploader
    type: apploader
    path: filesystem/sys/apploader.img
  - name: main
    type: dol
    path: filesystem/sys/main.dol
"""

    out_file = f"{basename}.yaml"
    with open(out_file, "w", newline="\n") as f:
        print(f"Writing config to {out_file}")
        f.write(header)
        f.write(segments)


if __name__ == "__main__":
    args = parser.parse_args()
    main(Path(args.file))
