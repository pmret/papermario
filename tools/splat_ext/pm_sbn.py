from pathlib import Path
from dataclasses import astuple, dataclass
import os
import yaml
import struct
from typing import Any, Dict, List
from collections import OrderedDict
from functools import total_ordering


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

def align(misaligned: int):
    return  (misaligned + 0xf) &(~0xf)
    

class SBN:
    files: List["SBNFile"]
    unknown_data: bytes
    init: "INIT"

    def __init__(self):
        self.files = []
        self.init = INIT()

    def decode(self, data: bytes):
        # Decode header
        header = SBNHeader(*struct.unpack_from(SBNHeader.fstring, data ))

        data = data[:header.size]

        self.unknown_data = data[0x7a0:0x7c0]

        print(f"Total size: {header.size}")

        # Decode file entries
        entry_addr = header.tableOffset
        seen_entry_offsets = set()


        for i in range(header.numEntries):
            entry = SBNFileEntry(*struct.unpack_from(SBNFileEntry.fstring, data, entry_addr))
            entry_addr += SBNFileEntry.length

            # Check for duplicate entry offsets
            if entry.offset in seen_entry_offsets:
                raise Exception("Duplicate SBN file entry: {:08}", entry.offset)
            seen_entry_offsets.add(entry.offset)

            # Decode file at entry
            sbn_file = SBNFile()
<<<<<<< HEAD
            sbn_file.decode(data[entry.offset:])
=======
            file_length = sbn_file.decode(data[entry.offset:], i)
            sbn_file.fakesize = entry.size
