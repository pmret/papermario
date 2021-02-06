import os
from segtypes.n64.segment import N64Segment
from pathlib import Path
from util.n64 import Yay0decompress
from util.color import unpack_color
from util.iter import iter_in_groups
import png


def decode_null_terminated_ascii(data):
    length = 0
    for byte in data:
        if byte == 0:
            break
        length += 1

    return data[:length].decode('ascii')


def parse_palette(data):
        palette = []

        for a, b in iter_in_groups(data, 2):
            palette.append(unpack_color([a, b]))

        return palette


class N64SegPaperMarioMapFS(N64Segment):
    def __init__(self, segment, next_segment, options):
        super().__init__(segment, next_segment, options)

    def split(self, rom_bytes, base_path):
        bin_dir = self.create_split_dir(base_path, self.options.get("assets_dir", "bin"))
        img_party_dir = self.create_split_dir(base_path, self.options.get("assets_dir", "img") + "/party")

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
            elif name.startswith("party_"):
                path = os.path.join(img_party_dir, "{}.png".format(name))
            elif name.endswith("_hit") or name.endswith("_shape"):
                area = "area_" + name.split("_")[0][0:3]
                map_dir = self.create_split_dir(base_path, self.options.get("assets_dir", "bin") + f"/map/{area}")

                path = os.path.join(map_dir, "{}.bin".format(name))
            elif name.endswith("_tex"):
                map_dir = self.create_split_dir(base_path, self.options.get("assets_dir", "bin") + f"/map/texture")
                path = os.path.join(map_dir, "{}.bin".format(name))
            else:
                path = os.path.join(bin_dir, "{}.bin".format(name))

            if name == "end_data":
                break

            bytes = rom_bytes[self.rom_start + 0x20 +
                                offset: self.rom_start + 0x20 + offset + size]

            Path(path).parent.mkdir(parents=True, exist_ok=True)

            if is_compressed:
                self.log(f"Decompressing {name}...")
                bytes = Yay0decompress.decompress_yay0(bytes)

            if name.startswith("party_"):
                with open(path, "wb") as f:
                    # CI-8
                    w = png.Writer(150, 105, palette=parse_palette(bytes[:0x200]))
                    w.write_array(f, bytes[0x200:])
            else:
                with open(path, "wb") as f:
                    f.write(bytes)

            self.log(f"Wrote {name} to {Path(bin_dir, path)}")

            asset_idx += 1


    def get_ld_files(self):
        return [(self.options.get("assets_dir", "bin"), self.name, ".data", self.rom_start)]


    @staticmethod
    def get_default_name(addr):
        return "assets"
