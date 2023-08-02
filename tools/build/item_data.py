#!/usr/bin/env python3

import re
import sys
import yaml
import argparse
from pathlib import Path
from typing import List, Dict
from io import TextIOWrapper


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


def read_items_yaml(in_yaml: Path) -> List[ItemEntry]:
    items: List[ItemEntry] = []

    with open(in_yaml) as f:
        entry_list = yaml.load(f.read(), Loader=yaml.SafeLoader)

        for entry in entry_list:
            items.append(ItemEntry(entry))

    return items


def generate_item_table(fout: TextIOWrapper, items: List[ItemEntry], hs_map: Dict[str, int]):
    fout.write("ItemData gItemTable[] = {\n")

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

        fout.write(f"    {{   // 0x{idx:03X}: {item.name}\n")
        fout.write(f"        .nameMsg = {item.nameMsg},\n")
        fout.write(f"        .fullDescMsg = {item.fullDescMsg},\n")
        fout.write(f"        .shortDescMsg = {item.shortDescMsg},\n")
        fout.write(f"        .hudElemID = {hud_elem_id}, // {hud_elem_str}\n")
        fout.write(f"        .sellValue = {item.sellValue},\n")
        fout.write(f"        .sortValue = {item.sortValue},\n")
        fout.write(f"        .targetFlags = {join_flags(item.targetFlags)},\n")
        fout.write(f"        .typeFlags = {join_flags(item.typeFlags)},\n")
        fout.write(f"        .moveID = {item.moveID},\n")
        fout.write(f"        .potencyA = {item.potencyA},\n")
        fout.write(f"        .potencyB = {item.potencyB},\n")
        fout.write(f"    }},\n")

    fout.write("};\n")
    fout.write("\n")


def generate_item_enum(fout: TextIOWrapper, items: List[ItemEntry]):
    fout.write("#ifndef ITEM_ENUM_H\n")
    fout.write("#define ITEM_ENUM_H\n")
    fout.write("\n")

    fout.write("enum ItemIDs {\n")

    item_enum: List[str] = []

    for idx, item in enumerate(items):
        # FireFlower     -> FIRE_FLOWER
        # POWBlock       -> POW_BLOCK
        # MagicalSeed1   -> MAGICAL_SEED1
        # UnusedLetter_4 -> UNUSED_LETTER_4
        # etc
        name = "ITEM_" + re.sub("((?<=[a-z0-9])[A-Z]|(?!^)(?<!_)[A-Z](?=[a-z]))", r"_\1", item.name).upper()
        item_enum.append(name)
        fout.write(f"    {name:39} = 0x{idx:03X},\n")

    fout.write("};\n")
    fout.write("\n")

    # determine itemID ranges for each category
    min_cat: Dict[str, int] = {}
    max_cat: Dict[str, int] = {}

    for idx, item in enumerate(items):
        cat = item.category
        if cat not in min_cat:
            min_cat[cat] = idx
        max_cat[cat] = idx

    fout.write(f"#define ITEM_FIRST_KEY              {item_enum[min_cat['KEY']]}\n")
    fout.write(f"#define ITEM_LAST_KEY               {item_enum[max_cat['KEY']]}\n")
    fout.write(f"#define ITEM_FIRST_CONSUMABLE       {item_enum[min_cat['CONSUMABLE']]}\n")
    fout.write(f"#define ITEM_LAST_CONSUMABLE        {item_enum[max_cat['CONSUMABLE']]}\n")
    fout.write(f"#define ITEM_FIRST_BADGE            {item_enum[min_cat['BADGE']]}\n")
    fout.write(f"#define ITEM_LAST_BADGE             {item_enum[max_cat['BADGE']]}\n")
    fout.write("\n")

    fout.write("#define ITEM_NUM_KEYS (ITEM_LAST_KEY - ITEM_FIRST_KEY + 1)\n")
    fout.write("#define ITEM_NUM_CONSUMABLES (ITEM_LAST_CONSUMABLE - ITEM_FIRST_CONSUMABLE + 1)\n")
    fout.write("\n")

    fout.write("#define IS_ITEM(itemID) (itemID >= ITEM_FIRST_KEY && itemID <= ITEM_LAST_CONSUMABLE)\n")
    fout.write("#define IS_BADGE(itemID) (itemID >= ITEM_FIRST_BADGE && itemID <= ITEM_LAST_BADGE)\n")
    fout.write("\n")

    fout.write("#endif // ITEM_ENUM_H\n")


