#!/usr/bin/env python3

import re
import sys
import argparse
from pathlib import Path
from typing import List
import xml.etree.ElementTree as ET


def get_optional_boolean_attrib(elem: ET.Element, attrib: str) -> bool:
    return elem.attrib.get(attrib, "false").lower() == "true"


class ItemHudScriptEntry:
    def __init__(self, elem: ET.Element):
        self.name = elem.attrib.get("name", None)
        self.template = elem.attrib.get("template", None)
        self.icon = elem.attrib.get("icon", "")
        priority_str = elem.attrib.get("priority", "auto")
        self.pair = get_optional_boolean_attrib(elem, "pair")
        self.extern = get_optional_boolean_attrib(elem, "extern")

        if self.name == None:
            raise Exception(f"{elem.tag} is missing attribute: 'name'")

        if self.template == None and not self.extern:
            raise Exception(f"{elem.tag} is missing attribute: 'template'")

        self.icon = re.sub("\\W", "_", self.icon)

        if priority_str.lower() == "auto":
            self.priority = sys.maxsize
        else:
            self.priority = int(priority_str)


def generate_scripts(in_xml: Path, out_c: Path):
    xml = ET.parse(in_xml)
    ScriptList = xml.getroot()

    scripts: List[ItemHudScriptEntry] = []

    for elem in ScriptList.findall("HScript"):
        scripts.append(ItemHudScriptEntry(elem))

    with open(out_c, "w") as f:
        f.write("#ifndef ITEM_HUD_SCRIPTS_H\n")
        f.write("#define ITEM_HUD_SCRIPTS_H\n")
        f.write("/* This file is auto-generated. Do not edit. */\n\n")
        f.write('#include "hud_element.h"\n\n')

        for entry in scripts:
            # do not generate scripts for entries defined externally
            if entry.extern:
                continue

            f.write(f"HudScript HES_{entry.name} = HES_TEMPLATE_{entry.template}({entry.icon});\n")

            if entry.pair:
                f.write(
                    f"HudScript HES_{entry.name}_disabled = HES_TEMPLATE_{entry.template}({entry.icon}_disabled);\n"
                )

            # there is no item for these scripts, just generate them after the coin script
            if entry.name == "Item_Coin":
                f.write("HudScript HES_Item_CoinSparkleA = HES_COIN_SPARKLE(-8,  0);\n")
                f.write("HudScript HES_Item_CoinSparkleB = HES_COIN_SPARKLE( 8,  8);\n")
                f.write("HudScript HES_Item_CoinSparkleC = HES_COIN_SPARKLE(-4,  8);\n")
                f.write("HudScript HES_Item_CoinSparkleD = HES_COIN_SPARKLE( 6, -6);\n")
                f.write("HudScript HES_Item_CoinSparkleE = HES_COIN_SPARKLE( 1, -8);\n")
                f.write("HudScript HES_Item_CoinSparkleRandom = HES_TEMPLATE_COIN_SPARKLE();\n")
            elif entry.name == "Item_StarPoint":
                f.write("HudScript HES_Item_SmallStarPoint = HES_TEMPLATE_SMALL_STAR_POINT();\n")

        f.write("\n#endif // ITEM_HUD_SCRIPTS_H\n")


def generate_table(in_xml: Path, out_c: Path):
    xml = ET.parse(in_xml)
    ScriptList = xml.getroot()

    scripts: List[ItemHudScriptEntry] = []

    for elem in ScriptList.findall("HScript"):
        scripts.append(ItemHudScriptEntry(elem))

    scripts.sort(key=lambda x: x.priority)

    with open(out_c, "w") as f:
        f.write("#ifndef ITEM_HUD_SCRIPT_TABLE_H\n")
        f.write("#define ITEM_HUD_SCRIPT_TABLE_H\n")
        f.write("/* This file is auto-generated. Do not edit. */\n\n")
        f.write('#include "hud_element.h"\n\n')

        for entry in scripts:
            if entry.extern:
                f.write(f"extern HudScript HES_{entry.name};\n")
                if entry.pair:
                    f.write(f"extern HudScript HES_{entry.name}_disabled;\n")
                f.write("\n")

        f.write("IconHudScriptPair gItemHudScripts[] = {\n")
        f.write("    { .enabled = NULL, .disabled = NULL },\n")

        for entry in scripts:
            if entry.pair:
                f.write(f"    {{ .enabled = &HES_{entry.name}, .disabled = &HES_{entry.name}_disabled }},\n")
            else:
                f.write(f"    {{ .enabled = &HES_{entry.name}, .disabled = &HES_{entry.name} }},\n")

        f.write("};\n")
        f.write("\n#endif // ITEM_HUD_SCRIPT_TABLE_H\n")


def generate_mapping(in_xml: Path, out_c: Path):
    xml = ET.parse(in_xml)
    ScriptList = xml.getroot()

    scripts: List[ItemHudScriptEntry] = []

    for elem in ScriptList.findall("HScript"):
        scripts.append(ItemHudScriptEntry(elem))

    scripts.sort(key=lambda x: x.priority)

    with open(out_c, "w") as f:
        f.write("/* This file is auto-generated. Do not edit. */\n\n")

        f.write("// indices into gItemHudScripts for hud scripts used by the item table\n")

        for idx, entry in enumerate(scripts):
            f.write(f"#define HS_INDEX_HES_{entry.name:50} 0x{idx + 1:03X}\n")

        f.write("\n")
        f.write("// handle the mapping from HudScript name to gItemHudScripts array index,\n")
        f.write("// allowing item table entries to reference their HudScripts by name\n")
        f.write("#define ITEM_HS_INDEX(scrName) HS_INDEX_##scrName\n")


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Generates item HUD scripts")
    parser.add_argument("mode", help="generate | table")
    parser.add_argument("in_xml", type=Path, help="input xml file path")
    parser.add_argument("header_path", help="output header file to generate")
    args = parser.parse_args()

    if args.mode == "generate":
        generate_scripts(args.in_xml, args.header_path)
    elif args.mode == "table":
        generate_table(args.in_xml, args.header_path)
    elif args.mode == "mapping":
        generate_mapping(args.in_xml, args.header_path)
