#! /usr/bin/env

from dataclasses import dataclass
import io
from pathlib import Path
import sys
from typing import List

sys.path.append(str(Path(__file__).parent.parent.parent))
sys.path.append(str(Path(__file__).parent.parent.parent / "splat"))
from splat_ext.pm_sprites import (
    BACK_PALETTE_XML,
    LIST_END_BYTES,
    MAX_COMPONENTS_XML,
    NPC_SPRITE_MEDADATA_XML_FILENAME,
    PALETTE_GROUPS_XML,
    PLAYER_SPRITE_MEDADATA_XML_FILENAME,
    SPECIAL_RASTER,
    PlayerRaster,
    RasterTableEntry,
    NpcSprite,
)
from splat_ext.sprite_common import AnimComponent, iter_in_groups

import os
import png  # type: ignore
import struct
import subprocess
import xml.etree.ElementTree as ET
from dataclasses import dataclass
from typing import Dict, List, Tuple

TOOLS_DIR = Path(
    os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
)
sys.path.append(str(TOOLS_DIR))


def pack_color(r, g, b, a) -> int:
    r = r >> 3
    g = g >> 3
    b = b >> 3
    a = a >> 7
    return (r << 11) | (g << 6) | (b << 1) | a


def get_player_sprite_metadata(xml_dir: Path) -> Tuple[str, List[str], List[str]]:
    orderings_tree = ET.parse(xml_dir / PLAYER_SPRITE_MEDADATA_XML_FILENAME)

    build_info = str(orderings_tree.getroot()[0].text)

    sprite_order: List[str] = []
    for sprite_tag in orderings_tree.getroot()[1]:
        sprite_order.append(sprite_tag.attrib["name"])

    raster_order: List[str] = []
    for raster_tag in orderings_tree.getroot()[2]:
        raster_order.append(raster_tag.attrib["name"])

    return build_info, sprite_order, raster_order


def get_npc_sprite_metadata(xml_dir: Path) -> List[str]:
    orderings_tree = ET.parse(xml_dir / NPC_SPRITE_MEDADATA_XML_FILENAME)

    sprite_order: List[str] = []
    for sprite_tag in orderings_tree.getroot()[0]:
        sprite_order.append(sprite_tag.attrib["name"])

    return sprite_order


@dataclass
class CI4Info:
    offset: int
    width: int
    height: int
    data: bytes

    @property
    def size(self):
        return self.width * self.height // 2


RASTER_CACHE: Dict[str, CI4Info] = {}
PALETTE_CACHE: Dict[str, bytes] = {}
PLAYER_XML_CACHE: Dict[str, ET.Element] = {}

SPECIAL_RASTER_BYTES = (
    b"\x80\x30\x02\x10\x00\x00\x02\x00\x00\x00\x00\x01\x00\x10\x00\x00"
)


def cache_rasters(raster_order: List[str], player_sprite_dir: Path):
    # Read all rasters and cache them
    cur_offset = 0
    for raster_name in raster_order:
        # "Weird" raster
        if (
            os.path.getsize(player_sprite_dir / "rasters" / f"{raster_name}.png")
            == 0x10
        ):
            RASTER_CACHE[raster_name] = CI4Info(0, 0, cur_offset, SPECIAL_RASTER_BYTES)
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
            RASTER_CACHE[raster_name] = CI4Info(cur_offset, width, height, img_bytes)
            cur_offset += RASTER_CACHE[raster_name].size


def player_xml_to_bytes(xml: ET.Element, xml_dir: Path) -> List[bytes]:
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
    # TODO is there always padding needed, or is this just a result of the vanilla data alignment?
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


def xml_has_back(xml: ET.Element) -> bool:
    for raster_xml in xml[1]:
        if "back" in raster_xml.attrib:
            return True
    return False


