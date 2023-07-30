#!/usr/bin/env python3

from sys import argv, path
from pathlib import Path

path.append(str(Path(__file__).parent.parent))

from sprite.npc_sprite import from_dir as npc_from_dir

if __name__ == "__main__":
    if len(argv) < 4:
        print("usage: header.py [OUT] [NAME] [ID]")
        exit(1)

    _, outfile, sprite_name, s_in, asset_stack_raw = argv

    asset_stack = tuple(Path(d) for d in asset_stack_raw.split(","))

    with open(outfile, "w") as f:
        # get sprite index
        s = int(s_in)
        assert s >= 1

        sprite = npc_from_dir(sprite_name, asset_stack, load_images=False)

        f.write(f"#ifndef _NPC_SPRITE_{sprite_name.upper()}_H_\n")
        f.write(f"#define _NPC_SPRITE_{sprite_name.upper()}_H_\n")
        f.write("\n")
        f.write('#include "types.h"\n')
        f.write("\n")

        # sprite definition
        f.write(f"#define SPR_{sprite_name} 0x{s:02X}\n")
        f.write("\n")

        # definitions for images
        for i, image_name in enumerate(sprite.image_names):
            f.write(f"#define SPR_IMG_{sprite_name}_{image_name} 0x{i:X}\n")
        f.write("\n")

        # definitions for palettes
        for p, palette_name in enumerate(sprite.palette_names):
            if palette_name == "Default":
                f.write(f"#define SPR_PAL_{sprite_name} 0x{p:X}\n")
            else:
                f.write(f"#define SPR_PAL_{sprite_name}_{palette_name} 0x{p:X}\n")
        f.write("\n")

        # definitions for animations
        for p, palette_name in enumerate(sprite.palette_names):
            for a, name in enumerate(sprite.animation_names):
                if palette_name == "Default":
                    f.write(f"#define ANIM_{sprite_name}_{name} 0x{s:02X}{p:02X}{a:02X}\n")
                else:
                    f.write(f"#define ANIM_{sprite_name}_{palette_name}_{name} 0x{s:02X}{p:02X}{a:02X}\n")
            f.write("\n")

        f.write("#endif\n")
