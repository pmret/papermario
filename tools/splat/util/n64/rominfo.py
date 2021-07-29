#! /usr/bin/python3

import argparse
from capstone import *
from capstone.mips import *
import hashlib
import zlib

parser = argparse.ArgumentParser(description='Gives information on n64 roms')
parser.add_argument('rom', help='path to a .z64 rom')
parser.add_argument('--encoding', help='Text encoding the game header is using; see docs.python.org/3/library/codecs.html#standard-encodings for valid encodings', default='ASCII')

country_codes = {
    0x00: "Unknown",
    0x37: "Beta",
    0x41: "Asian (NTSC)",
    0x42: "Brazillian",
    0x43: "Chiniese",
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
    0x57: "Scandanavian",
    0x58: "European",
    0x59: "European",
}

crc_to_cic = {
    0x6170A4A1: {"ntsc-name": "6101", "pal-name": "7102", "offset": 0x000000},
    0x90BB6CB5: {"ntsc-name": "6102", "pal-name": "7101", "offset": 0x000000},
    0x0B050EE0: {"ntsc-name": "6103", "pal-name": "7103", "offset": 0x100000},
    0x98BC2C86: {"ntsc-name": "6105", "pal-name": "7105", "offset": 0x000000},
    0xACC8580A: {"ntsc-name": "6106", "pal-name": "7106", "offset": 0x200000},
    0x00000000: {"ntsc-name": "unknown", "pal-name": "unknown", "offset": 0x0000000}
}


def read_rom(rom):
    with open(rom, "rb") as f:
        return f.read()


def get_cic(rom_bytes):
    crc = zlib.crc32(rom_bytes[0x40:0x1000])
    if crc in crc_to_cic:
        return crc_to_cic[crc]
    else:
        return crc_to_cic[0]


def get_entry_point(program_counter, cic):
    return program_counter - cic["offset"]


def get_info(rom_path, encoding="ASCII", bytes=None):
    if not bytes:
        return get_info_bytes(read_rom(rom_path), encoding)
    else:
        return get_info_bytes(bytes, encoding)


def get_info_bytes(rom_bytes, encoding):
    program_counter = int(rom_bytes[0x8:0xC].hex(), 16)
    libultra_version = chr(rom_bytes[0xF])
    crc1 = rom_bytes[0x10:0x14].hex().upper()
    crc2 = rom_bytes[0x14:0x18].hex().upper()

    try:
        name = rom_bytes[0x20:0x34].decode(encoding).strip()
    except:
        print("splat could not decode the game name; try using a different encoding by passing the --encoding argument (see docs.python.org/3/library/codecs.html#standard-encodings for valid encodings)")
        exit(1)

    country_code = rom_bytes[0x3E]

    cic = get_cic(rom_bytes)
    entry_point = get_entry_point(program_counter, cic)

    # TODO: add support for
    # compression_formats = []
    #  for format in ["Yay0", "vpk0"]:
    #     if rom_bytes.find(bytes(format, "ASCII")) != -1:
    #         compression_formats.append(format)

    compiler = get_compiler_info(rom_bytes, entry_point, print_result=False)

    sha1 = hashlib.sha1(rom_bytes).hexdigest()

    return N64Rom(name, country_code, libultra_version, crc1, crc2, cic, entry_point, len(rom_bytes), compiler, sha1)


class N64Rom:
    def __init__(self, name, country_code, libultra_version, crc1, crc2, cic, entry_point, size, compiler, sha1):
        self.name = name
        self.country_code = country_code
        self.libultra_version = libultra_version
        self.crc1 = crc1
        self.crc2 = crc2
        self.cic = cic
        self.entry_point = entry_point
        self.size = size
        self.compiler = compiler
        self.sha1 = sha1

    def get_country_name(self):
        return country_codes[self.country_code]

def get_compiler_info(rom_bytes, entry_point, print_result=True):
    md = Cs(CS_ARCH_MIPS, CS_MODE_MIPS64 + CS_MODE_BIG_ENDIAN)
    md.detail = True

    jumps = 0
    branches = 0

    for insn in md.disasm(rom_bytes[0x1000:], entry_point):
        if insn.mnemonic == "j":
            jumps += 1
        elif insn.mnemonic == "b":
            branches += 1

    compiler = "IDO" if branches > jumps else "GCC"
    if (print_result):
        print(f"{branches} branches and {jumps} jumps detected in the first code segment. Compiler is most likely {compiler}")
    return compiler

# TODO: support .n64 extension
def main():
    args = parser.parse_args()
    rom_bytes = read_rom(args.rom)
    rom = get_info(args.rom, args.encoding, rom_bytes)

    print("Image name: " + rom.name)
    print("Country code: " + chr(rom.country_code) + " - " + rom.get_country_name())
    print("Libultra version: " + rom.libultra_version)
    print("CRC1: " + rom.crc1)
    print("CRC2: " + rom.crc2)
    print("CIC: " + rom.cic["ntsc-name"] + " / " + rom.cic["pal-name"])
    print("RAM entry point: " + hex(rom.entry_point))
    print("")

    get_compiler_info(rom_bytes, rom.entry_point)

if __name__ == "__main__":
    main()
