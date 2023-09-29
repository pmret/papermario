#!/usr/bin/env python3

import re
import yaml
import argparse
from pathlib import Path
from typing import List
from io import TextIOWrapper


class ActorTypeEntry:
    def __init__(self, entry):
        self.name = list(entry.keys())[0]
        data = entry[self.name]

        self.level = data.get("level", 0)
        self.nameMsg = data.get("nameMsg", "MSG_NONE")
        self.tattleMsg = data.get("tattleMsg", "MSG_NONE")
        self.walkSounds = data.get("walkSound", ["SOUND_NONE", "SOUND_NONE"])
        self.flySounds = data.get("flySound", ["SOUND_NONE", "SOUND_NONE"])
        self.jumpSound = data.get("jumpSound", "SOUND_NONE")
        self.hurtSound = data.get("hurtSound", "SOUND_NONE")
        self.stepDelay = data.get("stepDelay", [30, 30])
        self.tattleCamOffset = data.get("tattleCamOffset", [0, 0, 0])
        self.shadowOffset = data.get("shadowOffset", 0)
        self.ignoreDuringCount = data.get("ignoreDuringCount", False)

        if len(self.walkSounds) != 2:
            raise Exception("Walk sounds array has incorrect size: " + self.walkSounds)

        if len(self.flySounds) != 2:
            raise Exception("Fly sounds array has incorrect size: " + self.flySounds)

        if len(self.stepDelay) != 2:
            raise Exception("Steps delay array has incorrect size: " + self.stepDelay)

        if len(self.tattleCamOffset) != 3:
            raise Exception("Tattle cam offset array has incorrect size: " + self.tattleCamOffset)

        self.enum_suffix = re.sub("((?<=[a-z0-9])[A-Z]|(?!^)(?<!_)[A-Z](?=[a-z]))", r"_\1", self.name).upper()
        self.enum_name = "ACTOR_TYPE_" + self.enum_suffix


def read_actors_yaml(in_yaml: Path) -> List[ActorTypeEntry]:
    actors: List[ActorTypeEntry] = []

    with open(in_yaml) as f:
        entry_list = yaml.load(f.read(), Loader=yaml.SafeLoader)

        for entry in entry_list:
            actors.append(ActorTypeEntry(entry))

    return actors


def generate_actors_data(fout: TextIOWrapper, actors: List[ActorTypeEntry]):
    fout.write("s32 bActorNames[] = {\n")
    for actor in actors:
        key = "[" + actor.enum_name + "]"
        fout.write(f"    {key:40}{actor.nameMsg},\n")
    fout.write("};\n")
    fout.write("\n")

    fout.write("// enemy types to ignore when deciding initialEnemyCount\n")
    fout.write("s32 bActorsIgnoreDuringCount[] = {\n")
    for actor in actors:
        if actor.ignoreDuringCount:
            fout.write(f"    {actor.enum_name},\n")
    fout.write("    -1\n")
    fout.write("};\n")
    fout.write("\n")

    fout.write("ActorSounds bActorSoundTable[] = {\n")
    for actor in actors:
        fout.write(f"    [{actor.enum_name}] = {{\n")
        fout.write(f"        .walk = {{ {', '.join(actor.walkSounds)} }},\n")
        fout.write(f"        .fly = {{ {', '.join(actor.flySounds)} }},\n")
        fout.write(f"        .jump = {actor.jumpSound},\n")
        fout.write(f"        .hurt = {actor.hurtSound},\n")
        fout.write(f"        .delay = {{ {', '.join(map(str, actor.stepDelay))} }},\n")
        fout.write(f"    }},\n")
    fout.write("};\n")
    fout.write("\n")

    fout.write("s32 bActorTattles[] = {\n")
    for actor in actors:
        key = "[" + actor.enum_name + "]"
        fout.write(f"    {key:40}{actor.tattleMsg},\n")
    fout.write("};\n")
    fout.write("\n")

    fout.write("ActorOffsets bActorOffsets[] = {\n")
    for actor in actors:
        fout.write(f"    [{actor.enum_name}] = {{\n")
        fout.write(f"        .tattleCam = {{ {', '.join(map(str, actor.tattleCamOffset))} }},\n")
        fout.write(f"        .shadow = {actor.shadowOffset},\n")
        fout.write(f"    }},\n")
    fout.write("};\n")
    fout.write("\n")


def generate_actors_enums(fout: TextIOWrapper, actors: List[ActorTypeEntry]):
    fout.write("#ifndef ACTORS_ENUM_H\n")
    fout.write("#define ACTORS_ENUM_H\n")
    fout.write("\n")

    fout.write("enum ActorTypes {\n")

    for idx, actor in enumerate(actors):
        fout.write(f"    {actor.enum_name:48} = 0x{idx:02X},\n")

    fout.write("};\n")
    fout.write("\n")

    fout.write(f"#define ACTOR_LEVEL_NONE                             99\n")
    for idx, actor in enumerate(actors):
        fout.write(f"#define ACTOR_LEVEL_{actor.enum_suffix:32} {actor.level}\n")
    fout.write("\n")

    fout.write("#endif // ACTORS_ENUM_H\n")


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Generates actor tables")
    parser.add_argument("out_data", help="output header file to generate containing the data")
    parser.add_argument("out_enum", help="output header file to generate containing the enum")
    parser.add_argument("actors_yaml", type=Path, help="input yaml file path")
    args = parser.parse_args()

    actors = read_actors_yaml(args.actors_yaml)

    with open(args.out_data, "w") as fout:
        fout.write("/* This file is auto-generated. Do not edit. */\n")
        fout.write('#include "common.h"\n')
        fout.write('#include "message_ids.h"\n')
        fout.write("\n")

        generate_actors_data(fout, actors)

    with open(args.out_enum, "w") as fout:
        fout.write("/* This file is auto-generated. Do not edit. */\n")
        fout.write("\n")

        generate_actors_enums(fout, actors)
