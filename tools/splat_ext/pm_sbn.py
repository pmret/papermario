from pathlib import Path
import os
import yaml
import struct
from typing import Any, Dict, List, Optional
from collections import OrderedDict


# splat imports; will fail if script run directly
try:
    from segtypes.n64.segment import N64Segment
    from segtypes.linker_entry import LinkerEntry
    from util import options
    splat_loaded = True
except ImportError:
    splat_loaded = False


def decode_null_terminated_ascii(data):
    length = 0
    for byte in data:
        if byte == 0:
            break
        length += 1

    return data[:length].decode("ascii")


class SBN:
    files: List["SBNFile"]
    init: "INIT"

    def __init__(self):
        self.files = []
        self.init = INIT()

    def decode(self, data: bytes):
        # Decode header
        header = SBNHeader()
        header.decode(data)

        data = data[:header.size]

        # Decode file entries
        entry_addr = header.tableOffset
        seen_entry_offsets = set()
        for i in range(header.numEntries):
            entry = SBNFileEntry()
            entry_addr += entry.decode(data[entry_addr:])

            # Check for duplicate entry offsets
            if entry.offset in seen_entry_offsets:
                raise Exception("Duplicate SBN file entry: {:08}", entry.offset)
            seen_entry_offsets.add(entry.offset)

            # Decode file at entry
            sbn_file = SBNFile()
            sbn_file.decode(data[entry.offset:], i)
            self.files.append(sbn_file)

        # Decode INIT
        self.init.decode(data[header.INIToffset:])

        return len(data)

    def encode(self) -> bytes:
        data = bytearray()

        # TODO
        raise NotImplementedError()

        return bytes(data)

    # Write the files in the SBN to a directory.
    def write(self, path: Path):
        if not path.exists():
            path.mkdir()

        for sbn_file in self.files:
            try:
                filename = sbn_file.file_name()
                sbn_file.write(path / filename)
            except Exception as e:
                raise Exception(f"Failed to write {sbn_file}: {e}")

        with open(path / "sbn.yaml", "w") as f:
            # Filename->ID map
            f.write("# Mapping of filenames to entry IDs. Use 'id: auto' to automatically assign a unique ID.\n")
            f.write("files:\n")
            for id, sbn_file in enumerate(self.files):
                filename = sbn_file.file_name()
                f.write(f"  - id: 0x{id:02X}\n")
                f.write(f"    file: {filename}\n")

            f.write("\n")

            # INIT songs
            f.write("# Songs. Use 'id: auto' to automatically assign a unique ID.\n")
            f.write("# Symbols are used to generate the SongIDs C enum.\n")
            f.write("songs:\n")
            for id, entry in enumerate(self.init.song_entries):
                bgm_file_name = self.files[entry.bgmFileIndex].file_name()
                bk_file_names = []
                for index in entry.bkFileIndex:
                    if index == 0:
                        bk_file_names.append("null")
                    else:
                        bk_file_names.append(self.files[index].file_name())
                f.write(f"  - id: 0x{id:02x}\n")
                f.write(f"    symbol: {get_song_symbol_name(id)}\n")
                f.write(f"    file: {bgm_file_name}\n")
                f.write(f"    bk_files: [{', '.join(bk_file_names)}]\n")
            f.write("\n")

            # INIT mseqs
            f.write("# AuGlobals::mseqFileList. Not sure why there's non-MSEQ files here!\n")
            f.write("mseqs:\n")
            for id, entry in enumerate(self.init.mseq_entries):
                f.write(f"  - id: 0x{id:02x}\n")
                f.write(f"    file: {self.files[entry].file_name()}\n")

            # INIT banks
            f.write("# BK file list.\n")
            f.write("banks:\n")
            for id, entry in enumerate(self.init.bk_entries):
                f.write(f"  - id: 0x{id:02x}\n")
                if entry.fileIndex != -1:
                    f.write(f"    file: {self.files[entry.fileIndex].file_name()}\n")                    
                f.write(f"    bank_index: 0x{entry.bankIndex:02X}\n")
                f.write(f"    bank_group: 0x{entry.bankGroup:02X}\n")
            f.write("\n")

    def read(self, dir: Path) -> List[Path]:
        config_file_path = dir / "sbn.yaml"
        with config_file_path.open("r") as f:
            config = yaml.safe_load(f)

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
                id = len(self.files)
            assert type(id) == int

            filename = file_dict.get("file")
            assert type(filename) == str

            sbn_file = SBNFile()
            sbn_file.read(dir / filename)

            # Replace self.files[id]
            if id < len(self.files):
                print("Overwriting file ID {:02X}", id)
                self.files[id] = sbn_file
            elif id == len(self.files):
                self.files.append(sbn_file)
            else:
                raise Exception(f"Invalid file ID: 0x{id:02X} - cannot have gaps")

        # Read INIT songs
        for song in songs:
            id = song.get("id", "auto")
            if id == "auto":
                id = len(self.init.song_entries)
            assert type(id) == int

            # Lookup file ID
            file = song.get("file")
            assert type(file) == str
            file_id = self.lookup_file_id(file)

            # Lookup BK file IDs
            bk_files = song.get("bk_files", [])
            assert type(bk_files) == list
            bk_file_ids = []
            for bk_file in bk_files:
                if bk_file is None:
                    bk_file_ids.append(0)
                else:
                    assert type(bk_file) == str
                    bk_file_ids.append(self.lookup_file_id(bk_file))

            init_song_entry = InitSongEntry()
            init_song_entry.bgmFileIndex = file_id
            init_song_entry.bkFileIndex = bk_file_ids

            # Replace self.init.song_entries[id]
            if id < len(self.init.song_entries):
                print(f"Overwriting song ID {id:02X}")
                self.init.song_entries[id] = init_song_entry
            elif id == len(self.init.song_entries):
                self.init.song_entries.append(init_song_entry)
            else:
                raise Exception(f"Invalid song ID: 0x{id:02X} - cannot have gaps")

        # Read INIT mseqs
        for mseq in mseqs:
            id = mseq.get("id", "auto")
            if id == "auto":
                id = len(self.init.mseq_entries)
            assert type(id) == int

            # Lookup file ID
            file = mseq.get("file")
            assert type(file) == str
            file_id = self.lookup_file_id(file)

            # Replace self.init.mseq_entries[id]
            if id < len(self.init.mseq_entries):
                print(f"Overwriting MSEQ ID {id:02X}")
                self.init.mseq_entries[id] = file_id
            elif id == len(self.init.mseq_entries):
                self.init.mseq_entries.append(file_id)
            else:
                raise Exception(f"Invalid MSEQ ID: 0x{id:02X} - cannot have gaps")

        # Read INIT banks
        for bank in banks:
            id = bank.get("id", "auto")
            if id == "auto":
                id = len(self.init.bk_entries)
            assert type(id) == int

            file = bank.get("file")    
            assert (type(file) == str or file is None)
            file_id = self.lookup_file_id(file)

            bank_index = bank.get("bank_index")
            assert type(bank_index) == int

            bank_group = bank.get("bank_group")
            assert type(bank_group) == int

            entry = BufferEntry()
            entry.fileIndex = file_id
            entry.bankIndex = bank_index
            entry.bankGroup = bank_group

            # Replace self.init.bk_entries[id]
            if id < len(self.init.bk_entries):
                print(f"Overwriting bank ID {id:02X}")
                self.init.bk_entries[id] = entry
            elif id == len(self.init.bk_entries):
                self.init.bk_entries.append(entry)
            else:
                raise Exception(f"Invalid bank ID: {id:02X} - cannot have gaps")

        return [config_file_path]


    def lookup_file_id(self, filename: Optional[str]) -> int:
        if filename is None:
            return -1
        for id, sbn_file in enumerate(self.files):
            if sbn_file.file_name() == filename:
                return id
        raise Exception(f"File not found: {filename} - is it in the file_id_map?")

    def __str__(self) -> str:
        s = "SBN(\n"
        s += "  files=[\n"
        for sbn_file in self.files:
            s += f"    {sbn_file},\n"
        s += "  ],\n"
        s += f"  init={self.init}\n"
        s += ")"
        return s

    def __hash__(self) -> int:
        h = 0
        for sbn_file in self.files:
            h ^= hash(sbn_file)
        h ^= hash(self.init)
        return h

