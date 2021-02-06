import os
from segtypes.n64.segment import N64Segment
from pathlib import Path
from util.n64 import Yay0decompress


def decode_null_terminated_ascii(data):
    length = 0
    for byte in data:
        if byte == 0:
            break
        length += 1

    return data[:length].decode('ascii')


class N64SegPaperMarioMapFS(N64Segment):
    def __init__(self, segment, next_segment, options):
        super().__init__(segment, next_segment, options)

    def split(self, rom_bytes, base_path):
        bin_dir = self.create_split_dir(base_path, self.options.get("assets_dir", "bin"))

        data = rom_bytes[self.rom_start: self.rom_end]

        asset_idx = 0
        while True:
            asset_data = data[0x20 + asset_idx * 0x1C:]

            name = decode_null_terminated_ascii(asset_data[0:])
            offset = int.from_bytes(asset_data[0x10:0x14], byteorder="big")
            size = int.from_bytes(asset_data[0x14:0x18], byteorder="big")
            decompressed_size = int.from_bytes(
                asset_data[0x18:0x1C], byteorder="big")

            is_compressed = size != decompressed_size

            if offset == 0:
                path = None
            else:
                path = "{}.bin".format(name)
                self.create_parent_dir(bin_dir, path)

            if name == "end_data":
                break

            with open(os.path.join(bin_dir, path), "wb") as f:
                bytes = rom_bytes[self.rom_start + 0x20 +
                                  offset: self.rom_start + 0x20 + offset + size]

                if is_compressed:
                    self.log(f"Decompressing {name}...")
                    bytes = Yay0decompress.decompress_yay0(bytes)

                f.write(bytes)
                self.log(f"Wrote {name} to {Path(bin_dir, path)}")

            asset_idx += 1


    def get_ld_files(self):
        return [(self.options.get("assets_dir", "bin"), self.name, ".data", self.rom_start)]


    @staticmethod
    def get_default_name(addr):
        return "assets"
