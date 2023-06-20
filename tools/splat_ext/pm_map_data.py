from dataclasses import dataclass
import os
import struct
import json
from pathlib import Path
from typing import List
from segtypes.n64.segment import N64Segment
from util.n64.Yay0decompress import Yay0Decompressor
from util.color import unpack_color
from segtypes.n64.palette import iter_in_groups
from util import options
import png
import yaml as yaml_loader
import n64img.image

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

    for a, b in iter_in_groups(data, 2):
        palette.append(unpack_color([a, b]))

    return palette


def add_file_ext(name: str) -> str:
    if name.startswith("party_"):
        return "party/" + name + ".png"
    elif name.endswith("_hit") or name.endswith("_shape"):
        return "geom/" + name + ".bin"  # TODO: xml
    elif name.endswith("_tex"):
        return "tex/" + name + ".bin"  # TODO: texture archive
    elif name.endswith("_bg"):
        return "bg/" + name + ".png"
    else:
        return name + ".bin"


FMT_RGBA = 0
FMT_CI = 2
FMT_IA = 3
FMT_I = 4

DEPTH_4_BIT = 0
DEPTH_8_BIT = 1
DEPTH_16_BIT = 2
DEPTH_32_BIT = 3

aux_combine_modes = {
    0x00: "None",  # multiply main * prim, ignore aux
    0x08: "Multiply",  # multiply main * aux * prim
    0x0D: "ModulateAlpha",  # use prim color, but multiply alpha by the difference between main and aux red channels
    0x10: "LerpMainAux",  # use prim alpha to lerp between main and aux color, use main alpha
}

wrap_modes = {
    0: "Repeat",
    1: "Mirror",
    2: "Clamp",
}


def get_format_name(fmt, depth):
    # get image from bytes for valid combinations of fmt and bit depth
    if fmt == FMT_RGBA:
        if depth == DEPTH_16_BIT:
            return "RGBA16"
        if depth == DEPTH_32_BIT:
            return "RGBA32"
    elif fmt == FMT_CI:
        if depth == DEPTH_4_BIT:
            return "CI4"
        elif depth == DEPTH_8_BIT:
            return "CI8"
    elif fmt == FMT_IA:
        if depth == DEPTH_4_BIT:
            return "IA4"
        elif depth == DEPTH_8_BIT:
            return "IA8"
        elif depth == DEPTH_16_BIT:
            return "IA16"
    elif fmt == FMT_I:
        if depth == DEPTH_4_BIT:
            return "I4"
        elif depth == DEPTH_8_BIT:
            return "I8"
    return "INVALID"


def get_format_code(name):
    # get image from bytes for valid combinations of fmt and bit depth
    if name == "RGBA16":
        return (FMT_RGBA, DEPTH_16_BIT)
    elif name == "RGBA32":
        return (FMT_RGBA, DEPTH_32_BIT)
    elif name == "CI4":
        return (FMT_CI, DEPTH_4_BIT)
    elif name == "CI8":
        return (FMT_CI, DEPTH_8_BIT)
    elif name == "IA4":
        return (FMT_IA, DEPTH_4_BIT)
    elif name == "IA8":
        return (FMT_IA, DEPTH_8_BIT)
    elif name == "IA16":
        return (FMT_IA, DEPTH_16_BIT)
    elif name == "I4":
        return (FMT_I, DEPTH_4_BIT)
    elif name == "I8":
        return (FMT_I, DEPTH_8_BIT)
    return (-1, -1)  # invalid


# class for reading a tex file buffer one chunk at a time
@dataclass
class TexBuffer:
    data: bytes
    pos: int = 0

    @property
    def capacity(self):
        return len(self.data)

    def get(self, count):
        amt = int(min(count, self.capacity - self.pos))
        ret = self.data[self.pos : self.pos + amt]
        self.pos += amt
        return ret

    def remaining(self):
        return self.capacity - self.pos


