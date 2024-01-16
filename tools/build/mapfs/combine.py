#!/usr/bin/env python3

from sys import argv
from pathlib import Path
import struct


def next_multiple(pos, multiple):
    return pos + pos % multiple


def get_version_date(version):
    if version == "us":
        return "Map Ver.00/11/07 15:36"
    elif version == "jp":
        return "Map Ver.00/07/05 19:13"
    elif version == "pal":
        return "Map Ver.01/03/23 16:30"
    elif version == "ique":
        return "Map Ver.04/05/18 13:41"
    else:
        return "Map Ver.??/??/?? ??:??"


def build_mapfs(out_bin, assets, version, pre_write_assets):
    # every TOC entry's name field has data after the null terminator made up from all the previous name fields.
    # we probably don't have to do this for the game to read the data properly (it doesn't read past the null terminator
    # of `string`), but the original devs' equivalent of this script had this bug so we need to replicate it to match.

    with open(out_bin, "wb") as f:
        f.write(get_version_date(version).encode("ascii"))

        next_data_pos = (len(assets) + 1) * 0x1C

        asset_idx = 0
        lastname = ""
        for decompressed, compressed in assets:
            toc_entry_pos = 0x20 + asset_idx * 0x1C

            # data for TOC entry
            name = decompressed.stem + "\0"
            offset = next_data_pos
            decompressed_size = decompressed.stat().st_size
            size = next_multiple(compressed.stat().st_size, 2) if compressed.exists() else decompressed_size

            if version == "ique" and decompressed.stem == "title_data":
                size = compressed.stat().st_size

            # print(f"{name} {offset:08X} {size:08X} {decompressed_size:08X}")

            # write all previously-written names; required to match
            lastname = name + lastname[len(name) :]
            f.seek(toc_entry_pos)
            f.write(lastname.encode("ascii"))

            # write TOC entry.
            f.seek(toc_entry_pos + 0x10)
            f.write(struct.pack(">III", offset, size, decompressed_size))

            # initial data to be overwritten back, provided by .raw.dat files
            pre_write_bytes = b""
            if pre_write_assets.get(decompressed.stem):
                with open(pre_write_assets[decompressed.stem], "rb") as pwf:
                    pre_write_bytes = pwf.read()
                f.seek(0x20 + next_data_pos)
                f.write(pre_write_bytes)

            # write data.
            f.seek(0x20 + next_data_pos)
            f.write(compressed.read_bytes() if compressed.exists() else decompressed.read_bytes())
            next_data_pos += max(len(pre_write_bytes), size)

            asset_idx += 1

        # end_data
        toc_entry_pos = 0x20 + asset_idx * 0x1C

        last_name_entry = "end_data\0"
        f.seek(toc_entry_pos)
        lastname = last_name_entry + lastname[len(last_name_entry) :]
        f.write(lastname.encode("ascii"))

        f.seek(toc_entry_pos + 0x18)
        f.write((0x903F0000).to_bytes(4, byteorder="big"))  # TODO: figure out purpose


if __name__ == "__main__":
    argv.pop(0)  # python3
    version = argv.pop(0)
    out = argv.pop(0)

    assets = []
    pre_write_assets = {}

    for path in argv:
        path = Path(path)
        if path.suffixes[-2:] == [".raw", ".dat"]:
            pre_write_assets[path.with_suffix("").stem] = path
        else:
            assets.append(path)

    # turn them into pairs
    assets = list(zip(assets[::2], assets[1::2]))

    build_mapfs(out, assets, version, pre_write_assets)
