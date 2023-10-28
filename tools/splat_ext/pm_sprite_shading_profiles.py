import os
import sys
from pathlib import Path

TOOLS_DIR = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.append(str(Path(TOOLS_DIR) / "build/sprite"))
from sprite_shading_profiles import SpriteShadingGroup, SpriteShadingProfile, Light

import json
import struct
from typing import Literal

from segtypes.n64.segment import N64Segment
from util import options

GROUPS = [
    SpriteShadingGroup("TIK"),
    SpriteShadingGroup("KMR"),
    SpriteShadingGroup("ISK"),
    SpriteShadingGroup("HOS"),
    SpriteShadingGroup("OSR"),
    SpriteShadingGroup("KKJ"),
    SpriteShadingGroup("JSN"),
    SpriteShadingGroup("MIM"),
    SpriteShadingGroup("ARN"),
    SpriteShadingGroup("DGB"),
    SpriteShadingGroup("KZN"),
    SpriteShadingGroup("unused"),
    SpriteShadingGroup("ISK_BTL"),
]


def extract(input_data: bytes, endian: Literal["big", "little"] = "big") -> str:
    PROFILE_NAMES = [
        [
            "TIK_01",
            "TIK_02",
            "TIK_03",
            "TIK_04",
            "TIK_05",
            "TIK_06",
            "TIK_07",
            "TIK_08",
            "TIK_09",
            "TIK_10",
            "TIK_12",
            "TIK_14",
            "TIK_15",
            "TIK_18",
            "TIK_20",
            "TIK_21",
            "TIK_22",
            "TIK_23",
            "TIK_24",
            "TIK_25",
        ],
        ["KMR_30"],
        [
            "ISK_03",
            "ISK_04",
            "ISK_05",
            "ISK_06",
            "ISK_07",
            "ISK_08",
            "ISK_09",
            "ISK_10",
            "ISK_11",
            "ISK_12",
            "ISK_13",
            "ISK_14",
            "ISK_16",
            "ISK_UNUSED",
            "ISK_18",
            "ISK_19",
        ],
        ["HOS_01"],
        ["OSR_02"],
        [
            "KKJ_10",
            "KKJ_11",
            "KKJ_12",
            "KKJ_13",
            "KKJ_17",
            "KKJ_20",
            "KKJ_22",
            "KKJ_23",
            "KKJ_24",
            "KKJ_25",
            "KKJ_26",
            "KKJ_27",
        ],
        ["JAN_17", "JAN_19"],
        [
            "MIM_01",
            "MIM_02",
            "MIM_03",
            "MIM_04",
            "MIM_05",
            "MIM_06",
            "MIM_07",
            "MIM_08",
            "MIM_09",
            "MIM_11",
            "MIM_12",
        ],
        ["ARN_09", "ARN_10", "ARN_11", "ARN_12", "ARN_13"],
        ["DGB_06"],
        [
            "KZN_01",
            "KZN_02",
            "KZN_03",
            "KZN_04",
            "KZN_05",
            "KZN_06",
            "KZN_07",
            "KZN_08",
            "KZN_09",
            "KZN_10",
            "KZN_11",
            "KZN_17",
            "KZN_18",
            "KZN_19",
            "KZN_20",
            "KZN_22",
            "KZN_23",
        ],
        ["UNUSED"],
        ["BTL_ISK"],
    ]

    END = ">" if endian == "big" else "<"

    offsets_table = input_data[:0x1D0]
    lighting_data = input_data[0x1D0:]

    for g, group in enumerate(GROUPS):
        b = g * 8
        data_offset = struct.unpack(END + "i", offsets_table[b : b + 4])[0]
        pl_it = struct.unpack(END + "i", offsets_table[b + 4 : b + 8])[0]
        profile_list = []

        for _ in range(len(PROFILE_NAMES[g])):
            profile_list.append(struct.unpack(END + "i", offsets_table[pl_it : pl_it + 4])[0])
            pl_it += 4

        for j, pl_offset in enumerate(profile_list):
            profile_offset = data_offset + pl_offset
            num_lights = lighting_data[profile_offset]
            profile = SpriteShadingProfile(
                name=PROFILE_NAMES[g][j].lower(),
                ambient=[
                    lighting_data[profile_offset + 2],
                    lighting_data[profile_offset + 3],
                    lighting_data[profile_offset + 4],
                ],
                power=lighting_data[profile_offset + 5],
            )
            profile_offset += 6
            for _ in range(num_lights):
                profile.lights.append(
                    Light(
                        flags=lighting_data[profile_offset],
                        rgb=[
                            lighting_data[profile_offset + 1],
                            lighting_data[profile_offset + 2],
                            lighting_data[profile_offset + 3],
                        ],
                        pos=[
                            struct.unpack(
                                END + "h",
                                lighting_data[profile_offset + 4 : profile_offset + 6],
                            )[0],
                            struct.unpack(
                                END + "h",
                                lighting_data[profile_offset + 6 : profile_offset + 8],
                            )[0],
                            struct.unpack(
                                END + "h",
                                lighting_data[profile_offset + 8 : profile_offset + 10],
                            )[0],
                        ],
                        falloff=struct.unpack(
                            END + "f",
                            lighting_data[profile_offset + 10 : profile_offset + 14],
                        )[0],
                    )
                )
                profile_offset += 0x10
            group.profiles.append(profile)
    return json.dumps(
        [g.to_json() for g in GROUPS],
        sort_keys=False,
        indent=2,
    )


class N64SegPm_sprite_shading_profiles(N64Segment):
    OUT_DIR: Path = options.opts.asset_path / "sprite"

    def scan(self, rom_bytes):
        data = rom_bytes[self.rom_start : self.rom_end]

        self.json_out = extract(data)

    def split(self, rom_bytes):
        self.out_path().parent.mkdir(parents=True, exist_ok=True)
        with open(self.out_path(), "w") as f:
            f.write(self.json_out)

    def out_path(self) -> Path:
        return self.OUT_DIR / f"{self.name}.json"

    def get_linker_entries(self):
        from segtypes.linker_entry import LinkerEntry

        return [
            LinkerEntry(
                self,
                [self.OUT_DIR / f"{self.name}.json"],
                options.opts.asset_path / self.dir / f"{self.name}.bin",
                self.get_linker_section(),
                self.get_linker_section(),
            )
        ]
