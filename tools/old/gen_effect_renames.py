#!/usr/bin/env python3

import argparse
import os


def auto_int(x):
    return int(x, 0)


script_dir = os.path.dirname(os.path.realpath(__file__))

parser = argparse.ArgumentParser(description="Generate rename file for effects")

parser.add_argument(
    "id",
    help="Effect num to rename",
    type=auto_int,
)

parser.add_argument(
    "to",
    help="Name (in snake case) to change the effect to",
)


def main(args):
    id = args.id
    to = args.to

    to_write = []

    hex_str = f"{id:02x}".upper()

    struct_name = "".join(word.title() for word in to.split("_"))
    to_write.append(f"Effect{id} {struct_name}FXData")
    to_write.append(f"playFX_{hex_str} fx_{to}")
    to_write.append(f"FX_ENTRY_NUMBERED({id}, FX_ENTRY({to},")
    to_write.append(f"effect_{id} {to}")
    to_write.append(f"fx_{id}_main {to}_main")
    to_write.append(f"fx_{id}_init {to}_init")
    to_write.append(f"fx_{id}_update {to}_update")
    to_write.append(f"fx_{id}_render {to}_render")
    to_write.append(f"fx_{id}_appendGfx {to}_appendGfx")
    to_write.append(f"EFFECT_ID_{hex_str} EFFECT_{to.upper()}")

    with open(os.path.join(script_dir, "to_rename.txt"), "a") as f:
        for line in to_write:
            f.write(f"{line}\n")


if __name__ == "__main__":
    args = parser.parse_args()
    main(args)
