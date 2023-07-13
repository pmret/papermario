#! /usr/bin/env python3

import argparse

import hashlib
import itertools
import struct

import sys
import zlib
from dataclasses import dataclass

from pathlib import Path
from typing import Optional

import rabbitizer
import spimdisasm

parser = argparse.ArgumentParser(description="Gives information on N64 roms")
parser.add_argument("rom", help="path to an N64 rom")
parser.add_argument(
    "--header-encoding",
    dest="header_encoding",
    help=(
        "Text encoding the game header is using;"
        " see docs.python.org/3/library/codecs.html#standard-encodings for valid encodings"
    ),
)

country_codes = {
    0x00: "Unknown",
    0x37: "Beta",
    0x41: "Asian (NTSC)",
    0x42: "Brazilian",
    0x43: "Chinese",
    0x44: "German",
    0x45: "North America",
    0x46: "French",
    0x47: "Gateway 64 (NTSC)",
    0x48: "Dutch",
    0x49: "Italian",
    0x4A: "Japanese",
    0x4B: "Korean",
    0x4C: "Gateway 64 (PAL)",
    0x4E: "Canadian",
    0x50: "European (basic spec.)",
    0x53: "Spanish",
    0x55: "Australian",
    0x57: "Scandinavian",
    0x58: "European",
    0x59: "European",
}


@dataclass
class CIC:
    ntsc_name: str
    pal_name: str
    offset: int


crc_to_cic = {
    0x6170A4A1: CIC("6101", "7102", 0x000000),
    0x90BB6CB5: CIC("6102", "7101", 0x000000),
    0x0B050EE0: CIC("6103", "7103", 0x100000),
    0x98BC2C86: CIC("6105", "7105", 0x000000),
    0xACC8580A: CIC("6106", "7106", 0x200000),
}
unknown_cic = CIC("unknown", "unknown", 0x0000000)


@dataclass
class N64EntrypointInfo:
    entry_size: int
    bss_start_address: Optional[int]
    bss_size: Optional[int]
    main_address: Optional[int]
    stack_top: int

    @staticmethod
    def parse_rom_bytes(
        rom_bytes, offset: int = 0x1000, size: int = 0x60
    ) -> "N64EntrypointInfo":
        word_list = spimdisasm.common.Utils.bytesToWords(
            rom_bytes, offset, offset + size
        )
        nops_count = 0

        register_values = [0 for _ in range(32)]

        register_bss_address: Optional[int] = None
        register_bss_size: Optional[int] = None
        register_main_address: Optional[int] = None

        size = 0
        for word in word_list:
            insn = rabbitizer.Instruction(word)
            if not insn.isImplemented():
                break

            if insn.isNop():
                nops_count += 1
            elif nops_count >= 3:
                break
            elif insn.canBeHi():
                register_values[insn.rt.value] = insn.getProcessedImmediate() << 16
            elif insn.canBeLo():
                if insn.isLikelyHandwritten():
                    # Try to skip these instructions:
                    # addi        $t0, $t0, 0x8
                    # addi        $t1, $t1, -0x8
                    pass
                elif insn.modifiesRt():
                    register_values[insn.rt.value] = (
                        register_values[insn.rs.value] + insn.getProcessedImmediate()
                    )
                elif insn.doesStore():
                    if insn.rt == rabbitizer.RegGprO32.zero:
                        # Try to detect the zero-ing bss algorithm
                        # sw          $zero, 0x0($t0)
                        register_bss_address = insn.rs.value
            elif insn.isBranch():
                # lui         $t1, 0x2
                # addiu       $t1, $t1, -0x7220
                # ...
                # addi        $t1, $t1, -0x8
                # ...
                # bnez        $t1, label
                register_bss_size = insn.rs.value

            elif insn.isJumptableJump() or insn.isReturn():
                # lui         $t2, 0x8000
                # addiu       $t2, $t2, 0x494
                # ...
                # jr          $t2
                register_main_address = insn.rs.value

            # print(f"{word:08X}", insn)
            size += 4

        # for i, val in enumerate(register_values):
        #     print(i, f"{val:08X}")

        bss_address = (
            register_values[register_bss_address]
            if register_bss_address is not None
            else None
        )
        bss_size = (
            register_values[register_bss_size]
            if register_bss_size is not None
            else None
        )
        main_address = (
            register_values[register_main_address]
            if register_main_address is not None
            else None
        )
        stack_top = register_values[rabbitizer.RegGprO32.sp.value]
        return N64EntrypointInfo(size, bss_address, bss_size, main_address, stack_top)


