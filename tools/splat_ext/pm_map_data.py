from math import ceil
import os, sys
from pathlib import Path

import crunch64
from splat.segtypes.n64.segment import N64Segment
from common import iter_in_groups
from splat.util import options
import png  # type: ignore
import yaml as yaml_loader
import n64img.image
from tex_archives import TexArchive

script_dir = Path(os.path.dirname(os.path.realpath(__file__)))


def decode_null_terminated_ascii(data):
    length = 0
    for byte in data:
        if byte == 0:
            break
        length += 1

    return data[:length].decode("ascii")


def parse_palette(data):
    palette = []

    # RRRRRGGG GGBBBBBA
    def unpack_color(data):
        s = int.from_bytes(data[0:2], byteorder="big")

        r = (s >> 11) & 0x1F
        g = (s >> 6) & 0x1F
        b = (s >> 1) & 0x1F
        a = (s & 1) * 0xFF

        r = ceil(0xFF * (r / 31))
        g = ceil(0xFF * (g / 31))
        b = ceil(0xFF * (b / 31))

        return r, g, b, a

    for a, b in iter_in_groups(data, 2):
        palette.append(unpack_color([a, b]))

    return palette


def add_file_ext(name: str, linker: bool = False) -> str:
    if name.startswith("party_"):
        return "party/" + name + ".png"
    elif name.endswith("_hit"):
        return "geom/" + name + ".bin"
    elif name.endswith("_shape"):
        if linker:
            name += "_built"
        return "geom/" + name + ".bin"
    elif name.endswith("_tex"):
        return "tex/" + name + ".bin"
    elif name.endswith("_bg"):
        return "bg/" + name + ".png"
    else:
        return name + ".bin"


class N64SegPm_map_data(N64Segment):
    def __init__(
        self,
        rom_start,
        rom_end,
        type,
        name,
        vram_start,
        args,
        yaml,
    ):
        super().__init__(
            rom_start,
            rom_end,
            type,
            name,
            vram_start,
            args=args,
            yaml=yaml,
        )

        with open(script_dir / "map_data.yaml") as f:
            self.files = yaml_loader.load(f.read(), Loader=yaml_loader.SafeLoader)

    def split(self, rom_bytes):
        assert isinstance(self.rom_start, int)

        fs_dir = options.opts.asset_path / self.dir / self.name
        (fs_dir / "title").mkdir(parents=True, exist_ok=True)
        (fs_dir / "party").mkdir(parents=True, exist_ok=True)
        (fs_dir / "bg").mkdir(parents=True, exist_ok=True)
        (fs_dir / "tex").mkdir(parents=True, exist_ok=True)
        (fs_dir / "geom").mkdir(parents=True, exist_ok=True)

        data = rom_bytes[self.rom_start : self.rom_end]

        asset_idx = 0
        while True:
            asset_data = data[0x20 + asset_idx * 0x1C :]

            name = decode_null_terminated_ascii(asset_data[0:])
            offset = int.from_bytes(asset_data[0x10:0x14], byteorder="big")
            size = int.from_bytes(asset_data[0x14:0x18], byteorder="big")
            decompressed_size = int.from_bytes(asset_data[0x18:0x1C], byteorder="big")

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
                bytes = crunch64.yay0.decompress(bytes)

            if name.startswith("party_"):
                assert path is not None
                with open(path, "wb") as f:
                    # CI-8
                    w = png.Writer(150, 105, palette=parse_palette(bytes[:0x200]))
                    w.write_array(f, bytes[0x200:])
            elif name == "title_data":
                if "ver/us" in str(options.opts.target_path) or "ver/pal" in str(options.opts.target_path):
                    w = 200
                    h = 112
                    img = n64img.image.RGBA32(data=bytes[0x2210 : 0x2210 + w * h * 4], width=w, height=h)
                    img.write(fs_dir / "title/logotype.png")

                    w = 144
                    h = 32
                    img = n64img.image.IA8(data=bytes[0x10 : 0x10 + w * h], width=w, height=h)
                    img.write(fs_dir / "title/copyright.png")

                    w = 128
                    h = 32
                    img = n64img.image.IA8(data=bytes[0x1210 : 0x1210 + w * h], width=w, height=h)
                    img.write(fs_dir / "title/press_start.png")
                else:
                    w = 272
                    h = 88
                    img = n64img.image.RGBA32(data=bytes[0x1830 : 0x1830 + w * h * 4], width=w, height=h)
                    img.write(fs_dir / "title/logotype.png")

                    w = 128
                    h = 32
                    img = n64img.image.CI4(data=bytes[0x10 : 0x10 + (w * h // 2)], width=w, height=h)
                    img.palette = parse_palette(bytes[0x810:0x830])
                    img.write(fs_dir / "title/copyright.png")

                    w = 128
                    h = 32
                    img = n64img.image.IA8(data=bytes[0x830 : 0x830 + w * h], width=w, height=h)
                    img.write(fs_dir / "title/press_start.png")
            elif name.endswith("_bg"):

                def write_bg_png(bytes, path, header_offset=0):
                    header = bytes[header_offset : header_offset + 0x10]

                    raster_offset = int.from_bytes(header[0:4], byteorder="big") - 0x80200000
                    palette_offset = int.from_bytes(header[4:8], byteorder="big") - 0x80200000
                    assert int.from_bytes(header[8:12], byteorder="big") == 0x000C0014  # draw pos
                    width = int.from_bytes(header[12:14], byteorder="big")
                    height = int.from_bytes(header[14:16], byteorder="big")

                    with open(path, "wb") as f:
                        # CI-8
                        w = png.Writer(
                            width,
                            height,
                            palette=parse_palette(bytes[palette_offset : palette_offset + 512]),
                        )
                        w.write_array(f, bytes[raster_offset:])

                write_bg_png(bytes, fs_dir / "bg" / f"{name}.png")

                # sbk_bg has an alternative palette
                if name == "sbk_bg":
                    write_bg_png(bytes, fs_dir / "bg" / f"{name}.alt.png", header_offset=0x10)
            elif name.endswith("_tex"):
                TexArchive.extract(bytes, fs_dir / "tex" / name)
            else:
                assert path is not None
                with open(path, "wb") as f:
                    f.write(bytes)

            asset_idx += 1

    def get_linker_entries(self):
        from splat.segtypes.linker_entry import LinkerEntry

        fs_dir = options.opts.asset_path / self.dir / self.name

        return [
            LinkerEntry(
                self,
                [fs_dir / add_file_ext(name, linker=True) for name in self.files],
                fs_dir.with_suffix(".dat"),
                ".data",
                ".data",
            ),
        ]