>>>>>>> af8e30b7c (Encoding functional)
            self.files.append(sbn_file)

        # Decode INIT
        self.init.decode(data[header.INIToffset:], header.INIToffset)

        for idx, file in enumerate(self.files):
            if os.path.splitext(file.file_name())[1] != ".bgm":
                continue

            print(f"Potential human readable names for {file.file_name()}: ")
            for sid, song in enumerate(self.init.song_entries):
                if song.bgmFileIndex == idx:
                    print(f" - {get_song_symbol_name(sid)}.bgm")



        return len(data)

    def encode(self) -> bytes:
        numBytes = 0
        numBytes += 0x40 # header

        entriesOffset = numBytes
        numBytes += 8 * len(self.files) # file entry table.
        numBytes = align(numBytes)
        
        unknownDataOffset = numBytes
        numBytes += 0x20 # unknown data

        filesOffset = numBytes
        for file in self.files:
            numBytes += file.size # file data itself
            numBytes = align(numBytes)
        
        initHeaderOffset = numBytes
        numBytes += 0x20 # init table header
        
        bankEntryOffset = numBytes
        numBytes +=  4 * len(self.init.bk_entries) # bank entries
        numBytes += 4 # bank sentinel
        bankEntryEnd = numBytes
        numBytes = align(numBytes)

        songEntryOffset = numBytes
        numBytes += 8 * len(self.init.song_entries) # song entries
        numBytes += 8 # song sentinel
        songEntryEnd = numBytes
        numBytes = align(numBytes)

        mseqOffset = numBytes
        numBytes += 2 * len(self.init.mseq_entries) # mseq entries
        numBytes += 2 # mseq sentinel
        mseqEnd = numBytes

        initFileEnd = numBytes
        numBytes = align(numBytes)

        data = bytearray(numBytes)

        # header

        header = SBNHeader(
            size = numBytes,
            tableOffset = entriesOffset,
            numEntries = len(self.files),
            INIToffset = initHeaderOffset,
        )

        struct.pack_into(SBNHeader.fstring, data, 0, *header)

        #unknown data
        for offset, byte in enumerate(self.unknown_data):
            data[unknownDataOffset + offset] = byte 

        # files
        currFileOffset = filesOffset
        for index, file in enumerate(self.files):


            extension = os.path.splitext(file.file_name())[1]
            
            format = {
                ".bgm": 0x10,
                ".sef": 0x20,
                ".bk": 0x30,
                ".prg": 0x40,
                ".mseq": 0x40,
                ".per": 0x40,
            }.get(extension, 0)
            
            entry = SBNFileEntry(
                offset = currFileOffset,
                fmt = format,
                size = file.fakesize
            )

            struct.pack_into(SBNFileEntry.fstring, data, entriesOffset + index * SBNFileEntry.length, *entry)

            for offset,byte in enumerate(file.data):
                data[currFileOffset + offset] = byte

            currFileOffset += file.size
            currFileOffset = align(currFileOffset)


        initHeader = INITHeader(
            size = initFileEnd - initHeaderOffset,

            tblOffset = songEntryOffset - initHeaderOffset,
            tblSize = songEntryEnd - songEntryOffset,

            entriesOffset = bankEntryOffset - initHeaderOffset,
            entriesSize = bankEntryEnd - bankEntryOffset,

            shortsOffset = mseqOffset - initHeaderOffset,
            shortsSize = mseqEnd - mseqOffset,
        )

        struct.pack_into(INITHeader.fstring, data, initHeaderOffset, *initHeader)

        currBankOffset = bankEntryOffset
        for bank in self.init.bk_entries:
            struct.pack_into(BufferEntry.fstring, data, currBankOffset, *bank)
            currBankOffset += BufferEntry.length

        sentinel = BufferEntry(0xffff, 0x00, 0x00)
        struct.pack_into(BufferEntry.fstring, data, currBankOffset, *sentinel)

        currSongOffset = songEntryOffset
        for song in self.init.song_entries:
            struct.pack_into(InitSongEntry.fstring, data, currSongOffset, *song)
            currSongOffset += InitSongEntry.length

        sentinel = InitSongEntry(0xffff,0x00,0x00,0x00)
        struct.pack_into(InitSongEntry.fstring, data, currSongOffset, *sentinel)

        currMseqOffset = mseqOffset
        for mseq in self.init.mseq_entries:
            struct.pack_into(">H", data, currMseqOffset, mseq)
            currMseqOffset += 2
        struct.pack_into(">H", data, currMseqOffset, 0xffff)

        return bytes(data)

    # Write the files in the SBN to a directory.
    def write(self, path: Path):
        if not path.exists():
            path.mkdir()
        
        with open("unknown.bin", "wb") as f:
            f.write(self.unknown_data)

        for sbn_file in self.files:
            try:
                filename = sbn_file.file_name()
                sbn_file.write(path / filename)
            except Exception as e:
                raise Exception(f"Failed to write {sbn_file}: {e}")

        with open(path / "sbn.yaml", "w") as f:
            # Filename->ID map
            f.write("# Mapping of filenames to entry IDs. Use 'id: auto' to automatically assign a unique ID.\n")
            f.write("""
# 'fakesize is an interesting case. In the final ROM, the size of a file is stored in the file header and the entry table. 
# For bank files, however, the entry table has seemingly random data stored for file size. This data appears to be unused.
# Rather than figure out how this data is actually generated, I hardcoded it. What does this mean for modders?
# Well, for non bank files and bankfiles less than 65536 bytes it means nothing. Simply don't set the fakesize field and it will be fine. 
# As for bank files that are more than 65536 bytes long, you have to set fakesize to something but it doesn't appear to matter what.\n""")

            f.write("files:\n")
            for id, sbn_file in enumerate(self.files):
                filename = sbn_file.file_name()
                f.write(f"  - id: 0x{id:02X}\n")
                f.write(f"    file: {filename}\n")

                if(sbn_file.fakesize != sbn_file.size):
                    f.write(f"    fakesize: {sbn_file.fakesize}\n")

            f.write("\n")

            # INIT songs
            f.write("# Songs. Use 'id: auto' to automatically assign a unique ID.\n")
            f.write("# Symbols are used to generate the SongIDs C enum.\n")
            f.write("songs:\n")
            for id, entry in enumerate(self.init.song_entries):
                bgm_file_name = self.files[entry.bgmFileIndex].file_name()
                bk_file_names = []
                for index in (entry.bkFile0Index, entry.bkFile1Index, entry.bkFile2Index):
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
                f.write(f"    file: {self.files[entry.fileIndex].file_name()}\n")
                f.write(f"    bank_index: 0x{entry.bankIndex:02X}\n")
                f.write(f"    bank_group: 0x{entry.bankGroup:02X}\n")
            f.write("\n")

    def read(self, dir: Path) -> List[Path]:
        config_file_path = dir / "sbn.yaml"
        with config_file_path.open("r") as f:
            config = yaml.safe_load(f)

        with open("unknown.bin", "rb") as f:
            self.unknown_data = f.read()

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

            fakesize = file_dict.get("fakesize")
            assert type(fakesize) == int or fakesize is None

            sbn_file = SBNFile()
            sbn_file.read(dir / filename)

            if fakesize is not None:
                sbn_file.fakesize = fakesize
            else:
                sbn_file.fakesize = sbn_file.size

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

            init_song_entry = InitSongEntry(file_id, bk_file_ids[0], bk_file_ids[1], bk_file_ids[2])

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

<<<<<<< HEAD
            file = bank.get("file")
=======
            file = bank.get("file")    
>>>>>>> af8e30b7c (Encoding functional)
            assert type(file) == str
            file_id = self.lookup_file_id(file)

            bank_index = bank.get("bank_index")
            assert type(bank_index) == int

            bank_group = bank.get("bank_group")
            assert type(bank_group) == int

            entry = BufferEntry(file_id, bank_index, bank_group)

            # Replace self.init.bk_entries[id]
            if id < len(self.init.bk_entries):
                print(f"Overwriting bank ID {id:02X}")
                self.init.bk_entries[id] = entry
            elif id == len(self.init.bk_entries):
                self.init.bk_entries.append(entry)
            else:
                raise Exception(f"Invalid bank ID: {id:02X} - cannot have gaps")

        return [config_file_path]


    def lookup_file_id(self, filename: str) -> int:
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

