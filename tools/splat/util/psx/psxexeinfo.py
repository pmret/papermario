#! /usr/bin/env python3

from __future__ import annotations

import argparse

import hashlib
import struct

import dataclasses

from pathlib import Path


@dataclasses.dataclass
class PsxExe:
    # Based on https://psx-spx.consoledev.net/cdromdrive/#filenameexe-general-purpose-executable
    initial_pc: int  # offset: 0x10
    initial_gp: int  # offset: 0x14
    destination_vram: int  # offset: 0x18
    file_size: int  # offset: 0x1C
    data_vram: int  # offset: 0x20
    data_size: int  # offset: 0x24
    bss_vram: int  # offset: 0x28
    bss_size: int  # offset: 0x2C
    initial_sp_base: int  # offset: 0x30
    initial_sp_offset: int  # offset: 0x34

    size: int
    sha1: str

    @property
    def text_offset(self) -> int:
        return self.initial_pc - self.destination_vram + 0x800

    @property
    def data_offset(self) -> int:
        if self.data_vram == 0 or self.data_size == 0:
            return 0
        return self.data_vram - self.destination_vram + 0x800

    @staticmethod
    def get_info(exe_path: Path, exe_bytes: bytes) -> PsxExe:
        initial_pc = struct.unpack("<I", exe_bytes[0x10 : 0x10 + 4])[0]
        initial_gp = struct.unpack("<I", exe_bytes[0x14 : 0x14 + 4])[0]
        destination_vram = struct.unpack("<I", exe_bytes[0x18 : 0x18 + 4])[0]
        file_size = struct.unpack("<I", exe_bytes[0x1C : 0x1C + 4])[0]
        data_vram = struct.unpack("<I", exe_bytes[0x20 : 0x20 + 4])[0]
        data_size = struct.unpack("<I", exe_bytes[0x24 : 0x24 + 4])[0]
        bss_vram = struct.unpack("<I", exe_bytes[0x28 : 0x28 + 4])[0]
        bss_size = struct.unpack("<I", exe_bytes[0x2C : 0x2C + 4])[0]
        initial_sp_base = struct.unpack("<I", exe_bytes[0x30 : 0x30 + 4])[0]
        initial_sp_offset = struct.unpack("<I", exe_bytes[0x34 : 0x34 + 4])[0]

        sha1 = hashlib.sha1(exe_bytes).hexdigest()

        return PsxExe(
            initial_pc,
            initial_gp,
            destination_vram,
            file_size,
            data_vram,
            data_size,
            bss_vram,
            bss_size,
            initial_sp_base,
            initial_sp_offset,
            len(exe_bytes),
            sha1,
        )


def main():
    parser = argparse.ArgumentParser(description="Gives information on PSX EXEs")
    parser.add_argument("exe", help="path to an PSX EXE")

    args = parser.parse_args()

    exe_path = Path(args.exe)
    exe_bytes = exe_path.read_bytes()
    exe = PsxExe.get_info(exe_path, exe_bytes)

    print(f"Initial PC: 0x{exe.initial_pc:08X}")

    print(f"Initial GP: ", end="")
    if exe.initial_gp != 0:
        print(f"0x{exe.initial_gp:08X}")
    else:
        print(f"No")

    print()
    print(f"Destination VRAM: 0x{exe.destination_vram:08X}")
    print(f"File size (without header): 0x{exe.file_size:X}")
    print(f"Text binary offset: 0x{exe.text_offset:08X}")

    if exe.data_vram != 0 and exe.data_size != 0:
        print()
        print(f"Data VRAM: 0x{exe.data_vram:08X}")
        print(f"Data size: 0x{exe.data_size:08X}")
        print(f"Data binary offset: 0x{exe.data_offset:08X}")

    if exe.bss_vram != 0 and exe.bss_size != 0:
        print()
        print(f"bss VRAM: 0x{exe.bss_vram:08X}")
        print(f"bss size: 0x{exe.bss_size:08X}")

    print()
    print(f"Initial SP base: 0x{exe.initial_sp_base:08X}")
    print(f"Initial SP offset: 0x{exe.initial_sp_offset:08X}")

    print()
    print(f"File size: 0x{exe.size:X}")
    print(f"sha1: {exe.sha1}")


if __name__ == "__main__":
    main()
