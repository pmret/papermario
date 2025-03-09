#!/usr/bin/env python3

import os
import re
import glob


def process_file(file_path):
    with open(file_path, "r") as file:
        content = file.read()

    # Previous version mismatched loop iteration count and jump position, creating spurious labels in the process.
    # Switch them back and use pos attribute to force fixed jump positions; leave the extra labels alone.
    content = re.sub(
        r'<Loop count="(\d+)" dest="Pos_(\d+)"/>', lambda m: f'<Loop count="{m.group(2)}" pos="{m.group(1)}"/>', content
    )

    # SetParent used decimal instead of hex for its indices, conflicting with the policy of SetRaster and SetPalette
    content = re.sub(
        r'<SetParent index="(\d+)"/>', lambda m: f'<SetParent index="{hex(int(m.group(1)))[2:].upper()}"/>', content
    )

    with open(file_path, "w") as file:
        file.write(content)
    print(f"Updated: {file_path}")


def find_and_process_files():
    script_dir = os.path.dirname(os.path.realpath(__file__))
    root_dir = os.path.join(script_dir, "..")

    base_dirs = [
        os.path.join(root_dir, "assets", "*", "sprite", "npc"),
        os.path.join(root_dir, "assets", "*", "sprite", "player"),
    ]

    for base_dir in base_dirs:
        for root_dir in glob.glob(base_dir):
            for root, _, files in os.walk(root_dir):
                for file in files:
                    if file.endswith(".xml"):
                        file_path = os.path.join(root, file)
                        process_file(file_path)


if __name__ == "__main__":
    find_and_process_files()
    print("Done. :)")
