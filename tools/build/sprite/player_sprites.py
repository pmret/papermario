from dataclasses import dataclass
from pathlib import Path
import sys
from typing import List

sys.path.append(str(Path(__file__).parent.parent.parent))
sys.path.append(str(Path(__file__).parent.parent.parent / "splat"))
from splat_ext.pm_player_sprites import (
    BACK_PALETTE_XML,
    LIST_END_BYTES,
    MAX_COMPONENTS_XML,
    PALETTE_GROUPS_XML,
    SPECIAL_RASTER,
    PlayerRaster,
    RasterTableEntry,
)
from splat_ext.sprite_common import AnimComponent

import os
import png
import struct
import subprocess
import xml.etree.ElementTree as ET
from dataclasses import dataclass
from typing import Dict, List, Tuple

from sprite import iter_in_groups

TOOLS_DIR = Path(
    os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
)
sys.path.append(str(TOOLS_DIR))


def get_orderings_from_xml(xml_dir: Path) -> Tuple[List[str], List[str]]:
    orderings_tree = ET.parse(xml_dir / "player_sprite_names.xml")

    sprite_order: List[str] = []
    for sprite_tag in orderings_tree.getroot()[0]:
        sprite_order.append(sprite_tag.attrib["name"])

    raster_order: List[str] = []
    for raster_tag in orderings_tree.getroot()[1]:
        raster_order.append(raster_tag.attrib["name"])

    return sprite_order, raster_order


@dataclass
class PNGInfo:
    offset: int
    width: int
    height: int
    data: bytes


RASTER_CACHE: Dict[str, PNGInfo] = {}
PALETTE_CACHE: Dict[str, bytes] = {}