def write_player_sprite_header(
    sprite_order: List[str],
    out_file: Path,
) -> None:
    ifdef_name = "_PLAYER_SPRITE_H_"

    sprite_id = 1
    player_sprites: Dict[str, int] = {}
    player_rasters: Dict[str, Dict[str, int]] = {}
    player_palettes: Dict[str, Dict[str, int]] = {}
    player_anims: Dict[str, Dict[str, int]] = {}
    max_sprite_sizes: Dict[str, int] = {}

    for sprite_name in sprite_order:
        sprite_xml = PLAYER_XML_CACHE[sprite_name]
        has_back = xml_has_back(sprite_xml)

        player_sprites[f"SPR_{sprite_name}"] = sprite_id
        player_rasters[sprite_name] = {}
        player_palettes[sprite_name] = {}
        player_anims[sprite_name] = {}

        for palette_xml in sprite_xml[0]:
            palette_id = int(palette_xml.attrib["id"], 0x10)
            palette_name = palette_xml.attrib["name"]
            player_palettes[sprite_name][
                f"SPR_PAL_{sprite_name}_{palette_name}"
            ] = palette_id

            for anim_id, anim_xml in enumerate(sprite_xml[2]):
                anim_name = anim_xml.attrib["name"]
                if palette_id > 0:
                    anim_name = f"{palette_name}_{anim_name}"
                player_anims[sprite_name][f"ANIM_{sprite_name}_{anim_name}"] = (
                    (sprite_id << 16) | (palette_id << 8) | anim_id
                )

        max_size = 0
        for raster_xml in sprite_xml[1]:
            raster_id = int(raster_xml.attrib["id"], 0x10)
            raster_name = raster_xml.attrib["name"]
            player_rasters[sprite_name][
                f"SPR_IMG_{sprite_name}_{raster_name}"
            ] = raster_id

            raster = RASTER_CACHE[raster_xml.attrib["src"][:-4]]
            if max_size < raster.size:
                max_size = raster.size
        max_sprite_sizes[sprite_name] = max_size

        sprite_id += 1

        if has_back:
            player_sprites[f"SPR_{sprite_name}_Back"] = sprite_id

            max_size = 0
            for raster_xml in sprite_xml[1]:
                if "back" in raster_xml.attrib:
                    raster = RASTER_CACHE[raster_xml.attrib["back"][:-4]]
                    if max_size < raster.size:
                        max_size = raster.size
            max_sprite_sizes[f"{sprite_name}_Back"] = max_size

            sprite_id += 1

    out_file.parent.mkdir(exist_ok=True, parents=True)
    with open(out_file, "w") as f:
        f.write(f"#ifndef {ifdef_name}\n")
        f.write(f"#define {ifdef_name}\n\n")

        # PlayerSprites
        f.write("enum PlayerSprites {\n")
        for sprite_name, sprite_id in player_sprites.items():
            f.write(f"    {sprite_name} = 0x{sprite_id:X},\n")
        f.write("};\n\n")

        for sprite_name in max_sprite_sizes:
            f.write(
                f"#define MAX_IMG_{sprite_name} 0x{max_sprite_sizes[sprite_name]:04X}\n"
            )
        f.write("\n")

        for sprite_name in sprite_order:
            f.write(f"// {sprite_name}\n")

            for raster_name, raster_id in player_rasters[sprite_name].items():
                f.write(f"#define {raster_name} 0x{raster_id:02X}\n")
            f.write("\n")

            for palette_name, palette_id in player_palettes[sprite_name].items():
                f.write(f"#define {palette_name} 0x{palette_id:02X}\n")
            f.write("\n")

            for anim_name, anim_id in player_anims[sprite_name].items():
                f.write(f"#define {anim_name} 0x{anim_id:X}\n")
            f.write("\n")

        f.write(f"#endif // {ifdef_name}\n")


