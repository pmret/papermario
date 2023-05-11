from dataclasses import dataclass, field
from itertools import zip_longest
import struct
from typing import Dict, List
import xml.etree.ElementTree as ET


def iter_in_groups(iterable, n, fillvalue=None):
    args = [iter(iterable)] * n
    return zip_longest(*args, fillvalue=fillvalue)


def read_offset_list(data: bytes):
    l = []

    for offset in struct.iter_unpack(">i", data):
        if offset[0] == -1:
            break
        l.append(offset[0])

    return l


class Animation:
    @property
    def name(self) -> str:
        return self.__class__.__name__

    def get_attributes(self) -> Dict[str, str]:
        raise NotImplementedError()


@dataclass
class Wait(Animation):
    duration: int

    def get_attributes(self):
        return {
            "duration": str(self.duration),
        }


@dataclass
class SetRaster(Animation):
    raster: int

    def get_attributes(self):
        return {
            "raster": f"{self.raster:X}",
        }


@dataclass
class SetPalette(Animation):
    palette: int

    def get_attributes(self):
        return {
            "palette": f"{self.palette:X}",
        }


@dataclass
class Goto(Animation):
    pos: int

    def get_attributes(self):
        return {
            "pos": str(self.pos),
        }


@dataclass
class Loop(Animation):
    count: int
    pos: int

    def get_attributes(self):
        return {
            "count": str(self.count),
            "pos": str(self.pos),
        }


@dataclass
class SetPos(Animation):
    flag: int
    x: int
    y: int
    z: int

    def get_attributes(self):
        return {
            "flag": str(self.flag),
            "xyz": f"{self.x},{self.y},{self.z}",
        }


@dataclass
class SetRot(Animation):
    x: int
    y: int
    z: int

    def get_attributes(self):
        return {
            "xyz": f"{self.x},{self.y},{self.z}",
        }


SCALE_MODE_INT_TO_STR = {
    0: "uniform",
    1: "x",
    2: "y",
    3: "z",
}
SCALE_MODE_STR_TO_INT = {v: k for k, v in SCALE_MODE_INT_TO_STR.items()}


@dataclass
class SetScale(Animation):
    mode: int
    percent: int

    def get_mode_str(self):
        if self.mode in SCALE_MODE_INT_TO_STR:
            return SCALE_MODE_INT_TO_STR[self.mode]
        else:
            raise ValueError(f"invalid scale mode {self.mode}")

    def get_attributes(self):
        return {
            "mode": self.get_mode_str(),
            "percent": str(self.percent),
        }


@dataclass
class Unknown(Animation):
    v: int

    def get_attributes(self):
        return {
            "v": str(self.v),
        }


@dataclass
class SetParent(Animation):
    component_index: int

    def get_attributes(self):
        return {
            "component_index": str(self.component_index),
        }


@dataclass
class SetNotify(Animation):
    v: int

    def get_attributes(self):
        return {
            "v": str(self.v),
        }


@dataclass
class Keyframe(Animation):
    pass


