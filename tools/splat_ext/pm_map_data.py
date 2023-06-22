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

from sys import path
path.append(str(Path(__file__).parent.parent / "build"))
from img.build import Converter

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

# extra tile modes
TILES_BASIC = 0
TILES_MIPMAPS = 1
TILES_SHARED_AUX = 2
TILES_INDEPENDENT_AUX = 3

aux_combine_modes = {
    0x00: "None",  # multiply main * prim, ignore aux
    0x08: "Multiply",  # multiply main * aux * prim
    0x0D: "ModulateAlpha",  # use prim color, but multiply alpha by the difference between main and aux red channels
    0x10: "LerpMainAux",  # use prim alpha to lerp between main and aux color, use main alpha
}
aux_combine_modes_inv = {v: k for k, v in aux_combine_modes.items()}

wrap_modes = {
    0: "Repeat",
    1: "Mirror",
    2: "Clamp",
}
wrap_modes_inv = {v: k for k, v in wrap_modes.items()}

# correspond to modes provided to gSetTextureFilter, only 0 and 2 are ever used
filter_modes = {
    0: "Nearest",
    2: "Bilerp",
    3: "Average",
}
filter_modes_inv = {v: k for k, v in filter_modes.items()}

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
    else:
        raise Exception(f"Invalid format/depth pair: {fmt} and {depth}")


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
    else:
        raise Exception(f"Invalid format: {name}")