def npc_sprite_to_bytes(sprite_dir: Path) -> bytes:
    try:
        sprite = NpcSprite.from_dir(Path(sprite_dir))
    except AssertionError as e:
        print("error:", e)
        exit(1)

    f = io.BytesIO()

    f.seek(0x10)  # leave space for header

    # leave space for animation offset list
    f.seek((len(sprite.animations) + 1) * 4, 1)
    animation_offsets = []

    # write animations
    for i, components in enumerate(sprite.animations):
        animation_offsets.append(f.tell())

        # leave space for component offset list
        f.seek((len(components) + 1) * 4, 1)
        component_offsets = []

        for comp in components:
            offset = f.tell()

            for command in comp.commands:
                f.write(command.to_bytes(2, byteorder="big"))

            f.seek(f.tell() % 4, 1)
            component_offsets.append(f.tell())

            f.write(offset.to_bytes(4, byteorder="big"))
            f.write((len(comp.commands) * 2).to_bytes(2, byteorder="big"))
            f.write(comp.x.to_bytes(2, byteorder="big", signed=True))
            f.write(comp.y.to_bytes(2, byteorder="big", signed=True))
            f.write(comp.z.to_bytes(2, byteorder="big", signed=True))

        next_anim = f.tell()

        # write component offset list
        f.seek(animation_offsets[i])
        component_offsets.append(-1)
        for offset in component_offsets:
            f.write(offset.to_bytes(4, byteorder="big", signed=True))

        f.seek(next_anim)

    # palettes start 8-byte aligned
    if (f.tell() & 7) == 4:
        f.seek(4, 1)

    # write palettes
    palette_offsets: List[int] = []
    for i, palette in enumerate(sprite.palettes):
        palette_offsets.append(f.tell())
        for rgba in palette:
            if rgba[3] not in (0, 0xFF):
                print(
                    "error: translucent pixels not allowed in palette {sprite.palette_names[i]}"
                )
                exit(1)

            color = pack_color(*rgba)
            f.write(color.to_bytes(2, byteorder="big"))

    # write images/rasters
    image_offsets = []
    for image in sprite.images:
        offset = f.tell()

        for a, b in iter_in_groups(image.raster, 2):
            byte = (a << 4) | b
            f.write(byte.to_bytes(1, byteorder="big"))

        image_offsets.append(f.tell())

        f.write(offset.to_bytes(4, byteorder="big"))
        f.write(bytes([image.width, image.height, image.palette_index, 0xFF]))

    # write image offset list
    image_offset_list_offset = f.tell()
    image_offsets.append(-1)
    for offset in image_offsets:
        f.write(offset.to_bytes(4, byteorder="big", signed=True))

    # write palette offset list
    palette_offset_list_offset = f.tell()
    palette_offsets.append(-1)
    for offset in palette_offsets:
        f.write(offset.to_bytes(4, byteorder="big", signed=True))

    # write header
    f.seek(0)
    f.write(image_offset_list_offset.to_bytes(4, byteorder="big"))
    f.write(palette_offset_list_offset.to_bytes(4, byteorder="big"))
    f.write(sprite.max_components.to_bytes(4, byteorder="big"))
    f.write(sprite.num_variations.to_bytes(4, byteorder="big"))

    # write animation offset list
    animation_offsets.append(-1)
    for offset in animation_offsets:
        f.write(offset.to_bytes(4, byteorder="big", signed=True))

    f.seek(0)
    return f.read()


def build_player_sprites(sprite_order: List[str], player_sprite_dir: Path) -> bytes:
    sprite_bytes: List[bytes] = []

    for sprite_name in sprite_order:
        sprite_bytes.extend(
            player_xml_to_bytes(PLAYER_XML_CACHE[sprite_name], player_sprite_dir)
        )

    # Compress sprite bytes
    compressed_sprite_bytes: bytes = b""
    yay0_cur_offset = 4 * (len(sprite_bytes) + 1)
    list_bytes: bytes = struct.pack(">I", yay0_cur_offset)

    # TODO figure out how to use tmp files if possible
    yay0_in_path = player_sprite_dir / "yay0_bytes.bin"
    yay0_out_path = player_sprite_dir / "yay0_bytes.Yay0"

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

    return list_bytes + compressed_sprite_bytes


def build_npc_sprites(sprite_order: List[str], sprite_dir: Path) -> bytes:
    sprite_bytes: List[bytes] = []

    for sprite_name in sprite_order:
        sprite_bytes.append(npc_sprite_to_bytes(sprite_dir / "npc" / sprite_name))

    # Compress sprite bytes
    compressed_sprite_bytes: bytes = b""
    yay0_cur_offset = 4 * (len(sprite_bytes) + 1)
    list_bytes: bytes = struct.pack(">I", yay0_cur_offset)

    # TODO figure out how to use tmp files if possible
    yay0_in_path = sprite_dir / "yay0_bytes.bin"
    yay0_out_path = sprite_dir / "yay0_bytes.Yay0"

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
            # Add 0s to pad to 0x8
            yay0_bytes_len = (len(yay0_bytes) + 0x7) & ~0x7
            yay0_bytes += b"\0" * (yay0_bytes_len - len(yay0_bytes))

        compressed_sprite_bytes += yay0_bytes
        yay0_cur_offset += len(yay0_bytes)
        list_bytes += struct.pack(">I", yay0_cur_offset)

    os.remove(yay0_in_path)
    os.remove(yay0_out_path)

    return list_bytes + compressed_sprite_bytes


