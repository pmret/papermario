#!/usr/bin/env python3

import argparse
from pathlib import Path
from typing import List, Dict
import xml.etree.ElementTree as ET


def get_required_attrib(elem: ET.Element, attrib: str) -> str:
    value = elem.attrib.get(attrib, None)
    if value == None:
        raise Exception(f"{elem.tag} is missing attribute: '{attrib}'")
    return str(value)


class WorldMapEntry:
    def __init__(self, elem: ET.Element):
        self.location = get_required_attrib(elem, "id")
        self.parent = get_required_attrib(elem, "parent")
        self.requires = get_required_attrib(elem, "requires")
        self.startX = get_required_attrib(elem, "startX")
        self.startY = get_required_attrib(elem, "startY")
        path_str = get_required_attrib(elem, "path")

        self.path = []
        if path_str != "":
            for i in path_str.split(";"):
                self.path.append(i.split(","))


def generate(in_xml: Path, out_c: Path):
    xml = ET.parse(in_xml)
    ScriptList = xml.getroot()

    with open(out_c, "w") as f:
        f.write("#ifndef WORLD_MAP_H\n")
        f.write("#define WORLD_MAP_H\n")
        f.write("/* This file is auto-generated. Do not edit. */\n\n")
        f.write('#include "common.h"\n\n')

        locations: List[WorldMapEntry] = []

        for elem in ScriptList.findall("Location"):
            locations.append(WorldMapEntry(elem))

        loc_to_idx: Dict[str, int] = {}
        for idx, loc in enumerate(locations):
            loc_to_idx[loc.location] = idx

        # write paths
        # note: len(locations) = 34, will only match if hardcoded to 32 here
        f.write("Vec2b PauseMapPaths[][32] = {\n")

        for loc in locations:
            f.write("    { ")
            for point in loc.path:
                f.write(f"{{ {point[0]}, {point[1]} }}, ")
            f.write("},\n")

        f.write("};\n\n")

        # write locations
        f.write("PauseMapSpace PauseMapSpaces[] = {\n")

        for idx, loc in enumerate(locations):
            if loc.parent not in loc_to_idx:
                raise Exception(f"{loc.parent} is not defined")

            f.write(
                f"    {{ .id = {loc.location}, .parent = {loc_to_idx[loc.parent]}, .afterRequirement = {loc.requires}, "
                + f".pos = {{ .x = {loc.startX}, .y = {loc.startY} }}, "
                + f".pathLength = {len(loc.path)}, .path = PauseMapPaths[{idx}] }},\n"
            )

        f.write("};\n")

        f.write("\n#endif // WORLD_MAP_H\n")


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Generates world map data")
    parser.add_argument("in_xml", type=Path, help="input xml file path")
    parser.add_argument("header_path", help="output header file to generate")
    args = parser.parse_args()

    generate(args.in_xml, args.header_path)