class SBNHeader:
    signature: bytes
    size: int
    unk_08: int
    unk_0C: int
    tableOffset: int
    numEntries: int
    unk_18: int
    unk_1C: int
    unk_20: int
    INIToffset: int
    unk_28: int
    unk_2C: int
    unk_30: int
    unk_34: int
    unk_38: int
    unk_3C: int

    def decode(self, data: bytes) -> int:
        self.signature, = struct.unpack(">4s", data[0x00:0x04])
        self.size, = struct.unpack(">i", data[0x04:0x08])
        self.unk_08, = struct.unpack(">i", data[0x08:0x0C])
        self.unk_0C, = struct.unpack(">i", data[0x0C:0x10])
        self.tableOffset, = struct.unpack(">i", data[0x10:0x14])
        self.numEntries, = struct.unpack(">i", data[0x14:0x18])
        self.unk_18, = struct.unpack(">i", data[0x18:0x1C])
        self.unk_1C, = struct.unpack(">i", data[0x1C:0x20])
        self.unk_20, = struct.unpack(">i", data[0x20:0x24])
        self.INIToffset, = struct.unpack(">i", data[0x24:0x28])
        self.unk_28, = struct.unpack(">i", data[0x28:0x2C])
        self.unk_2C, = struct.unpack(">i", data[0x2C:0x30])
        self.unk_30, = struct.unpack(">i", data[0x30:0x34])
        self.unk_34, = struct.unpack(">i", data[0x34:0x38])
        self.unk_38, = struct.unpack(">i", data[0x38:0x3C])
        self.unk_3C, = struct.unpack(">i", data[0x3C:0x40])
        assert(self.signature == b"SBN ")
        return 0x40


