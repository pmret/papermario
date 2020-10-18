#! /usr/bin/python3

import os
import json
import sys
from subprocess import call
from pathlib import Path
import shutil

tools_dir = Path(__file__).parent.absolute()

with open("assets/fs.json", "r") as f:
    config = json.loads(f.read())

def build_mapfs(src_dir, build_dir, out_bin):
    with open(out_bin, "wb") as f:
        f.write(config["title"].encode("ascii"))

        next_data_pos = 0x20 + (len(config["assets"]) + 1) * 0x1C

        asset_idx = 0
        for asset in config["assets"]:
            offset = 0x20 + asset_idx * 0x1C


            src_path = Path(src_dir, asset["path"])
            build_path = Path(build_dir, asset["path"])

            name = asset["name"]
            src_size = src_path.stat().st_size
            compressed_size = build_path.stat().st_size + 1

            print({
                "name": name,
                "offset": (next_data_pos + 0x20),
                "size": compressed_size,
                "decompressed_size": src_size,
            })

            # write TOC row
            f.seek(offset)
            f.write(name.encode('ascii'))
            f.seek(offset + 0x10)
            f.write((next_data_pos - 0x20).to_bytes(4, byteorder="big"))
            f.write(compressed_size.to_bytes(4, byteorder="big"))
            f.write(src_size.to_bytes(4, byteorder="big"))

            # write data
            f.seek(next_data_pos)
            f.write(build_path.read_bytes())
            next_data_pos += compressed_size

            asset_idx += 1

        f.seek(0x20 + asset_idx * 0x1C)
        f.write(b"end_data")

def build_file(src_dir, out_dir, filename):
    asset = None
    for a in config["assets"]:
        if (a["path"] == filename):
            asset = a

    if not asset:
        print("asset not configured in json file")
        exit(1)

    src_path = Path(src_dir, filename)
    out_path = Path(out_dir, filename)

    if asset["compress"]:
        call([f"{tools_dir}/Yay0compress", src_path, out_path])
    else:
        shutil.copy(src_path, out_path)

if __name__ == "__main__":
    if len(sys.argv) > 1:
        # copy (and compress if required) the given file
        build_file("assets/fs", "build/assets/fs", sys.argv[1])
    else:
        # build the aggregate file
        build_mapfs("assets/fs", "build/assets/fs", "build/assets/fs.bin")
