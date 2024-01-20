#! /usr/bin/env python3

import struct
import sys
import re
import xml.etree.ElementTree as ET
from dataclasses import dataclass, field
from pathlib import Path
from typing import Any, Dict, List, Optional, Set, Tuple
import crunch64

import png  # type: ignore
import yaml as yaml_loader
from n64img.image import CI4
from splat.segtypes.n64.segment import N64Segment
from splat.util import options
from splat.util.color import unpack_color

sys.path.insert(0, str(Path(__file__).parent))
from sprite_common import AnimComponent, iter_in_groups, read_offset_list

sys.path.insert(0, str(Path(__file__).parent.parent))
from common import get_asset_path

# TODO move into yaml
PLAYER_PAL_TO_RASTER: Dict[str, int] = {
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


PLAYER_SPRITE_MEDADATA_XML_FILENAME = "player.xml"
NPC_SPRITE_MEDADATA_XML_FILENAME = "npc.xml"

MAX_COMPONENTS_XML = "maxComponents"
PALETTE_GROUPS_XML = "paletteGroups"
HAS_BACK_XML = "hasBack"
PALETTE_XML = "palette"
BACK_PALETTE_XML = "backPalette"

SPECIAL_RASTER = 0x1F880

LIST_END_BYTES = b"\xFF\xFF\xFF\xFF"


def indent(elem, level=0):
    i = "\n" + level * "    "
    if len(elem):
        if not elem.text or not elem.text.strip():
            elem.text = i + "    "
        if not elem.tail or not elem.tail.strip():
            elem.tail = i
        for elem in elem:
            indent(elem, level + 1)
        if not elem.tail or not elem.tail.strip():
            elem.tail = i
    else:
        if level and (not elem.tail or not elem.tail.strip()):
            elem.tail = i


def pretty_print_xml(tree: ET.ElementTree, path: Path):
    root = tree.getroot()
    indent(root)
    xml_str = ET.tostring(root, encoding="unicode")
    xml_str = re.sub(" />", "/>", xml_str)
    with open(path, "w") as f:
        f.write(xml_str)


@dataclass
class RasterTableEntry:
    offset: int
    size: int

    height: int = 0
    width: int = 0

    raster_bytes: bytes = field(default_factory=bytes)
    palette: Optional[bytes] = None

    def write_png(self, raster_buffer: bytes, path: Path, palette: Optional[bytes] = None):
        if self.height == 0 or self.width == 0:
            raise ValueError("Raster size has not been set")

        if palette is None:
            palette = self.palette

        if palette is None:
            raise ValueError("Palette has not been set")

        if self.raster_bytes is not None:
            self.raster_bytes = raster_buffer[self.offset : self.offset + (self.width * self.height // 2)]

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

    @staticmethod
    def from_bytes(
        metadata: bytes,
        raster_set: PlayerSpriteRasterSet,
        palettes: List[bytes],
        img_idx: int,
    ) -> "PlayerRaster":
        offset, width, height, default_palette = struct.unpack(">iBBB", metadata)

        assert offset == raster_set.raster_positions[img_idx]

        is_special = raster_set.raster_offsets[img_idx] == SPECIAL_RASTER

        if not is_special:
            rte = raster_set.raster_table_entries[img_idx]
            rte.width = width
            rte.height = height
            rte.palette = palettes[default_palette]

        return PlayerRaster(offset, width, height, default_palette, is_special)


@dataclass
class PlayerSprite:
    max_components: int
    num_variations: int

    animations: List[List[AnimComponent]]
    palettes: List[bytes]
    palette_indexes: List[int]
    rasters: List[PlayerRaster]

    @staticmethod
    def from_bytes(data: bytes, raster_set: PlayerSpriteRasterSet) -> "PlayerSprite":
        raster_list_offset = int.from_bytes(data[0x0:0x4], byteorder="big")
        palette_list_offset = int.from_bytes(data[0x4:0x8], byteorder="big")
        max_components = int.from_bytes(data[0x8:0xC], "big")
        num_variations = int.from_bytes(data[0xC:0x10], "big")

        raster_offsets = read_offset_list(data[raster_list_offset:])
        palette_offsets = read_offset_list(data[palette_list_offset:])
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


def extract_raster_table_entries(data: bytes, raster_sets: List[PlayerSpriteRasterSet]) -> Dict[int, RasterTableEntry]:
    ret: Dict[int, RasterTableEntry] = {}
    current_section_pos = 0
    current_section = 0

    for i in range(0, len(data) - 4, 4):
        packed = int.from_bytes(data[i : i + 4], "big")

        size = (packed >> 20) << 4
        offset = packed & 0xFFFFF

        rte = RasterTableEntry(offset, size)

        if offset in ret:
            assert ret[offset].size == size
        else:
            ret[offset] = rte

        if current_section > len(raster_sets) - 1:
            continue  # skip the last one, because it's weird...?

        raster_sets[current_section].add_table_entry(rte)

        current_section_pos += 1

        if current_section_pos == raster_sets[current_section].count:
            current_section += 1
            current_section_pos = 0
    return ret


def extract_sprites(yay0_data: bytes, raster_sets: List[PlayerSpriteRasterSet]) -> List[PlayerSprite]:
    yay0_splits = []
    for i in range(14):
        yay0_splits.append(int.from_bytes(yay0_data[i * 4 : i * 4 + 4], "big"))

    yay0_sprite_data = []
    for i in range(0, len(yay0_splits) - 1):
        yay0_sprite_data.append(yay0_data[yay0_splits[i] : yay0_splits[i + 1]])

    ret: List[PlayerSprite] = []
    for i, yay0_piece in enumerate(yay0_sprite_data):
        sprite_data = crunch64.yay0.decompress(yay0_piece)

        sprite = PlayerSprite.from_bytes(sprite_data, raster_sets[i])
        ret.append(sprite)
    return ret


def write_player_metadata(
    out_path: Path,
    cfg: Any,
    raster_names: List[str],
    build_date: str,
) -> None:
    Names = ET.Element("Names")

    BuildDate = ET.SubElement(Names, "BuildDate")
    BuildDate.text = build_date

    Sprites = ET.SubElement(Names, "Sprites")
    for sprite_name in cfg:
        ET.SubElement(
            Sprites,
            "Sprite",
            name=sprite_name,
        )

    Rasters = ET.SubElement(Names, "Rasters")
    for raster_name in raster_names:
        ET.SubElement(
            Rasters,
            "Raster",
            name=raster_name,
        )

    xml = ET.ElementTree(Names)
    pretty_print_xml(xml, out_path / PLAYER_SPRITE_MEDADATA_XML_FILENAME)


def write_npc_metadata(
    out_path: Path,
    cfg: Any,
) -> None:
    Names = ET.Element("Names")

    Sprites = ET.SubElement(Names, "Sprites")
    for sprite_name in cfg:
        ET.SubElement(
            Sprites,
            "Sprite",
            name=sprite_name,
        )

    xml = ET.ElementTree(Names)
    pretty_print_xml(xml, out_path / NPC_SPRITE_MEDADATA_XML_FILENAME)


def write_player_xmls(
    out_path: Path,
    cfg: Any,
    sprites: List[PlayerSprite],
    sprite_names: List[str],
    raster_sets: List[PlayerSpriteRasterSet],
    raster_table_entry_dict: Dict[int, RasterTableEntry],
    raster_names: List[str],
) -> None:
    def get_sprite_name_from_offset(offset: int, offsets: List[int], names: List[str]) -> str:
        return names[offsets.index(offset)]

    sprite_idx = 0

    num_sprite_cfgs = len(list(cfg.keys()))

    sprite_offsets: list[int] = list(raster_table_entry_dict.keys())

    for cfg_idx in range(num_sprite_cfgs):
        cur_sprite_name = sprite_names[sprite_idx]

        cur_sprite: PlayerSprite = sprites[sprite_idx]
        cur_sprite_back: Optional[PlayerSprite] = None
        has_back = cfg[cur_sprite_name].get("has_back", False)

        if has_back:
            if cfg_idx == num_sprite_cfgs - 1:
                print("ERROR: Last sprite has back, but no sprite to pair with")
                sys.exit(1)
            cur_sprite_back = sprites[sprite_idx + 1]

        SpriteSheet = ET.Element(
            "SpriteSheet",
            {
                MAX_COMPONENTS_XML: str(cur_sprite.max_components),
                PALETTE_GROUPS_XML: str(cur_sprite.num_variations),
                HAS_BACK_XML: str(has_back).lower(),
            },
        )

        PaletteList = ET.SubElement(SpriteSheet, "PaletteList")
        RasterList = ET.SubElement(SpriteSheet, "RasterList")
        AnimationList = ET.SubElement(SpriteSheet, "AnimationList")

        for i, raster in enumerate(cur_sprite.rasters):
            name_offset = raster_sets[sprite_idx].raster_offsets[i]

            raster_attributes = {
                "id": f"{i:X}",
                "name": f"{i:02X}",
                PALETTE_XML: f"{raster.palette_idx:X}",
                "src": f"{get_sprite_name_from_offset(name_offset, sprite_offsets, raster_names)}.png",
            }

            if has_back:
                assert cur_sprite_back is not None
                back_raster = cur_sprite_back.rasters[i]

                if back_raster.is_special:
                    raster_attributes["special"] = f"{back_raster.width & 0xFF:X},{back_raster.height & 0xFF:X}"
                else:
                    back_name_offset = raster_sets[sprite_idx + 1].raster_offsets[i]
                    raster_attributes[
                        "back"
                    ] = f"{get_sprite_name_from_offset(back_name_offset, sprite_offsets, raster_names)}.png"
                if back_raster.palette_idx != raster.palette_idx:
                    raster_attributes[BACK_PALETTE_XML] = f"{back_raster.palette_idx:X}"

            ET.SubElement(RasterList, "Raster", raster_attributes)

        palette_names = cfg[cur_sprite_name].get("palettes")
        for i, pal in enumerate(palette_names):
            front_only = False

            if isinstance(pal, str):
                name = pal
            elif isinstance(pal, dict):
                name = str(pal["name"])
                front_only = pal.get("front_only", False)
            else:
                raise Exception("Invalid palette format for palette: " + pal)

            pal_attributes = {
                "id": f"{i:X}",
                "name": name,
                "src": name + ".png",
            }

            if front_only:
                pal_attributes["front_only"] = "True"

            ET.SubElement(PaletteList, "Palette", pal_attributes)

        animation_names = cfg[cur_sprite_name].get("animations")
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
                    ET.SubElement(Component, anim.__class__.__name__, anim.get_attributes())

        xml = ET.ElementTree(SpriteSheet)
        pretty_print_xml(xml, out_path / f"{cur_sprite_name}.xml")

        if has_back:
            sprite_idx += 2
        else:
            sprite_idx += 1


def write_player_rasters(
    out_path: Path,
    raster_table_entry_dict: Dict[int, RasterTableEntry],
    raster_data: bytes,
    raster_names: List[str],
) -> None:
    base_path = out_path / "rasters"
    base_path.mkdir(parents=True, exist_ok=True)

    for i, (offset, rte) in enumerate(raster_table_entry_dict.items()):
        if offset == SPECIAL_RASTER:
            with open(base_path / f"{raster_names[i]}.png", "wb") as f:
                f.write(b"\x00" * 0x10)
            continue

        # Last raster... weird for some reason
        if offset == 0x9CD50:
            with open(base_path / f"{raster_names[i]}.png", "wb") as f:
                f.write(b"\x00" * 0x10)
            continue

        rte.write_png(raster_data, base_path / f"{raster_names[i]}.png")


def write_player_palettes(
    out_path: Path,
    cfg: Any,
    sprites: List[PlayerSprite],
    sprite_names: List[str],
    raster_table_entry_dict: Dict[int, RasterTableEntry],
    raster_data: bytes,
) -> None:
    dumped_palettes: Set[str] = set()

    for i, sprite in enumerate(sprites):
        sprite_name = sprite_names[i]
        path = out_path / "palettes"
        path.mkdir(parents=True, exist_ok=True)

        for i, palette in enumerate(sprite.palettes):
            pal = cfg[sprite_name]["palettes"][sprite.palette_indexes[i]]
            if isinstance(pal, str):
                pal_name = pal
            elif isinstance(pal, dict):
                pal_name = str(pal["name"])
            else:
                raise Exception("Invalid palette format for palette: " + pal)

            if pal_name not in dumped_palettes:
                offset = PLAYER_PAL_TO_RASTER[pal_name]
                if pal_name not in PLAYER_PAL_TO_RASTER:
                    print(f"WARNING: Palette {pal_name} has no specified raster, not dumping!")
                raster_table_entry_dict[offset].write_png(raster_data, path / (pal_name + ".png"), palette)


###########
### NPC ###
###########


@dataclass
class NpcRaster:
    width: int
    height: int
    palette_index: int
    raster: bytearray

    @staticmethod
    def from_bytes(data, sprite_data) -> "NpcRaster":
        raster_offset = int.from_bytes(data[0:4], byteorder="big")
        width = data[4] & 0xFF
        height = data[5] & 0xFF
        palette_index = data[6]
        assert data[7] == 0xFF

        # CI4
        raster = bytearray()
        for i in range(width * height // 2):
            raster.append(sprite_data[raster_offset + i] >> 4)
            raster.append(sprite_data[raster_offset + i] & 0xF)

        return NpcRaster(width, height, palette_index, raster)

    def write(self, path, palette):
        w = png.Writer(self.width, self.height, palette=palette)

        with open(path, "wb") as f:
            w.write_array(f, self.raster)


@dataclass
class NpcSprite:
    max_components: int
    num_variations: int

    animations: List[List[AnimComponent]]
    palettes: List[List[Tuple[int, int, int, int]]]
    images: List[NpcRaster]

    image_names: List[str] = field(default_factory=list)
    palette_names: List[str] = field(default_factory=list)
    animation_names: List[str] = field(default_factory=list)
    variation_names: List[str] = field(default_factory=list)

    @staticmethod
    def from_bytes(data: bytearray):
        image_offsets = read_offset_list(data[int.from_bytes(data[0:4], byteorder="big") :])
        palette_offsets = read_offset_list(data[int.from_bytes(data[4:8], byteorder="big") :])
        max_components = int.from_bytes(data[8:0xC], byteorder="big")
        num_variations = int.from_bytes(data[0xC:0x10], byteorder="big")
        animation_offsets = read_offset_list(data[0x10:])

        palettes = []
        for offset in palette_offsets:
            # 16 colors
            color_data = data[offset : offset + 16 * 2]
            palettes.append([unpack_color(c) for c in iter_in_groups(color_data, 2)])

        images = []
        for offset in image_offsets:
            img = NpcRaster.from_bytes(data[offset:], data)
            images.append(img)

        animations = []
        for offset in animation_offsets:
            anim = []

            for comp_offset in read_offset_list(data[offset:]):
                comp = AnimComponent.from_bytes(data[comp_offset:], data)
                anim.append(comp)

            animations.append(anim)

        return NpcSprite(max_components, num_variations, animations, palettes, images)

    def write_to_dir(self, path):
        if len(self.variation_names) > 1:
            SpriteSheet = ET.Element(
                "SpriteSheet",
                {
                    MAX_COMPONENTS_XML: str(self.max_components),
                    PALETTE_GROUPS_XML: str(self.num_variations),
                    "variations": ",".join(self.variation_names),
                },
            )
        else:
            SpriteSheet = ET.Element(
                "SpriteSheet",
                {
                    MAX_COMPONENTS_XML: str(self.max_components),
                    PALETTE_GROUPS_XML: str(self.num_variations),
                },
            )

        PaletteList = ET.SubElement(SpriteSheet, "PaletteList")
        RasterList = ET.SubElement(SpriteSheet, "RasterList")
        AnimationList = ET.SubElement(SpriteSheet, "AnimationList")

        palette_to_raster = {}

        for i, image in enumerate(self.images):
            name = self.image_names[i] if self.image_names else f"Raster{i:02X}"

            (path / "rasters").mkdir(parents=True, exist_ok=True)
            image.write(path / "rasters" / (name + ".png"), self.palettes[image.palette_index])

            if image.palette_index not in palette_to_raster:
                palette_to_raster[image.palette_index] = []
            palette_to_raster[image.palette_index].append(image)

            ET.SubElement(
                RasterList,
                "Raster",
                {
                    "id": f"{i:X}",
                    "palette": f"{image.palette_index:X}",
                    "src": name + ".png",
                },
            )

        for i, palette in enumerate(self.palettes):
            name = self.palette_names[i] if (self.palette_names and i < len(self.palette_names)) else f"Pal{i:02X}"

            if i in palette_to_raster:
                img = palette_to_raster[i][0]
            else:
                img = self.images[0]

            (path / "palettes").mkdir(parents=True, exist_ok=True)
            img.write(path / "palettes" / (name + ".png"), palette)

            ET.SubElement(
                PaletteList,
                "Palette",
                {
                    "id": f"{i:X}",
                    "src": name + ".png",
                },
            )

        for i, components in enumerate(self.animations):
            Animation = ET.SubElement(
                AnimationList,
                "Animation",
                {
                    "name": self.animation_names[i] if self.animation_names else f"Anim{i:02X}",
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
                    ET.SubElement(Component, anim.__class__.__name__, anim.get_attributes())

        xml = ET.ElementTree(SpriteSheet)
        pretty_print_xml(xml, path / "SpriteSheet.xml")


class N64SegPm_sprites(N64Segment):
    DEFAULT_NPC_SPRITE_NAMES = [f"{i:02X}" for i in range(0xEA)]

    def __init__(self, rom_start, rom_end, type, name, vram_start, args, yaml) -> None:
        super().__init__(rom_start, rom_end, type, name, vram_start, args=args, yaml=yaml)

        with (Path(__file__).parent / f"npc_sprite_names.yaml").open("r") as f:
            self.npc_cfg = yaml_loader.load(f.read(), Loader=yaml_loader.SafeLoader)

        with (Path(__file__).parent / f"player_sprite_names.yaml").open("r") as f:
            self.player_cfg = yaml_loader.load(f.read(), Loader=yaml_loader.SafeLoader)

    def out_path(self):
        return options.opts.asset_path / "sprite" / "sprites"

    def split_player(self, build_date: str, player_raster_data: bytes, player_yay0_data: bytes) -> None:
        player_sprite_cfg = self.player_cfg["player_sprites"]
        player_raster_names: List[str] = self.player_cfg["player_rasters"]

        player_sprite_names = []
        for sprite_name in player_sprite_cfg.keys():
            player_sprite_names.append(sprite_name)
            if player_sprite_cfg[sprite_name].get("has_back", False):
                player_sprite_names.append(sprite_name)

        # Header parsing
        index_ranges_offset = int.from_bytes(player_raster_data[0:0x4], "big")
        raster_info_offset = int.from_bytes(player_raster_data[0x4:0x8], "big")
        ci4_raster_data_offset = int.from_bytes(player_raster_data[0x8:0xC], "big")

        index_ranges = player_raster_data[index_ranges_offset:raster_info_offset]
        raster_info = player_raster_data[raster_info_offset:ci4_raster_data_offset]
        # ci4_raster_data = player_raster_data[ci4_raster_data_offset:]

        # Parse raster sets (readSpriteSections)
        raster_sets: List[PlayerSpriteRasterSet] = []
        for i in range(0, len(index_ranges) - 4, 4):
            start = int.from_bytes(index_ranges[i : i + 4], "big")
            end = int.from_bytes(index_ranges[i + 4 : i + 8], "big")
            raster_sets.append(PlayerSpriteRasterSet(start, end - start))

        raster_table_entry_dict = extract_raster_table_entries(raster_info, raster_sets)

        player_sprites = extract_sprites(player_yay0_data, raster_sets)

        #########
        # Writing
        #########

        player_out_path = self.out_path().parent / "player"

        player_out_path.mkdir(parents=True, exist_ok=True)
        write_player_metadata(
            self.out_path().parent,
            player_sprite_cfg,
            player_raster_names,
            build_date,
        )
        write_player_xmls(
            player_out_path,
            player_sprite_cfg,
            player_sprites,
            player_sprite_names,
            raster_sets,
            raster_table_entry_dict,
            player_raster_names,
        )
        write_player_rasters(
            player_out_path,
            raster_table_entry_dict,
            player_raster_data,
            player_raster_names,
        )
        write_player_palettes(
            player_out_path,
            player_sprite_cfg,
            player_sprites,
            player_sprite_names,
            raster_table_entry_dict,
            player_raster_data,
        )

    def split_npc(self, data: bytes) -> None:
        out_dir = self.out_path().parent / "npc"

        write_npc_metadata(
            self.out_path().parent,
            self.npc_cfg,
        )

        for i, sprite_name in enumerate(self.npc_cfg):
            sprite_dir = out_dir / sprite_name
            sprite_dir.mkdir(parents=True, exist_ok=True)

            start = int.from_bytes(data[i * 4 : (i + 1) * 4], byteorder="big")
            end = int.from_bytes(data[(i + 1) * 4 : (i + 2) * 4], byteorder="big")

            sprite_data = crunch64.yay0.decompress(data[start:end])
            sprite = NpcSprite.from_bytes(sprite_data)

            sprite.image_names = self.npc_cfg[sprite_name].get("frames", [])
            sprite.palette_names = self.npc_cfg[sprite_name].get("palettes", [])
            sprite.animation_names = self.npc_cfg[sprite_name].get("animations", [])
            sprite.variation_names = self.npc_cfg[sprite_name].get("variations", [])

            sprite.write_to_dir(sprite_dir)

    def split(self, rom_bytes) -> None:
        sprite_in_bytes = rom_bytes[self.rom_start : self.rom_end]
        build_date = sprite_in_bytes[0:0x10].decode("ascii").rstrip("\0")
        player_raster_offset = int.from_bytes(sprite_in_bytes[0x10:0x14], "big") + 0x10
        player_yay0_offset = int.from_bytes(sprite_in_bytes[0x14:0x18], "big") + 0x10
        npc_yay0_offset = int.from_bytes(sprite_in_bytes[0x18:0x1C], "big") + 0x10
        sprite_end_offset = int.from_bytes(sprite_in_bytes[0x1C:0x20], "big") + 0x10

        player_raster_data: bytes = sprite_in_bytes[player_raster_offset:player_yay0_offset]
        player_yay0_data: bytes = sprite_in_bytes[player_yay0_offset:npc_yay0_offset]
        npc_yay0_data: bytes = sprite_in_bytes[npc_yay0_offset:sprite_end_offset]

        self.split_player(build_date, player_raster_data, player_yay0_data)
        self.split_npc(npc_yay0_data)

    def get_linker_entries(self):
        from splat.segtypes.linker_entry import LinkerEntry
        import splat.scripts.split as split

        src_paths = [options.opts.asset_path / "sprite"]

        # read npc.xml - we can't use self.npc_cfg because nonvanilla asset packs can change it
        # for each sprite, add to src_paths
        asset_stack = tuple(Path(p) for p in split.config["asset_stack"])
        orderings_tree = ET.parse(get_asset_path(Path("sprite") / NPC_SPRITE_MEDADATA_XML_FILENAME, asset_stack))
        for sprite_tag in orderings_tree.getroot()[0]:
            name = sprite_tag.attrib["name"]
            src_paths.append(options.opts.asset_path / "sprite" / "npc" / name)

        return [LinkerEntry(self, src_paths, self.out_path(), self.get_linker_section(), self.get_linker_section())]

    def cache(self):
        return (self.yaml, self.rom_end, self.player_cfg, self.npc_cfg)