class SBNFileEntry:
    offset: int
    fmt: int
    unk__05: int
    size: int

    def decode(self, data: bytes) -> int:
        self.offset, = struct.unpack(">i", data[0x00:0x04])
        self.fmt = data[0x04]
        self.unk__05 = data[0x05]
        self.size, = struct.unpack(">h", data[0x06:0x08])
        return 0x08


class SBNFile:
    signature: bytes
    size: int
    name: bytes
    data: bytes

    ident: int # we have to track this ourselves because filenames aren't unique

    def decode(self, data: bytes, ident: int) -> int:
        self.signature, = struct.unpack(">4s", data[0x00:0x04])
        self.size, = struct.unpack(">i", data[0x04:0x08])
        self.name, = struct.unpack(">4s", data[0x08:0x0C])
        self.data = data[:self.size]
        self.ident = ident

        return self.size

    def write(self, path: Path):
        with open(path, "wb") as f:
            f.write(self.data)

    def read(self, path: Path):
        with open(path, "rb") as f:
            data = f.read()

        filename = os.path.basename(path)

        ident = int(filename.split("_")[0],16)

        assert self.decode(data, ident) == len(data), "File size mismatch"

    def file_name(self) -> str:
        prefix = f"{self.ident:02X}_"
        stem = decode_null_terminated_ascii(self.name).rstrip(" ")
        extension = decode_null_terminated_ascii(self.signature).rstrip(" ").lower()
        return prefix + stem + "." + extension

    def __str__(self):
        return "SBNFile(" + self.file_name() + ")"

    def __hash__(self):
        return hash((self.signature, self.size, self.name, self.data))


# Could extend SBNFile as BGM etc in future if we want higher-level formats


