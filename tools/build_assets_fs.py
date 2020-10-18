#! /usr/bin/python3

import os
import json
import sys
from subprocess import call
from pathlib import Path
import shutil

tools_dir = Path(__file__).parent.absolute()

def next_multiple(pos, multiple):
    return pos + pos % multiple

def build_mapfs(src_dir, build_dir, out_bin):
    with open(src_dir + ".json", "r") as f:
        config = json.loads(f.read())

    # every TOC entry's name field has data after the null terminator made up from all the previous name fields.
    # we probably don't have to do this for the game to read the data properly (it doesn't read past the null terminator
    # of `string`), but the original devs' equivalent to build_assets_fs.py had this bug so we need to replicate it to match.
    written_names = []

    with open(out_bin, "wb") as f:
        f.write(config["title"].encode("ascii"))

        next_data_pos = (len(config["assets"]) + 1) * 0x1C

        asset_idx = 0
        for asset in config["assets"]:
            toc_entry_pos = 0x20 + asset_idx * 0x1C

            src_path = Path(src_dir, asset["path"])
            build_path = Path(build_dir, asset["path"])

            # data for TOC entry
            name = asset["name"] + "\0"
            offset = next_data_pos
            size = next_multiple(build_path.stat().st_size, 2)
            decompressed_size = src_path.stat().st_size

            print(f"{name} {offset:08X} {size:08X} {decompressed_size:08X}")

            written_names.append(name)
            # write all previously-written names; required to match
            for prev_name in written_names:
                f.seek(toc_entry_pos)
                f.write(prev_name.encode('ascii'))

            # write TOC entry.
            f.seek(toc_entry_pos + 0x10)
            f.write(offset.to_bytes(4, byteorder="big"))
            f.write(size.to_bytes(4, byteorder="big"))
            f.write(decompressed_size.to_bytes(4, byteorder="big"))

            # write data.
            f.seek(0x20 + next_data_pos)
            f.write(build_path.read_bytes())
            next_data_pos += size

            asset_idx += 1

        # end_data
        toc_entry_pos = 0x20 + asset_idx * 0x1C

        written_names.append("end_data\0")
        for prev_name in written_names:
            f.seek(toc_entry_pos)
            f.write(prev_name.encode('ascii'))

        f.seek(toc_entry_pos + 0x18)
        f.write((0x903F0000).to_bytes(4, byteorder="big")) # TODO: figure out purpose

def build_file(src_dir, out_dir, filename):
    with open(src_dir + ".json", "r") as f:
        config = json.loads(f.read())

    asset = None
    for a in config["assets"]:
        if (a["path"] == filename):
            asset = a

    if not asset:
        print("asset not configured in {}.json".format(src_dir))
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
