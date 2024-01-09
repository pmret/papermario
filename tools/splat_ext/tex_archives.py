from dataclasses import dataclass
from math import ceil
import struct
import json
from pathlib import Path

import png
import n64img.image
from common import iter_in_groups

from sys import path

path.append(str(Path(__file__).parent.parent / "build"))
from img.build import Converter


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

AUX_COMBINE_MODES = {
    0x00: "None",  # multiply main * prim, ignore aux
    0x08: "Multiply",  # multiply main * aux * prim
    0x0D: "ModulateAlpha",  # use prim color, but multiply alpha by the difference between main and aux red channels
    0x10: "LerpMainAux",  # use prim alpha to lerp between main and aux color, use main alpha
}
AUX_COMBINE_MODES_INV = {v: k for k, v in AUX_COMBINE_MODES.items()}

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

    # get n64img object from the buffer
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
            img = n64img.image.RGBA16(data=bytes, width=w, height=h)
        elif fmt_name == "RGBA32":
            img = n64img.image.RGBA32(data=bytes, width=w, height=h)
        elif fmt_name == "CI4":
            img = n64img.image.CI4(data=bytes, width=w, height=h)
        elif fmt_name == "CI8":
            img = n64img.image.CI8(data=bytes, width=w, height=h)
        elif fmt_name == "IA4":
            img = n64img.image.IA4(data=bytes, width=w, height=h)
        elif fmt_name == "IA8":
            img = n64img.image.IA8(data=bytes, width=w, height=h)
        elif fmt_name == "IA16":
            img = n64img.image.IA16(data=bytes, width=w, height=h)
        elif fmt_name == "I4":
            img = n64img.image.I4(data=bytes, width=w, height=h)
        elif fmt_name == "I8":
            img = n64img.image.I8(data=bytes, width=w, height=h)
        else:
            raise Exception(f"Invalid format: {fmt_name}")

        img.flip_v = True
        return img

    # get palette from the buffer
    def get_n64_pal(self, texbuf, fmt, depth):
        if fmt == FMT_CI:
            if depth == DEPTH_4_BIT:
                return parse_palette(texbuf.get(0x20))
            elif depth == DEPTH_8_BIT:
                return parse_palette(texbuf.get(0x200))

    # extract texture properties and rasters from buffer
    def from_bytes(self, texbuf: TexBuffer):
        # strip area prefix and original extension suffix
        raw_name = decode_null_terminated_ascii(texbuf.get(32))
        self.img_name = raw_name[4:-3]
        self.raw_ext = raw_name[-3:]

        (
            self.aux_width,
            self.main_width,
            self.aux_height,
            self.main_height,
            self.is_variant,
            self.extra_tiles,
            self.combine_mode,
            fmts,
            depths,
            hwraps,
            vwraps,
            self.filter_mode,
        ) = struct.unpack(">HHHHBBBBBBBB", texbuf.get(16))

        # unpack upper/lower nibbles for aux/main
        (self.aux_fmt, self.main_fmt) = self.split_byte(fmts)
        (self.aux_depth, self.main_depth) = self.split_byte(depths)
        (self.aux_hwrap, self.main_hwrap) = self.split_byte(hwraps)
        (self.aux_vwrap, self.main_vwrap) = self.split_byte(vwraps)

        self.has_mipmaps = False
        self.has_aux = False

        # main img only
        if self.extra_tiles == TILES_BASIC:
            self.main_img = self.get_n64_img(
                texbuf,
                self.main_fmt,
                self.main_depth,
                self.main_width,
                self.main_height,
            )
            if self.main_fmt == FMT_CI:
                self.main_img.palette = self.get_n64_pal(texbuf, self.main_fmt, self.main_depth)
        # main img + mipmaps
        elif self.extra_tiles == TILES_MIPMAPS:
            self.has_mipmaps = True
            self.main_img = self.get_n64_img(
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
                    mipmap = self.get_n64_img(texbuf, self.main_fmt, self.main_depth, mmw, mmh)
                    self.mipmaps.append(mipmap)

                    divisor = divisor * 2
                    if (self.main_width // divisor) < (16 >> self.main_depth):
                        break
            # read palette and assign to all images
            if self.main_fmt == FMT_CI:
                shared_pal = self.get_n64_pal(texbuf, self.main_fmt, self.main_depth)
                self.main_img.palette = shared_pal
                for mipmap in self.mipmaps:
                    mipmap.palette = shared_pal

        # main + aux (shared attributes)
        elif self.extra_tiles == TILES_SHARED_AUX:
            self.has_aux = True
            self.main_img = self.get_n64_img(
                texbuf,
                self.main_fmt,
                self.main_depth,
                self.main_width,
                self.main_height // 2,
            )
            self.aux_img = self.get_n64_img(
                texbuf,
                self.main_fmt,
                self.main_depth,
                self.main_width,
                self.main_height // 2,
            )
            if self.main_fmt == FMT_CI:
                shared_pal = self.get_n64_pal(texbuf, self.main_fmt, self.main_depth)
                self.main_img.palette = shared_pal
                self.aux_img.palette = shared_pal

        # main + aux (independent attributes)
        elif self.extra_tiles == TILES_INDEPENDENT_AUX:
            self.has_aux = True
            # read main
            self.main_img = self.get_n64_img(
                texbuf,
                self.main_fmt,
                self.main_depth,
                self.main_width,
                self.main_height,
            )
            if self.main_fmt == FMT_CI:
                pal = self.get_n64_pal(texbuf, self.main_fmt, self.main_depth)
                self.main_img.palette = pal
            # read aux
            self.aux_img = self.get_n64_img(texbuf, self.aux_fmt, self.aux_depth, self.aux_width, self.aux_height)
            if self.aux_fmt == FMT_CI:
                self.aux_img.palette = self.get_n64_pal(texbuf, self.aux_fmt, self.aux_depth)

    # constructs a dictionary entry for the tex archive for this texture
    def get_json_entry(self):
        out = {}
        out["name"] = self.img_name

        # only a single texture in 'tst_tex' has 'rgb', otherwise this is always 'tif'
        if self.raw_ext != "tif":
            out["ext"] = self.raw_ext

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

        out["combine"] = AUX_COMBINE_MODES.get(self.combine_mode)

        if self.is_variant:
            out["variant"] = True

        return out

    def save_images(self, tex_path):
        self.main_img.write(tex_path / f"{self.img_name}.png")
        if self.has_aux:
            self.aux_img.write(tex_path / f"{self.img_name}_AUX.png")
        if self.has_mipmaps:
            for idx, mipmap in enumerate(self.mipmaps):
                mipmap.write(tex_path / f"{self.img_name}_MM{idx + 1}.png")

    def read_json_img(self, img_data, tile_name, img_name):
        fmt_str = img_data.get("format")
        if fmt_str == None:
            raise Exception(f"Texture {img_name} is missing 'format' for '{tile_name}'")

        hwrap_str = img_data.get("hwrap", "Missing")
        hwrap = wrap_modes_inv.get(hwrap_str)
        if hwrap == None:
            raise Exception(f"Texture {img_name} has invalid 'hwrap' for '{tile_name}'")

        vwrap_str = img_data.get("vwrap", "Missing")
        vwrap = wrap_modes_inv.get(vwrap_str)
        if vwrap == None:
            raise Exception(f"Texture {img_name} has invalid 'vwrap' for '{tile_name}'")

        return fmt_str, hwrap, vwrap

    def get_img_file(self, fmt_str, img_file: str):
        def pack_color(r, g, b, a):
            r = r >> 3
            g = g >> 3
            b = b >> 3
            a = a >> 7

            return (r << 11) | (g << 6) | (b << 1) | a

        (out_img, out_w, out_h) = Converter(mode=fmt_str.lower(), infile=img_file, flip_y=True).convert()

        out_pal = bytearray()
        if fmt_str == "CI4" or fmt_str == "CI8":
            img = png.Reader(img_file)
            img.preamble(True)
            palette = img.palette(alpha="force")

            # load_texture_by_name assumes palettes have a particular length
            palette_count = (0x20 if fmt_str == "CI4" else 0x200) // 2
            if len(palette) > palette_count:
                palette = palette[:palette_count]
                print(f"warning: {self.img_name} has more than {palette_count} colors, truncating")
            elif len(palette) < palette_count:
                palette += [(0, 0, 0, 0)] * (palette_count - len(palette))

            for rgba in palette:
                if rgba[3] not in (0, 0xFF):
                    self.warn("alpha mask mode but translucent pixels used")

                color = pack_color(*rgba)
                out_pal += color.to_bytes(2, byteorder="big")

        return (out_img, out_pal, out_w, out_h)

    # write texture header and image raster/palettes to byte array
    def add_bytes(self, tex_name: str, bytes: bytearray):
        pos = len(bytes)

        # form raw name and write to header
        raw_name = tex_name[:4] + self.img_name + self.raw_ext
        name_bytes = raw_name.encode("ascii")
        bytes += name_bytes

        # pad name out to 32 bytes
        pad_len = 32 - len(name_bytes)
        assert pad_len > 0
        bytes += b"\0" * pad_len

        # write header fields
        bytes += struct.pack(
            ">HHHHBBBBBBBB",
            self.aux_width,
            self.main_width,
            self.aux_height,
            self.main_height,
            self.is_variant,
            self.extra_tiles,
            self.combine,
            self.pack_byte(self.aux_fmt, self.main_fmt),
            self.pack_byte(self.aux_depth, self.main_depth),
            self.pack_byte(self.aux_hwrap, self.main_hwrap),
            self.pack_byte(self.aux_vwrap, self.main_vwrap),
            self.filter_mode,
        )

        # write rasters and palettes
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

        size = len(bytes) - pos
        assert size == self.expected_size(), f"{raw_name}: size mismatch: {size} != {self.expected_size()}"

    def expected_size(self) -> int:
        """
        Uses logic from load_texture_by_name to calculate the expected size.
        """

        raster_size = self.main_width * self.main_height

        # compute mipmaps size
        if self.main_depth == DEPTH_4_BIT:
            if self.has_mipmaps:
                divisor = 2
                while self.main_width // divisor >= 16 and self.main_height // divisor > 0:
                    raster_size += self.main_width // divisor * self.main_height // divisor
                    divisor *= 2
            raster_size //= 2
        elif self.main_depth == DEPTH_8_BIT:
            if self.has_mipmaps:
                divisor = 2
                while self.main_width // divisor >= 8 and self.main_height // divisor > 0:
                    raster_size += self.main_width // divisor * self.main_height // divisor
                    divisor *= 2
        elif self.main_depth == DEPTH_16_BIT:
            if self.has_mipmaps:
                divisor = 2
                while self.main_width // divisor >= 4 and self.main_height // divisor > 0:
                    raster_size += self.main_width // divisor * self.main_height // divisor
                    divisor *= 2
            raster_size *= 2
        elif self.main_depth == DEPTH_32_BIT:
            if self.has_mipmaps:
                divisor = 2
                while self.main_width // divisor >= 2 and self.main_height // divisor > 0:
                    raster_size += self.main_width // divisor * self.main_height // divisor
                    divisor *= 2
            raster_size *= 4

        # compute palette size
        if self.main_fmt == FMT_CI:
            palette_size = 0x20
            if self.main_depth == DEPTH_8_BIT:
                palette_size = 0x200
        else:
            palette_size = 0

        # compute aux tile size
        if self.extra_tiles == TILES_INDEPENDENT_AUX:
            aux_raster_size = self.aux_width * self.aux_height
            if self.aux_depth == DEPTH_4_BIT:
                aux_raster_size //= 2
            elif self.aux_depth == DEPTH_16_BIT:
                aux_raster_size *= 2
            elif self.aux_depth == DEPTH_32_BIT:
                aux_raster_size *= 4

            if self.aux_fmt == FMT_CI:
                aux_palette_size = 0x20
                if self.aux_depth == DEPTH_8_BIT:
                    aux_palette_size = 0x200
            else:
                aux_palette_size = 0
        else:
            aux_palette_size = 0
            aux_raster_size = 0

        return raster_size + palette_size + 48 + aux_raster_size + aux_palette_size


class TexArchive:
    @staticmethod
    def extract(bytes, tex_path: Path):
        textures = []
        texbuf = TexBuffer(bytes)

        while texbuf.remaining() > 0:
            img = TexImage()
            img.from_bytes(texbuf)
            textures.append(img)

        tex_path.mkdir(parents=True, exist_ok=True)

        out = []
        for texture in textures:
            texture.save_images(tex_path)
            out.append(texture.get_json_entry())

        json_out = json.dumps(out, sort_keys=False, indent=4)

        json_fn = str(tex_path) + ".json"
        with open(json_fn, "w") as f:
            f.write(json_out)
