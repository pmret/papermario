#!/usr/bin/env python3

import re
import yaml
import argparse
from pathlib import Path
from typing import List
from io import TextIOWrapper


class MoveEntry:
    def __init__(self, entry):
        self.name = list(entry.keys())[0]
        data = entry[self.name]

        self.nameMsg = data.get("nameMsg", "MSG_NONE")
        self.fullDescMsg = data.get("fullDescMsg", "MSG_NONE")
        self.shortDescMsg = data.get("shortDescMsg", "MSG_NONE")
        self.flags = data.get("flags", [])
        self.category = data.get("category", "")
        self.actionTip = data.get("actionTip", "")
        self.costFP = data.get("costFP", 0)
        self.costBP = data.get("costBP", 0)


def read_moves_yaml(in_yaml: Path) -> List[MoveEntry]:
    items: List[MoveEntry] = []

    with open(in_yaml) as f:
        entry_list = yaml.load(f.read(), Loader=yaml.SafeLoader)

        for entry in entry_list:
            items.append(MoveEntry(entry))

    return items


def generate_move_table(fout: TextIOWrapper, moves: List[MoveEntry]):
    fout.write("MoveData gMoveTable[] = {\n")

    def join_flags(flags: List[str]) -> str:
        if len(flags) > 0:
            joined = " | ".join(flags)
        else:
            joined = "0"
        return joined

    for idx, move in enumerate(moves):
        fout.write(f"    {{   // 0x{idx:02X}: {move.name}\n")
        fout.write(f"        .nameMsg = {move.nameMsg},\n")
        fout.write(f"        .fullDescMsg = {move.fullDescMsg},\n")
        fout.write(f"        .shortDescMsg = {move.shortDescMsg},\n")
        fout.write(f"        .flags = {join_flags(move.flags)},\n")
        fout.write(f"        .category = {move.category},\n")
        fout.write(f"        .actionTip = {move.actionTip},\n")
        fout.write(f"        .costFP = {move.costFP},\n")
        fout.write(f"        .costBP = {move.costBP},\n")
        fout.write(f"    }},\n")

    fout.write("};\n")
    fout.write("\n")


def generate_move_enum(fout: TextIOWrapper, moves: List[MoveEntry]):
    fout.write("#ifndef MOVE_ENUM_H\n")
    fout.write("#define MOVE_ENUM_H\n")
    fout.write("\n")

    fout.write("enum MoveIDs {\n")

    item_enum: List[str] = []

    for idx, move in enumerate(moves):
        if re.match(r"Unused_(?:Hammer_)?([0-9A-F]{2})", move.name):
            name = "MOVE_" + move.name.upper()
        else:
            name = "MOVE_" + re.sub("((?<=[a-z0-9])[A-Z]|(?!^)(?<!_)[A-Z](?=[a-z]))", r"_\1", move.name).upper()
        item_enum.append(name)
        fout.write(f"    {name:39} = 0x{idx:03X},\n")

    fout.write("};\n")
    fout.write("\n")

    fout.write("#define STAR_POWER_INDEX(x) (x - MOVE_FOCUS)\n")
    fout.write("\n")

    fout.write("#endif // MOVE_ENUM_H\n")


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Generates item table")
    parser.add_argument("out_data", help="output header file to generate containing the data")
    parser.add_argument("out_enum", help="output header file to generate containing the enum")
    parser.add_argument("moves_yaml", type=Path, help="input yaml file path")
    args = parser.parse_args()

    moves = read_moves_yaml(args.moves_yaml)

    with open(args.out_data, "w") as fout:
        fout.write("/* This file is auto-generated. Do not edit. */\n")
        fout.write('#include "common.h"\n')
        fout.write('#include "message_ids.h"\n')
        fout.write("\n")

        generate_move_table(fout, moves)

    with open(args.out_enum, "w") as fout:
        fout.write("/* This file is auto-generated. Do not edit. */\n")
        fout.write("\n")

        generate_move_enum(fout, moves)
