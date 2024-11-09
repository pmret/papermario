#!/usr/bin/env python3

import argparse
import mapfile_parser
from pathlib import Path
import rabbitizer

script_dir = Path(__file__).resolve().parent
root_dir = script_dir
build_dir = root_dir / "ver" / "jp" / "build"
expected_build_dir = root_dir / "ver/jp/expected/ver/jp/build"


def decode_instruction(bytes_diff: bytes, map_file: mapfile_parser.MapFile) -> str:
    word = (
        (bytes_diff[0] << 24)
        | (bytes_diff[1] << 16)
        | (bytes_diff[2] << 8)
        | (bytes_diff[3] << 0)
    )
    instr = rabbitizer.Instruction(word)
    imm_override = None

    if instr.isJumpWithAddress():
        # Instruction is a function call (jal)

        # Get the embedded address of the function call
        sym_address = instr.getInstrIndexAsVram()

        # Search for the address in the mapfile
        sym_info = map_file.findSymbolByVramOrVrom(sym_address)
        if sym_info is not None:
            # Use the symbol from the mapfile instead of a raw value
            imm_override = sym_info.symbol.name

    return instr.disassemble(immOverride=imm_override, extraLJust=-20)


def main():
    parser = argparse.ArgumentParser(
        description="Find the first difference(s) between the built ROM and the base ROM."
    )

    parser.add_argument(
        "-c",
        "--count",
        type=int,
        default=5,
        help="find up to this many instruction difference(s)",
    )
    parser.add_argument(
        "-v", "--version", help="Which version should be processed", default="us"
    )
    parser.add_argument(
        "-a", "--add-colons", action="store_true", help="Add colon between bytes"
    )

    args = parser.parse_args()

    mapfile_parser.frontends.first_diff.doFirstDiff(
        build_dir / f"papermario.map",
        expected_build_dir / f"papermario.map",
        build_dir / f"papermario.z64",
        expected_build_dir / f"papermario.z64",
        args.count,
        mismatchSize=True,
        addColons=args.add_colons,
        bytesConverterCallback=decode_instruction,
    )


if __name__ == "__main__":
    main()
