import struct
from pathlib import Path
from typing import List, Optional

from segtypes.gc.segment import GCSegment

from util import options
from util.gc.gcutil import read_string_from_bytes


# Represents the info for either a directory or a file within a GameCube disc image's file system.
class GCFSTEntry:
    def __init__(self, flags: bool, name_offset, offset, length):
        self.flags = flags
        self.name_offset = name_offset
        self.offset = offset
        self.length = length

        self.name = ""
        self.parent: Optional[GCFSTEntry] = None
        self.children: List[GCFSTEntry] = []

    def populate_children_recursive(
        self, root_dir: "GCFSTEntry", current_node_offset, fst_bytes, string_table_bytes
    ):
        self.parent = root_dir
        self.name = read_string_from_bytes(self.name_offset, string_table_bytes)

        # This node is a file, so we don't do anything but return that we read 1 node.
        if self.flags == False:
            return 1

        nodes_read = 1
        next_child_offset = current_node_offset + 0x0C

        # Directory nodes contain the index of the next node that is NOT its child, meaning the index of their next sibling node.
        # We can figure out when we're done reading child nodes by comparing the offset of the next node to read to the
        # offset of the next sibling node. We stop reading when the next node offset is >= the offset of the next sibling node.
        while next_child_offset < self.length * 0x0C:
            new_entry = GCFSTEntry(
                bool(fst_bytes[next_child_offset + 0x0000]),
                struct.unpack_from(
                    ">I", fst_bytes[next_child_offset : next_child_offset + 0x0004]
                )[0]
                & 0x00FFFFFF,
                struct.unpack_from(">I", fst_bytes, next_child_offset + 0x0004)[0],
                struct.unpack_from(">I", fst_bytes, next_child_offset + 0x0008)[0],
            )

            self.children.append(new_entry)
            nodes_read += new_entry.populate_children_recursive(
                self, next_child_offset, fst_bytes, string_table_bytes
            )

            next_child_offset = current_node_offset + nodes_read * 0x0C

        return nodes_read

    # Builds this entry's full path within the filesystem from its parents' names.
    def get_full_name(self):
        path_components: List[str] = []

        entry = self
        while entry.parent != None:
            path_components.insert(0, entry.name)

            if entry.parent is None:
                break
            entry = entry.parent

        return Path(*path_components)

    # Emits this entry to the filesystem.
    def emit(self, filesystem_dir: Path, iso_bytes):
        full_path = filesystem_dir / self.get_full_name()

        # If this is a directory, we just need to make the directory on disk.
        if self.flags == True:
            full_path.mkdir(parents=True, exist_ok=True)
            return

        file_bytes = iso_bytes[self.offset : self.offset + self.length]
        with open(full_path, "wb") as f:
            f.write(file_bytes)

    def emit_recursive(self, filesystem_dir: Path, iso_bytes):
        # Don't emit if this is the root directory.
        if self.parent != None:
            self.emit(filesystem_dir, iso_bytes)

        for e in self.children:
            e.emit_recursive(filesystem_dir, iso_bytes)


# Splits the ISO into its component parts - header info, apploader, DOL, FST metadata, and the individual files in the filesystem.
def split_iso(iso_bytes):
    split_sys_info(iso_bytes)
    split_content(iso_bytes)


# Splits the header info, apploader, DOL, and FST metadata from the ISO.
def split_sys_info(iso_bytes):
    assert options.opts.filesystem_path is not None

    sys_path = options.opts.filesystem_path / "sys"
    sys_path.mkdir(parents=True, exist_ok=True)

    # Split boot.info. Always at 0x0000 and 0x0440 bytes long.
    with open(sys_path / "boot.bin", "wb") as f:
        f.write(iso_bytes[0x0000:0x0440])

    # Split bi2.info. Always at 0x0440 and 0x2000 bytes long.
    with open(sys_path / "bi2.bin", "wb") as f:
        f.write(iso_bytes[0x0440:0x2440])

    # Split apploader.img. Always at 0x2440 and size is listed at 0x0400.
    apploader_size = struct.unpack_from(">I", iso_bytes, 0x0400)[0]
    with open(sys_path / "apploader.img", "wb") as f:
        f.write(iso_bytes[0x2440 : 0x2440 + apploader_size])

    # Split main.dol. Offset specified explicitly at 0x0420, but size must be calculated.
    dol_offset = struct.unpack_from(">I", iso_bytes, 0x0420)[0]
    fst_offset = struct.unpack_from(">I", iso_bytes, 0x0424)[0]

    dol_size = fst_offset - dol_offset
    with open(sys_path / "main.dol", "wb") as f:
        f.write(iso_bytes[dol_offset : dol_offset + dol_size])

    # Split fst.bin. Offset specified at 0x0424 and size specified at 0x402C.
    fst_size = struct.unpack_from(">I", iso_bytes, 0x0428)[0]
    with open(sys_path / "fst.bin", "wb") as f:
        f.write(iso_bytes[fst_offset : fst_offset + fst_size])


# Splits the ISO's filesystem into individual files.
def split_content(iso_bytes):
    assert options.opts.filesystem_path is not None

    fst_path = options.opts.filesystem_path / "sys" / "fst.bin"
    assert fst_path.is_file()

    fst_bytes = fst_path.read_bytes()
    fst_root_entry = populate_filesystem(fst_bytes)

    files_path = options.opts.filesystem_path / "files"
    files_path.mkdir(parents=True, exist_ok=True)
    fst_root_entry.emit_recursive(files_path, iso_bytes)


# Loads the FST data needed to split the filesystem.
def populate_filesystem(fst_bytes):
    root_dir = GCFSTEntry(
        bool(fst_bytes[0x0000]),
        struct.unpack_from(">I", fst_bytes, 0x0000)[0] & 0x00FFFFFF,
        struct.unpack_from(">I", fst_bytes, 0x0004)[0],
        struct.unpack_from(">I", fst_bytes, 0x0008)[0],
    )

    string_table_bytes = fst_bytes[root_dir.length * 0x0C : len(fst_bytes)]

    # Parsing the filesystem is a bit tricky. The root directory's length property is the total number of nodes in the FST.
    # So, we initialize nodes_read to 1, since the root is included in the number of nodes.
    # We will rely on each directory and file on the root directory to tell us how many nodes were read while parsing them.
    # We can stop reading the FST when our total number of nodes read is >= the number of nodes in the FST.
    nodes_read = 1
    while nodes_read < root_dir.length:
        current_offset = nodes_read * 0x0C

        new_entry = GCFSTEntry(
            bool(fst_bytes[current_offset + 0x0000]),
            struct.unpack_from(">I", fst_bytes, current_offset)[0] & 0x00FFFFFF,
            struct.unpack_from(">I", fst_bytes, current_offset + 0x0004)[0],
            struct.unpack_from(">I", fst_bytes, current_offset + 0x0008)[0],
        )

        root_dir.children.append(new_entry)
        nodes_read += new_entry.populate_children_recursive(
            root_dir, current_offset, fst_bytes, string_table_bytes
        )

    return root_dir
