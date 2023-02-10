#! /usr/bin/python3

import os
from pathlib import Path
import sys

script_dir = Path(os.path.dirname(os.path.realpath(__file__)))
root_dir = script_dir / "../../.."

if __name__ == "__main__":
    version = sys.argv[1]

    syms_to_max = [
        "entity_default_VRAM_END",
        "entity_jan_iwa_VRAM_END",
        "entity_sbk_omo_VRAM_END",
    ]

    with open(root_dir / "ver" / version / "build/papermario.map") as f:
        lines = f.readlines()

    addrs = []
    for line in lines:
        for sym in syms_to_max:
            if f"{sym} = ." in line:
                addrs.append(int(line.strip().split()[0], 16))
                syms_to_max.remove(sym)
                if not syms_to_max:
                    break

    if syms_to_max:
        print(f"Error: {syms_to_max} not found in map file")
        sys.exit(1)

    print(f"0x{max(addrs):X}")
