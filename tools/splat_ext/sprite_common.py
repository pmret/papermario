from dataclasses import dataclass, field
from itertools import zip_longest
import struct
from typing import Dict, List

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
            "raster": str(self.raster),
        }

@dataclass
class SetPalette(Animation):
    palette: int

    def get_attributes(self):
        return {
            "palette": str(self.palette),
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
            "x": str(self.x),
            "y": str(self.y),
            "z": str(self.z),
        }

@dataclass
class SetRot(Animation):
    x: int
    y: int
    z: int

    def get_attributes(self):
        return {
            "x": str(self.x),
            "y": str(self.y),
            "z": str(self.z),
        }

@dataclass
class SetScale(Animation):
    mode: int
    percent: int

    def get_attributes(self):
        return {
            "mode": str(self.mode),
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
    animations: List[Animation] = field(default_factory=list)

    @staticmethod
    def parse_commands(command_list: List[int]) -> List[Animation]:
        ret: List[Animation] = []

        def to_signed(value):
            return -(value & 0x8000) | (value & 0x7fff)

        i = 0
        while i < len(command_list):
            cmd_start = command_list[i]

            if cmd_start <= 0xFFF:
                ret.append(Wait(cmd_start))
            elif cmd_start <= 0x1FFF:
                raster = cmd_start % 1000
                if raster == 0xFFF:
                    raster = -1
                ret.append(SetRaster(raster))
            elif cmd_start <= 0x2FFF:
                ret.append(Goto(cmd_start % 2000))
            elif cmd_start <= 0x3FFF:
                flag = cmd_start % 3000
                x, y, z = command_list[i+1:i+4]
                x = to_signed(x)
                y = to_signed(y)
                z = to_signed(z)
                i += 3
                ret.append(SetPos(flag, x, y, z))
            elif cmd_start <= 0x4FFF:
                x, y, z = command_list[i+1:i+4]
                x = to_signed(x)
                y = to_signed(y)
                z = to_signed(z)
                i += 2
                ret.append(SetRot(x, y, z))
            elif cmd_start <= 0x5FFF:
                mode = cmd_start % 5000
                percent = command_list[i+1]
                i += 1
                ret.append(SetScale(mode, percent))
            elif cmd_start <= 0x6FFF:
                palette = cmd_start % 6000
                if palette == 0xFFF:
                    palette = -1
                ret.append(SetPalette(palette))
            elif cmd_start <= 0x7FFF:
                count = cmd_start % 7000
                pos = command_list[i+1]
                i += 1
                ret.append(Loop(count, pos))
            elif cmd_start <= 0x80FF:
                ret.append(Unknown(cmd_start % 8000))
            elif cmd_start <= 0x81FF:
                ret.append(SetParent(cmd_start % 8100))
            elif cmd_start <= 0x82FF:
                ret.append(SetNotify(cmd_start % 8200))
            else:
                raise Exception("Unknown command")
            i += 1
        return ret

    @staticmethod
    def from_bytes(data: bytes, sprite_data: bytes):
        commands_offset = int.from_bytes(data[0:4], byteorder="big")
        commands_size = int.from_bytes(data[4:6], byteorder="big") # size in bytes
        commands_data = sprite_data[commands_offset : commands_offset + commands_size]

        x, y, z = struct.unpack(">hhh", data[6:12])

        commands = [int.from_bytes(d[0:2], byteorder="big", signed=False) for d in iter_in_groups(commands_data, 2)]
        animations = AnimComponent.parse_commands(commands)

        return AnimComponent(x, y, z, commands, animations)