class ItemHudScriptEntry:
    def __init__(self, script):
        self.name = script.get("name", None)
        self.template = script.get("template", None)
        self.icon = script.get("icon", "")
        priority_str = script.get("priority", "auto")
        self.pair = script.get("pair", False)

        if self.name == None:
            raise Exception(f"ItemHudScript is missing 'name'")

        self.extern = self.name.startswith("HES_")
        if self.extern:
            self.full_name = self.name
        else:
            self.full_name = "HES_Item_" + self.name

        if self.template == None and not self.extern:
            raise Exception(f"{self.name} is missing 'template'")

        self.icon = re.sub("\\W", "_", self.icon)

        if str(priority_str).lower() == "auto":
            self.priority = sys.maxsize
        else:
            self.priority = int(priority_str)


def read_hud_scripts_yaml(in_yaml: Path) -> List[ItemHudScriptEntry]:
    scripts: List[ItemHudScriptEntry] = []

    with open(in_yaml) as f:
        entry_list = yaml.load(f.read(), Loader=yaml.SafeLoader)

        for entry in entry_list:
            scripts.append(ItemHudScriptEntry(entry))

    return scripts


def generate_hud_scripts(fout: TextIOWrapper, hud_scripts: List[ItemHudScriptEntry]):
    for entry in hud_scripts:
        # do not generate scripts for entries defined externally
        if entry.extern:
            continue

        fout.write(f"HudScript {entry.full_name} = HES_TEMPLATE_{entry.template}({entry.icon});\n")

        if entry.pair:
            fout.write(
                f"HudScript {entry.full_name}_disabled = HES_TEMPLATE_{entry.template}({entry.icon}_disabled);\n"
            )

        # there is no item for these scripts, just generate them after the coin script
        if entry.name == "Coin":
            fout.write("HudScript HES_Item_CoinSparkleA = HES_COIN_SPARKLE(-8,  0);\n")
            fout.write("HudScript HES_Item_CoinSparkleB = HES_COIN_SPARKLE( 8,  8);\n")
            fout.write("HudScript HES_Item_CoinSparkleC = HES_COIN_SPARKLE(-4,  8);\n")
            fout.write("HudScript HES_Item_CoinSparkleD = HES_COIN_SPARKLE( 6, -6);\n")
            fout.write("HudScript HES_Item_CoinSparkleE = HES_COIN_SPARKLE( 1, -8);\n")
            fout.write("HudScript HES_Item_CoinSparkleRandom = HES_TEMPLATE_COIN_SPARKLE();\n")
        elif entry.name == "StarPoint":
            fout.write("HudScript HES_Item_SmallStarPoint = HES_TEMPLATE_SMALL_STAR_POINT();\n")
    fout.write("\n")

    fout.write("s32 pad_after_item_hudscripts[] = { 0, 0 };\n")
    fout.write("\n")


def generate_hud_scripts_table(fout: TextIOWrapper, hud_scripts: List[ItemHudScriptEntry]):
    for entry in hud_scripts:
        if entry.extern:
            fout.write(f"extern HudScript {entry.full_name};\n")
            if entry.pair:
                fout.write(f"extern HudScript {entry.full_name}_disabled;\n")
            fout.write("\n")

    fout.write("IconHudScriptPair gItemHudScripts[] = {\n")
    fout.write("    { .enabled = NULL, .disabled = NULL },\n")  # array index 0 is always NULL

    for entry in hud_scripts:
        if entry.pair:
            fout.write(f"    {{ .enabled = &{entry.full_name}, .disabled = &{entry.full_name}_disabled }},\n")
        else:
            fout.write(f"    {{ .enabled = &{entry.full_name}, .disabled = &{entry.full_name} }},\n")

    fout.write("};\n")
    fout.write("\n")


