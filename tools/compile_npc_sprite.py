#! /usr/bin/python3

from sys import argv, path
from pathlib import Path
import os
path.append(os.path.join(os.path.dirname(__file__), "splat"))
from splat_ext.PaperMarioNpcSprites import Sprite
from img.build import pack_color, iter_in_groups

if __name__ == "__main__":
    if len(argv) != 3:
        print("usage: compile_npc_sprite.py [OUTBIN] [DIR]")
        exit(1)

    _, outfile, sprite_dir = argv

    try:
        sprite = Sprite.from_dir(Path(sprite_dir))
    except AssertionError as e:
        print("error:", e)
        exit(1)

    with open(outfile, "wb") as f:
        f.seek(0x10) # leave space for header

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
        palette_offsets = []
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