class INIT:
    song_entries = List["InitSongEntry"]
    mseq_entries: List[int]
    bk_entries: List["BufferEntry"]

    def __init__(self):
        self.song_entries = []
        self.mseq_entries = []
        self.bk_entries = []

    def decode(self, data: bytes) -> int:
        # see au_load_INIT

        header = INITHeader()
        header.decode(data)

        data = data[:header.size]

        # Decode song list
        song_addr = header.tblOffset
        while True:
            try:
                song = InitSongEntry()
                song_addr += song.decode(data[song_addr:])
                self.song_entries.append(song)
            except EndOfDataException:
                break

        # Decode MSEQ list
        mseq_addr = header.shortsOffset
        while True:
            mseq, = struct.unpack(">h", data[mseq_addr:mseq_addr+2])
            mseq_addr += 2
            if mseq < 0:
                break
            self.mseq_entries.append(mseq)

        # Decode BK file list
        entries_addr = header.entriesOffset
        entries_len = (header.entriesSize + 0xF) & 0xFFF0 # TODO: make sure python math isnt fucking up here - BKs seem to end after 0x95
        for i in range(entries_len):
            entry = BufferEntry()
            entries_addr += entry.decode(data[entries_addr:])
            self.bk_entries.append(entry)

        return len(data)

    def __str__(self) -> str:
        s = "INIT(\n"
        s += "  song_entries = [\n"
        for song in self.song_entries:
            s += f"    {song},\n"
        s += "  ],\n"
        s += "  mseq_entries = [\n"
        for mseq in self.mseq_entries:
            s += f"    {mseq},\n"
        s += "  ],\n"
        s += "  bk_entries = [\n"
        for bk in self.bk_entries:
            s += f"    {bk},\n"
        s += "  ]\n"
        s += ")"
        return s

    def __hash__(self):
        h = 0
        for song in self.song_entries:
            h ^= hash(song)
        for mseq in self.mseq_entries:
            h ^= hash(mseq)
        for bk in self.bk_entries:
            h ^= hash(bk)
        return h


class INITHeader:
    signature: bytes
    size: int
    entriesOffset: int
    entriesSize: int
    tblOffset: int
    tblSize: int
    shortsOffset: int
    shortsSize: int
    unk_14: bytes

    def decode(self, data: bytes) -> int:
        self.signature, = struct.unpack(">4s", data[0x00:0x04])
        self.size, = struct.unpack(">i", data[0x04:0x08])
        self.entriesOffset, = struct.unpack(">h", data[0x08:0x0A])
        self.entriesSize, = struct.unpack(">h", data[0x0A:0x0C])
        self.tblOffset, = struct.unpack(">h", data[0x0C:0x0E])
        self.tblSize, = struct.unpack(">h", data[0x0E:0x10])
        self.shortsOffset, = struct.unpack(">h", data[0x10:0x12])
        self.shortsSize, = struct.unpack(">h", data[0x12:0x14])
        self.unk_14 = data[0x14:0x20]
        assert(self.signature == b"INIT")
        return 0x20


# see au_load_BK_headers
class BufferEntry:
    fileIndex: int
    bankIndex: int
    bankGroup: int

    def decode(self, data: bytes) -> int:
        self.fileIndex, = struct.unpack(">h", data[0x00:0x02])
        self.bankIndex = data[0x02]
        self.bankGroup = data[0x03]
        return 0x04

    def __str__(self) -> str:
        return f"BufferEntry({self.fileIndex}, {self.bankIndex}, {self.bankGroup})"

    def __hash__(self) -> int:
        return hash((self.fileIndex, self.bankIndex, self.bankGroup))


class EndOfDataException(Exception):
    pass


class InitSongEntry:
    bgmFileIndex: int
    bkFileIndex: List[int]

    def decode(self, data: bytes) -> int:
        self.bgmFileIndex, = struct.unpack(">h", data[0x00:0x02])
        if self.bgmFileIndex < 0:
            raise EndOfDataException()
        self.bkFileIndex = [
            struct.unpack(">h", data[0x02:0x04])[0],
            struct.unpack(">h", data[0x04:0x06])[0],
            struct.unpack(">h", data[0x06:0x08])[0]
        ]
        return 0x08

    def __str__(self) -> str:
        return f"InitSongEntry({self.bgmFileIndex}, {self.bkFileIndex})"

    def __hash__(self) -> int:
        return hash((self.bgmFileIndex, sum(self.bkFileIndex)))