def build_player_rasters(sprite_order: List[str], raster_order: List[str]) -> bytes:
    packed_raster_data = b""
    raster_info_offsets: list[int] = []
    rtes: List[RasterTableEntry] = []
    num_sheets = 0

    # Get raster data
    for sprite_name in sprite_order:
        sprite_xml = PLAYER_XML_CACHE[sprite_name]

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
                        RasterTableEntry(png_info.offset, png_info.size)
                    )
                else:
                    sheet_rtes_back.append(RasterTableEntry(SPECIAL_RASTER, 0x10))

            png_info = RASTER_CACHE[raster_xml.attrib["src"][:-4]]
            sheet_rtes.append(RasterTableEntry(png_info.offset, png_info.size))

        raster_info_offsets.append(len(rtes))
        num_sheets += 1
        rtes.extend(sheet_rtes)
        if has_back:
            raster_info_offsets.append(len(rtes))
            num_sheets += 1
            rtes.extend(sheet_rtes_back)
    raster_info_offsets.append(len(rtes))  # Final 'offset' (size of list)

    info_list_bytes = b""
    for offset in raster_info_offsets:
        info_list_bytes += struct.pack(">I", offset)

    separators_offset = 0x10
    infos_offset = separators_offset + (num_sheets + 1) * 4
    rasters_offset = infos_offset + (len(rtes) + 1) * 4

    # Align raster_offset_start to 0x10 offset
    rasters_offset = (rasters_offset + 0xF) & ~0xF

    for rte in rtes:
        if rte.offset == SPECIAL_RASTER:
            packed_raster_data += struct.pack(">I", 0x0011F880)
            continue

        packed_info = (rte.size >> 4) << 20
        packed_info |= (rte.offset + rasters_offset) & 0xFFFFF
        packed_raster_data += struct.pack(">I", packed_info)

    # This is the missing raster from before
    packed_raster_data += struct.pack(">I", 0x06C9CD50)

    header = struct.pack(">IIII", separators_offset, infos_offset, rasters_offset, 0)

    ret = header + info_list_bytes + packed_raster_data

    # Align cumulative data to 0x10 offset
    ret += b"\0" * ((0x10 - len(ret)) & 0xF)

    raster_bytes = b""
    for raster_name in raster_order[:-1]:  # Skip last raster
        png_info = RASTER_CACHE[raster_name]
        raster_bytes += png_info.data

    ret += raster_bytes
    return ret


def build(out_file: Path, player_header_path: Path, sprite_dir: Path) -> None:
    player_sprite_dir = sprite_dir / "player"

    build_info, player_sprite_order, player_raster_order = get_player_sprite_metadata(
        sprite_dir
    )
    npc_sprite_order = get_npc_sprite_metadata(sprite_dir)

    cache_rasters(player_raster_order, player_sprite_dir)

    # Read and cache player XMLs
    for sprite_name in player_sprite_order:
        sprite_xml = ET.parse(player_sprite_dir / f"{sprite_name}.xml").getroot()
        PLAYER_XML_CACHE[sprite_name] = sprite_xml

    write_player_sprite_header(player_sprite_order, player_header_path)

    # Encode build_info to bytes and pad to 0x10
    build_info_bytes = build_info.encode("ascii")
    build_info_bytes += b"\0" * (0x10 - len(build_info_bytes))

    player_sprite_bytes = build_player_sprites(player_sprite_order, player_sprite_dir)
    player_raster_bytes = build_player_rasters(player_sprite_order, player_raster_order)
    npc_sprite_bytes = build_npc_sprites(npc_sprite_order, sprite_dir)

    built_raster_info_offset = 0x10 + len(player_raster_bytes)
    compressed_sprite_bytes_offset = built_raster_info_offset + len(player_sprite_bytes)
    npc_sprites_offset = compressed_sprite_bytes_offset + len(npc_sprite_bytes)

    major_file_divisons = struct.pack(
        ">IIII",
        0x10,
        built_raster_info_offset,
        compressed_sprite_bytes_offset,
        npc_sprites_offset,
    )

    final_data = (
        build_info_bytes
        + major_file_divisons
        + player_raster_bytes
        + player_sprite_bytes
        + npc_sprite_bytes
    )

    with open(out_file, "wb") as f:
        f.write(final_data)


if __name__ == "__main__":
    if len(sys.argv) != 4:
        print("usage: sprites.py [OUT] [PLAYER_HEADER_OUT] [IN_DIR]")
        exit(1)

    _, out, player_header_out, in_dir = sys.argv
    build(Path(out), Path(player_header_out), Path(in_dir))
