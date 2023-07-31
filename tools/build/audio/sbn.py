#! /usr/bin/python3

import argparse
from sys import path
from pathlib import Path
import sys
from typing import Tuple

import yaml

sys.path.append(str(Path(__file__).parent.parent))
sys.path.append(str(Path(__file__).parent.parent.parent))
sys.path.append(str(Path(__file__).parent.parent.parent))
sys.path.append(str(Path(__file__).parent.parent.parent / "splat"))
from common import get_asset_path

# allow importing splat_ext
path.append(str(Path(__file__).parent.parent.parent))

from splat_ext.pm_sbn import SBN, BufferEntry, InitSongEntry, SBNFile


# Sorts a list of dicts by their "id" key. If "id" is "auto" or missing, it is sorted to the end.
def sort_by_id_or_auto(list):
    def get_id(item):
        id = item.get("id")
        return 0xFFFF if id == "auto" else id

    list.sort(key=get_id)


def from_yaml(yaml_path: Path, asset_stack: Tuple[Path, ...]) -> SBN:
    sbn = SBN()

    with yaml_path.open("r") as f:
        config = yaml.safe_load(f)

    unknown_bin_path = get_asset_path("audio/unknown.bin", asset_stack)
    with open(unknown_bin_path, "rb") as f:
        sbn.unknown_data = f.read()

    files = config.get("files", {})
    songs = config.get("songs", [])
    mseqs = config.get("mseqs", [])
    banks = config.get("banks", [])

    sort_by_id_or_auto(files)
    sort_by_id_or_auto(songs)
    sort_by_id_or_auto(mseqs)
    sort_by_id_or_auto(banks)

    # Read files
    for file_dict in files:
        id = file_dict.get("id", "auto")
        if id == "auto":
            id = len(sbn.files)
        assert type(id) == int

        filename = file_dict.get("file")
        assert type(filename) == str

        fakesize = file_dict.get("fakesize")
        assert type(fakesize) == int or fakesize is None

        sbn_file = SBNFile()
        sbn_file_path = get_asset_path(f"audio/{filename}", asset_stack)
        sbn_file.read(sbn_file_path)

        if fakesize is not None:
            sbn_file.fakesize = fakesize
        else:
            sbn_file.fakesize = sbn_file.size

        # Replace sbn.files[id]
        if id < len(sbn.files):
            print("Overwriting file ID {:02X}", id)
            sbn.files[id] = sbn_file
        elif id == len(sbn.files):
            sbn.files.append(sbn_file)
        else:
            raise Exception(f"Invalid file ID: 0x{id:02X} - cannot have gaps")

    # Read INIT songs
    for song in songs:
        id = song.get("id", "auto")
        if id == "auto":
            id = len(sbn.init.song_entries)
        assert type(id) == int

        # Lookup file ID
        file = song.get("file")
        assert type(file) == str
        file_id = sbn.lookup_file_id(file)

        # Lookup BK file IDs
        bk_files = song.get("bk_files", [])
        assert type(bk_files) == list
        bk_file_ids = []
        for bk_file in bk_files:
            if bk_file is None:
                bk_file_ids.append(0)
            else:
                assert type(bk_file) == str
                bk_file_ids.append(sbn.lookup_file_id(bk_file))

        init_song_entry = InitSongEntry(file_id, bk_file_ids[0], bk_file_ids[1], bk_file_ids[2])

        # Replace sbn.init.song_entries[id]
        if id < len(sbn.init.song_entries):
            print(f"Overwriting song ID {id:02X}")
            sbn.init.song_entries[id] = init_song_entry
        elif id == len(sbn.init.song_entries):
            sbn.init.song_entries.append(init_song_entry)
        else:
            raise Exception(f"Invalid song ID: 0x{id:02X} - cannot have gaps")

    # Read INIT mseqs
    for mseq in mseqs:
        id = mseq.get("id", "auto")
        if id == "auto":
            id = len(sbn.init.mseq_entries)
        assert type(id) == int

        # Lookup file ID
        file = mseq.get("file")
        assert type(file) == str
        file_id = sbn.lookup_file_id(file)

        # Replace sbn.init.mseq_entries[id]
        if id < len(sbn.init.mseq_entries):
            print(f"Overwriting MSEQ ID {id:02X}")
            sbn.init.mseq_entries[id] = file_id
        elif id == len(sbn.init.mseq_entries):
            sbn.init.mseq_entries.append(file_id)
        else:
            raise Exception(f"Invalid MSEQ ID: 0x{id:02X} - cannot have gaps")

    # Read INIT banks
    for bank in banks:
        id = bank.get("id", "auto")
        if id == "auto":
            id = len(sbn.init.bk_entries)
        assert type(id) == int

        file = bank.get("file")
        assert type(file) == str
        file_id = sbn.lookup_file_id(file)

        bank_index = bank.get("bank_index")
        assert type(bank_index) == int

        bank_group = bank.get("bank_group")
        assert type(bank_group) == int

        entry = BufferEntry(file_id, bank_index, bank_group)

        # Replace sbn.init.bk_entries[id]
        if id < len(sbn.init.bk_entries):
            print(f"Overwriting bank ID {id:02X}")
            sbn.init.bk_entries[id] = entry
        elif id == len(sbn.init.bk_entries):
            sbn.init.bk_entries.append(entry)
        else:
            raise Exception(f"Invalid bank ID: {id:02X} - cannot have gaps")
    return sbn


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Builds SBN")
    parser.add_argument("out")
    parser.add_argument("asset_stack")
    args = parser.parse_args()

    out_path = Path(args.out)
    asset_stack = tuple(Path(d) for d in args.asset_stack.split(","))

    yaml_path = get_asset_path(Path("audio/sbn.yaml"), asset_stack)
    sbn = from_yaml(yaml_path, asset_stack)

    data = sbn.encode()

    with open(out_path, "wb") as f:
        f.write(data)