if splat_loaded:
    class N64SegPm_sbn(N64Segment):
        def split(self, rom_bytes):
            dir = options.opts.asset_path / self.dir / self.name
            data = rom_bytes[self.rom_start : self.rom_end]

            if dir.exists():
                raise Exception(f"SBN directory {dir} already exists")

            sbn = SBN()
            byte_count = sbn.decode(data)
            sbn.write(dir)

            if self.rom_end:
                assert byte_count == self.rom_end - self.rom_start
            else:
                self.rom_end = self.rom_start + byte_count

        def get_linker_entries(self):
            dir = options.opts.asset_path / self.dir / self.name
            out = options.opts.asset_path / self.dir / (self.name + ".sbn")

            sbn = SBN()
            config_files = sbn.read(dir) # TODO: LayeredFS/AssetsFS read, supporting merges
            inputs = config_files + [dir / f.file_name() for f in sbn.files]
            return [
                LinkerEntry(
                    self,
                    inputs,
                    out,
                    ".data",
                ),
            ]

def get_song_symbol_name(song_id: int) -> str:
    song_names = {
        0x00000000: "SONG_TOAD_TOWN",
        0x00000002: "SONG_NORMAL_BATTLE",
        0x00000003: "SONG_SPECIAL_BATTLE",
        0x00000004: "SONG_JR_TROOPA_BATTLE",
        0x00000005: "SONG_FINAL_BOWSER_BATTLE",
        0x00000007: "SONG_GOOMBA_KING_BATTLE",
        0x00000008: "SONG_KOOPA_BROS_BATTLE",
        0x00000009: "SONG_FAKE_BOWSER_BATTLE",
        0x0000000A: "SONG_TUTANKOOPA_BATTLE",
        0x0000000B: "SONG_TUBBA_BLUBBA_BATTLE",
        0x0000000C: "SONG_GENERAL_GUY_BATTLE",
        0x0000000D: "SONG_LAVA_PIRANHA_BATTLE",
        0x0000000E: "SONG_HUFF_N_PUFF_BATTLE",
        0x0000000F: "SONG_CRYSTAL_KING_BATTLE",
        0x00000010: "SONG_GOOMBA_VILLAGE",
        0x00000011: "SONG_PLEASANT_PATH",
        0x00000012: "SONG_FUZZY_ATTACK",
        0x00000013: "SONG_KOOPA_VILLAGE",
        0x00000014: "SONG_KOOPA_FORTRESS",
        0x00000015: "SONG_DRY_DRY_OUTPOST",
        0x00000016: "SONG_MT_RUGGED",
        0x00000017: "SONG_DRY_DRY_DESERT",
        0x00000018: "SONG_DRY_DRY_RUINS",
        0x00000019: "SONG_RUINS_BASEMENT",
        0x0000001A: "SONG_FOREVER_FOREST",
        0x0000001B: "SONG_BOOS_MANSION",
        0x0000001C: "SONG_CHEERFUL_BOOS_MANSION",
        0x0000001D: "SONG_GUSTY_GULCH",
        0x0000001E: "SONG_TUBBAS_MANOR",
        0x0000001F: "SONG_TUBBA_ESCAPE",
        0x00000020: "SONG_SHY_GUY_TOYBOX",
        0x00000021: "SONG_TOYBOX_TRAIN",
        0x00000022: "SONG_CREEPY_TOYBOX",
        0x00000024: "SONG_JADE_JUNGLE",
        0x00000025: "SONG_DEEP_JUNGLE",
        0x00000026: "SONG_YOSHIS_VILLAGE",
        0x00000027: "SONG_YOSHIS_PANIC",
        0x00000028: "SONG_RAPHAEL_RAVEN",
        0x00000029: "SONG_MT_LAVALAVA",
        0x0000002A: "SONG_VOLCANO_ESCAPE",
        0x0000002B: "SONG_STAR_WAY_OPENS",
        0x0000002C: "SONG_MASTER_BATTLE",
        0x0000002D: "SONG_RADIO_ISLAND_SOUNDS",
        0x0000002E: "SONG_RADIO_HOT_HITS",
        0x0000002F: "SONG_RADIO_GOLDEN_OLDIES",
        0x00000030: "SONG_FLOWER_FIELDS_CLOUDY",
        0x00000031: "SONG_FLOWER_FIELDS_SUNNY",
        0x00000032: "SONG_CLOUDY_CLIMB",
        0x00000033: "SONG_PUFF_PUFF_MACHINE",
        0x00000034: "SONG_SUN_TOWER_CLOUDY",
        0x00000035: "SONG_SUN_TOWER_SUNNY",
        0x00000037: "SONG_CRYSTAL_PALACE",
        0x00000038: "SONG_SHIVER_CITY",
        0x00000039: "SONG_PENGUIN_MYSTERY",
        0x0000003A: "SONG_SHIVER_SNOWFIELD",
        0x0000003B: "SONG_SHIVER_MOUNTAIN",
        0x0000003C: "SONG_STARBORN_VALLEY",
        0x0000003D: "SONG_MERLAR_THEME",
        0x0000003E: "SONG_MAIL_CALL",
        0x0000003F: "SONG_PEACHS_CASTLE_PARTY",
        0x00000040: "SONG_CHAPTER_END",
        0x00000041: "SONG_CHAPTER_START",
        0x00000042: "SONG_ITEM_UPGRADE",
        0x00000044: "SONG_PHONOGRAPH_MUSIC",
        0x00000045: "SONG_TUTANKOOPA_THEME",
        0x00000046: "SONG_KAMMY_KOOPA_THEME",
        0x00000047: "SONG_JR_TROOPA_THEME",
        0x00000048: "SONG_BULLET_BILL_ASSAULT",
        0x00000049: "SONG_MONTY_MOLE_ASSAULT",
        0x0000004A: "SONG_SHY_GUY_INVASION",
        0x0000004B: "SONG_TOAD_TOWN_TUNNELS",
        0x0000004C: "SONG_WHALE_THEME",
        0x0000004D: "SONG_FOREVER_FOREST_WARNING",
        0x0000004E: "SONG_YOSHI_KIDS_FOUND",
        0x0000004F: "SONG_UNUSED_FANFARE",
        0x00000050: "SONG_GOOMBA_KING_THEME",
        0x00000051: "SONG_KOOPA_BROS_INTERLUDE",
        0x00000052: "SONG_KOOPA_BROS_THEME",
        0x00000053: "SONG_TUTANKOOPA_WARNING",
        0x00000054: "SONG_TUTANKOOPA_REVEALED",
        0x00000055: "SONG_TUBBA_BLUBBA_THEME",
        0x00000056: "SONG_GENERAL_GUY_THEME",
        0x00000057: "SONG_LAVA_PIRANHA_THEME",
        0x00000058: "SONG_HUFF_N_PUFF_THEME",
        0x00000059: "SONG_CRYSTAL_KING_THEME",
        0x0000005A: "SONG_BLOOPER_THEME",
        0x0000005B: "SONG_MINIBOSS_BATTLE",
        0x0000005C: "SONG_MONSTAR_THEME",
        0x0000005D: "SONG_CLUB64",
        0x0000005E: "SONG_UNUSED_OPENING",
        0x0000005F: "SONG_BOWSERS_CASTLE_FALLS",
        0x00000060: "SONG_STAR_HAVEN",
        0x00000061: "SONG_SHOOTING_STAR_SUMMIT",
        0x00000062: "SONG_STARSHIP_THEME",
        0x00000063: "SONG_STAR_SANCTUARY",
        0x00000064: "SONG_BOWSERS_CASTLE",
        0x00000065: "SONG_BOWSERS_CASTLE_CAVES",
        0x00000066: "SONG_BOWSER_THEME",
        0x00000067: "SONG_BOWSER_BATTLE",
        0x00000068: "SONG_PEACH_WISHES",
        0x00000069: "SONG_FILE_SELECT",
        0x0000006A: "SONG_MAIN_THEME",
        0x0000006B: "SONG_BOWSER_ATTACKS",
        0x0000006C: "SONG_MARIO_FALLS",
        0x0000006D: "SONG_PEACH_APPEARS",
        0x0000006E: "SONG_THE_END",
        0x0000006F: "SONG_RECOVERED_STAR_ROD",
        0x00000070: "SONG_TWINK_THEME",
        0x00000071: "SONG_STIRRING_CAKE",
        0x00000072: "SONG_GOURMET_GUY_FREAKOUT",
        0x00000073: "SONG_PRISONER_PEACH_THEME",
        0x00000074: "SONG_PEACH_MISSION",
        0x00000075: "SONG_PEACH_SNEAKING",
        0x00000076: "SONG_PEACH_CAUGHT",
        0x00000077: "SONG_PEACH_QUIZ_INTRO",
        0x00000078: "SONG_STAR_SPIRIT_THEME",
        0x00000079: "SONG_PENGUIN_WHODUNIT",
        0x0000007A: "SONG_PENGUIN_WAKES_UP",
        0x0000007B: "SONG_MAGIC_BEANSTALK",
        0x0000007C: "SONG_MERLEE_SPELL",
        0x0000007D: "SONG_LAKILESTER_THEME",
        0x0000007E: "SONG_GOOMBA_BROS_RETREAT",
        0x0000007F: "SONG_SUNSHINE_RETURNS",
        0x00000080: "SONG_RIDING_THE_RAILS",
        0x00000081: "SONG_RIDING_THE_WHALE",
        0x00000082: "SONG_NEW_PARTNER",
        0x00000083: "SONG_DRY_DRY_RUINS_APPEAR",
        0x00000084: "SONG_CANDY_CANES",
        0x00000085: "SONG_PLAYROOM",
        0x00000086: "SONG_MOUSTAFA_THEME",
        0x00000087: "SONG_GAME_OVER",
        0x00000088: "SONG_TAKING_REST",
        0x00000089: "SONG_FLOWER_NPC_THEME",
        0x0000008A: "SONG_FLOWER_GATE_APPEARS",
        0x0000008B: "SONG_BATTLE_END",
        0x0000008C: "SONG_POP_DIVA_SONG",
        0x0000008D: "SONG_BOO_MINIGAME",
        0x0000008E: "SONG_LEVEL_UP",
        0x00000090: "SONG_PARADE_DAY",
        0x00000091: "SONG_PARADE_NIGHT",
        0x00000094: "SONG_MARIO_BROS_HOUSE",
        0x00000095: "SONG_INTRO_STORY",
        0x00000096: "SONG_NEW_PARTNER_JP",
    }
    return song_names.get(song_id, f"null")


