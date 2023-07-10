#!/usr/bin/env python3

import argparse
from pathlib import Path
from sys import argv, path
path.append(str(Path(__file__).parent.parent.parent / "splat"))
path.append(str(Path(__file__).parent.parent.parent / "splat_ext"))
from tex_archives import TexArchive

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Texture archives")
    parser.add_argument("bin_out", type=Path, help="Output binary file path")
    parser.add_argument("tex_dir", type=Path, help="File path to input tex subdirectory")
    parser.add_argument(
        "--endian", choices=["big", "little"], default="big", help="Output endianness"
    )
    args = parser.parse_args()

    TexArchive.build(args.bin_out, args.tex_dir, args.endian)