@dataclass
class SBNHeader:
    signature: bytes = b"SBN "
    size: int = 0
    unk_08: int = 0
    unk_0C: int = 0
    tableOffset: int = 0
    numEntries: int = 0
    unk_18: int = 0x07c0 # TODO figure out what these are, don't hardcode
    unk_1C: int = 0x07a0 # TODO figure out what these are, don't hardcode
    unk_20: int = 0
    INIToffset: int = 0
    unk_28: int = 0
    unk_2C: int = 0
    unk_30: int = 0
    unk_34: int = 0
    unk_38: int = 0
    unk_3C: int = 0

    fstring = ">4siii iiii iiii iiii"
    length = 0x40

    def __iter__(self):
        return iter(astuple(self))

    def __post_init__(self):
        assert(self.signature == b"SBN ")

    
@dataclass
class SBNFileEntry:
    offset: int
    fmt: int
    unk__05: int = 0
    size: int = 0
    
    fstring = ">iBBh"
    length = 0x08

    def __iter__(self):
        return iter(astuple(self))

class SBNFile:
    signature: bytes
    size: int

    name: bytes
    data: bytes

<<<<<<< HEAD
    def decode(self, data: bytes) -> int:
=======
    host_system_name: str
    # the "size" field of the SBN File entry usually, but not always, matches the actual file size.
    # since this field is unused (I think), it doesn't actually matter other than for reproducing the original cart
    # I couldn't figure out the pattern behind these fake sizes (if there even is one), so I'm just hardcoding them.
    fakesize: int
    def decode(self, data: bytes, ident: int) -> int:
>>>>>>> af8e30b7c (Encoding functional)
        self.signature, = struct.unpack(">4s", data[0x00:0x04])
        self.size, = struct.unpack(">i", data[0x04:0x08])
        self.name, = struct.unpack(">4s", data[0x08:0x0C])
        self.data = data[:self.size]
        return self.size

    def write(self, path: Path):
        with open(path, "wb") as f:
            f.write(self.data)

    def read(self, path: Path):
        with open(path, "rb") as f:
            data = f.read()
        assert self.decode(data) == len(data), "File size mismatch"

    def file_name(self) -> str:
        stem = decode_null_terminated_ascii(self.name).rstrip(" ")
        extension = decode_null_terminated_ascii(self.signature).rstrip(" ").lower()
        return stem + "." + extension

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

    def decode(self, data: bytes, offset: int) -> int:
        # see au_load_INIT

        header = INITHeader(*struct.unpack_from(INITHeader.fstring, data))

        data = data[:header.size]
        # Decode song list
        song_addr = header.tblOffset
        song_number = 0
        while True:
            song = InitSongEntry(*struct.unpack_from(InitSongEntry.fstring, data, song_addr))

            if(song.bgmFileIndex == 0xffff):
                break
            song_addr_old = song_addr
            song_addr += song.length
            self.song_entries.append(song)

            song_number += 1

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
        # header.entriesSize represents the size of the entries table in bytes.
        # the sentinel value at the end of the list is included in this size byte, so subtract 1 to not load it
        entries_len = header.entriesSize // 4 - 1 

        for i in range(entries_len):
            entry = BufferEntry(*struct.unpack_from(BufferEntry.fstring, data, entries_addr))
            entries_addr_old = entries_addr
            entries_addr += BufferEntry.length

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

@dataclass
class INITHeader:
    signature: bytes = b"INIT"
    size: int = 0
    entriesOffset: int = 0
    entriesSize: int = 0
    tblOffset: int = 0
    tblSize: int = 0
    shortsOffset: int = 0
    shortsSize: int = 0
    unk_14: int = 0
    unk_18: int = 0
    unk_1c: int = 0

    fstring = ">4si hhhh hhi ii "
    length = 0x20

    def __iter__(self):
        return iter(astuple(self))

    def __post__init__(self) -> int:
        assert(self.signature == b"INIT")


# see au_load_BK_headers
@dataclass(frozen=True)
class BufferEntry:
    fileIndex: int
    bankIndex: int
    bankGroup: int

    fstring = ">HBB"
    length = 0x04

    def __iter__(self):
        return iter(astuple(self))

class EndOfDataException(Exception):
    pass

@dataclass(frozen = True)
class InitSongEntry:
    bgmFileIndex: int
    bkFile0Index: int
    bkFile1Index: int
    bkFile2Index: int

    fstring = ">Hhhh"
    length = 0x08

    def __iter__(self):
        return iter(astuple(self))


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

    size, = struct.unpack_from(">i", data, 4)

    data = data[:size]

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