# Sorts a list of dicts by their "id" key. If "id" is "auto" or missing, it is sorted to the end.
def sort_by_id_or_auto(list):
    def get_id(item):
        id = item.get("id")
        return 0xFFFF if id == "auto" else id

    list.sort(key=get_id)


# For testing, run from root directory with `python -m tools.splat_ext.pm_sbn`.
if __name__ == "__main__":
    with open("ver/us/baserom.z64", "rb") as f:
        f.seek(0xF00000)
        data = f.read()

    dir = Path("assets/us/audio")

    with open("sbn_a.sbn", "wb") as f:
        f.write(data)

    # Write to directory
    sbn = SBN()
    sbn.decode(data)
    sbn.write(dir)
    with open("sbn_a.txt", "w") as f:
        f.write(str(sbn))
    print("Wrote to directory:", dir)
    expected_hash = hash(sbn)

    # Read back and check matching
    sbn = SBN()
    sbn.read(dir)
    with open("sbn_b.txt", "w") as f:
        f.write(str(sbn))
    assert hash(sbn) == expected_hash, "read-write mismatch! try `diff sbn_a.txt sbn_b.txt`"
    data_b = sbn.encode()
    with open("sbn_b.sbn", "wb") as f:
        f.write(data_b)
    assert data_b == data, "encode-decode mismatch! try `vbindiff sbn_a.sbn sbn_b.sbn`"
