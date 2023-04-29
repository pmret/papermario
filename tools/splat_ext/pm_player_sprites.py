#! /usr/bin/python3

from dataclasses import dataclass, field
from pathlib import Path
import os
import struct
import sys
from typing import Any, Dict, List, Optional
import xml.etree.ElementTree as ET

from sprite_common import AnimComponent, read_offset_list
import pylibyaml
import yaml as yaml_loader

TOOLS_DIR = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.append(str(Path(TOOLS_DIR)))
from splat.util.n64.Yay0decompress import Yay0Decompressor


@dataclass
class RasterInfo:
    offset: int
    size: int


@dataclass
class SpriteListEntry:
    start: int
    count: int
    loaded_position: int = 0
    raster_offsets: List[int] = field(default_factory=list)
    raster_positions: List[int] = field(default_factory=list)
    rasters: List[RasterInfo] = field(default_factory=list)

    def add_raster(self, raster: RasterInfo):
        self.rasters.append(raster)
        self.raster_offsets.append(raster.offset)
        self.raster_positions.append(self.loaded_position)
        self.loaded_position += raster.size


@dataclass
class PlayerRasterReference:
    offset: int
    width: int
    height: int
    default_palette: int
    special: bool

    @staticmethod
    def from_bytes(data: bytes, unknown_raster: bool) -> "PlayerRasterReference":
        offset, width, height, default_palette = struct.unpack(">iBBB", data)

        return PlayerRasterReference(offset, width, height, default_palette, unknown_raster)


@dataclass
class PlayerSprite:
    max_components: int
    num_variations: int

    animations: List[List[AnimComponent]]
    palettes: List[bytes]
    images: List[PlayerRasterReference]

    @staticmethod
    def from_bytes(data: bytes, raster_section: SpriteListEntry) -> "PlayerSprite":
        image_offsets = read_offset_list(data[int.from_bytes(data[0:4], byteorder="big"):])
        palette_offsets = read_offset_list(data[int.from_bytes(data[4:8], byteorder="big"):])
        max_components = int.from_bytes(data[8:0xC], "big")
        num_variations = int.from_bytes(data[0xC:0x10], "big")
        animation_offsets = read_offset_list(data[0x10:])

        palettes: List[bytes] = []
        images: List[PlayerRasterReference] = []
        animations: List[List[AnimComponent]] = []

        # Read palettes
        for offset in palette_offsets:
            pal = data[offset:offset+0x20]
            palettes.append(pal)

        # Read images
        for i, offset in enumerate(image_offsets):
            is_unknown_raster = raster_section.raster_offsets[i] == UNKNOWN_RASTER
            image = PlayerRasterReference.from_bytes(data[offset:offset + 7], is_unknown_raster)
            images.append(image)

        # Read animations
        for offset in animation_offsets:
            anim: List[AnimComponent] = []

            for comp_offset in read_offset_list(data[offset:]):
                anim.append(AnimComponent.from_bytes(data[comp_offset:], data))
            animations.append(anim)

        return PlayerSprite(max_components, num_variations, animations, palettes, images)

def get_raster_infos(data: bytes) -> List[RasterInfo]:
    raster_infos = []
    current_section_pos = 0
    current_section = 0

    for i in range(0, len(data) - 4, 4):
        packed = int.from_bytes(data[i:i+4])

        size = (packed >> 20) << 4
        offset = packed & 0xFFFFF
        ri = RasterInfo(offset, size)
        raster_infos.append(ri)

        if current_section > len(raster_sections) - 1:
            continue # TODO figure out

        raster_sections[current_section].add_raster(ri)

        current_section_pos += 1

        if current_section_pos == raster_sections[current_section].count:
            current_section += 1
            current_section_pos = 0
    return raster_infos


with (Path(__file__).parent / f"player.yaml").open("r") as f:
    sprite_cfg = yaml_loader.load(f.read(), Loader=yaml_loader.SafeLoader)

with open("assets/us/1943020.bin", "rb") as f:
    player_sprite_raster_data: bytes = f.read()

# Header parsing
index_ranges_offset = int.from_bytes(player_sprite_raster_data[0:0x4], "big")
packed_raster_info_offset = int.from_bytes(player_sprite_raster_data[0x4:0x8], "big")
ci4_raster_data_offset = int.from_bytes(player_sprite_raster_data[0x8:0xC], "big")

index_ranges: bytes = player_sprite_raster_data[index_ranges_offset:packed_raster_info_offset]
packed_raster_info_data = player_sprite_raster_data[packed_raster_info_offset:ci4_raster_data_offset]
ci4_raster_data = player_sprite_raster_data[ci4_raster_data_offset:]

# Create raster info intervals (readSpriteSections)
raster_sections: List[SpriteListEntry] = []
for i in range(0, len(index_ranges) - 4, 4):
    start = int.from_bytes(index_ranges[i:i+4], "big")
    end = int.from_bytes(index_ranges[i+4:i+8], "big")
    raster_sections.append(SpriteListEntry(start, end - start))