@dataclass
class N64Rom:
    name: str
    header_encoding: str
    country_code: int
    libultra_version: str
    checksum: str
    cic: CIC
    entry_point: int
    size: int
    compiler: str
    sha1: str
    entrypoint_info: N64EntrypointInfo

    def get_country_name(self) -> str:
        return country_codes[self.country_code]


def swap_bytes(data):
    return bytes(
        itertools.chain.from_iterable(
            struct.pack(">H", x) for (x,) in struct.iter_unpack("<H", data)
        )
    )


def read_rom(rom_path: Path):
    rom_bytes = rom_path.read_bytes()

    if rom_path.suffix.lower() == ".n64":
        print("Warning: Input file has .n64 suffix, byte-swapping!")
        rom_bytes = swap_bytes(rom_bytes)
        as_z64 = rom_path.with_suffix(".z64")
        if not as_z64.exists():
            print(f"Writing down {as_z64}")
            as_z64.write_bytes(rom_bytes)
    return rom_bytes


def get_cic(rom_bytes: bytes):
    ipl3_crc = zlib.crc32(rom_bytes[0x40:0x1000])

    return crc_to_cic.get(ipl3_crc, unknown_cic)


def get_entry_point(program_counter: int, cic: CIC):
    return program_counter - cic.offset


def guess_header_encoding(rom_bytes: bytes):
    header = rom_bytes[0x20:0x34]
    encodings = ["ASCII", "shift_jis", "euc-jp"]
    for encoding in encodings:
        try:
            header.decode(encoding)
            return encoding
        except UnicodeDecodeError:
            # we guessed wrong...
            pass

    sys.exit("Unknown header encoding, please raise an Issue with us")


def get_info(
    rom_path: Path, rom_bytes: Optional[bytes] = None, header_encoding=None
) -> N64Rom:
    if rom_bytes is None:
        rom_bytes = read_rom(rom_path)

    if header_encoding is None:
        header_encoding = guess_header_encoding(rom_bytes)

    return get_info_bytes(rom_bytes, header_encoding)


def get_info_bytes(rom_bytes: bytes, header_encoding: str) -> N64Rom:
    (program_counter,) = struct.unpack(">I", rom_bytes[0x8:0xC])
    libultra_version = chr(rom_bytes[0xF])
    checksum = rom_bytes[0x10:0x18].hex().upper()

    try:
        name = rom_bytes[0x20:0x34].decode(header_encoding).rstrip(" \0") or "empty"
    except:
        sys.exit(
            "splat could not decode the game name;"
            " try using a different encoding by passing the --header-encoding argument"
            " (see docs.python.org/3/library/codecs.html#standard-encodings for valid encodings)"
        )

    country_code = rom_bytes[0x3E]

    cic = get_cic(rom_bytes)
    entry_point = get_entry_point(program_counter, cic)

    compiler = get_compiler_info(rom_bytes, entry_point, print_result=False)

    sha1 = hashlib.sha1(rom_bytes).hexdigest()

    entrypoint_info = N64EntrypointInfo.parse_rom_bytes(rom_bytes)

    return N64Rom(
        name,
        header_encoding,
        country_code,
        libultra_version,
        checksum,
        cic,
        entry_point,
        len(rom_bytes),
        compiler,
        sha1,
        entrypoint_info,
    )


def get_compiler_info(rom_bytes, entry_point, print_result=True):
    jumps = 0
    branches = 0

    word_list = spimdisasm.common.Utils.bytesToWords(rom_bytes[0x1000:])
    for word in word_list:
        insn = rabbitizer.Instruction(word)
        if not insn.isImplemented():
            break

        if insn.uniqueId == rabbitizer.InstrId.cpu_j:
            jumps += 1
        elif insn.uniqueId == rabbitizer.InstrId.cpu_b:
            branches += 1

    compiler = "IDO" if branches > jumps else "GCC"
    if print_result:
        print(
            f"{branches} branches and {jumps} jumps detected in the first code segment."
            f" Compiler is most likely {compiler}"
        )
    return compiler


def main():
    rabbitizer.config.pseudos_pseudoB = True

    args = parser.parse_args()
    rom_bytes = read_rom(Path(args.rom))
    rom = get_info(Path(args.rom), rom_bytes, args.header_encoding)

    print("Image name: " + rom.name)
    print("Country code: " + chr(rom.country_code) + " - " + rom.get_country_name())
    print("Libultra version: " + rom.libultra_version)
    print("Checksum: " + rom.checksum)
    print("CIC: " + rom.cic.ntsc_name + " / " + rom.cic.pal_name)
    print("RAM entry point: " + hex(rom.entry_point))
    print("Header encoding: " + rom.header_encoding)
    print("")

    get_compiler_info(rom_bytes, rom.entry_point)


if __name__ == "__main__":
    main()
