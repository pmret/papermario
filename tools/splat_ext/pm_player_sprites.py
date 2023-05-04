#!/usr/bin/python3

import os
import struct
import sys
import xml.etree.ElementTree as ET
from dataclasses import dataclass, field
from math import ceil
from pathlib import Path
from typing import Dict, List, Optional, Set

from n64img.image import CI4

import yaml as yaml_loader
from sprite_common import AnimComponent, read_offset_list

TOOLS_DIR = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.append(str(Path(TOOLS_DIR)))
from splat.util.n64.Yay0decompress import Yay0Decompressor

PAL_TO_RASTER: Dict[str, int] = {
    "8bit": 0x57C90,
    "BareCake": 0x63F10,
    "BerryCake": 0x65D10,
    "Bowl": 0x63910,
    "Bowl_Dark": 0x63910,
    "Bowl_Poisoned": 0x63910,
    "Bowl_Shocked": 0x63910,
    "Burnt": 0x38390,
    "Burnt_Crouch": 0x0C380,
    "Butter": 0x63010,
    "CakeBatter": 0x63D90,
    "CakeBowl": 0x63910,
    "CakeMixed": 0x63A90,
    "CakePan": 0x63C10,
    "Cleanser": 0x63190,
    "CompleteCake": 0x63790,
    "Cream": 0x62D10,
    "Dark": 0x00B80,
    "Default": 0x00B80,
    "Egg": 0x63610,
    "Flour": 0x63490,
    "Frozen_Dark": 0x00B80,
    "Glove": 0x89610,
    "Glove_Dark": 0x89610,
    "Glove_Poisoned": 0x89610,
    "Glove_Shocked": 0x89610,
    "Golden": 0x00B80,
    "Golden_19": 0x00B80,
    "Golden_Dark": 0x00B80,
    "Golden_Poisoned": 0x00B80,
    "Golden_Shocked": 0x00B80,
    "Hammer1": 0x2C950,
    "Hammer1_Dark": 0x2C950,
    "Hammer1_Poisoned": 0x2C950,
    "Hammer1_Shocked": 0x2C950,
    "Hammer2": 0x2DE50,
    "Hammer2_Dark": 0x2DE50,
    "Hammer2_Poisoned": 0x2DE50,
    "Hammer2_Shocked": 0x2DE50,
    "Hammer3": 0x2F350,
    "Hammer3_Dark": 0x2F350,
    "Hammer3_Poisoned": 0x2F350,
    "Hammer3_Shocked": 0x2F350,
    "IcingCake": 0x65B90,
    "Milk": 0x63310,
    "Parasol": 0x8D410,
    "Parasol_Dark": 0x8D410,
    "Parasol_Poisoned": 0x8D410,
    "Parasol_Shocked": 0x8D410,
    "Peach": 0x58B10,
    "Peach_Dark": 0x58B10,
    "Peach_Poisoned": 0x58B10,
    "Peach_Shocked": 0x58B10,
    "Poisoned": 0x00B80,
    "Red": 0x00B80,
    "Red_Dark": 0x00B80,
    "Red_Poisoned": 0x00B80,
    "Red_Shocked": 0x00B80,
    "Salt": 0x63490,
    "Shocked": 0x00B80,
    "Strawberry": 0x62E90,
    "Sugar": 0x63490,
    "Water": 0x63310,
}


SPECIAL_RASTER = 0x1F880


