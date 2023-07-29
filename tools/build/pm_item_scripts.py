#!/usr/bin/env python3

import re
import argparse
from pathlib import Path
import xml.etree.ElementTree as ET

def build(in_xml: Path, out_c: Path):
    xml = ET.parse(in_xml)
    ScriptList = xml.getroot()

    with open(out_c, "w") as f:

        f.write("#ifndef ITEM_ENTITY_SCRIPTS_H\n")
        f.write("#define ITEM_ENTITY_SCRIPTS_H\n")
        f.write(f"/* This file is auto-generated. Do not edit. */\n\n")

        for Script in ScriptList.findall("IScript"):
            name = Script.attrib.get("name", None)
            template = Script.attrib.get("template", None)
            icon = Script.attrib.get("icon", None)

            if name is None:
                raise Exception("IScript is missing attribute: 'name'")
            
            if template is None:
                raise Exception("IScript is missing attribute: 'template'")
            
            if icon is None:
                icon = ""
            else:
                icon = re.sub("\\W", "_", icon)

            f.write(f"ItemScript IES_{name} = IES_TEMPLATE_{template}({icon});\n")

        f.write("\n#endif // ITEM_ENTITY_SCRIPTS_H\n")

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Generates item entity scripts")
    parser.add_argument("in_xml", type=Path, help="input xml file path")
    parser.add_argument("header_path", help="output header file to generate")
    args = parser.parse_args()

    build(args.in_xml, args.header_path)