@dataclass
class AnimComponent:
    x: int
    y: int
    z: int
    commands: List[int]

    @property
    def size(self):
        return len(self.commands)

    @staticmethod
    def parse_commands(command_list: List[int]) -> List[Animation]:
        ret: List[Animation] = []

        def to_signed(value):
            return -(value & 0x8000) | (value & 0x7FFF)

        i = 0
        while i < len(command_list):
            cmd_start = command_list[i]

            if cmd_start <= 0xFFF:
                ret.append(Wait(cmd_start))
            elif cmd_start <= 0x1FFF:
                raster = cmd_start % 0x1000
                if raster == 0xFFF:
                    raster = -1
                ret.append(SetRaster(raster))
            elif cmd_start <= 0x2FFF:
                ret.append(Goto(cmd_start % 0x2000))
            elif cmd_start <= 0x3FFF:
                flag = cmd_start % 0x3000
                x, y, z = command_list[i + 1 : i + 4]
                x = to_signed(x)
                y = to_signed(y)
                z = to_signed(z)
                i += 3
                ret.append(SetPos(flag, x, y, z))
            elif cmd_start <= 0x4FFF:
                x, y, z = command_list[i : i + 3]
                x = ((x % 0x4000) << 20) >> 20
                y = to_signed(y)
                z = to_signed(z)
                i += 2
                ret.append(SetRot(x, y, z))
            elif cmd_start <= 0x5FFF:
                mode = cmd_start % 0x5000
                percent = command_list[i + 1]
                i += 1
                ret.append(SetScale(mode, percent))
            elif cmd_start <= 0x6FFF:
                palette = cmd_start % 0x6000
                if palette == 0xFFF:
                    palette = -1
                ret.append(SetPalette(palette))
            elif cmd_start <= 0x7FFF:
                count = cmd_start % 0x7000
                pos = command_list[i + 1]
                i += 1
                ret.append(Loop(count, pos))
            elif cmd_start <= 0x80FF:
                ret.append(Unknown(cmd_start % 0x8000))
            elif cmd_start <= 0x81FF:
                ret.append(SetParent(cmd_start % 0x8100))
            elif cmd_start <= 0x82FF:
                ret.append(SetNotify(cmd_start % 0x8200))
            else:
                raise Exception("Unknown command")
            i += 1
        return ret

    @staticmethod
    def from_bytes(data: bytes, sprite_data: bytes):
        commands_offset = int.from_bytes(data[0:4], byteorder="big")
        commands_size = int.from_bytes(data[4:6], byteorder="big")  # size in bytes
        commands_data = sprite_data[commands_offset : commands_offset + commands_size]

        x, y, z = struct.unpack(">hhh", data[6:12])

        commands = [
            int.from_bytes(d[0:2], byteorder="big", signed=False)
            for d in iter_in_groups(commands_data, 2)
        ]
        return AnimComponent(x, y, z, commands)

    @property
    def animations(self) -> List[Animation]:
        return AnimComponent.parse_commands(self.commands)

    @staticmethod
    def from_xml(xml: ET.Element):
        commands: List[int] = []
        for cmd in xml:
            if cmd.tag == "Wait":
                duration = int(cmd.attrib["duration"])
                commands.append(duration)
            elif cmd.tag == "SetRaster":
                raster = int(cmd.attrib["raster"], 0x10)
                if raster == -1:
                    raster = 0xFFF
                commands.append(0x1000 + raster)
            elif cmd.tag == "Goto":
                commands.append(0x2000 + int(cmd.attrib["pos"]))
            elif cmd.tag == "SetPos":
                flag = int(cmd.attrib["flag"])
                x, y, z = cmd.attrib["xyz"].split(",")
                commands.append(0x3000 + flag)
                commands.append(int(x) & 0xFFFF)
                commands.append(int(y) & 0xFFFF)
                commands.append(int(z) & 0xFFFF)
            elif cmd.tag == "SetRot":
                x, y, z = cmd.attrib["xyz"].split(",")
                commands.append(0x4000 + (int(x) & 0xFFFF))
                commands.append(int(y) & 0xFFFF)
                commands.append(int(z) & 0xFFFF)
            elif cmd.tag == "SetScale":
                mode = SCALE_MODE_STR_TO_INT[cmd.attrib["mode"]]
                percent = int(cmd.attrib["percent"])
                commands.append(0x5000 + mode)
                commands.append(percent)
            elif cmd.tag == "SetPalette":
                palette = int(cmd.attrib["palette"], 0x10)
                if palette == -1:
                    palette = 0xFFF
                commands.append(0x6000 + palette)
            elif cmd.tag == "Loop":
                count = int(cmd.attrib["count"])
                pos = int(cmd.attrib["pos"])
                commands.append(0x7000 + count)
                commands.append(pos)
            elif cmd.tag == "Unknown":
                commands.append(0x8000 + int(cmd.attrib["v"]))
            elif cmd.tag == "SetParent":
                commands.append(0x8100 + int(cmd.attrib["component_index"]))
            elif cmd.tag == "SetNotify":
                commands.append(0x8200 + int(cmd.attrib["v"]))
            else:
                raise ValueError(f"unknown command {cmd.tag}")
        x, y, z = xml.attrib["xyz"].split(",")
        return AnimComponent(int(x), int(y), int(z), commands)
