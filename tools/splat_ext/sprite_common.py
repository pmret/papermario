from dataclasses import dataclass
from itertools import zip_longest
import struct
from typing import Dict, List
import xml.etree.ElementTree as ET
from enum import IntEnum


class CMD(IntEnum):
    WAIT = 0
    SET_IMG = 1
    GOTO = 2
    SET_POS = 3
    SET_ROT = 4
    SET_SCALE = 5
    SET_PAL = 6
    LOOP = 7
    SET_META = 8


XML_ATTR_NAME = "name"
XML_ATTR_INDEX = "index"
XML_ATTR_VALUE = "value"
XML_ATTR_DURATION = "duration"
XML_ATTR_DEST = "dest"
XML_ATTR_POS = "pos"
XML_ATTR_COUNT = "count"
XML_ATTR_MODE = "mode"
XML_ATTR_PCT = "percent"
XML_ATTR_XYZ = "xyz"
XML_ATTR_FLAG = "flag"


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
class Label(Animation):
    lbl_name: str

    def get_attributes(self):
        return {
            XML_ATTR_NAME: str(self.lbl_name),
        }


@dataclass
class Wait(Animation):
    duration: int

    def get_attributes(self):
        return {
            XML_ATTR_DURATION: str(self.duration),
        }


@dataclass
class SetRaster(Animation):
    raster: int

    def get_attributes(self):
        return {
            XML_ATTR_INDEX: f"{self.raster:X}",
        }


@dataclass
class SetPalette(Animation):
    palette: int

    def get_attributes(self):
        return {
            XML_ATTR_INDEX: f"{self.palette:X}",
        }


@dataclass
class Goto(Animation):
    dest: str
    pos: int

    def get_attributes(self):
        if self.pos != 0:
            return {
                XML_ATTR_POS: str(self.pos),
            }
        else:
            return {
                XML_ATTR_DEST: str(self.dest),
            }


@dataclass
class Loop(Animation):
    count: int
    dest: str
    pos: int

    def get_attributes(self):
        if self.pos != 0:
            return {
                XML_ATTR_COUNT: str(self.count),
                XML_ATTR_POS: str(self.pos),
            }
        else:
            return {
                XML_ATTR_COUNT: str(self.count),
                XML_ATTR_DEST: str(self.dest),
            }


@dataclass
class SetPos(Animation):
    flag: int
    x: int
    y: int
    z: int

    def get_attributes(self):
        return {
            XML_ATTR_FLAG: str(self.flag),
            XML_ATTR_XYZ: f"{self.x},{self.y},{self.z}",
        }


@dataclass
class SetRot(Animation):
    x: int
    y: int
    z: int

    def get_attributes(self):
        return {
            XML_ATTR_XYZ: f"{self.x},{self.y},{self.z}",
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
            XML_ATTR_MODE: self.get_mode_str(),
            XML_ATTR_PCT: str(self.percent),
        }


@dataclass
class Unknown(Animation):
    v: int

    def get_attributes(self):
        return {
            XML_ATTR_VALUE: str(self.v),
        }


@dataclass
class SetParent(Animation):
    index: int

    def get_attributes(self):
        return {
            XML_ATTR_INDEX: str(self.index),
        }


