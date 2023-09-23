#!/usr/bin/env python3

from math import floor
from sys import argv, path
from pathlib import Path
from typing import List, Tuple
import xml.etree.ElementTree as ET
import png  # type: ignore

path.append(str(Path(__file__).parent.parent))
path.append(str(Path(__file__).parent.parent.parent))
path.append(str(Path(__file__).parent.parent.parent / "splat"))
path.append(str(Path(__file__).parent.parent.parent / "splat_ext"))

from common import get_asset_path, iter_in_groups
from splat_ext.pm_sprites import (
    MAX_COMPONENTS_XML,
    PALETTE_GROUPS_XML,
    NpcRaster,
    NpcSprite,
)

from splat_ext.sprite_common import AnimComponent


def pack_color(r, g, b, a):
    r = floor(31 * (r / 255))
    g = floor(31 * (g / 255))
    b = floor(31 * (b / 255))

    s = round(a / 0xFF)
    s |= (r & 0x1F) << 11
    s |= (g & 0x1F) << 6
    s |= (b & 0x1F) << 1

    return s


def from_dir(
    sprite_name: str,
    asset_stack: Tuple[Path, ...],
    load_images: bool = True,
) -> NpcSprite:
    sprite_dir = Path(f"sprite/npc/{sprite_name}")

    sprite_sheet_xml_path = get_asset_path(sprite_dir / "SpriteSheet.xml", asset_stack)
    xml = ET.parse(sprite_sheet_xml_path)
    SpriteSheet = xml.getroot()

    true_max_components = 0

    if "a" in SpriteSheet.attrib:
        max_components = int(SpriteSheet.attrib["a"])
    else:
        max_components = int(SpriteSheet.attrib[MAX_COMPONENTS_XML])

    if "b" in SpriteSheet.attrib:
        num_variations = int(SpriteSheet.attrib["b"])
    else:
        num_variations = int(SpriteSheet.attrib[PALETTE_GROUPS_XML])

    variation_names = SpriteSheet.get("variations", default="").split(",")

    palettes = []
    palette_names: List[str] = []
    for Palette in SpriteSheet.findall("./PaletteList/Palette"):
        if asset_stack is not None and load_images:
            img_name = Palette.attrib["src"]
            img_path = str(get_asset_path(sprite_dir / "palettes" / img_name, asset_stack))
            img = png.Reader(img_path)
            img.preamble(True)
            palette = img.palette(alpha="force")

            palette = palette[0:16]
            assert len(palette) == 16

            palettes.append(palette)

        palette_names.append(Palette.get("name", Palette.attrib["src"].split(".png")[0]))

    images = []
    image_names: List[str] = []
    for Raster in SpriteSheet.findall("./RasterList/Raster"):
        if asset_stack is not None and load_images:
            img_name = Raster.attrib["src"]
            img_path = str(get_asset_path(sprite_dir / "rasters" / img_name, asset_stack))
            width, height, raster, info = png.Reader(img_path).read_flat()

            palette_index = int(Raster.attrib["palette"], base=16)
            image = NpcRaster(width, height, palette_index, raster)

            assert (image.width % 8) == 0, f"{img_path} width is not a multiple of 8"
            assert (image.height % 8) == 0, f"{img_path} height is not a multiple of 8"

            images.append(image)

        image_names.append(Raster.attrib["src"].split(".png")[0])

    animations = []
    animation_names: List[str] = []
    for Animation in SpriteSheet.findall("./AnimationList/Animation"):
        comps: List[AnimComponent] = []
        for comp_xml in Animation:
            comp: AnimComponent = AnimComponent.from_xml(comp_xml)
            comps.append(comp)
        animation_names.append(Animation.attrib["name"])
        animations.append(comps)

        if len(comps) > true_max_components:
            true_max_components = len(comps)

    max_components = true_max_components
    # assert self.max_components == true_max_components, f"{true_max_components} component(s) used, but SpriteSheet.a = {self.max_components}"

    return NpcSprite(
        max_components,
        num_variations,
        animations,
        palettes,
        images,
        image_names,
        palette_names,
        animation_names,
        variation_names,
    )


if __name__ == "__main__":
    if len(argv) != 4:
        print("usage: sprite.py [OUTBIN] [SPRITE_NAME] [ASSET_STACK]")
        exit(1)

    _, outfile, sprite_name, asset_stack_raw = argv

    asset_stack = tuple(Path(d) for d in asset_stack_raw.split(","))

    try:
        sprite = from_dir(sprite_name, asset_stack)
    except AssertionError as e:
        print("error:", e)
        exit(1)

    with open(outfile, "wb") as f:
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
                    print("error: translucent pixels not allowed in palette {sprite.palette_names[i]}")
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
