#! /usr/bin/python3

import os
from sys import argv
from pathlib import Path

def next_multiple(pos, multiple):
    return pos + pos % multiple

def build_mapfs(out_bin, assets):
    # every TOC entry's name field has data after the null terminator made up from all the previous name fields.
    # we probably don't have to do this for the game to read the data properly (it doesn't read past the null terminator
    # of `string`), but the original devs' equivalent to build_assets_fs.py had this bug so we need to replicate it to match.
    written_names = []

    with open(out_bin, "wb") as f:
        f.write("Map Ver.00/11/07 15:36".encode("ascii"))

        next_data_pos = (len(assets) + 1) * 0x1C

        asset_idx = 0
        for decompressed in assets:
            toc_entry_pos = 0x20 + asset_idx * 0x1C

            decompressed = Path(decompressed)
            compressed = decompressed.with_suffix(".Yay0")

            # non-texture assets should be compressed
            if not decompressed.stem.endswith("_tex") and not compressed.exists():
                print(f"uncompressed asset: {decompressed} (expected {compressed} to exist)")
                exit(1)

            # data for TOC entry
            name = decompressed.stem + "\0"
            offset = next_data_pos
            decompressed_size = decompressed.stat().st_size
            size = next_multiple(compressed.stat().st_size, 2) if compressed.exists() else decompressed_size

            #print(f"{name} {offset:08X} {size:08X} {decompressed_size:08X}")

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
            f.write(compressed.read_bytes() if compressed.exists() else decompressed.read_bytes())
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

if __name__ == "__main__":
    argv.pop(0) # python3
    out = argv.pop(0)

    build_mapfs(out, argv)