@dataclass
class SetNotify(Animation):
    v: int

    def get_attributes(self):
        return {
            XML_ATTR_VALUE: str(self.v),
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

        labels = {}
        boundaries = []
        labels[0] = "Start"
        i = 0
        while i < len(command_list):
            boundaries.append(i)
            cmd_start = command_list[i]
            cmd_op = cmd_start >> 12
            cmd_arg = cmd_start & 0xFFF

            if cmd_op == CMD.GOTO:
                dest = cmd_arg
                if dest in boundaries and dest not in labels:
                    labels[dest] = f"Pos_{dest}"
            elif cmd_op == CMD.SET_POS:
                i += 3
            elif cmd_op == CMD.SET_ROT:
                i += 2
            elif cmd_op == CMD.SET_SCALE:
                i += 1
            elif cmd_op == CMD.LOOP:
                dest = command_list[i + 1]
                if dest in boundaries and dest not in labels:
                    labels[dest] = f"Pos_{dest}"
                i += 1
            i += 1

        def to_signed(value):
            return -(value & 0x8000) | (value & 0x7FFF)

        i = 0
        while i < len(command_list):
            cmd_start = command_list[i]
            cmd_op = cmd_start >> 12
            cmd_arg = cmd_start & 0xFFF

            if i in labels:
                ret.append(Label(labels[i]))

            if cmd_op == CMD.WAIT:
                ret.append(Wait(cmd_start))
            elif cmd_op == CMD.SET_IMG:
                raster = cmd_arg
                if raster == 0xFFF:
                    raster = -1
                ret.append(SetRaster(raster))
            elif cmd_op == CMD.GOTO:
                dest = cmd_arg
                if dest in labels:
                    lbl_name = labels[dest]
                    ret.append(Goto(lbl_name, 0))
                else:
                    ret.append(Goto(None, dest))
            elif cmd_op == CMD.SET_POS:
                flag = cmd_arg
                x, y, z = command_list[i + 1 : i + 4]
                x = to_signed(x)
                y = to_signed(y)
                z = to_signed(z)
                i += 3
                ret.append(SetPos(flag, x, y, z))
            elif cmd_op == CMD.SET_ROT:
                x, y, z = command_list[i : i + 3]
                x = (cmd_arg << 20) >> 20
                y = to_signed(y)
                z = to_signed(z)
                i += 2
                ret.append(SetRot(x, y, z))
            elif cmd_op == CMD.SET_SCALE:
                mode = cmd_arg
                percent = command_list[i + 1]
                i += 1
                ret.append(SetScale(mode, percent))
            elif cmd_op == CMD.SET_PAL:
                palette = cmd_arg
                if palette == 0xFFF:
                    palette = -1
                ret.append(SetPalette(palette))
            elif cmd_op == CMD.LOOP:
                count = cmd_arg
                dest = command_list[i + 1]
                if dest in labels:
                    lbl_name = labels[dest]
                    ret.append(Loop(count, lbl_name, 0))
                else:
                    ret.append(Loop(count, None, dest))
                i += 1
            elif cmd_op == CMD.SET_META:
                if cmd_start <= 0x80FF:
                    ret.append(Unknown(cmd_arg & 0xFF))
                elif cmd_start <= 0x81FF:
                    ret.append(SetParent(cmd_arg & 0xFF))
                elif cmd_start <= 0x82FF:
                    ret.append(SetNotify(cmd_arg & 0xFF))
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

        commands = [int.from_bytes(d[0:2], byteorder="big", signed=False) for d in iter_in_groups(commands_data, 2)]
        return AnimComponent(x, y, z, commands)

    @property
    def animations(self) -> List[Animation]:
        return AnimComponent.parse_commands(self.commands)

    @staticmethod
    def from_xml(xml: ET.Element):
        commands: List[int] = []
        labels = {}
        for cmd in xml:
            if cmd.tag == "Label":
                idx = len(commands)
                labels[cmd.attrib[XML_ATTR_NAME]] = idx
            elif cmd.tag == "Wait":
                duration = int(cmd.attrib[XML_ATTR_DURATION])
                commands.append(duration & 0xFFF)
            elif cmd.tag == "SetRaster":
                raster = int(cmd.attrib[XML_ATTR_INDEX], 0x10)
                if raster == -1:
                    raster = 0xFFF
                commands.append(0x1000 + (raster & 0xFFF))
            elif cmd.tag == "Goto":
                if XML_ATTR_POS in cmd.attrib:
                    # support hardcoded positions for glitched animations
                    pos = int(cmd.attrib[XML_ATTR_POS])
                else:
                    # properly formatted animations will have labels
                    lbl_name = cmd.attrib[XML_ATTR_DEST]
                    if not lbl_name in labels:
                        raise Exception("Label missing for Goto dest: " + lbl_name)
                    pos = labels[lbl_name]
                commands.append(0x2000 + (pos & 0xFFF))
            elif cmd.tag == "SetPos":
                flag = int(cmd.attrib[XML_ATTR_FLAG], 0x10)
                x, y, z = cmd.attrib[XML_ATTR_XYZ].split(",")
                commands.append(0x3000 + (flag & 0xFFF))
                commands.append(int(x) & 0xFFFF)
                commands.append(int(y) & 0xFFFF)
                commands.append(int(z) & 0xFFFF)
            elif cmd.tag == "SetRot":
                x, y, z = cmd.attrib[XML_ATTR_XYZ].split(",")
                commands.append(0x4000 + (int(x) & 0xFFF))
                commands.append(int(y) & 0xFFFF)
                commands.append(int(z) & 0xFFFF)
            elif cmd.tag == "SetScale":
                mode = SCALE_MODE_STR_TO_INT[cmd.attrib[XML_ATTR_MODE]]
                percent = int(cmd.attrib[XML_ATTR_PCT])
                commands.append(0x5000 + mode)
                commands.append(percent)
            elif cmd.tag == "SetPalette":
                palette = int(cmd.attrib[XML_ATTR_INDEX], 0x10)
                if palette == -1:
                    palette = 0xFFF
                commands.append(0x6000 + (palette & 0xFFF))
            elif cmd.tag == "Loop":
                count = int(cmd.attrib[XML_ATTR_COUNT])
                if XML_ATTR_POS in cmd.attrib:
                    # support hardcoded positions for glitched animations
                    pos = int(cmd.attrib[XML_ATTR_POS])
                else:
                    # properly formatted animations will have labels
                    lbl_name = cmd.attrib[XML_ATTR_DEST]
                    if not lbl_name in labels:
                        raise Exception("Label missing for Loop dest: " + lbl_name)
                    pos = labels[lbl_name]
                commands.append(0x7000 + (count & 0xFFF))
                commands.append(pos)
            elif cmd.tag == "Unknown":
                commands.append(0x8000 + (int(cmd.attrib[XML_ATTR_VALUE]) & 0xFF))
            elif cmd.tag == "SetParent":
                commands.append(0x8100 + (int(cmd.attrib[XML_ATTR_INDEX]) & 0xFF))
            elif cmd.tag == "SetNotify":
                commands.append(0x8200 + (int(cmd.attrib[XML_ATTR_VALUE]) & 0xFF))
            else:
                raise ValueError(f"unknown command {cmd.tag}")
        x, y, z = xml.attrib[XML_ATTR_XYZ].split(",")
        return AnimComponent(int(x), int(y), int(z), commands)
