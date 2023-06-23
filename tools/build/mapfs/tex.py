#!/usr/bin/env python3

import os
import argparse
from pathlib import Path
from sys import argv, path
path.append(str(Path(__file__).parent.parent.parent / "splat"))
path.append(str(Path(__file__).parent.parent.parent / "splat_ext"))
from pm_map_data import TexImage

def build(out_path: Path, in_path: Path, endian: str = "big"):
    out_bytes = bytearray()

    file_list = os.listdir(in_path)
    json_list = [file for file in file_list if file.endswith('json')]
    json_list.sort(key=lambda x: x[:-5].replace("_"," "))

    for file in json_list:
        img = TexImage()
        img.build(out_bytes, in_path / file)

    with open(out_path, "wb") as out_bin:
        out_bin.write(out_bytes)


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Texture archives")
    parser.add_argument("bin_out", type=Path, help="Output binary file path")
    parser.add_argument("in_dir", type=Path, help="File path to input tex subdirectory")
    parser.add_argument(
        "--endian", choices=["big", "little"], default="big", help="Output endianness"
    )
    args = parser.parse_args()

    build(args.bin_out, args.in_dir, args.endian)
