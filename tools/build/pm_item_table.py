#!/usr/bin/env python3

import re
import yaml
import argparse
from pathlib import Path
from typing import List, Dict
from pm_item_hud_scripts import ItemHudScriptEntry, read_hud_scripts_xml


class ItemEntry:
    def __init__(self, entry):
        self.name = list(entry.keys())[0]
        data = entry[self.name]

        self.category = data.get("category", "")
        self.nameMsg = data.get("nameMsg", "MSG_NONE")
        self.fullDescMsg = data.get("fullDescMsg", "MSG_NONE")
        self.shortDescMsg = data.get("shortDescMsg", "MSG_NONE")
        self.hudElem = data.get("hudElement", "Item_Present")
        self.itemEntity = data.get("itemEntity", "Placeholder")
        self.icon = data.get("icon", "key/Gift")
        self.sellValue = data.get("sellValue", -1)
        self.sortValue = data.get("sortValue", 0)
        self.targetFlags = data.get("targetFlags", [])
        self.typeFlags = data.get("typeFlags", [])
        self.moveID = data.get("moveID", "MOVE_NONE")
        self.potencyA = data.get("potencyA", 0)
        self.potencyB = data.get("potencyB", 0)

        self.icon = re.sub("\\W", "_", self.icon)


def generate_table(out_c: Path, items_yaml: Path, ies_xml: Path, hes_yaml: Path):
    hud_scripts = read_hud_scripts_xml(hes_yaml)
    hud_scripts.sort(key=lambda x: x.priority)

    hs_map: Dict[str, int] = {}
    for idx, hs in enumerate(hud_scripts):
        hs_map[hs.name] = idx + 1

    items: List[ItemEntry] = []

    with open(items_yaml) as f:
        item_list = yaml.load(f.read(), Loader=yaml.SafeLoader)

        for entry in item_list:
            items.append(ItemEntry(entry))

    # sort items by category
    CATEGORY_ORDER = {
        "NONE": 0,
        "GEAR": 1,
        "QUEST": 2,
        "KEY": 3,
        "CONSUMABLE": 4,
        "UNUSED": 5,
        "BADGE": 6,
        "UTILITY": 7,
        "DUMMY": 1000,  # must always be at the end of the item table
    }
    items.sort(key=lambda x: CATEGORY_ORDER.get(x.category, 999))

    # determine itemID ranges for each category
    min_cat: Dict[str, int] = {}
    max_cat: Dict[str, int] = {}

    for idx, item in enumerate(items):
        cat = item.category
        if cat not in min_cat:
            min_cat[cat] = idx
        max_cat[cat] = idx

    # write the item table file
    with open(out_c, "w") as f:
        f.write("/* This file is auto-generated. Do not edit. */\n")
        f.write('#include "common.h"\n\n')
        f.write('#include "message_ids.h"\n\n')

        f.write("ItemData gItemTable[] = {\n")

        def join_flags(flags: List[str]) -> str:
            if len(flags) > 0:
                joined = " | ".join(flags)
            else:
                joined = "0"
            return joined

        for idx, item in enumerate(items):
            hud_elem_id = hs_map.get(item.hudElem, None)
            if hud_elem_id == None:
                raise Exception(f"Item {item.name} requires undefined HudScript: {item.hudElem}")
            if item.hudElem.startswith("HES_"):
                hud_elem_str = item.hudElem
            else:
                hud_elem_str = "HES_Item_" + item.hudElem

            f.write(f"{{   // 0x{idx:03X}: {item.name}\n")
            f.write(f"    .nameMsg = {item.nameMsg},\n")
            f.write(f"    .fullDescMsg = {item.fullDescMsg},\n")
            f.write(f"    .shortDescMsg = {item.shortDescMsg},\n")
            f.write(f"    .hudElemID = {hud_elem_id}, // {hud_elem_str}\n")  # ITEM_HS_INDEX(HES_{item.hudElem}),\n")
            f.write(f"    .sellValue = {item.sellValue},\n")
            f.write(f"    .sortValue = {item.sortValue},\n")
            f.write(f"    .targetFlags = {join_flags(item.targetFlags)},\n")
            f.write(f"    .typeFlags = {join_flags(item.typeFlags)},\n")
            f.write(f"    .moveID = {item.moveID},\n")
            f.write(f"    .potencyA = {item.potencyA},\n")
            f.write(f"    .potencyB = {item.potencyB},\n")
            f.write("},\n")

        f.write("};\n")


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Generates item table")
    parser.add_argument("header_path", help="output header file to generate")
    parser.add_argument("items_yaml", type=Path, help="input yaml file path")
    parser.add_argument("ies_xml", type=Path, help="input xml file path for item entity scripts")
    parser.add_argument("hes_xml", type=Path, help="input xml file path for item hud element scripts")
    args = parser.parse_args()

    generate_table(args.header_path, args.items_yaml, args.ies_xml, args.hes_xml)
