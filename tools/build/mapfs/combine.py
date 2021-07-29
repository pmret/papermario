#! /usr/bin/python3

import os
from sys import argv
from pathlib import Path
from itertools import tee

def next_multiple(pos, multiple):
    return pos + pos % multiple

def get_version_date(version):
    if version == "us":
        return "Map Ver.00/11/07 15:36"
    elif version == "jp":
        return "Map Ver.00/07/05 19:13"
    else:
        return "Map Ver.??/??/?? ??:??"

def build_mapfs(out_bin, assets, version):
    # every TOC entry's name field has data after the null terminator made up from all the previous name fields.
    # we probably don't have to do this for the game to read the data properly (it doesn't read past the null terminator
    # of `string`), but the original devs' equivalent of this script had this bug so we need to replicate it to match.
    written_names = []

    with open(out_bin, "wb") as f:
        f.write(get_version_date(version).encode("ascii"))

        next_data_pos = (len(assets) + 1) * 0x1C

        asset_idx = 0
        for decompressed, compressed in assets:
            toc_entry_pos = 0x20 + asset_idx * 0x1C

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
    version = argv.pop(0)
    out = argv.pop(0)

    assets = []

    # pairs
    for i in range(0, len(argv), 2):
        assets.append((Path(argv[i]), Path(argv[i+1])))

    build_mapfs(out, assets, version)