raster_infos = get_raster_infos(packed_raster_info_data) # (readRasterTable)

# (readSprites)

# raster_info_groups: List[List[RasterInfo]] = []
# for interval in raster_sections:
#     raster_info_groups.append(raster_infos[interval[0]:interval[1]])

# raster_groups = [
#     [
#     player_sprite_raster_data[info.offset:info.offset + info.size] for info in group
#     ] for group in raster_info_groups
# ]

UNKNOWN_RASTER = 0x1F880

with open("assets/us/19E0970.bin", "rb") as f:
    yay0_sprite_data_chunked: bytes = f.read()

yay0_splits = []
for i in range(14):
    yay0_splits.append(int.from_bytes(yay0_sprite_data_chunked[i*4:i*4+4], "big"))

yay0_sprite_data = []
for i in range(0, len(yay0_splits) - 1):
    yay0_sprite_data.append(yay0_sprite_data_chunked[yay0_splits[i]:yay0_splits[i+1]])

sprites = []
for i, yay0_piece in enumerate(yay0_sprite_data):
    sprite_data = Yay0Decompressor.decompress(yay0_piece, "big")
    raster_section = raster_sections[i]
    sprite = PlayerSprite.from_bytes(sprite_data, raster_section)
    sprites.append(sprite)

sprite_pos = 0
sprite_names = list(sprite_cfg.keys())
for s in range(len(sprite_names)):
    cur_sprite_name = sprite_names[s]

    path = Path(f"assets/us/sprite/player/")
    path.mkdir(parents=True, exist_ok=True)

    cur_sprite: PlayerSprite = sprites[sprite_pos]
    cur_sprite_back: Optional[PlayerSprite] = None
    has_back = sprite_cfg[cur_sprite_name].get("has_back", False)

    if has_back:
        if s == len(sprite_names) - 1:
            print("ERROR: Last sprite has back, but no sprite to pair with")
            sys.exit(1)
        cur_sprite_back = sprites[sprite_pos + 1]

    SpriteSheet = ET.Element("SpriteSheet", {
        "maxComponents": str(cur_sprite.max_components),
        "paletteGroups": str(cur_sprite.num_variations),
    })

    PaletteList = ET.SubElement(SpriteSheet, "PaletteList")
    RasterList = ET.SubElement(SpriteSheet, "RasterList")
    AnimationList = ET.SubElement(SpriteSheet, "AnimationList")

    palette_to_raster: Dict[int, List[Any]] = {}

    for i, image in enumerate(cur_sprite.images):
        # image.write(path / (name + ".png"), cur_sprite.palettes[image.palette_index])

        if image.default_palette not in palette_to_raster:
            palette_to_raster[image.default_palette] = []
        palette_to_raster[image.default_palette].append(image)

        name_offset = raster_sections[sprite_pos].raster_offsets[i]
        raster_attributes = {
            "id": f"{i:X}",
            "palette": f"{image.default_palette:X}",
            "src":  f"Player_{name_offset:05X}.png",
        }

        if has_back:
            assert cur_sprite_back is not None
            back_image = cur_sprite_back.images[i]

            if back_image.special:
                raster_attributes["special"] = f"{back_image.width & 0xFF:X},{back_image.height & 0xFF:X}"
            else:
                back_name_offset = raster_sections[sprite_pos + 1].raster_offsets[i]
                raster_attributes["back"] = f"Player_{back_name_offset:05X}.png"

        ET.SubElement(RasterList, "Raster", raster_attributes)

    palette_names = sprite_cfg[cur_sprite_name].get("palettes")
    for i, palette in enumerate(cur_sprite.palettes):
        name = palette_names[i] if (palette_names and i < len(palette_names)) else f"Pal{i:02X}"

        if i in palette_to_raster:
            img = palette_to_raster[i][0]
        else:
            img = cur_sprite.images[0]

        # img.write(path / (name + ".png"), palette)

        ET.SubElement(PaletteList, "Palette", {
            "id": f"{i:X}",
            "src": name + ".png",
        })

    animation_names = sprite_cfg[cur_sprite_name].get("animations")
    for i, components in enumerate(cur_sprite.animations):
        Animation = ET.SubElement(AnimationList, "Animation", {
            "name": animation_names[i] if animation_names else f"Anim{i:02X}",
        })

        for j, comp in enumerate(components):
            Component = ET.SubElement(Animation, "Component", {
                "name": f"Comp_{j:X}",
                "xyz": ",".join(map(str, [comp.x, comp.y, comp.z])),
            })

            for anim in comp.animations:
                ET.SubElement(Component, anim.__class__.__name__, anim.get_attributes())

    xml = ET.ElementTree(SpriteSheet)

    # pretty print (Python 3.9+)
    if hasattr(ET, "indent"):
        ET.indent(xml, "    ")

    xml.write(str(path / f"{cur_sprite_name}.xml"), encoding="unicode")

    if has_back:
        sprite_pos += 2
    else:
        sprite_pos += 1