@dataclass
class RasterTableEntry:
    offset: int
    size: int

    count: int = 0
    height: int = 0
    width: int = 0

    raster_bytes: bytes = field(default_factory=bytes)
    palette: Optional[bytes] = None

    def write_png(
        self, raster_buffer: bytes, path: Path, palette: Optional[bytes] = None
    ):
        if self.height == 0 or self.width == 0:
            raise ValueError("Raster size has not been set")

        if palette is None:
            palette = self.palette

        if palette is None:
            raise ValueError("Palette has not been set")

        if self.raster_bytes is not None:
            self.raster_bytes = raster_buffer[
                self.offset : self.offset + (self.width * self.height // 2)
            ]

        img = CI4(self.raster_bytes, self.width, self.height)
        img.set_palette(palette)
        img.write(path)


@dataclass
class PlayerSpriteRasterSet:
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
    palette_idx: int
    is_special: bool
    raster: bytearray = field(default_factory=bytearray)

    @staticmethod
    def from_bytes(
        metadata: bytes,
        raster_set: PlayerSpriteRasterSet,
        ci4_raster_bytes: bytes,
        palettes: List[bytes],
        img_idx: int,
    ) -> "PlayerRaster":
        offset, width, height, default_palette = struct.unpack(">iBBB", metadata)

        assert offset == raster_set.raster_positions[img_idx]

        # Get raster bytes into ci4 format
        raster = bytearray()
        for i in range(width * height // 2):
            raster.append(ci4_raster_bytes[offset + i] >> 4)
            raster.append(ci4_raster_bytes[offset + i] & 0xF)

        is_special = raster_set.raster_offsets[img_idx] == SPECIAL_RASTER

        if not is_special:
            rte = raster_set.raster_table_entries[img_idx]
            rte.width = width
            rte.height = height
            rte.palette = palettes[default_palette]

        return PlayerRaster(offset, width, height, default_palette, is_special, raster)

    def write(self, path: Path, palette: bytes) -> None:
        img = CI4(self.raster, self.width, self.height)
        img.set_palette(palette)
        img.write(path)


@dataclass
class PlayerSprite:
    max_components: int
    num_variations: int

    animations: List[List[AnimComponent]]
    palettes: List[bytes]
    palette_indexes: List[int]
    rasters: List[PlayerRaster]

    @staticmethod
    def from_bytes(
        data: bytes, raster_set: PlayerSpriteRasterSet, ci4_raster_data: bytes
    ) -> "PlayerSprite":
        raster_offsets = read_offset_list(
            data[int.from_bytes(data[0:4], byteorder="big") :]
        )
        palette_offsets = read_offset_list(
            data[int.from_bytes(data[4:8], byteorder="big") :]
        )
        max_components = int.from_bytes(data[8:0xC], "big")
        num_variations = int.from_bytes(data[0xC:0x10], "big")
        animation_offsets = read_offset_list(data[0x10:])

        palettes: List[bytes] = []
        palette_indexes: List[int] = []
        rasters: List[PlayerRaster] = []
        animations: List[List[AnimComponent]] = []

        # Read palettes
        for i, pal_offset in enumerate(palette_offsets):
            pal = data[pal_offset : pal_offset + 0x20]
            palettes.append(pal)
            palette_indexes.append(i)

        # Read rasters
        for i, metadata_offset in enumerate(raster_offsets):
            raster = PlayerRaster.from_bytes(
                data[metadata_offset : metadata_offset + 7],
                raster_set,
                ci4_raster_data,
                palettes,
                i,
            )
            rasters.append(raster)

        # Read animations
        for anim_offset in animation_offsets:
            anim: List[AnimComponent] = []

            for comp_offset in read_offset_list(data[anim_offset:]):
                anim.append(AnimComponent.from_bytes(data[comp_offset:], data))
            animations.append(anim)

        return PlayerSprite(
            max_components,
            num_variations,
            animations,
            palettes,
            palette_indexes,
            rasters,
        )


def parse_raster_table_entries(data: bytes) -> Dict[int, RasterTableEntry]:
    ret: Dict[int, RasterTableEntry] = {}
    current_section_pos = 0
    current_section = 0

    for i in range(0, len(data) - 4, 4):
        packed = int.from_bytes(data[i : i + 4])

        size = (packed >> 20) << 4
        offset = packed & 0xFFFFF
        rte = RasterTableEntry(offset, size)

        if offset in ret:
            assert ret[offset].size == size
        else:
            ret[offset] = rte

        if current_section > len(raster_sets) - 1:
            continue  # TODO skip the last one, but why? how do we rebuild this if we're just ignoring it?

        raster_sets[current_section].add_table_entry(rte)

        current_section_pos += 1

        if current_section_pos == raster_sets[current_section].count:
            current_section += 1
            current_section_pos = 0
    return ret


def write_player_xmls() -> None:
    sprite_idx = 0
    path = Path(f"assets/us/sprite/player/")
    path.mkdir(parents=True, exist_ok=True)

    num_sprite_cfgs = len(list(sprite_cfg.keys()))

    for cfg_idx in range(num_sprite_cfgs):
        cur_sprite_name = sprite_names[sprite_idx]

        cur_sprite: PlayerSprite = sprites[sprite_idx]
        cur_sprite_back: Optional[PlayerSprite] = None
        has_back = sprite_cfg[cur_sprite_name].get("has_back", False)

        if has_back:
            if cfg_idx == num_sprite_cfgs - 1:
                print("ERROR: Last sprite has back, but no sprite to pair with")
                sys.exit(1)
            cur_sprite_back = sprites[sprite_idx + 1]

        SpriteSheet = ET.Element(
            "SpriteSheet",
            {
                "maxComponents": str(cur_sprite.max_components),
                "paletteGroups": str(cur_sprite.num_variations),
            },
        )

        PaletteList = ET.SubElement(SpriteSheet, "PaletteList")
        RasterList = ET.SubElement(SpriteSheet, "RasterList")
        AnimationList = ET.SubElement(SpriteSheet, "AnimationList")

        for i, raster in enumerate(cur_sprite.rasters):
            name_offset = raster_sets[sprite_idx].raster_offsets[i]

            raster_attributes = {
                "id": f"{i:X}",
                "palette": f"{raster.palette_idx:X}",
                "src": f"{name_offset:05X}.png",
            }

            if has_back:
                assert cur_sprite_back is not None
                back_sprite = cur_sprite_back.rasters[i]

                if back_sprite.is_special:
                    raster_attributes[
                        "special"
                    ] = f"{back_sprite.width & 0xFF:X},{back_sprite.height & 0xFF:X}"
                else:
                    back_name_offset = raster_sets[sprite_idx + 1].raster_offsets[i]
                    raster_attributes["back"] = f"{back_name_offset:05X}.png"

            ET.SubElement(RasterList, "Raster", raster_attributes)

        palette_names = sprite_cfg[cur_sprite_name].get("palettes")
        for i, name in enumerate(palette_names):
            ET.SubElement(
                PaletteList,
                "Palette",
                {
                    "id": f"{i:X}",
                    "src": name + ".png",
                },
            )

        animation_names = sprite_cfg[cur_sprite_name].get("animations")
        for i, components in enumerate(cur_sprite.animations):
            Animation = ET.SubElement(
                AnimationList,
                "Animation",
                {
                    "name": animation_names[i] if animation_names else f"Anim{i:02X}",
                },
            )

            for j, comp in enumerate(components):
                Component = ET.SubElement(
                    Animation,
                    "Component",
                    {
                        "name": f"Comp_{j:X}",
                        "xyz": ",".join(map(str, [comp.x, comp.y, comp.z])),
                    },
                )

                for anim in comp.animations:
                    ET.SubElement(
                        Component, anim.__class__.__name__, anim.get_attributes()
                    )

        xml = ET.ElementTree(SpriteSheet)

        # pretty print (Python 3.9+)
        if hasattr(ET, "indent"):
            ET.indent(xml, "    ")

        xml.write(str(path / f"{cur_sprite_name}.xml"), encoding="unicode")

        if has_back:
            sprite_idx += 2
        else:
            sprite_idx += 1


def write_player_rasters() -> None:
    base_path = Path(f"assets/us/sprite/player/rasters")
    base_path.mkdir(parents=True, exist_ok=True)

    for offset, rte in raster_table_entries.items():
        if offset == SPECIAL_RASTER:
            continue

        if offset == 0x9CD50:
            continue  # TODO handle this one
        rte.write_png(player_sprite_raster_data, base_path / f"{offset:05X}.png")


def write_player_palettes() -> None:
    dumped_palettes: Set[str] = set()

    for i, sprite in enumerate(sprites):
        sprite_name = sprite_names[i]
        path = Path(f"assets/us/sprite/player/palettes/")
        path.mkdir(parents=True, exist_ok=True)

        for i, palette in enumerate(sprite.palettes):
            pal_name = sprite_cfg[sprite_name]["palettes"][sprite.palette_indexes[i]]
            if pal_name not in dumped_palettes:
                offset = PAL_TO_RASTER[pal_name]
                if pal_name not in PAL_TO_RASTER:
                    print(
                        f"WARNING: Palette {pal_name} has no specified raster, not dumping!"
                    )
                raster_table_entries[offset].write_png(
                    player_sprite_raster_data, path / (pal_name + ".png"), palette
                )


def write_build_info() -> None:
    with open("assets/us/sprite/player/build_info.txt", "w") as f:
        f.write(build_date)


with (Path(__file__).parent / f"player.yaml").open("r") as f:
    sprite_cfg = yaml_loader.load(f.read(), Loader=yaml_loader.SafeLoader)

sprite_names = []
for sprite_name in sprite_cfg.keys():
    sprite_names.append(sprite_name)
    if sprite_cfg[sprite_name].get("has_back", False):
        sprite_names.append(sprite_name)

with open("assets/us/1943000.bin", "rb") as f:
    sprites_bin: bytes = f.read()

build_date = sprites_bin[0:0x10].decode("ascii").rstrip("\0")
player_raster_offset = int.from_bytes(sprites_bin[0x10:0x14], "big") + 0x10
player_yay0_offset = int.from_bytes(sprites_bin[0x14:0x18], "big") + 0x10
npc_yay0_offset = int.from_bytes(sprites_bin[0x18:0x1C], "big") + 0x10
sprite_end_offset = int.from_bytes(sprites_bin[0x1C:0x20], "big") + 0x10

player_sprite_raster_data: bytes = sprites_bin[player_raster_offset:player_yay0_offset]

# Header parsing
index_ranges_offset = int.from_bytes(player_sprite_raster_data[0:0x4], "big")
packed_raster_info_offset = int.from_bytes(player_sprite_raster_data[0x4:0x8], "big")
ci4_raster_data_offset = int.from_bytes(player_sprite_raster_data[0x8:0xC], "big")

index_ranges = player_sprite_raster_data[index_ranges_offset:packed_raster_info_offset]
packed_raster_info_data = player_sprite_raster_data[
    packed_raster_info_offset:ci4_raster_data_offset
]
ci4_raster_data = player_sprite_raster_data[ci4_raster_data_offset:]

# Parse raster sets (readSpriteSections)
raster_sets: List[PlayerSpriteRasterSet] = []
for i in range(0, len(index_ranges) - 4, 4):
    start = int.from_bytes(index_ranges[i : i + 4], "big")
    end = int.from_bytes(index_ranges[i + 4 : i + 8], "big")
    raster_sets.append(PlayerSpriteRasterSet(start, end - start))

raster_table_entries = parse_raster_table_entries(packed_raster_info_data)

player_yay0_sprite_data_chunked: bytes = sprites_bin[player_yay0_offset:npc_yay0_offset]

yay0_splits = []
for i in range(14):
    yay0_splits.append(
        int.from_bytes(player_yay0_sprite_data_chunked[i * 4 : i * 4 + 4], "big")
    )

yay0_sprite_data = []
for i in range(0, len(yay0_splits) - 1):
    yay0_sprite_data.append(
        player_yay0_sprite_data_chunked[yay0_splits[i] : yay0_splits[i + 1]]
    )

sprites: List[PlayerSprite] = []
for i, yay0_piece in enumerate(yay0_sprite_data):
    sprite_data = Yay0Decompressor.decompress(yay0_piece, "big")
    sprite = PlayerSprite.from_bytes(sprite_data, raster_sets[i], ci4_raster_data)
    sprites.append(sprite)


write_build_info()
write_player_xmls()
write_player_rasters()
write_player_palettes()


##########
# Building
##########

# Build info
with open("assets/us/sprite/player/build_info.txt", "r") as f:
    build_info = f.read()

# Encode build_info to bytes and pad to 0x10
build_info_bytes = build_info.encode("ascii")
build_info_bytes += b"\0" * (0x10 - len(build_info_bytes))
dog = 5