def xml_to_bytes(xml: ET.Element, xml_dir: Path) -> List[bytes]:
    has_back = False

    out_bytes = b""
    back_out_bytes = b""

    max_components = int(xml.attrib[MAX_COMPONENTS_XML])
    num_variations = int(xml.attrib[PALETTE_GROUPS_XML])

    # Animations
    animations: List[List[AnimComponent]] = []
    for anim_xml in xml[2]:
        comps: List[AnimComponent] = []
        for comp_xml in anim_xml:
            comp: AnimComponent = AnimComponent.from_xml(comp_xml)
            comps.append(comp)
        animations.append(comps)

    cur_offset = 0x10  # header
    cur_offset += (len(animations) + 1) * 4  # animation offsets and list terminator

    animation_offsets: List[int] = []
    total_anim_bytes = b""

    for anim in animations:
        animation_offsets.append(cur_offset)
        animation_bytes: bytes = b""
        cur_offset += (len(anim) + 1) * 4

        comp_offsets = []
        for comp in anim:
            cmd_start_offset = cur_offset

            for cmd in comp.commands:
                animation_bytes += int.to_bytes(cmd, 2, "big")
                cur_offset += 2
            if comp.size % 2 != 0:
                animation_bytes += b"\x00\x00"
                cur_offset += 2

            comp_offsets.append(cur_offset)

            animation_bytes += int.to_bytes(cmd_start_offset, 4, "big")
            animation_bytes += int.to_bytes(comp.size * 2, 2, "big")
            animation_bytes += struct.pack(">hhh", comp.x, comp.y, comp.z)
            cur_offset += 12

        offset_bytes = b""
        for offset in comp_offsets:
            offset_bytes += int.to_bytes(offset, 4, "big")
        offset_bytes += LIST_END_BYTES
        blah_bytes = offset_bytes + animation_bytes
        total_anim_bytes += blah_bytes

    animation_offset_bytes: bytes = b""
    for offset in animation_offsets:
        animation_offset_bytes += int.to_bytes(offset, 4, "big")
    animation_offset_bytes += LIST_END_BYTES

    total_anim_bytes = animation_offset_bytes + total_anim_bytes

    out_bytes += total_anim_bytes

    # Pad out_bytes to 0x8
    while len(out_bytes) % 8 != 0:
        out_bytes += b"\x00"

    # Back sprite sheets don't have animations, so just -1 and 0 padding
    back_out_bytes += LIST_END_BYTES + b"\x00\x00\x00\x00"

    # Palettes
    palette_list_start = len(out_bytes) + 0x10
    palette_list_start_back = len(back_out_bytes) + 0x10
    palette_bytes: bytes = b""
    palette_bytes_back: bytes = b""
    for palette_xml in xml[0]:
        source = palette_xml.attrib["src"]
        front_only = bool(palette_xml.get("front_only", False))
        if source not in PALETTE_CACHE:
            with open(xml_dir / "palettes" / source, "rb") as f:
                img = png.Reader(f)
                img.preamble(True)
                palette = img.palette(alpha="force")

            pal: bytes = b""
            for rgba in palette:
                if rgba[3] not in (0, 0xFF):
                    print("alpha mask mode but translucent pixels used")

                def pack_color(r, g, b, a) -> int:
                    r = r >> 3
                    g = g >> 3
                    b = b >> 3
                    a = a >> 7
                    return (r << 11) | (g << 6) | (b << 1) | a

                color = pack_color(*rgba)
                pal += int.to_bytes(color, 2, "big")

            PALETTE_CACHE[source] = pal
        palette_bytes += PALETTE_CACHE[source]
        if not front_only:
            palette_bytes_back += PALETTE_CACHE[source]

    # Pad out_bytes to 0x8
    while len(out_bytes) % 8 != 0:
        out_bytes += b"\x00"

    out_bytes += palette_bytes
    back_out_bytes += palette_bytes_back

    # Rasters
    raster_list_start = len(out_bytes) + 0x10
    raster_list_start_back = len(back_out_bytes) + 0x10
    raster_bytes: bytes = b""
    raster_bytes_back: bytes = b""
    raster_offset = 0
    for raster_xml in xml[1]:
        if "back" in raster_xml.attrib:
            has_back = True
        r = PlayerRaster.from_xml(xml_dir, raster_xml, back=False)
        raster_bytes += struct.pack(
            ">IBBBB", raster_offset, r.width, r.height, r.palette_idx, 0xFF
        )

        raster_offset += r.width * r.height // 2

    if has_back:
        raster_offset = 0
        for raster_xml in xml[1]:
            is_back = False

            r = PlayerRaster.from_xml(xml_dir, raster_xml, back=is_back)
            if "back" in raster_xml.attrib:
                is_back = True
                width = r.width
                height = r.height
            else:
                special = raster_xml.attrib["special"].split(",")
                width = int(special[0], 16)
                height = int(special[1], 16)
            palette = int(raster_xml.attrib.get(BACK_PALETTE_XML, r.palette_idx))

            raster_bytes_back += struct.pack(
                ">IBBBB", raster_offset, width, height, palette, 0xFF
            )

            if is_back:
                raster_offset += width * height // 2
            else:
                raster_offset += 0x10

    out_bytes += raster_bytes
    back_out_bytes += raster_bytes_back

    raster_list_offset = len(out_bytes) + 0x10
    raster_list_offset_back = len(back_out_bytes) + 0x10

    # Raster file offsets
    raster_offsets_bytes = b""
    raster_offsets_bytes_back = b""
    for i in range(len(xml[1])):
        raster_offsets_bytes += int.to_bytes(raster_list_start + i * 8, 4, "big")
        raster_offsets_bytes_back += int.to_bytes(
            raster_list_start_back + i * 8, 4, "big"
        )
    raster_offsets_bytes += LIST_END_BYTES
    raster_offsets_bytes_back += LIST_END_BYTES

    out_bytes += raster_offsets_bytes
    back_out_bytes += raster_offsets_bytes_back

    # Palette file offsets
    palette_list_offset = len(out_bytes) + 0x10
    palette_list_offset_back = len(back_out_bytes) + 0x10
    palette_offsets_bytes = b""
    palette_offsets_bytes_back = b""
    for i, palette_xml in enumerate(xml[0]):
        palette_offsets_bytes += int.to_bytes(palette_list_start + i * 0x20, 4, "big")
        front_only = bool(palette_xml.attrib.get("front_only", False))
        if not front_only:
            palette_offsets_bytes_back += int.to_bytes(
                palette_list_start_back + i * 0x20, 4, "big"
            )
    palette_offsets_bytes += LIST_END_BYTES
    palette_offsets_bytes_back += LIST_END_BYTES

    out_bytes += palette_offsets_bytes
    back_out_bytes += palette_offsets_bytes_back

    header = struct.pack(
        ">IIII",
        raster_list_offset,
        palette_list_offset,
        max_components,
        num_variations,
    )
    out_bytes = header + out_bytes

    ret = [out_bytes]

    if has_back:
        back_header = struct.pack(
            ">IIII",
            raster_list_offset_back,
            palette_list_offset_back,
            0,
            num_variations,
        )
        back_out_bytes = back_header + back_out_bytes

        ret.append(back_out_bytes)

    return ret


