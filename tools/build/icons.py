#!/usr/bin/env python3

import re
import argparse
from pathlib import Path
from typing import Dict, Tuple
from common import get_asset_path
import xml.etree.ElementTree as ET
from img.build import Converter
import png


def get_img_file(fmt_str, img_file: str):
    def pack_color(r, g, b, a):
        r = r >> 3
        g = g >> 3
        b = b >> 3
        a = a >> 7

        return (r << 11) | (g << 6) | (b << 1) | a

    (out_img, out_w, out_h) = Converter(mode=fmt_str.lower(), infile=img_file).convert()

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


def build(out_bin: Path, in_xml: Path, out_header: Path, asset_stack: Tuple[Path, ...]):
    out_bytes = bytearray()
    offsets: Dict[str, int] = {}

    xml = ET.parse(in_xml)
    IconList = xml.getroot()

    for Icon in IconList.findall("Icon"):
        type = Icon.attrib["type"]
        file = Icon.attrib["name"]

        if file is None:
            raise Exception("Icon is missing attribute: 'name'")

        if type is None:
            raise Exception("Icon is missing attribute: 'type'")

        name = re.sub("\\W", "_", file)

        if type == "solo" or type == "pair":
            img_path = str(get_asset_path(Path(f"icon/{file}.png"), asset_stack))
            (out_img, out_pal, out_w, out_h) = get_img_file("CI4", str(img_path))

            offsets[name + "_raster"] = len(out_bytes)
            out_bytes += out_img

            offsets[name + "_palette"] = len(out_bytes)
            out_bytes += out_pal

            if type == "pair":
                img_path = str(get_asset_path(Path(f"icon/{file}.disabled.png"), asset_stack))
                (out_img, out_pal, out_w, out_h) = get_img_file("CI4", str(img_path))

                offsets[name + "_disabled_raster"] = offsets[name + "_raster"]
                offsets[name + "_disabled_palette"] = len(out_bytes)
                out_bytes += out_pal

        elif type == "rgba16":
            img_path = str(get_asset_path(Path(f"icon/{file}.png"), asset_stack))
            (out_img, out_pal, out_w, out_h) = get_img_file("RGBA16", str(img_path))

            offsets[name + "_raster"] = len(out_bytes)
            out_bytes += out_img

        else:
            raise Exception("Invalid icon format: " + type)

    with open(out_bin, "wb") as f:
        f.write(out_bytes)

    with open(out_header, "w") as f:
        f.write("#ifndef ICON_OFFSETS_H\n")
        f.write("#define ICON_OFFSETS_H\n")
        f.write(f"/* This file is auto-generated. Do not edit. */\n\n")

        for name, offset in offsets.items():
            f.write(f"#define ICON_{name} 0x{offset:X}\n")

        f.write("\n#endif // ICON_OFFSETS_H\n")


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Icon archive")
    parser.add_argument("out_bin", type=Path, help="output binary file path")
    parser.add_argument("list_path", type=Path, help="input xml file path")
    parser.add_argument("header_path", type=Path, help="output header file to generate")
    parser.add_argument("asset_stack", help="comma-separated asset stack")
    args = parser.parse_args()

    asset_stack = tuple(Path(d) for d in args.asset_stack.split(","))

    build(args.out_bin, args.list_path, args.header_path, asset_stack)
