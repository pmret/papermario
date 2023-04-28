from pathlib import Path
import json
import struct
from typing import List


# splat imports; will fail if script run directly
try:
    from segtypes.n64.segment import N64Segment
    from segtypes.linker_entry import LinkerEntry
    from util import options
    splat_loaded = True
except ImportError:
    splat_loaded = False


def write_json(path: Path, data: dict):
    with open(path, "w") as f:
        json.dump(data, f, indent=4)


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
            sbn_file.decode(data[entry.offset:])
            self.files.append(sbn_file)

        # Decode INIT
        self.init.decode(data[header.INIToffset:])

        return len(data)

    def encode(self) -> bytes:
        raise NotImplementedError()

    # Write the files in the SBN to a directory.
    def write(self, path: Path):
        if not path.exists():
            path.mkdir()

        filenames = []
        for sbn_file in self.files:
            try:
                filename = sbn_file.file_name()
                filenames.append(filename)
                sbn_file.write(path / filename)
            except Exception as e:
                raise Exception(f"Failed to write {sbn_file}: {e}")

        # Write filenames to a file so we can encode in the correct order
        with open(path / "files.json", "w") as f:
            # TODO: consider dict instead of list, for merging
            f.write(json.dumps(filenames, indent=4))

        self.init.write(path / "init.json")

    # Reads files into this SBN.
    def read(self, paths: List[Path]):
        # should merge, not overwrite
        raise NotImplementedError()

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

    def write(self, path: Path):
        data = self.__dict__
        data.pop("signature")
        write_json(path, data)


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

    def decode(self, data: bytes) -> int:
        self.signature, = struct.unpack(">4s", data[0x00:0x04])
        self.size, = struct.unpack(">i", data[0x04:0x08])
        self.name, = struct.unpack(">4s", data[0x08:0x0C])
        self.data = data[:self.size]
        return self.size

    def write(self, path: Path):
        # unknown, so write binary file
        with open(path, "wb") as f:
            f.write(self.data)

    def file_name(self) -> str:
        stem = decode_null_terminated_ascii(self.name).rstrip(" ")
        extension = decode_null_terminated_ascii(self.signature).rstrip(" ").lower()
        return stem + "." + extension

    def __str__(self):
        return "SBNFile(" + self.file_name() + ")"


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
        entries_len = (header.entriesSize + 0xF) & 0xFFF0
        for i in range(entries_len):
            entry = BufferEntry()
            entries_addr += entry.decode(data[entries_addr:])
            self.bk_entries.append(entry)

        return len(data)

    def write(self, path: Path):
        # TODO: use dicts instead of lists, for merging
        data = {
            "song": [entry.to_dict() for entry in self.song_entries],
            "mseq": self.mseq_entries,
            "bk": [entry.to_dict() for entry in self.bk_entries]
        }
        write_json(path, data)


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

    def to_dict(self):
        return {
            "fileIndex": self.fileIndex,
            "bankIndex": self.bankIndex,
            "bankGroup": self.bankGroup,
        }

    @staticmethod
    def from_dict(dict: dict) -> "BufferEntry":
        entry = BufferEntry()
        entry.fileIndex = dict["fileIndex"]
        entry.bankIndex = dict["bankIndex"]
        entry.bankGroup = dict["bankGroup"]
        return entry


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
        # Get rid of trailing 0s
        while len(self.bkFileIndex) != 0 and self.bkFileIndex[-1] == 0:
            self.bkFileIndex.pop()

        return 0x08

    def to_dict(self):
        return self.__dict__

    @staticmethod
    def from_dict(dict: dict) -> "InitSongEntry":
        entry = InitSongEntry()
        entry.bgmFileIndex = dict["bgmFileIndex"]
        entry.bkFileIndex = dict["bkFileIndex"]
        return entry


if splat_loaded:
    class N64SegPm_sbn(N64Segment):
        sbn: SBN # TODO: remove, only available during split

        def split(self, rom_bytes):
            dir = options.opts.asset_path / self.dir / self.name
            data = rom_bytes[self.rom_start : self.rom_end]

            if dir.exists():
                raise Exception(f"SBN directory {dir} already exists")

            self.sbn = SBN()
            byte_count = self.sbn.decode(data)
            self.sbn.write(dir)

            if self.rom_end:
                assert byte_count == self.rom_end - self.rom_start
            else:
                self.rom_end = self.rom_start + byte_count

        def get_linker_entries(self):
            dir = options.opts.asset_path / self.dir / self.name
            out = options.opts.asset_path / self.dir / (self.name + ".sbn")

            inputs = [dir / "init.json", dir / "files.json"]
            # TODO: read dir instead, this wont work when not splitting
            # read dir should list every dir in the asset stack and merge them
            inputs += [dir / f.file_name() for f in self.sbn.files]

            return [
                LinkerEntry(
                    self,
                    inputs,
                    out,
                    ".data",
                ),
            ]


# For testing, run from root directory with `python -m tools.splat_ext.pm_sbn`.
if __name__ == "__main__":
    with open("ver/us/baserom.z64", "rb") as f:
        f.seek(0xF00000)
        data = f.read()

    dir = Path("assets/us/audio")
    sbn = SBN()
    sbn.decode(data)
    sbn.write(dir)
    print(dir)
