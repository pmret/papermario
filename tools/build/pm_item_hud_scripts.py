#!/usr/bin/env python3

import re
import argparse
from pathlib import Path
import xml.etree.ElementTree as ET


def build(in_xml: Path, out_c: Path):
    xml = ET.parse(in_xml)
    ScriptList = xml.getroot()

    with open(out_c, "w") as f:
        f.write("#ifndef ITEM_HUD_SCRIPTS_H\n")
        f.write("#define ITEM_HUD_SCRIPTS_H\n")
        f.write("/* This file is auto-generated. Do not edit. */\n\n")
        f.write('#include "hud_element.h"\n\n')

        for Script in ScriptList.findall("HScript"):
            name = Script.attrib.get("name", None)
            template = Script.attrib.get("template", None)
            icon = Script.attrib.get("icon", None)
            pair = Script.attrib.get("pair", "false").lower()

            if name is None:
                raise Exception("HScript is missing attribute: 'name'")

            if template is None:
                raise Exception("HScript is missing attribute: 'name'")

            if icon is None:
                icon = ""
            else:
                icon = re.sub("\\W", "_", icon)

            f.write(f"HudScript HES_Item_{name} = HES_TEMPLATE_{template}({icon});\n")

            if pair == "true":
                f.write(f"HudScript HES_Item_{name}_disabled = HES_TEMPLATE_{template}({icon}_disabled);\n")

            # there is no item for these scripts, just generate them after the coin script
            if name == "Coin":
                f.write("HudScript HES_Item_CoinSparkleA = HES_COIN_SPARKLE(-8,  0);\n")
                f.write("HudScript HES_Item_CoinSparkleB = HES_COIN_SPARKLE( 8,  8);\n")
                f.write("HudScript HES_Item_CoinSparkleC = HES_COIN_SPARKLE(-4,  8);\n")
                f.write("HudScript HES_Item_CoinSparkleD = HES_COIN_SPARKLE( 6, -6);\n")
                f.write("HudScript HES_Item_CoinSparkleE = HES_COIN_SPARKLE( 1, -8);\n")
                f.write("HudScript HES_Item_CoinSparkleRandom = HES_TEMPLATE_COIN_SPARKLE();\n")

        f.write("\n#endif // ITEM_HUD_SCRIPTS_H\n")


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Generates item HUD scripts")
    parser.add_argument("in_xml", type=Path, help="input xml file path")
    parser.add_argument("header_path", help="output header file to generate")
    args = parser.parse_args()

    build(args.in_xml, args.header_path)