def pack_color(r, g, b, a):
    r = r >> 3
    g = g >> 3
    b = b >> 3
    a = a >> 7

    return (r << 11) | (g << 6) | (b << 1) | a

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

    # utility function for unpacking aux/main property pairs from a single byte
    def pack_byte(self, aux, main):
        return ((aux & 0xF) << 4) | (main & 0xF)

    def get_n64_img(self, texbuf: TexBuffer, fmt, depth, w, h):
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

    def get_n64_img_and_flip(self, texbuf: TexBuffer, fmt, depth, w, h):
        img = self.get_n64_img(texbuf, fmt, depth, w, h)
    #TODO    img.flip_v = True
        return img

    def decode_pal(self, texbuf, fmt, depth):
        if fmt == FMT_CI:
            if depth == DEPTH_4_BIT:
                return parse_palette(texbuf.get(0x20))
            elif depth == DEPTH_8_BIT:
                return parse_palette(texbuf.get(0x200))

    def from_bytes(self, texbuf: TexBuffer):
        self.img_name = decode_null_terminated_ascii(texbuf.get(32))

        (
            self.aux_width,
            self.main_width,
            self.aux_height,
            self.main_height,
            self.extra_tiles,
            self.combine_mode,
            fmts,
            depths,
            hwraps,
            vwraps,
            self.filter_mode,
        ) = struct.unpack(">HHHHxBBBBBBB", texbuf.get(16))

        # unpack upper/lower nibbles for aux/main
        (self.aux_fmt, self.main_fmt) = self.split_byte(fmts)
        (self.aux_depth, self.main_depth) = self.split_byte(depths)
        (self.aux_hwrap, self.main_hwrap) = self.split_byte(hwraps)
        (self.aux_vwrap, self.main_vwrap) = self.split_byte(vwraps)

        self.has_mipmaps = False
        self.has_aux = False

        # main img only
        if self.extra_tiles == TILES_BASIC:
            self.main_img = self.get_n64_img_and_flip(
                texbuf,
                self.main_fmt,
                self.main_depth,
                self.main_width,
                self.main_height,
            )
            if self.main_fmt == FMT_CI:
                self.main_img.palette = self.decode_pal(
                    texbuf, self.main_fmt, self.main_depth
                )
        # main img + mipmaps
        elif self.extra_tiles == TILES_MIPMAPS:
            self.has_mipmaps = True
            self.main_img = self.get_n64_img_and_flip(
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
                    mipmap = self.get_n64_img_and_flip(
                        texbuf, self.main_fmt, self.main_depth, mmw, mmh
                    )
                    self.mipmaps.append(mipmap)

                    divisor = divisor * 2
                    if (self.main_width // divisor) < (16 >> self.main_depth):
                        break
            # read palette and assign to all images
            if self.main_fmt == FMT_CI:
                shared_pal = self.decode_pal(texbuf, self.main_fmt, self.main_depth)
                self.main_img.palette = shared_pal
                for mipmap in self.mipmaps:
                    mipmap.palette = shared_pal

        # main + aux (shared attributes)
        elif self.extra_tiles == TILES_SHARED_AUX:
            self.has_aux = True
            self.main_img = self.get_n64_img_and_flip(
                texbuf,
                self.main_fmt,
                self.main_depth,
                self.main_width,
                self.main_height // 2,
            )
            self.aux_img = self.get_n64_img_and_flip(
                texbuf,
                self.main_fmt,
                self.main_depth,
                self.main_width,
                self.main_height // 2,
            )
            if self.main_fmt == FMT_CI:
                shared_pal = self.decode_pal(texbuf, self.main_fmt, self.main_depth)
                self.main_img.palette = shared_pal
                self.aux_img.palette = shared_pal

        # main + aux (independent attributes)
        elif self.extra_tiles == TILES_INDEPENDENT_AUX:
            self.has_aux = True
            # read main
            self.main_img = self.get_n64_img_and_flip(
                texbuf,
                self.main_fmt,
                self.main_depth,
                self.main_width,
                self.main_height,
            )
            if self.main_fmt == FMT_CI:
                pal = self.decode_pal(texbuf, self.main_fmt, self.main_depth)
                self.main_img.palette = pal
            # read aux
            self.aux_img = self.get_n64_img_and_flip(
                texbuf, self.aux_fmt, self.aux_depth, self.aux_width, self.aux_height
            )
            if self.aux_fmt == FMT_CI:
                self.aux_img.palette = self.decode_pal(
                    texbuf, self.aux_fmt, self.aux_depth
                )

    def __to_json(self):
        out = {}
        out["main"] = {
            "format": get_format_name(self.main_fmt, self.main_depth),
            "hwrap": wrap_modes.get(self.main_hwrap),
            "vwrap": wrap_modes.get(self.main_vwrap),
        }

        if self.has_aux:
            if self.extra_tiles == TILES_SHARED_AUX:
                out["aux"] = {
                    "format": "Shared",
                    "hwrap": wrap_modes.get(self.aux_hwrap),
                    "vwrap": wrap_modes.get(self.aux_vwrap),
                }
            else:
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
            f.write(self.__to_json())


    def read_json_img(self, img_data, tile_name, tex_name):
        fmt_str = img_data.get("format")
        if fmt_str == None:
            raise Exception(f"Texture {tex_name} is missing 'format' for '{tile_name}'")

        hwrap_str = img_data.get("hwrap", "Missing")
        hwrap = wrap_modes_inv.get(hwrap_str)
        if hwrap == None:
            raise Exception(f"Texture {tex_name} has invalid 'hwrap' for '{tile_name}'")

        vwrap_str = img_data.get("vwrap", "Missing")
        vwrap = wrap_modes_inv.get(vwrap_str)
        if vwrap == None:
            raise Exception(f"Texture {tex_name} has invalid 'vwrap' for '{tile_name}'")

        return fmt_str, hwrap, vwrap

    def get_img_file(self, fmt_str, img_file):
        print("IN: " + img_file)
        (out_img, out_w, out_h) = Converter(fmt_str.lower(), img_file, None).convert() #TODO, "--flip-y")

        out_pal = bytearray()
        if fmt_str == "CI4" or fmt_str == "CI8":
            img = png.Reader(img_file)
            img.preamble(True)
            palette = img.palette(alpha="force")
            for rgba in palette:
                if rgba[3] not in (0, 0xFF):
                    self.warn("alpha mask mode but translucent pixels used")

                color = pack_color(*rgba)
                out_pal += color.to_bytes(2, byteorder="big")

        return (out_img, out_pal, out_w, out_h) 


    def from_json(self, json_path):
        basename = os.path.splitext(json_path)[0]
        self.img_name = os.path.basename(basename)

        # read json file
        with open(json_path, "r") as json_file:
            json_str = json_file.read()

        json_data = json.loads(json_str)

        # read data for main tile
        main_data = json_data.get("main")
        if main_data == None:
            raise Exception(f"Texture {self.img_name} has no definition for 'main'")
            
        (main_fmt_name, self.main_hwrap, self.main_vwrap) = self.read_json_img(main_data, "main", self.img_name)
        (self.main_fmt, self.main_depth) = get_format_code(main_fmt_name)

        # read main image
        found_img = os.path.isfile(basename + ".png")
        if not found_img:
            raise Exception(f"Could not find main image for texture: {self.img_name}")
        (self.main_img, self.main_pal, self.main_width, self.main_height) = self.get_img_file(main_fmt_name, basename + ".png")

        # read data for aux tile
        self.has_aux = "aux" in json_data
        if self.has_aux:
            aux_data = json_data.get("main")
            (aux_fmt_name, self.aux_hwrap, self.aux_vwrap) = self.read_json_img(aux_data, "aux", self.img_name)
            if aux_fmt_name == "Shared":
                self.aux_fmt = self.main_fmt
                self.aux_depth = self.main_depth
                self.extra_tiles = TILES_SHARED_AUX
            else:
                (self.aux_fmt, self.aux_depth) = get_format_code(aux_fmt_name)
                self.extra_tiles = TILES_INDEPENDENT_AUX

            # read aux image
            found_aux = os.path.isfile(basename + "_AUX.png")
            if not found_aux:
                raise Exception(f"Could not find AUX image for texture: {self.img_name}")
            (self.aux_img, self.aux_pal, self.aux_width, self.aux_height) = self.get_img_file(aux_fmt_name, basename + "_AUX.png")
        else:
            self.aux_fmt = 0
            self.aux_depth = 0
            self.aux_hwrap = 0
            self.aux_vwrap = 0
            self.aux_width = 0
            self.aux_height = 0
            self.extra_tiles = TILES_BASIC

        # read mipmaps
        self.has_mipmaps = json_data.get("hasMipmaps", False)
        if self.has_mipmaps:
            self.mipmaps = []
            mipmap_idx = 1
            while True:
                mipmap_path = basename + f"_MM{mipmap_idx}.png"
                if os.path.isfile(mipmap_path):
                    (raster, pal, width, height) = self.get_img_file(main_fmt_name, mipmap_path)                    
                    self.mipmaps.append(raster)
                    mipmap_idx += 1
                    print(f"{mipmap_idx} : {width} x {height}")
                else:
                    break
            self.extra_tiles = TILES_MIPMAPS
        
        # read filter mode
        if json_data.get("filter", False):
            self.filter_mode = 2
        else:
            self.filter_mode = 0

        # read tile combine mode
        combine_str = json_data.get("combine", "Missing")
        self.combine = aux_combine_modes_inv.get(combine_str)
        if self.combine == None:
            raise Exception(f"Texture {self.img_name} has invalid 'combine'")


    def append_to(self, bytes : bytearray):
        # write name, padded out to 32 bytes
        name_bytes = self.img_name.encode("ascii")
        bytes += name_bytes

        pad_len = 32 - len(name_bytes)
        assert(pad_len > 0)
        bytes += b"\0" * pad_len

        # header fields
        bytes += struct.pack(">HHHHxBBBBBBB",
            self.aux_width,
            self.main_width,
            self.aux_height  if self.extra_tiles != TILES_SHARED_AUX else self.main_height // 2, 
            self.main_height if self.extra_tiles != TILES_SHARED_AUX else self.main_height // 2,
            self.extra_tiles,
            self.combine,
            self.pack_byte(self.aux_fmt, self.main_fmt),
            self.pack_byte(self.aux_depth, self.main_depth),
            self.pack_byte(self.aux_hwrap, self.main_hwrap),
            self.pack_byte(self.aux_vwrap, self.main_vwrap),
            self.filter_mode
        )

        if self.extra_tiles == TILES_BASIC:
            bytes += self.main_img
            if self.main_fmt == FMT_CI:
                bytes += self.main_pal
        elif self.extra_tiles == TILES_MIPMAPS:
            bytes += self.main_img
            for mipmap in self.mipmaps:
                bytes += mipmap
            if self.main_fmt == FMT_CI:
                bytes += self.main_pal
        elif self.extra_tiles == TILES_SHARED_AUX:
            bytes += self.main_img
            bytes += self.aux_img
            if self.main_fmt == FMT_CI:
                bytes += self.main_pal
        elif self.extra_tiles == TILES_INDEPENDENT_AUX:
            bytes += self.main_img
            if self.main_fmt == FMT_CI:
                bytes += self.main_pal
            bytes += self.aux_img
            if self.aux_fmt == FMT_CI:
                bytes += self.aux_pal

    def build(self, bytes : bytearray, json_path):
        self.from_json(json_path)
        self.append_to(bytes)


class TexArchive:
    def __init__(self, bytes):
        self.textures: List[TexImage] = []
        texbuf = TexBuffer(bytes)

        while texbuf.remaining() > 0:
            img = TexImage()
            img.from_bytes(texbuf)
            self.textures.append(img)

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
