#! /usr/bin/python3

from dataclasses import dataclass, field
from math import ceil
from pathlib import Path
import os
import struct
import sys
from typing import Any, Dict, List, Optional, Tuple
import xml.etree.ElementTree as ET
import png

from sprite_common import AnimComponent, read_offset_list, iter_in_groups
import pylibyaml
import yaml as yaml_loader

TOOLS_DIR = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.append(str(Path(TOOLS_DIR)))
from splat.util.n64.Yay0decompress import Yay0Decompressor

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

PaletteData = List[Tuple[int, int, int, int]]

SPECIAL_RASTER = 0x1F880


@dataclass
class PlayerPalette:
    data: PaletteData
    is_dumped: bool = False


@dataclass
class RasterTableEntry:
    offset: int
    size: int

    count: int = 0
    size_set = False
    height: int = 0
    width: int = 0

    raster: bytearray = field(default_factory=bytearray)
    palette: Optional[PlayerPalette] = None

    def set_size(self, width: int, height: int):
        self.width = width
        self.height = height
        self.size_set = True

    def write_png(self, raster_buffer: bytes, path: Path):
        if not self.size_set:
            # raise ValueError("Size has not been set")
            print("Size has not been set")
            return

        if self.palette is None:
            raise ValueError("Palette has not been set")

        w = png.Writer(self.width, self.height, palette=self.palette.data)

        if self.raster is not None:
            raster = bytearray()
            # Get raster bytes into ci4 format
            for i in range(self.width * self.height // 2):
                raster.append(raster_buffer[self.offset + i] >> 4)
                raster.append(raster_buffer[self.offset + i] & 0xF)
            self.raster = raster

        with open(path, "wb") as f:
            w.write_array(f, self.raster)


@dataclass
class SpriteListEntry:
    start: int
    count: int
    raster_offsets: List[int] = field(default_factory=list)
    raster_positions: List[int] = field(default_factory=list)
    raster_table_entries: List[RasterTableEntry] = field(default_factory=list)
    loaded_position: int = 0

    def add_table_entry(self, raster: RasterTableEntry):
        self.raster_table_entries.append(raster)
        self.raster_offsets.append(raster.offset)
        self.raster_positions.append(self.loaded_position)
        self.loaded_position += raster.size



@dataclass
class PlayerRaster:
    offset: int
    width: int
    height: int
    default_palette: int
    is_special: bool
    raster: bytearray = field(default_factory=bytearray)

    @staticmethod
    def from_bytes(metadata: bytes, raster_section: SpriteListEntry, ci4_raster_bytes: bytes, palettes: List[PlayerPalette],
                   img_idx: int) -> "PlayerRaster":
        offset, width, height, default_palette = struct.unpack(">iBBB", metadata)

        # Get raster bytes into ci4 format
        raster = bytearray()
        for i in range(width * height // 2):
            raster.append(ci4_raster_bytes[offset + i] >> 4)
            raster.append(ci4_raster_bytes[offset + i] & 0xF)

        is_special = raster_section.raster_offsets[img_idx] == SPECIAL_RASTER

        if not is_special:
            rte = raster_section.raster_table_entries[img_idx]
            rte.set_size(width, height)
            rte.palette = palettes[default_palette]

        return PlayerRaster(offset, width, height, default_palette, is_special, raster)

    def write(self, path: Path, palette: PlayerPalette) -> None:
        if self.is_special:
            return

        w = png.Writer(self.width, self.height, palette=palette.data)

        with open(path, "wb") as f:
            w.write_array(f, self.raster)


@dataclass
class PlayerSprite:
    max_components: int
    num_variations: int

    animations: List[List[AnimComponent]]
    palettes: List[PlayerPalette]
    rasters: List[PlayerRaster]

    @staticmethod
    def from_bytes(data: bytes, raster_section: SpriteListEntry, ci4_raster_data: bytes) -> "PlayerSprite":
        image_offsets = read_offset_list(data[int.from_bytes(data[0:4], byteorder="big"):])
        palette_offsets = read_offset_list(data[int.from_bytes(data[4:8], byteorder="big"):])
        max_components = int.from_bytes(data[8:0xC], "big")
        num_variations = int.from_bytes(data[0xC:0x10], "big")
        animation_offsets = read_offset_list(data[0x10:])

        palettes: List[PlayerPalette] = []
        rasters: List[PlayerRaster] = []
        animations: List[List[AnimComponent]] = []

        # Read palettes
        for pal_offset in palette_offsets:
            pal = data[pal_offset:pal_offset+0x20]
            palettes.append(PlayerPalette([unpack_color(c) for c in iter_in_groups(pal, 2)]))

        # Read images
        for i, metadata_offset in enumerate(image_offsets):
            raster = PlayerRaster.from_bytes(
                data[metadata_offset:metadata_offset + 7], raster_section, ci4_raster_data, palettes, i)
            rasters.append(raster)

        # Read animations
        for anim_offset in animation_offsets:
            anim: List[AnimComponent] = []

            for comp_offset in read_offset_list(data[anim_offset:]):
                anim.append(AnimComponent.from_bytes(data[comp_offset:], data))
            animations.append(anim)

        return PlayerSprite(max_components, num_variations, animations, palettes, rasters)


def parse_raster_table_entries(data: bytes) -> Dict[int, RasterTableEntry]:
    ret: Dict[int, RasterTableEntry] = {}
    current_section_pos = 0
    current_section = 0

    for i in range(0, len(data) - 4, 4):
        packed = int.from_bytes(data[i:i+4])

        size = (packed >> 20) << 4
        offset = packed & 0xFFFFF
        rte = RasterTableEntry(offset, size)

        if offset in ret:
            assert ret[offset].size == size
        else:
            ret[offset] = rte

        if current_section > len(raster_sections) - 1:
            continue # TODO figure out

        raster_sections[current_section].add_table_entry(rte)

        current_section_pos += 1

        if current_section_pos == raster_sections[current_section].count:
            current_section += 1
            current_section_pos = 0
    return ret

def extract_sprite_data() -> None:
    sprite_pos = 0
    sprite_names = list(sprite_cfg.keys())
    for s in range(len(sprite_names)):
        cur_sprite_name = sprite_names[s]

        path = Path(f"assets/us/sprite/player/")
        path.mkdir(parents=True, exist_ok=True)

        (path / cur_sprite_name).mkdir(parents=True, exist_ok=True)

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

        for i, raster in enumerate(cur_sprite.rasters):
            name_offset = raster_sections[sprite_pos].raster_offsets[i]

            if raster.default_palette not in palette_to_raster:
                palette_to_raster[raster.default_palette] = []
            palette_to_raster[raster.default_palette].append(raster)

            raster_attributes = {
                "id": f"{i:X}",
                "palette": f"{raster.default_palette:X}",
                "src": f"Player_{name_offset:05X}.png",
            }

            if has_back:
                assert cur_sprite_back is not None
                back_image = cur_sprite_back.rasters[i]

                if back_image.is_special:
                    raster_attributes["special"] = f"{back_image.width & 0xFF:X},{back_image.height & 0xFF:X}"
                else:
                    back_name_offset = raster_sections[sprite_pos + 1].raster_offsets[i]
                    raster_attributes["back"] = f"Player_{back_name_offset:05X}.png"

            ET.SubElement(RasterList, "Raster", raster_attributes)

        palette_names = sprite_cfg[cur_sprite_name].get("palettes")
        for i, palette in enumerate(cur_sprite.palettes):
            name = palette_names[i] if (palette_names and i < len(palette_names)) else f"Pal{i:02X}"

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


def write_shared_sprites() -> None:
    base_path =  Path(f"assets/us/sprite/player/shared")
    base_path.mkdir(parents=True, exist_ok=True)

    for offset, rte in raster_table_entries.items():
        if offset == SPECIAL_RASTER:
            continue

        rte.write_png(player_sprite_raster_data, base_path / f"{offset:05X}.png")

def write_palettes() -> None:
    sprite_names = list(sprite_cfg.keys())
    for i, section in enumerate(raster_sections):
        sprite = sprites[i]

        sprite_name = sprite_names[i]
        print("Palettes: " + sprite_name)
        path = Path(f"assets/us/sprite/player/{sprite_name}")
        default_image: Optional[bytearray] = None

        for raster in sprite.rasters:
            if raster.is_special:
                continue

            if default_image is None:
                default_image = raster.raster

            pal_name = sprite_cfg[sprite_name]["palettes"][raster.default_palette]

            palette = sprite.palettes[raster.default_palette]

            raster.write(path / (pal_name + ".png"), palette)



with (Path(__file__).parent / f"player.yaml").open("r") as f:
    sprite_cfg = yaml_loader.load(f.read(), Loader=yaml_loader.SafeLoader)

with open("assets/us/1943020.bin", "rb") as f:
    player_sprite_raster_data: bytes = f.read()

# Header parsing
index_ranges_offset = int.from_bytes(player_sprite_raster_data[0:0x4], "big")
packed_raster_info_offset = int.from_bytes(player_sprite_raster_data[0x4:0x8], "big")
ci4_raster_data_offset = int.from_bytes(player_sprite_raster_data[0x8:0xC], "big")

index_ranges = player_sprite_raster_data[index_ranges_offset:packed_raster_info_offset]
packed_raster_info_data = player_sprite_raster_data[packed_raster_info_offset:ci4_raster_data_offset]
ci4_raster_data = player_sprite_raster_data[ci4_raster_data_offset:]

# Create raster info intervals (readSpriteSections)
raster_sections: List[SpriteListEntry] = []
for i in range(0, len(index_ranges) - 4, 4):
    start = int.from_bytes(index_ranges[i:i+4], "big")
    end = int.from_bytes(index_ranges[i+4:i+8], "big")
    raster_sections.append(SpriteListEntry(start, end - start))

raster_table_entries = parse_raster_table_entries(packed_raster_info_data)

with open("assets/us/19E0970.bin", "rb") as f:
    yay0_sprite_data_chunked: bytes = f.read()

yay0_splits = []
for i in range(14):
    yay0_splits.append(int.from_bytes(yay0_sprite_data_chunked[i*4:i*4+4], "big"))

yay0_sprite_data = []
for i in range(0, len(yay0_splits) - 1):
    yay0_sprite_data.append(yay0_sprite_data_chunked[yay0_splits[i]:yay0_splits[i+1]])

sprites: List[PlayerSprite] = []
for i, yay0_piece in enumerate(yay0_sprite_data):
    sprite_data = Yay0Decompressor.decompress(yay0_piece, "big")
    sprite = PlayerSprite.from_bytes(sprite_data, raster_sections[i], ci4_raster_data)
    sprites.append(sprite)


extract_sprite_data()

write_shared_sprites()
write_palettes()
