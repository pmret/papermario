from math import ceil
import os, sys
import struct
from pathlib import Path

import crunch64
from splat.segtypes.segment import Segment
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


class N64SegPm_map_data(Segment):
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

        if "ver/ique" in str(options.opts.target_path):
            cfg_name = "mapfs_ique.yaml"
        elif "ver/jp" in str(options.opts.target_path):
            cfg_name = "mapfs_jp.yaml"
        else:
            cfg_name = "mapfs.yaml"

        self.files = {}
        with open(script_dir / cfg_name) as f:
            mapfs_cfg = yaml_loader.load(f.read(), Loader=yaml_loader.SafeLoader)
            for file in mapfs_cfg:
                if isinstance(file, dict):
                    self.files[file["name"]] = file.copy()
                else:
                    name = file
                    self.files[name] = {"name": name}

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

            if name == "end_data":
                break

            if self.files.get(name) is None:
                # TODO
                # https://github.com/pmret/papermario/issues/1170
                self.warn(f"skipping unknown file {name}")
                asset_idx += 1
                continue

            if offset == 0:
                path = None
            else:
                path = fs_dir / add_file_ext(name)

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
                textures = self.files[name]["textures"]
                for tex in textures:
                    pos = tex[0]
                    imgtype = tex[1]
                    outname = tex[2]

                    if imgtype == "pal":
                        continue

                    w = tex[3]
                    h = tex[4]

                    if imgtype == "ia4":
                        img = n64img.image.IA4(data=bytes[pos : pos + w * h // 2], width=w, height=h)
                    elif imgtype == "ia8":
                        img = n64img.image.IA8(data=bytes[pos : pos + w * h], width=w, height=h)
                    elif imgtype == "ia16":
                        img = n64img.image.IA16(data=bytes[pos : pos + w * h * 2], width=w, height=h)
                    elif imgtype == "rgba16":
                        img = n64img.image.RGBA16(data=bytes[pos : pos + w * h * 2], width=w, height=h)
                    elif imgtype == "rgba32":
                        img = n64img.image.RGBA32(data=bytes[pos : pos + w * h * 4], width=w, height=h)
                    elif imgtype in ("ci4", "ci8"):
                        palette = next(filter(lambda x: x[1] == "pal" and x[2] == outname, textures))
                        pal_pos = palette[0]

                        if imgtype == "ci4":
                            img = n64img.image.CI4(data=bytes[pos : pos + w * h // 2], width=w, height=h)
                            img.palette = parse_palette(bytes[pal_pos : pal_pos + 0x20])
                        elif imgtype == "ci8":
                            img = n64img.image.CI8(data=bytes[pos : pos + w * h], width=w, height=h)
                            img.palette = parse_palette(bytes[pal_pos : pal_pos + 0x200])
                    else:
                        raise Exception(f"Invalid image type {imgtype}")

                    img.write(fs_dir / "title" / f"{outname}.png")

            elif name.endswith("_bg"):
                for i in range(self.files[name].get("pal_count", 1)):
                    header_offset = i * 0x10
                    raster_offset, palette_offset, draw_pos, width, height = struct.unpack(
                        ">IIIHH", bytes[header_offset : header_offset + 0x10]
                    )

                    raster_offset -= 0x80200000
                    palette_offset -= 0x80200000
                    assert draw_pos == 0x000C0014

                    outname = name
                    if i >= 1:
                        outname += f".{i}"

                    with open(fs_dir / "bg" / f"{outname}.png", "wb") as f:
                        # CI-8
                        w = png.Writer(
                            width,
                            height,
                            palette=parse_palette(bytes[palette_offset : palette_offset + 512]),
                        )
                        w.write_array(f, bytes[raster_offset:])

            elif name.endswith("_tex"):
                TexArchive.extract(bytes, fs_dir / "tex" / name)
            else:
                assert path is not None
                with open(path, "wb") as f:
                    f.write(bytes)

            if self.files[name].get("dump_raw", False):
                with open(fs_dir / f"{name}.raw.dat", "wb") as f:
                    f.write(rom_bytes[bytes_start : bytes_start + self.files[name]["dump_raw_size"]])

            asset_idx += 1

    def get_linker_entries(self):
        from splat.segtypes.linker_entry import LinkerEntry

        fs_dir = options.opts.asset_path / self.dir / self.name

        src_paths = []
        for name, file in self.files.items():
            src_paths.append(fs_dir / add_file_ext(name, linker=True))
            if file.get("dump_raw", False):
                src_paths.append(fs_dir / f"{name}.raw.dat")

        return [
            LinkerEntry(
                self,
                src_paths,
                fs_dir.with_suffix(".dat"),
                ".data",
                ".data",
            ),
        ]
