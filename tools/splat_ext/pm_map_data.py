from segtypes.n64.segment import N64Segment
from segtypes.n64.ia8 import N64SegIa8
from segtypes.n64.rgba32 import N64SegRgba32
from segtypes.n64.ci4 import N64SegCi4
from util.n64 import Yay0decompress
from util.color import unpack_color
from util.iter import iter_in_groups
from util import options
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

def add_file_ext(name: str) -> str:
    if name.startswith("party_"):
        return name + ".png"
    elif name.endswith("_hit") or name.endswith("_shape"):
        return name + ".bin" # TODO: xml
    elif name.endswith("_tex"):
        return name + ".bin" # TODO: texture archive
    elif name.endswith("_bg"):
        return name + ".png"
    else:
        return name + ".bin"

class N64SegPm_map_data(N64Segment):
    def __init__(self, rom_start, rom_end, type, name, vram_start, extract, given_subalign, given_is_overlay, given_dir, args, yaml):
        super().__init__(rom_start, rom_end, type, name, vram_start, extract, given_subalign, given_is_overlay, given_dir, args, yaml)

        self.files = yaml["files"]

    def split(self, rom_bytes):
        fs_dir = options.get_asset_path() / self.dir / self.name
        (fs_dir / "title").mkdir(parents=True, exist_ok=True)

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
                path = fs_dir / add_file_ext(name)

            if name == "end_data":
                break

            bytes_start = self.rom_start + 0x20 + offset
            bytes = rom_bytes[bytes_start : bytes_start + size]

            if is_compressed:
                bytes = Yay0decompress.decompress_yay0(bytes)

            if name.startswith("party_"):
                with open(path, "wb") as f:
                    # CI-8
                    w = png.Writer(150, 105, palette=parse_palette(bytes[:0x200]))
                    w.write_array(f, bytes[0x200:])
            elif name == "title_data":
                if "ver/us" in options.opts["target_path"]:
                    with open(fs_dir / "title/logotype.png", "wb") as f:
                        width = 200
                        height = 112
                        N64SegRgba32.get_writer(width, height).write_array(f, N64SegRgba32.parse_image(bytes[0x2210 : 0x2210 + width * height * 4], width, height))

                    with open(fs_dir / "title/copyright.png", "wb") as f:
                        width = 144
                        height = 32
                        N64SegIa8.get_writer(width, height).write_array(f, N64SegIa8.parse_image(bytes[0x10 : 0x10 + width * height], width, height))

                    with open(fs_dir / "title/press_start.png", "wb") as f:
                        width = 128
                        height = 32
                        N64SegIa8.get_writer(width, height).write_array(f, N64SegIa8.parse_image(bytes[0x1210 : 0x1210 + width * height], width, height))
                else:
                    with open(fs_dir / "title/logotype.png", "wb") as f:
                        width = 272
                        height = 88
                        N64SegRgba32.get_writer(width, height).write_array(f, N64SegRgba32.parse_image(bytes[0x1830 : 0x1830 + width * height * 4], width, height))

                    with open(fs_dir / "title/copyright.png", "wb") as f:
                        width = 128
                        height = 32

                        w = png.Writer(width, height, palette=parse_palette(bytes[0x810:0x830]))
                        w.write_array(f, N64SegCi4.parse_image(bytes[0x10 : 0x10 + width * height], width, height))

                    with open(fs_dir / "title/press_start.png", "wb") as f:
                        width = 128
                        height = 32
                        N64SegIa8.get_writer(width, height).write_array(f, N64SegIa8.parse_image(bytes[0x830 : 0x830 + width * height], width, height))
            elif name.endswith("_bg"):
                def write_bg_png(bytes, path, header_offset=0):
                    header = bytes[header_offset:header_offset+0x10]

                    raster_offset = int.from_bytes(header[0:4], byteorder="big") - 0x80200000
                    palette_offset = int.from_bytes(header[4:8], byteorder="big") - 0x80200000
                    assert int.from_bytes(header[8:12], byteorder="big") == 0x000C0014 # draw pos
                    width = int.from_bytes(header[12:14], byteorder="big")
                    height = int.from_bytes(header[14:16], byteorder="big")

                    with open(path, "wb") as f:
                        # CI-8
                        w = png.Writer(width, height, palette=parse_palette(bytes[palette_offset:palette_offset+512]))
                        w.write_array(f, bytes[raster_offset:])

                write_bg_png(bytes, path)

                # sbk_bg has an alternative palette
                if name == "sbk_bg":
                    write_bg_png(bytes, fs_dir / f"{name}.alt.png", header_offset=0x10)
            else:
                with open(path, "wb") as f:
                    f.write(bytes)

            asset_idx += 1

    def get_linker_entries(self):
        from segtypes.linker_entry import LinkerEntry

        fs_dir = options.get_asset_path() / self.dir / self.name

        return [LinkerEntry(
            self,
            [fs_dir / add_file_ext(name) for name in self.files],
            fs_dir.with_suffix(".dat"), ".data"),
        ]