def build(player_sprite_dir: Path, out_binary: Path) -> None:
    sprite_order, raster_order = get_orderings_from_xml(player_sprite_dir)

    # Build info
    with open(player_sprite_dir / "build_info.txt", "r") as f:
        build_info = f.read()

    # Read all rasters and cache them
    cur_offset = 0
    for raster_name in raster_order:
        # "Weird" raster
        if (
            os.path.getsize(player_sprite_dir / "rasters" / f"{raster_name}.png")
            == 0x10
        ):
            special_raster_bytes = (
                b"\x80\x30\x02\x10\x00\x00\x02\x00\x00\x00\x00\x01\x00\x10\x00\x00"
            )
            RASTER_CACHE[raster_name] = PNGInfo(0, 0, cur_offset, special_raster_bytes)
            cur_offset += 0x10
            continue

        with open(player_sprite_dir / "rasters" / f"{raster_name}.png", "rb") as f:
            reader = png.Reader(f)
            width, height, rows, _ = reader.read()
            img_bytes = b""
            for row in rows:
                for a, b in iter_in_groups(row, 2):
                    byte: int = (a << 4) | b
                    byte = byte & 0xFF
                    img_bytes += byte.to_bytes(1, byteorder="big")
            RASTER_CACHE[raster_name] = PNGInfo(cur_offset, width, height, img_bytes)
            cur_offset += width * height // 2

    # Encode build_info to bytes and pad to 0x10
    build_info_bytes = build_info.encode("ascii")
    build_info_bytes += b"\0" * (0x10 - len(build_info_bytes))

    # Read in the player sprite xmls
    sprite_bytes: List[bytes] = []

    # Convert xmls to uncompressed sprite bytes
    for sprite_name in sprite_order:
        sprite_xml = ET.parse(player_sprite_dir / f"{sprite_name}.xml").getroot()
        sprite_bytes.extend(xml_to_bytes(sprite_xml, player_sprite_dir))

    # Compress sprite bytes
    compressed_sprite_bytes: bytes = b""
    yay0_cur_offset = 4 * (len(sprite_bytes) + 1)
    list_bytes: bytes = struct.pack(">I", yay0_cur_offset)

    yay0_in_path = "yay0_bytes.bin"
    yay0_out_path = "yay0_bytes.Yay0"

    for sprite_byte in sprite_bytes:
        with open(yay0_in_path, "wb") as f:
            f.write(sprite_byte)

        subprocess.run(
            [
                str(TOOLS_DIR / "build/yay0/Yay0compress"),
                yay0_in_path,
                yay0_out_path,
            ]
        )

        with open(yay0_out_path, "rb") as f:
            yay0_bytes = f.read()
            # Pad to 0x8
            yay0_bytes += b"\0" * (8 - (len(yay0_bytes) % 8))

        compressed_sprite_bytes += yay0_bytes
        yay0_cur_offset += len(yay0_bytes)
        list_bytes += struct.pack(">I", yay0_cur_offset)

    os.remove(yay0_in_path)
    os.remove(yay0_out_path)

    compressed_sprite_bytes = list_bytes + compressed_sprite_bytes

    built_raster_info = b""
    raster_info_offsets: list[int] = []
    rtes: List[RasterTableEntry] = []
    num_sheets = 0

    # Get raster data
    for sprite_name in sprite_order:
        sprite_xml = ET.parse(player_sprite_dir / f"{sprite_name}.xml").getroot()

        sheet_rtes: List[RasterTableEntry] = []
        sheet_rtes_back: List[RasterTableEntry] = []

        has_back = False
        for raster_xml in sprite_xml[1]:
            if "back" in raster_xml.attrib:
                has_back = True

            if has_back:
                if "back" in raster_xml.attrib:
                    png_info = RASTER_CACHE[raster_xml.attrib["back"][:-4]]
                    sheet_rtes_back.append(
                        RasterTableEntry(
                            png_info.offset, png_info.width * png_info.height // 2
                        )
                    )
                else:
                    sheet_rtes_back.append(RasterTableEntry(SPECIAL_RASTER, 0x10))

            png_info = RASTER_CACHE[raster_xml.attrib["src"][:-4]]
            sheet_rtes.append(
                RasterTableEntry(png_info.offset, png_info.width * png_info.height // 2)
            )

        raster_info_offsets.append(len(rtes))
        num_sheets += 1
        rtes.extend(sheet_rtes)
        if has_back:
            raster_info_offsets.append(len(rtes))
            num_sheets += 1
            rtes.extend(sheet_rtes_back)
    raster_info_offsets.append(len(rtes))  # Final 'offset' (size of list)

    separators_offset = 0x10
    infos_offset = separators_offset + (num_sheets + 1) * 4
    rasters_offset = infos_offset + (len(rtes) + 1) * 4

    # Align raster_offset_start to 0x10 offset
    rasters_offset = (rasters_offset + 0xF) & ~0xF

    for rte in rtes:
        if rte.offset == SPECIAL_RASTER:
            built_raster_info += struct.pack(">I", 0x0011F880)
            continue

        packed_info = (rte.size >> 4) << 20
        packed_info |= (rte.offset + rasters_offset) & 0xFFFFF
        built_raster_info += struct.pack(">I", packed_info)

    # This is the missing raster from before
    built_raster_info += struct.pack(">I", 0x06C9CD50)

    header = struct.pack(">IIII", separators_offset, infos_offset, rasters_offset, 0)

    info_list_bytes = b""
    for offset in raster_info_offsets:
        info_list_bytes += struct.pack(">I", offset)

    built_raster_info = header + info_list_bytes + built_raster_info

    # Align build_raster_info to 0x10 offset
    built_raster_info += b"\0" * ((0x10 - len(built_raster_info)) & 0xF)

    raster_bytes = b""
    for raster_name in raster_order[:-1]:  # Skip last raster
        png_info = RASTER_CACHE[raster_name]
        raster_bytes += png_info.data

    built_raster_info += raster_bytes

    built_raster_info_offset = len(built_raster_info) + 0x10
    compressed_sprite_bytes_offset = built_raster_info_offset + len(
        compressed_sprite_bytes
    )

    major_file_divisons = struct.pack(
        ">IIII",
        0x10,
        built_raster_info_offset,
        compressed_sprite_bytes_offset,
        0x23F1F8,  # TODO hard-coded
    )

    final_data = (
        build_info_bytes
        + major_file_divisons
        + built_raster_info
        + compressed_sprite_bytes
    )

    with open(out_binary, "wb") as f:
        f.write(final_data)


if __name__ == "__main__":
    if len(sys.argv) != 3:
        print("usage: player_sprites.py [OUTBIN] [DIR]")
        exit(1)

    _, outfile, sprite_dir = sys.argv
    build(Path(sprite_dir), Path(outfile))
