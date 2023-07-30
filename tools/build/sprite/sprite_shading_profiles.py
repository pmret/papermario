#!/usr/bin/env python3

from dataclasses import dataclass, field
from enum import Enum
import argparse
import json
from pathlib import Path
import struct
from typing import List, Literal


class LightMode(Enum):
    UNIFORM = 0
    LINEAR = 4
    QUADRATIC = 8


@dataclass
class Light:
    flags: int
    rgb: List[int]
    pos: List[int]
    falloff: float

    def to_json(self):
        d = self.__dict__
        d["mode"] = LightMode(d["flags"] - 1).name.lower()
        del d["flags"]
        return d


@dataclass
class SpriteShadingProfile:
    name: str
    ambient: List[int]
    power: int
    lights: List[Light] = field(default_factory=lambda: [])

    def to_json(self):
        d = self.__dict__
        d["lights"] = [light.to_json() for light in self.lights]
        return d


@dataclass
class SpriteShadingGroup:
    area: str
    profiles: List[SpriteShadingProfile] = field(default_factory=lambda: [])

    def to_json(self):
        d = self.__dict__
        d["profiles"] = [profile.to_json() for profile in self.profiles]
        return d


def groups_from_json(data) -> List[SpriteShadingGroup]:
    groups = []
    for group in data:
        profiles = []
        for profile in group["profiles"]:
            lights = []
            for light in profile["lights"]:
                enabled = light.get("enabled", True)
                lights.append(
                    Light(
                        flags=LightMode[light["mode"].upper()].value + (1 if enabled else 0),
                        rgb=light["rgb"],
                        pos=light["pos"],
                        falloff=light["falloff"],
                    )
                )
            profiles.append(
                SpriteShadingProfile(
                    name=profile["name"],
                    ambient=profile["ambient"],
                    power=profile["power"],
                    lights=lights,
                )
            )
        groups.append(
            SpriteShadingGroup(
                area=group["area"],
                profiles=profiles,
            )
        )
    return groups


def build(
    input: Path,
    bin_out: Path,
    header_out: Path,
    endian: Literal["big", "little"] = "big",
    matching: bool = True,
):
    END = ">" if endian == "big" else "<"

    with open(input, "r") as f:
        json_data = json.load(f)

    groups = groups_from_json(json_data)

    # Header creation
    with open(header_out, "w") as f:
        f.write("#ifndef SHADING_PROFILES_H\n")
        f.write("#define SHADING_PROFILES_H\n")
        f.write(f"/* This file is auto-generated from {input.name}. Do not edit. */\n\n")
        f.write("enum ShadingProfile {\n")
        f.write("    SHADING_NONE = 0xFFFFFFFF,\n")

        for g, group in enumerate(groups):
            for i, profile in enumerate(group.profiles):
                f.write(f"    SHADING_{profile.name.upper()} = 0x{(g << 16) | i:08X},\n")
        f.write("};\n")
        f.write("#endif // SHADING_PROFILES_H\n")

    data_offset = 0
    profile_list_offset = len(groups) * 8
    offsets_table = bytearray()
    profile_lists = bytearray()
    data_table = bytearray()
    for g, group in enumerate(groups):
        offsets_table.extend(struct.pack(END + "i", data_offset))
        offsets_table.extend(struct.pack(END + "i", profile_list_offset))

        group_data_offset = 0

        for profile in group.profiles:
            profile_lists.extend(struct.pack(END + "i", group_data_offset))
            data_table.extend(struct.pack(END + "B", len(profile.lights)))
            data_table.append(0)
            data_table.extend(struct.pack(END + "B", profile.ambient[0]))
            data_table.extend(struct.pack(END + "B", profile.ambient[1]))
            data_table.extend(struct.pack(END + "B", profile.ambient[2]))
            data_table.extend(struct.pack(END + "B", profile.power))
            group_data_offset += 6
            profile_list_offset += 4

            for light in profile.lights:
                data_table.extend(struct.pack(END + "B", light.flags))
                data_table.extend(struct.pack(END + "B", light.rgb[0]))
                data_table.extend(struct.pack(END + "B", light.rgb[1]))
                data_table.extend(struct.pack(END + "B", light.rgb[2]))
                data_table.extend(struct.pack(END + "h", light.pos[0]))
                data_table.extend(struct.pack(END + "h", light.pos[1]))
                data_table.extend(struct.pack(END + "h", light.pos[2]))
                data_table.extend(struct.pack(END + "f", light.falloff))
                data_table.append(0)
                data_table.append(0)
                group_data_offset += 0x10
        data_offset += group_data_offset

    offsets_table.extend(profile_lists)
    if matching:
        offsets_table += b"\0" * (0x1D0 - len(offsets_table))  # Pad to 0x1D0

    final_data = offsets_table + data_table
    if matching:
        final_data += b"\0" * (0xE70 - len(final_data))  # Pad to 0xE70

    with open(bin_out, "wb") as f:
        f.write(final_data)


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Sprite shading profiles")
    parser.add_argument("input", type=Path, help="Input JSON file")
    parser.add_argument("bin_out", type=Path, help="Output binary file path")
    parser.add_argument("header_out", type=Path, help="Output header file path")
    parser.add_argument("--endian", choices=["big", "little"], default="big", help="Output endianness")
    parser.add_argument("--matching", help="Pad to matching size", default=True)
    args = parser.parse_args()

    build(args.input, args.bin_out, args.header_out, args.endian, args.matching)