class TexImage:
    # utility function for unpacking aux/main property pairs from a single byte
    def split_byte(self, byte):
        return (byte >> 4 & 0xF), (byte & 0xF)

    def read_img(self, texbuf: TexBuffer, fmt, depth, w, h):
        # calculate size for bit depth
        if depth == DEPTH_4_BIT:
            size = w * h // 2
        elif depth == DEPTH_8_BIT:
            size = w * h
        elif depth == DEPTH_16_BIT:
            size = w * h * 2
        elif depth == DEPTH_32_BIT:
            size = w * h * 4
        else:
            raise Exception(f"Invalid bit depth: {depth}")

        bytes = texbuf.get(size)

        # get image from bytes for valid combinations of fmt and bit depth
        fmt_name = get_format_name(fmt, depth)
        if fmt_name == "RGBA16":
            return n64img.image.RGBA16(data=bytes, width=w, height=h)
        elif fmt_name == "RGBA32":
            return n64img.image.RGBA32(data=bytes, width=w, height=h)
        elif fmt_name == "CI4":
            return n64img.image.CI4(data=bytes, width=w, height=h)
        elif fmt_name == "CI8":
            return n64img.image.CI8(data=bytes, width=w, height=h)
        elif fmt_name == "IA4":
            return n64img.image.IA4(data=bytes, width=w, height=h)
        elif fmt_name == "IA8":
            return n64img.image.IA8(data=bytes, width=w, height=h)
        elif fmt_name == "IA16":
            return n64img.image.IA16(data=bytes, width=w, height=h)
        elif fmt_name == "I4":
            return n64img.image.I4(data=bytes, width=w, height=h)
        elif fmt_name == "I8":
            return n64img.image.I8(data=bytes, width=w, height=h)
        else:
            raise Exception(f"Invalid format: {fmt_name}")

    def read_img_and_flip(self, texbuf: TexBuffer, fmt, depth, w, h):
        img = self.read_img(texbuf, fmt, depth, w, h)
        img.flip_v = True
        return img

    def read_pal(self, texbuf, fmt, depth):
        if fmt == FMT_CI:
            if depth == DEPTH_4_BIT:
                return parse_palette(texbuf.get(0x20))
            elif depth == DEPTH_8_BIT:
                return parse_palette(texbuf.get(0x200))

    def __init__(self, texbuf: TexBuffer):
        self.img_name = decode_null_terminated_ascii(texbuf.get(32))

        (
            self.aux_width,
            self.main_width,
            self.aux_height,
            self.main_height,  # img sizes
            self.extra_tiles,
            self.combine_mode,
            fmts,
            depths,
            hwraps,
            vwraps,  # packed upper/lower nibbles for aux/main
            self.filter_mode,
        ) = struct.unpack(">HHHHxBBBBBBB", texbuf.get(16))

        (self.aux_fmt, self.main_fmt) = self.split_byte(fmts)
        (self.aux_depth, self.main_depth) = self.split_byte(depths)
        (self.aux_hwrap, self.main_hwrap) = self.split_byte(hwraps)
        (self.aux_vwrap, self.main_vwrap) = self.split_byte(vwraps)

        #    print(self.img_name)

        self.has_mipmaps = False
        self.has_aux = False

        # main img only
        if self.extra_tiles == 0:
            self.main_img = self.read_img_and_flip(
                texbuf,
                self.main_fmt,
                self.main_depth,
                self.main_width,
                self.main_height,
            )
            if self.main_fmt == FMT_CI:
                self.main_img.palette = self.read_pal(
                    texbuf, self.main_fmt, self.main_depth
                )
        # main img + mipmaps
        elif self.extra_tiles == 1:
            self.has_mipmaps = True
            self.main_img = self.read_img_and_flip(
                texbuf,
                self.main_fmt,
                self.main_depth,
                self.main_width,
                self.main_height,
            )
            # read mipmaps
            self.mipmaps = []
            divisor = 2
            if self.main_width >= (32 >> self.main_depth):
                while True:
                    if (self.main_width // divisor) <= 0:
                        break
                    mmw = self.main_width // divisor
                    mmh = self.main_height // divisor
                    mipmap = self.read_img_and_flip(
                        texbuf, self.main_fmt, self.main_depth, mmw, mmh
                    )
                    self.mipmaps.append(mipmap)

                    divisor = divisor * 2
                    if (self.main_width // divisor) < (16 >> self.main_depth):
                        break
            # read palette and assign to all images
            if self.main_fmt == FMT_CI:
                shared_pal = self.read_pal(texbuf, self.main_fmt, self.main_depth)
                self.main_img.palette = shared_pal
                for mipmap in self.mipmaps:
                    mipmap.palette = shared_pal

        # main + aux (shared attributes)
        elif self.extra_tiles == 2:
            self.has_aux = True
            self.main_img = self.read_img_and_flip(
                texbuf,
                self.main_fmt,
                self.main_depth,
                self.main_width,
                self.main_height // 2,
            )
            self.aux_img = self.read_img_and_flip(
                texbuf,
                self.main_fmt,
                self.main_depth,
                self.main_width,
                self.main_height // 2,
            )
            if self.main_fmt == FMT_CI:
                shared_pal = self.read_pal(texbuf, self.main_fmt, self.main_depth)
                self.main_img.palette = shared_pal
                self.aux_img.palette = shared_pal

        # main + aux (independent attributes)
        elif self.extra_tiles == 3:
            self.has_aux = True
            # read main
            self.main_img = self.read_img_and_flip(
                texbuf,
                self.main_fmt,
                self.main_depth,
                self.main_width,
                self.main_height,
            )
            if self.main_fmt == FMT_CI:
                pal = self.read_pal(texbuf, self.main_fmt, self.main_depth)
                self.main_img.palette = pal
            # read aux
            self.aux_img = self.read_img_and_flip(
                texbuf, self.aux_fmt, self.aux_depth, self.aux_width, self.aux_height
            )
            if self.aux_fmt == FMT_CI:
                self.aux_img.palette = self.read_pal(
                    texbuf, self.aux_fmt, self.aux_depth
                )

    def to_json(self):
        out = {}
        out["main"] = {
            "format": get_format_name(self.main_fmt, self.main_depth),
            "hwrap": wrap_modes.get(self.main_hwrap),
            "vwrap": wrap_modes.get(self.main_vwrap),
        }

        if self.has_aux:
            out["aux"] = {
                "format": get_format_name(self.aux_fmt, self.aux_depth),
                "hwrap": wrap_modes.get(self.aux_hwrap),
                "vwrap": wrap_modes.get(self.aux_vwrap),
            }

        if self.has_mipmaps:
            out["hasMipmaps"] = True

        if self.filter_mode == 2:
            out["filter"] = True

        out["combine"] = aux_combine_modes.get(self.combine_mode)

        return json.dumps(out, sort_keys=False, indent=4)

    def extract(self, tex_path):
        self.main_img.write(tex_path / f"{self.img_name}.png")
        if self.has_aux:
            self.aux_img.write(tex_path / f"{self.img_name}_AUX.png")
        if self.has_mipmaps:
            for idx, mipmap in enumerate(self.mipmaps):
                mipmap.write(tex_path / f"{self.img_name}_MM{idx + 1}.png")

        with open(tex_path / f"{self.img_name}.json", "w") as f:
            f.write(self.to_json())


class TexArchive:
    def __init__(self, bytes):
        self.textures: List[TexImage] = []
        texbuf = TexBuffer(bytes)

        while texbuf.remaining() > 0:
            self.textures.append(TexImage(texbuf))

    def extract(self, tex_path: Path):
        tex_path.mkdir(parents=True, exist_ok=True)
        for texture in self.textures:
            texture.extract(tex_path)


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
                bytes = Yay0Decompressor.decompress_python(bytes)

            if name.startswith("party_"):
                assert path is not None
                with open(path, "wb") as f:
                    # CI-8
                    w = png.Writer(150, 105, palette=parse_palette(bytes[:0x200]))
                    w.write_array(f, bytes[0x200:])
            elif name == "title_data":
                if "ver/us" in str(options.opts.target_path) or "ver/pal" in str(
                    options.opts.target_path
                ):
                    w = 200
                    h = 112
                    img = n64img.image.RGBA32(
                        data=bytes[0x2210 : 0x2210 + w * h * 4], width=w, height=h
                    )
                    img.write(fs_dir / "title/logotype.png")

                    w = 144
                    h = 32
                    img = n64img.image.IA8(
                        data=bytes[0x10 : 0x10 + w * h], width=w, height=h
                    )
                    img.write(fs_dir / "title/copyright.png")

                    w = 128
                    h = 32
                    img = n64img.image.IA8(
                        data=bytes[0x1210 : 0x1210 + w * h], width=w, height=h
                    )
                    img.write(fs_dir / "title/press_start.png")
                else:
                    w = 272
                    h = 88
                    img = n64img.image.RGBA32(
                        data=bytes[0x1830 : 0x1830 + w * h * 4], width=w, height=h
                    )
                    img.write(fs_dir / "title/logotype.png")

                    w = 128
                    h = 32
                    img = n64img.image.CI4(
                        data=bytes[0x10 : 0x10 + (w * h // 2)], width=w, height=h
                    )
                    img.palette = parse_palette(bytes[0x810:0x830])
                    img.write(fs_dir / "title/copyright.png")

                    w = 128
                    h = 32
                    img = n64img.image.IA8(
                        data=bytes[0x830 : 0x830 + w * h], width=w, height=h
                    )
                    img.write(fs_dir / "title/press_start.png")
            elif name.endswith("_bg"):

                def write_bg_png(bytes, path, header_offset=0):
                    header = bytes[header_offset : header_offset + 0x10]

                    raster_offset = (
                        int.from_bytes(header[0:4], byteorder="big") - 0x80200000
                    )
                    palette_offset = (
                        int.from_bytes(header[4:8], byteorder="big") - 0x80200000
                    )
                    assert (
                        int.from_bytes(header[8:12], byteorder="big") == 0x000C0014
                    )  # draw pos
                    width = int.from_bytes(header[12:14], byteorder="big")
                    height = int.from_bytes(header[14:16], byteorder="big")

                    with open(path, "wb") as f:
                        # CI-8
                        w = png.Writer(
                            width,
                            height,
                            palette=parse_palette(
                                bytes[palette_offset : palette_offset + 512]
                            ),
                        )
                        w.write_array(f, bytes[raster_offset:])

                write_bg_png(bytes, fs_dir / "bg" / f"{name}.png")

                # sbk_bg has an alternative palette
                if name == "sbk_bg":
                    write_bg_png(
                        bytes, fs_dir / "bg" / f"{name}.alt.png", header_offset=0x10
                    )
            elif name.endswith("_tex"):
                archive = TexArchive(bytes)
                archive.extract(fs_dir / "tex" / name)
            else:
                assert path is not None
                with open(path, "wb") as f:
                    f.write(bytes)

            asset_idx += 1

    def get_linker_entries(self):
        from segtypes.linker_entry import LinkerEntry

        fs_dir = options.opts.asset_path / self.dir / self.name

        return [
            LinkerEntry(
                self,
                [fs_dir / add_file_ext(name) for name in self.files],
                fs_dir.with_suffix(".dat"),
                ".data",
            ),
        ]
