#!/usr/bin/env python3

import os
from pathlib import Path

script_dir = os.path.dirname(os.path.realpath(__file__))
root_dir = script_dir + "/../"
asm_dir = root_dir + "ver/current/asm/"
asm_effects_dir = asm_dir + "nonmatchings/effects/"
asm_data_dir = asm_dir + "data/effects/"

data_to_thing = {
    "337F10": "sparkles",
    "339F10": "shape_spell",
    "33BB70": "gather_energy_pink",
    "33D5D0": "drop_leaves",
    "33EFE0": "dust",
    "3407C0": "shattering_stones",
    "342120": "smoke_ring",
    "342FD0": "damage_stars",
    "343F30": "explosion",
    "345190": "lens_flare",
    "345B10": "got_item_outline",
    "34E710": "spiky_white_aura",
    "34F480": "smoke_impact",
    "352CB0": "purple_ring",
    "354F20": "stars_burst",
    "355D10": "stars_shimmer",
    "3564E0": "rising_bubble",
    "357380": "ring_blast",
    "359320": "shockwave",
    "35A580": "music_note",
    "35BFB0": "smoke_burst",
    "35C530": "sweat",
    "35E8A0": "windy_leaves",
    "35F0A0": "falling_leaves",
    "360A10": "stars_spread",
    "361640": "steam_burst",
    "362C30": "stars_orbiting",
    "365970": "green_impact",
    "366C80": "radial_shimmer",
    "36AE80": "ending_decals",
    "36DE10": "light_rays",
    "36ED30": "lightning",
    "374D80": "shimmer_burst",
    "375500": "energy_shockwave",
    "376FC0": "shimmer_wave",
    "37ACF0": "bulb_glow",
    "37D140": "effect_3D",
    "38A2F0": "firework",
    "38BAB0": "confetti",
    "38D040": "snowfall",
    "38E8F0": "effect_46",
    "38F6F0": "gather_magic",
    "393080": "flashing_box_shockwave",
    "3960C0": "floating_rock",
    "397010": "chomp_drop",
    "3BD770": "snowman_doll",
    "3C1B60": "fright_jar",
    "3CB7C0": "stop_watch",
    "3CD670": "effect_63",
    "3D11B0": "effect_65",
    "3D2460": "tubba_heart_attack",
    "3D3910": "whirlwind",
    "3D4930": "red_impact",
    "3D4E70": "floating_cloud_puff",
    "3D5E60": "energy_in_out",
    "3D7740": "shiny_flare",
    "3D80B0": "huff_puff_breath",
    "3D8F30": "cold_breath",
    "3DBEA0": "embers",
    "3DCD00": "hieroglyphs",
    "3DED90": "misc_particles",
    "3E11B0": "static_status",
    "3E1CC0": "moving_cloud",
    "3E5060": "firework_rocket",
    "3E5ED0": "peach_star_beam",
    "3EBC30": "chapter_change",
    "3F8CA0": "ice_shard",
    "3FA480": "spirit_card",
    "3FF180": "lil_oink",
    "4032A0": "something_rotating",
    "403BB0": "breaking_junk",
    "404E40": "partner_buff",
    "407040": "quizmo_assistant",
    "40A180": "ice_pillar",
    "40BB70": "sun",
    "40D130": "star_spirits_energy",
    "412FD0": "pink_sparkles",
    "413F20": "star_outline",
}


def handle_symbol(effect, symbol):
    for root, dirs, files in os.walk(asm_effects_dir + effect + "/"):
        for f_name in files:
            if f_name.endswith(".s"):
                f_path = os.path.join(root, f_name)

                with open(f_path) as f:
                    asm_lines = f.readlines()

                has_rodata_section = False
                for line in asm_lines:
                    if ".section .rodata" in line:
                        has_rodata_section = True
                        continue
                    if symbol[1] in line:
                        if not has_rodata_section:
                            asm_lines.insert(3, ".section .rodata\n")
                            asm_lines.insert(4, "\n")
                            asm_lines.insert(5, ".section .text\n")
                            asm_lines.insert(6, "\n")
                        asm_lines.insert(5, f"dlabel {symbol[1]}\n")
                        asm_lines.insert(6, f"{symbol[2]}\n")
                        asm_lines.insert(7, "\n")

                        with open(f_path, "w", newline="\n") as f:
                            f.write("".join(asm_lines))

                        return True
    return False


def handle_file(f_path):
    with open(f_path) as f:
        rodata_lines = f.readlines()[4:]

    effect = f_path.split("/")[-1].split(".")[0]

    symbols = []
    for i in range(0, len(rodata_lines), 3):
        l1 = rodata_lines[i].strip()
        l2 = rodata_lines[i + 1].strip()
        symbols.append((i + 4, l1.split()[1], l2))

    for symbol in reversed(symbols):
        if symbol[2].startswith(".word") and not symbol[1].startswith("jtbl_"):
            print("skipping" + str(symbol))
            continue
        migrated = handle_symbol(data_to_thing[effect], symbol)


# Walk through asm files and rename stuff
print("Walking through asm files")
for root, dirs, files in os.walk(asm_data_dir):
    for f_name in files:
        if f_name.endswith(".data.s"):
            f_path = os.path.join(root, f_name)

            handle_file(f_path)