def generate_item_entity_scripts(fout: TextIOWrapper, ies_yaml: Path):
    with open(ies_yaml) as f:
        scripts = yaml.load(f.read(), Loader=yaml.SafeLoader)

    for script in scripts:
        name = script.get("name", None)
        template = script.get("template", None)
        icon = script.get("icon", None)

        if name is None:
            raise Exception("Item entity script is missing 'name'")

        if template is None:
            raise Exception(f"{name} is missing 'template'")

        if icon is None:
            icon = ""
        else:
            icon = re.sub("\\W", "_", icon)

        fout.write(f"ItemScript IES_{name} = IES_TEMPLATE_{template}({icon});\n")

    fout.write("\n")


def generate_item_entity_scripts_table(fout: TextIOWrapper, items: List[ItemEntry]):
    fout.write("// indexed by itemID\n")
    fout.write("s32* gItemEntityScripts[] = {\n")
    idx = 0
    for item in items:
        fout.write(f"    IES_{item.itemEntity},\n")
        idx += 1

    # must pad with IES_Placeholder to match
    while idx <= 0x180:
        fout.write(f"    IES_{items[0].itemEntity},\n")
        idx += 1

    fout.write("};\n")
    fout.write("\n")


def generate_item_icon_tables(fout: TextIOWrapper, items: List[ItemEntry]):
    # note: DUMMY items have no icon rasters or palettes
    fout.write("// indexed by itemID\n")
    fout.write("s32 gItemIconRasterOffsets[] = {\n")
    for item in items:
        if item.category != "DUMMY":
            fout.write(f"    ICON_{item.icon}_raster,\n")
    fout.write("};\n")
    fout.write("\n")

    fout.write("// indexed by itemID\n")
    fout.write("s32 gItemIconPaletteOffsets[] = {\n")
    for item in items:
        if item.category != "DUMMY":
            fout.write(f"    ICON_{item.icon}_palette,\n")
    fout.write("};\n")
    fout.write("\n")


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Generates item table")
    parser.add_argument("out_data", help="output header file to generate containing the data")
    parser.add_argument("out_enum", help="output header file to generate containing the enum")
    parser.add_argument("items_yaml", type=Path, help="input yaml file path")
    parser.add_argument("ies_yaml", type=Path, help="input yaml file path for item entity scripts")
    parser.add_argument("hes_yaml", type=Path, help="input yaml file path for item hud element scripts")
    args = parser.parse_args()

    items = read_items_yaml(args.items_yaml)
    hud_scripts = read_hud_scripts_yaml(args.hes_yaml)

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

    with open(args.out_data, "w") as fout:
        fout.write("/* This file is auto-generated. Do not edit. */\n")
        fout.write('#include "common.h"\n')
        fout.write('#include "message_ids.h"\n')
        fout.write('#include "hud_element.h"\n')
        fout.write('#include "item_entity.h"\n')
        fout.write('#include "icon_offsets.h"\n')
        fout.write("\n")

        generate_hud_scripts(fout, hud_scripts)

        # after writing the hud script sources, sort them according to table order
        hud_scripts.sort(key=lambda x: x.priority)

        # get hudElemID for each hud element
        hs_map: Dict[str, int] = {}
        for idx, hs in enumerate(hud_scripts):
            hs_map[hs.name] = idx + 1

        generate_item_table(fout, items, hs_map)
        generate_hud_scripts_table(fout, hud_scripts)
        generate_item_entity_scripts(fout, args.ies_yaml)
        generate_item_entity_scripts_table(fout, items)
        generate_item_icon_tables(fout, items)

    with open(args.out_enum, "w") as fout:
        fout.write("/* This file is auto-generated. Do not edit. */\n")
        fout.write("\n")

        generate_item_enum(fout, items)
