import struct
from enum import IntEnum
from pathlib import Path

from typing import List, Optional

from util import options
from util.gc.gcutil import read_string_from_bytes
from util.n64.Yay0decompress import Yay0Decompressor

from segtypes.gc.segment import GCSegment


# Represents the RARC archive format used by first-party Nintendo games.
class GcSegRarc(GCSegment):
    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs)

    def split(self, file_bytes):
        assert self.file_path is not None

        archive = GCRARCArchive(self.file_path, file_bytes)
        archive.build_hierarchy(file_bytes)

        archive.emit(file_bytes)

    def should_split(self) -> bool:
        return True


class GCRARCArchive:
    def __init__(self, file_path: Path, file_bytes):
        self.file_path = file_path
        self.compression = "none"
        file_bytes = self.try_decompress_archive(file_bytes)

        self.magic = struct.unpack_from(">I", file_bytes, 0x0000)[0]
        self.file_size = struct.unpack_from(">I", file_bytes, 0x0004)[0]
        self.data_header_offset = struct.unpack_from(">I", file_bytes, 0x0008)[0]
        self.file_data_offset = struct.unpack_from(">I", file_bytes, 0x000C)[0] + 0x0020
        self.total_file_data_size = struct.unpack_from(">I", file_bytes, 0x0010)[0]

        self.mram_preload_size = struct.unpack_from(">I", file_bytes, 0x0014)[0]
        self.aram_preload_size = struct.unpack_from(">I", file_bytes, 0x0018)[0]

        self.data_header = GCRARCDataHeader(self.data_header_offset, file_bytes)
        self.nodes: List[GCRARCNode] = []

    def try_decompress_archive(self, file_bytes):
        compression_scheme = struct.unpack_from(">I", file_bytes, 0x0000)[0]

        # Yaz0
        if compression_scheme == 0x59617A30:
            self.compression = "yaz0"
            return file_bytes
        # Yay0
        elif compression_scheme == 0x59617930:
            self.compression = "yay0"
            return Yay0Decompressor.decompress(file_bytes)
        # Not compressed!
        else:
            return file_bytes

    def build_hierarchy(self, file_bytes):
        string_table_offset = self.data_header.string_table_offset
        string_table_size = self.data_header.string_table_size

        string_table_bytes = file_bytes[
            string_table_offset : string_table_offset + string_table_size
        ]

        # Load the file entries into their corresponding nodes.
        for i in range(self.data_header.node_count):
            offset = self.data_header.node_offset + i * 0x10

            new_node = GCRARCNode(offset, file_bytes, string_table_bytes)
            new_node.get_entries(
                self.data_header.file_entry_offset, file_bytes, string_table_bytes
            )

            self.nodes.append(new_node)

        # Now, organize the nodes into a hierarchy.
        for n in self.nodes:
            for e in n.entries:
                # We're only looking for directory nodes, so ignore files.
                if e.flags & int(GCRARCFlags.IS_FILE) != 0x00:
                    continue

                if e.name == "." or e.name == "..":
                    continue

                # This is the node that the current entry corresponds to.
                dir_node = self.nodes[e.data_offset]

                # Set up hierarchy relationship.
                dir_node.parent = n
                n.children.append(dir_node)

    def emit(self, file_bytes):
        assert options.opts.filesystem_path is not None

        rel_path = self.file_path.relative_to(options.opts.filesystem_path / "files")
        arc_root_path = options.opts.asset_path / rel_path.with_suffix("")

        self.nodes[0].emit_to_filesystem_recursive(
            arc_root_path, self.file_data_offset, file_bytes
        )
        self.emit_config(arc_root_path)

    def emit_config(self, config_path: Path):
        lines = []

        lines.append(f'name: "{self.file_path.name}"\n')

        if self.compression != "none":
            lines.append(f"compression: {self.compression}\n")

        lines.append(f"next_file_id: 0x{self.data_header.next_free_file_id:04X}\n")
        lines.append(
            f"sync_file_ids_to_indices: {self.data_header.sync_file_ids_to_indices}\n"
        )

        root_node = self.nodes[0]

        lines.append("root_dir:\n")
        lines.append(f'  res_type: "{root_node.resource_type}"\n')
        lines.append(f'  name: "{root_node.name}"\n')

        if len(root_node.entries) != 0:
            lines.append("  entries:\n")
            for e in root_node.entries:
                entry_config = e.emit_config(2)
                if entry_config != None:
                    lines.extend(entry_config)

        if len(root_node.children) != 0:
            lines.append("  subdirs:\n")
            for n in root_node.children:
                node_config = n.emit_config(2)
                if node_config != None:
                    lines.extend(node_config)

        with open(config_path / "arcinfo.yaml", "w", newline="\n") as f:
            f.writelines(lines)


class GCRARCDataHeader:
    def __init__(self, offset, file_bytes):
        self.node_count = struct.unpack_from(">I", file_bytes, offset + 0x0000)[0]
        self.node_offset = (
            struct.unpack_from(">I", file_bytes, offset + 0x0004)[0] + 0x0020
        )

        self.file_entry_count = struct.unpack_from(">I", file_bytes, offset + 0x0008)[0]
        self.file_entry_offset = (
            struct.unpack_from(">I", file_bytes, offset + 0x000C)[0] + 0x0020
        )

        self.string_table_size = struct.unpack_from(">I", file_bytes, offset + 0x0010)[
            0
        ]
        self.string_table_offset = (
            struct.unpack_from(">I", file_bytes, offset + 0x0014)[0] + 0x0020
        )

        self.next_free_file_id = struct.unpack_from(">H", file_bytes, offset + 0x0018)[
            0
        ]
        self.sync_file_ids_to_indices = bool(file_bytes[offset + 0x001A])


