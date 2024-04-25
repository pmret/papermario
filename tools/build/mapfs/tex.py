#!/usr/bin/env python3

import argparse
import json
import os
from pathlib import Path
from sys import path
from typing import Tuple

path.append(str(Path(__file__).parent.parent.parent / "splat"))
path.append(str(Path(__file__).parent.parent.parent / "build"))

from common import get_asset_path

path.append(str(Path(__file__).parent.parent.parent))
from splat_ext.tex_archives import (
    AUX_COMBINE_MODES_INV,
    TILES_BASIC,
    TILES_INDEPENDENT_AUX,
    TILES_MIPMAPS,
    TILES_SHARED_AUX,
    TexImage,
    get_format_code,
)


# read texture properties from dictionary and load images
def img_from_json(json_data, tex_name: str, asset_stack: Tuple[Path, ...]) -> TexImage:
    ret = TexImage()

    ret.img_name = json_data["name"]

    # read data for main tile
    main_data = json_data.get("main")
    if main_data == None:
        raise Exception(f"Texture {ret.img_name} has no definition for 'main'")

    (main_fmt_name, ret.main_hwrap, ret.main_vwrap) = ret.read_json_img(main_data, "main", ret.img_name)
    (ret.main_fmt, ret.main_depth) = get_format_code(main_fmt_name)

    # read main image
    img_path = get_asset_path(Path(f"mapfs/tex/{tex_name}/{ret.img_name}.png"), asset_stack)
    if not os.path.isfile(img_path):
        raise Exception(f"Could not find main image for texture: {ret.img_name}")
    (
        ret.main_img,
        ret.main_pal,
        ret.main_width,
        ret.main_height,
    ) = ret.get_img_file(main_fmt_name, str(img_path))

    # read data for aux tile
    ret.has_aux = "aux" in json_data
    if ret.has_aux:
        aux_data = json_data.get("aux")
        (aux_fmt_name, ret.aux_hwrap, ret.aux_vwrap) = ret.read_json_img(aux_data, "aux", ret.img_name)

        if aux_fmt_name == "Shared":
            # aux tiles have blank attributes in SHARED mode
            aux_fmt_name = main_fmt_name
            ret.aux_fmt = 0
            ret.aux_depth = 0
            ret.aux_hwrap = 0
            ret.aux_vwrap = 0
            ret.extra_tiles = TILES_SHARED_AUX
        else:
            (ret.aux_fmt, ret.aux_depth) = get_format_code(aux_fmt_name)
            ret.extra_tiles = TILES_INDEPENDENT_AUX

        # read aux image
        img_path = get_asset_path(Path(f"mapfs/tex/{tex_name}/{ret.img_name}_AUX.png"), asset_stack)
        if not os.path.isfile(img_path):
            raise Exception(f"Could not find AUX image for texture: {ret.img_name}")
        (
            ret.aux_img,
            ret.aux_pal,
            ret.aux_width,
            ret.aux_height,
        ) = ret.get_img_file(aux_fmt_name, str(img_path))
        if ret.extra_tiles == TILES_SHARED_AUX:
            # aux tiles have blank sizes in SHARED mode
            ret.main_height *= 2
            ret.aux_width = 0
            ret.aux_height = 0

    else:
        ret.aux_fmt = 0
        ret.aux_depth = 0
        ret.aux_hwrap = 0
        ret.aux_vwrap = 0
        ret.aux_width = 0
        ret.aux_height = 0
        ret.extra_tiles = TILES_BASIC

    # read mipmaps
    ret.has_mipmaps = json_data.get("hasMipmaps", False)
    if ret.has_mipmaps:
        ret.mipmaps = []
        mipmap_idx = 1
        divisor = 2
        if ret.main_width >= (32 >> ret.main_depth):
            while True:
                if (ret.main_width // divisor) <= 0:
                    break
                mmw = ret.main_width // divisor
                mmh = ret.main_height // divisor

                img_path = get_asset_path(
                    Path(f"mapfs/tex/{tex_name}/{ret.img_name}_MM{mipmap_idx}.png"),
                    asset_stack,
                )
                if not os.path.isfile(img_path):
                    raise Exception(
                        f"Texture {ret.img_name} is missing mipmap level {mipmap_idx} (size = {mmw} x {mmh})"
                    )

                (raster, pal, width, height) = ret.get_img_file(main_fmt_name, str(img_path))
                ret.mipmaps.append(raster)
                if width != mmw or height != mmh:
                    raise Exception(
                        f"Texture {ret.img_name} has wrong size for mipmap level {mipmap_idx} \n"
                        + f"MM{mipmap_idx} size = {width} x {height}, but should be = {mmw} x {mmh}"
                    )

                divisor = divisor * 2
                mipmap_idx += 1
                if (ret.main_width // divisor) < (16 >> ret.main_depth):
                    break
        ret.extra_tiles = TILES_MIPMAPS

    # read filter mode
    if json_data.get("filter", False):
        ret.filter_mode = 2
    else:
        ret.filter_mode = 0

    # read tile combine mode
    combine_str = json_data.get("combine", "Missing")
    ret.combine = AUX_COMBINE_MODES_INV.get(combine_str)
    if ret.combine == None:
        raise Exception(f"Texture {ret.img_name} has invalid 'combine'")

    ret.is_variant = json_data.get("variant", False)

    return ret


def build(out_path: Path, tex_name: str, asset_stack: Tuple[Path, ...], endian: str = "big"):
    out_bytes = bytearray()

    json_path = get_asset_path(Path(f"mapfs/tex/{tex_name}.json"), asset_stack)

    with open(json_path) as json_file:
        json_str = json_file.read()
        json_data = json.loads(json_str)

        if len(json_data) > 128:
            raise Exception(f"Maximum number of textures (128) exceeded by {tex_name} ({len(json_data)})`")

        for img_data in json_data:
            img = img_from_json(img_data, tex_name, asset_stack)
            img.add_bytes(tex_name, out_bytes)

    with open(out_path, "wb") as out_bin:
        out_bin.write(out_bytes)


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Texture archives")
    parser.add_argument("bin_out", type=Path, help="Output binary file path")
    parser.add_argument("name", help="Name of tex subdirectory")
    parser.add_argument("asset_stack", help="comma-separated asset stack")
    parser.add_argument("--endian", choices=["big", "little"], default="big", help="Output endianness")
    args = parser.parse_args()

    asset_stack = tuple(Path(d) for d in args.asset_stack.split(","))

    build(args.bin_out, args.name, asset_stack, args.endian)
