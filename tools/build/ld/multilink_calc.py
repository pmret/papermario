#!/usr/bin/env python3

import os
from pathlib import Path
import sys
from typing import Dict, List

script_dir = Path(os.path.dirname(os.path.realpath(__file__)))
root_dir = script_dir / "../../.."

HARDCODED_ADDR = 0x80000000

if __name__ == "__main__":
    if len(sys.argv) != 3:
        print(f"Usage: {sys.argv[0]} <version> <mode>")
        print("mode: hardcode, calc")
        sys.exit(1)

    version = sys.argv[1]
    mode = sys.argv[2]

    syms_to_max = {
        "entity_data_vram_end": [
            "entity_default_VRAM_END",
            "entity_jan_iwa_VRAM_END",
            "entity_sbk_omo_VRAM_END",
        ],
        "world_action_vram_end": [
            "world_action_idle_VRAM_END",
            "world_action_walk_VRAM_END",
            "world_action_jump_VRAM_END",
            "world_action_step_up_VRAM_END",
            "world_action_land_VRAM_END",
            "world_action_hammer_VRAM_END",
            "world_action_spin_VRAM_END",
            "world_action_tornado_jump_VRAM_END",
            "world_action_spin_jump_VRAM_END",
            "world_action_slide_VRAM_END",
            "world_action_hit_fire_VRAM_END",
            "world_action_hit_lava_VRAM_END",
            "world_action_knockback_VRAM_END",
            "world_action_misc_VRAM_END",
            "world_action_use_munchlesia_VRAM_END",
            "world_action_use_spinning_flower_VRAM_END",
            "world_action_use_tweester_VRAM_END",
            "world_action_sneaky_parasol_VRAM_END",
        ],
    }

    addrs: Dict[str, List[int]] = {}

    if mode == "hardcode":
        out = ""
        for sym in syms_to_max:
            addrs[sym] = [HARDCODED_ADDR]
    elif mode == "calc":
        with open(root_dir / "ver" / version / "build/papermario.map") as f:
            lines = f.readlines()

        finished = False
        syms_to_go = set(syms_to_max.keys())
        for line in lines:
            for sym in syms_to_max:
                for max_sym in syms_to_max[sym]:
                    if f"{max_sym} = ." in line:
                        if sym not in addrs:
                            addrs[sym] = []
                        addrs[sym].append(int(line.strip().split()[0], 16))
                        syms_to_max[sym].remove(max_sym)
                        if len(syms_to_max[sym]) == 0:
                            syms_to_go.remove(sym)
                        if not syms_to_go:
                            finished = True
            if finished:
                break

        if syms_to_go:
            print(f"Error: {syms_to_max} not found in map file")
            sys.exit(1)

    out_addrs = {sym: max(addrs[sym]) for sym in addrs}

    out_addrs["entity_data_vram_end"] = (
        out_addrs["entity_data_vram_end"] + out_addrs["world_action_vram_end"] - HARDCODED_ADDR
    )

    out = ""
    for sym in out_addrs:
        out += f" --defsym {sym}=0x{out_addrs[sym]:X}"
    print(out)