class GCRARCNode:
    def __init__(self, offset, file_bytes, string_table_bytes):
        self.resource_type = file_bytes[offset + 0x0000 : offset + 0x0004].decode(
            "utf-8"
        )
        self.name_offset = struct.unpack_from(">I", file_bytes, offset + 0x0004)[0]
        self.name_hash = struct.unpack_from(">H", file_bytes, offset + 0x0008)[0]
        self.file_entry_count = struct.unpack_from(">H", file_bytes, offset + 0x000A)[0]
        self.first_file_entry_index = struct.unpack_from(
            ">I", file_bytes, offset + 0x000C
        )[0]

        self.name = read_string_from_bytes(self.name_offset, string_table_bytes)
        self.entries = []

        self.parent: Optional[GCRARCNode] = None
        self.children = []

    def get_entries(self, file_entry_offset, file_bytes, string_table_bytes):
        for i in range(self.file_entry_count):
            entry_offset = file_entry_offset + (self.first_file_entry_index + i) * 0x14

            new_entry = GCRARCFileEntry(entry_offset, file_bytes, string_table_bytes)
            new_entry.parent_node = self

            self.entries.append(new_entry)

    def emit_to_filesystem_recursive(
        self, root_path: Path, file_data_offset, file_bytes
    ):
        dir_path = root_path / self.get_full_directory_path()
        dir_path.mkdir(parents=True, exist_ok=True)

        for n in self.children:
            n.emit_to_filesystem_recursive(root_path, file_data_offset, file_bytes)

        for e in self.entries:
            e.emit_to_filesystem(root_path, file_data_offset, file_bytes)

    def emit_config(self, level):
        lines = []

        lines.append("  " * level + f'- res_type: "{self.resource_type}"\n')
        lines.append("  " * level + f'  name: "{self.name}"\n')

        if len(self.entries) != 0:
            lines.append("  " * level + "  entries:\n")
            for e in self.entries:
                entry_config = e.emit_config(level + 1)
                if entry_config != None:
                    lines.extend(entry_config)

        if len(self.children) != 0:
            lines.append("  " * level + "  subdirs:\n")
            for n in self.children:
                node_config = n.emit_config(level + 1)
                if node_config != None:
                    lines.extend(node_config)

        return lines

    def print_recursive(self, level):
        print(("  " * level) + self.name)

        for n in self.children:
            n.print_recursive(level + 1)

    def get_full_directory_path(self):
        path_components: List[str] = []

        node: Optional[GCRARCNode] = self
        while node is not None:
            path_components.insert(0, node.name)
            node = node.parent

        return Path(*path_components)


class GCRARCFileEntry:
    def __init__(self, offset, file_bytes, string_table_bytes):
        self.file_id = struct.unpack_from(">H", file_bytes, offset + 0x0000)[0]
        self.name_hash = struct.unpack_from(">H", file_bytes, offset + 0x0002)[0]
        self.flags = file_bytes[offset + 0x0004]
        self.name_offset = (
            struct.unpack_from(">I", file_bytes, offset + 0x0004)[0] & 0x00FFFFFF
        )
        self.data_offset = struct.unpack_from(">I", file_bytes, offset + 0x0008)[0]
        self.data_size = struct.unpack_from(">I", file_bytes, offset + 0x000C)[0]

        self.name = read_string_from_bytes(self.name_offset, string_table_bytes)
        self.parent_node: Optional[GCRARCNode] = None

    def emit_to_filesystem(self, dir_path: Path, file_data_offset, file_bytes):
        if self.flags & int(GCRARCFlags.IS_DIR) != 0x00:
            return

        file_path = dir_path / self.get_full_file_path()

        file_data = file_bytes[
            file_data_offset
            + self.data_offset : file_data_offset
            + self.data_offset
            + self.data_size
        ]
        with open(file_path, "wb") as f:
            f.write(file_data)

    def emit_config(self, level):
        if self.flags & int(GCRARCFlags.IS_DIR) != 0x00:
            return

        lines = []

        lines.append("  " * level + f'  - name: "{self.name}"\n')
        lines.append("  " * level + f"    file_id: 0x{self.file_id:04X}\n")

        if self.flags & int(GCRARCFlags.IS_COMPRESSED) != 0x00:
            if self.flags & int(GCRARCFlags.IS_YAZ0_COMPRESSED) != 0x00:
                lines.append("  " * level + f"    compression: yaz0\n")
            else:
                lines.append("  " * level + f"    compression: yay0\n")

        if self.flags & int(GCRARCFlags.PRELOAD_TO_MRAM) == 0x00:
            if self.flags & int(GCRARCFlags.PRELOAD_TO_ARAM) != 0x00:
                lines.append("  " * level + f"    preload_type: aram\n")
            else:
                lines.append("  " * level + f"    preload_type: dvd\n")

        return lines

    def get_full_file_path(self):
        path_components = [self.name]

        node = self.parent_node
        while node is not None:
            path_components.insert(0, node.name)
            node = node.parent

        return Path("/".join(path_components))


class GCRARCFlags(IntEnum):
    IS_FILE = 0x01
    IS_DIR = 0x02
    IS_COMPRESSED = 0x04
    PRELOAD_TO_MRAM = 0x10
    PRELOAD_TO_ARAM = 0x20
    LOAD_FROM_DVD = 0x40
    IS_YAZ0_COMPRESSED = 0x80
