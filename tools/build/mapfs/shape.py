import argparse
from pathlib import Path
import struct
from abc import ABC
from collections import deque
from io import TextIOWrapper
from typing import List, Dict, Optional

BASE_ADDR = 0x80210000

NODE_TYPE_ROOT = 7
NODE_TYPE_MODEL = 2
NODE_TYPE_GROUP = 5
NODE_TYPE_SPECIAL_GROUP = 10

GFX_LOAD_VTX = 0x01
GFX_DRAW_TRI = 0x05
GFX_DRAW_TRIS = 0x06
GFX_RDP_PIPE_SYNC = 0xE7
GFX_POP_MATRIX = 0xD8
GFX_GEOMETRYMODE = 0xD9
GFX_LOAD_MATRIX = 0xDA
GFX_START_DL = 0xDE
GFX_END_DL = 0xDF

ALIGN_16 = "__attribute__ ((aligned (16))) "


def read_ascii_string(bytes: bytearray, addr: int) -> str:
    start = addr - BASE_ADDR
    length = 0

    for char in bytes[start:]:
        if char == 0:
            break
        length += 1

    return bytes[start : start + length].decode("ascii")


def get_shape_type_name(id: int) -> str:
    if id == NODE_TYPE_ROOT:
        return "SHAPE_TYPE_ROOT"
    elif id == NODE_TYPE_MODEL:
        return "SHAPE_TYPE_MODEL"
    elif id == NODE_TYPE_GROUP:
        return "SHAPE_TYPE_GROUP"
    elif id == NODE_TYPE_SPECIAL_GROUP:
        return "SHAPE_TYPE_SPECIAL_GROUP"
    raise Exception(f"Unknown shape type {id}")


class Segment(ABC):
    def __init__(self, addr: int, name: str):
        self.addr = addr
        self.name = name
        self.count = 0
        self.model_name = ""

    def get_sym(self) -> str:
        if self.model_name != "":
            return f"N({self.name}_{self.model_name})"
        else:
            return f"N({self.name})"

    def __str__(self):
        return str(self.__class__.__name__[:-7]) + " " + self.get_sym()

    def scan(self, shape):
        pass

    def print(self, shape):
        shape.print(hex(self.addr) + " : " + str(self))


class HeaderSegment(Segment):
    def __init__(self, addr: int, name: str):
        super().__init__(addr, name)

    def scan(self, shape):
        start = self.addr - BASE_ADDR
        (
            self.ptr_root_node,
            self.ptr_vtx_table,
            self.ptr_model_names,
            self.ptr_collider_names,
            self.ptr_zone_names,
        ) = struct.unpack(">IIIII", shape.file_bytes[start : start + 20])

        # note: do not push model root yet
        shape.root_node = NodeSegment(self.ptr_root_node, "Node")

        shape.vtx_table = shape.push(VertexTableSegment(self.ptr_vtx_table, "VertexTable"))
        shape.model_names = shape.push(StringListSegment(self.ptr_model_names, "ModelNames"))
        shape.collider_names = shape.push(StringListSegment(self.ptr_collider_names, "ColliderNames"))
        shape.zone_names = shape.push(StringListSegment(self.ptr_zone_names, "ZoneNames"))

    def print(self, shape):
        shape.print(f"ShapeFileHeader {self.get_sym()} = {{")
        shape.print(f"    .root = &{shape.get_symbol(self.ptr_root_node)},")
        shape.print(f"    .vertexTable = {shape.get_symbol(self.ptr_vtx_table)},")
        shape.print(f"    .modelNames = {shape.get_symbol(self.ptr_model_names)},")
        shape.print(f"    .colliderNames = {shape.get_symbol(self.ptr_collider_names)},")
        if self.ptr_zone_names != 0:
            shape.print(f"    .zoneNames = {shape.get_symbol(self.ptr_zone_names)},")
        shape.print("};")


class VertexTableSegment(Segment):
    def __init__(self, addr: int, name: str):
        super().__init__(addr, name)

    def print(self, shape):
        pos = self.addr - BASE_ADDR
        shape.print(f"Vtx_t {self.get_sym()}[] = {{")

        for idx in range(self.count):
            (
                x,
                y,
                z,
                flag,
                u,
                v,
                r,
                g,
                b,
                a,
            ) = struct.unpack(">hhhhhhBBBB", shape.file_bytes[pos : pos + 16])
            pos += 16

            shape.print(
                f"    {{{{ {x:4}, {y:4}, {z:4} }}, {flag}, {{ {u:6}, {v:6} }}, {{ {r:3}, {g:3}, {b:3}, {a:3} }}}},"
            )

        shape.print("};")


class VectorListSegment(Segment):
    def __init__(self, addr: int, name: str):
        super().__init__(addr, name)

    def print(self, shape):
        next = shape.get_segment_after(self)

        pos = self.addr - BASE_ADDR
        end = next.addr - BASE_ADDR
        count = (end - pos) // 12

        shape.print(f"Vec3f {self.get_sym()}[] = {{")

        for _ in range(count):
            (x, y, z) = struct.unpack(">fff", shape.file_bytes[pos : pos + 12])
            pos += 12

            shape.print(f"    {{ {x}, {y}, {z} }},")

        shape.print("};")


class StringListSegment(Segment):
    def __init__(self, addr: int, name: str):
        super().__init__(addr, name)
        self.list: deque

    def scan(self, shape):
        self.list = deque()
        pos = self.addr - BASE_ADDR
        while True:
            (ptr_str,) = struct.unpack(">I", shape.file_bytes[pos : pos + 4])
            pos += 4

            string = read_ascii_string(shape.file_bytes, ptr_str)

            if string == "db":
                break

            self.list.append(string)

    def print(self, shape):
        align_attribute = ""
        if self.name == "ModelNames":
            align_attribute = ALIGN_16

        shape.print(f"{align_attribute}char* {self.get_sym()}[] = {{")

        for name in self.list:
            shape.print(f'    "{name}",')
        shape.print('    "db",')
        shape.print("};")


class NodeSegment(Segment):
    def __init__(self, addr: int, name: str):
        super().__init__(addr, name)

    def scan(self, shape):
        pos = self.addr - BASE_ADDR
        (
            self.node_type,
            self.ptr_display_data,
            self.num_properties,
            self.ptr_property_list,
            self.ptr_group_data,
        ) = struct.unpack(">IIIII", shape.file_bytes[pos : pos + 20])

        self.model_name = shape.model_name_map[self.addr]
        shape.push(GroupDataSegment(self.ptr_group_data, "GroupData", self.model_name))
        shape.push(DisplayDataSegment(self.ptr_display_data, "DisplayData", self.model_name))
        shape.push(
            PropertyListSegment(
                self.ptr_property_list,
                "Properties",
                self.model_name,
                self.num_properties,
            )
        )

    def print(self, shape):
        shape.print(f"ModelNode {self.get_sym()} = {{")
        shape.print(f"    .type = {get_shape_type_name(self.node_type)},")
        if self.ptr_group_data != 0:
            shape.print(f"    .groupData = &{shape.get_symbol(self.ptr_group_data)},")
        shape.print(f"    .displayData = &{shape.get_symbol(self.ptr_display_data)},")
        shape.print(f"    .propertyList = {shape.get_symbol(self.ptr_property_list)},")
        shape.print(f"    .numProperties = {self.num_properties},")
        shape.print("};")


class NodeListSegment(Segment):
    def __init__(self, addr: int, name: str, model_name: str, num_children: int):
        super().__init__(addr, name)
        self.model_name = model_name
        self.count = num_children
        self.children: List[NodeSegment] = []

    def scan(self, shape):
        pos = self.addr - BASE_ADDR

        for _ in range(self.count):
            (ptr_child,) = struct.unpack(">I", shape.file_bytes[pos : pos + 4])
            pos += 4

            self.children.append(ptr_child)
            shape.push(NodeSegment(ptr_child, "Node"))

    def print(self, shape):
        shape.print(f"ModelNode* {self.get_sym()}[] = {{")

        for addr in self.children:
            shape.print(f"    &{shape.get_symbol(addr)},")
        shape.print("};")


class PropertyListSegment(Segment):
    def __init__(self, addr: int, name: str, model_name: str, count: int):
        super().__init__(addr, name)
        self.model_name = model_name
        self.count = count

    def print(self, shape):
        pos = self.addr - BASE_ADDR
        shape.print(f"ModelNodeProperty {self.get_sym()}[] = {{")

        for _ in range(self.count):
            (
                key,
                fmt,
                value,
            ) = struct.unpack(">III", shape.file_bytes[pos : pos + 12])
            pos += 12

            if key == 0x5E:
                if value == 0:
                    shape.print(f"    {{ .key = {hex(key)}, .dataType = {fmt}, .data = {{ .p = NULL }}}},")
                else:
                    tex_name = read_ascii_string(shape.file_bytes, value)
                    shape.print(f'    {{ .key = {hex(key)}, .dataType = {fmt}, .data = {{ .p = "{tex_name}" }}}},')
            elif key == 0x5F:
                shape.print(f"    {{ .key = {hex(key)}, .dataType = {fmt}, .data = {{ .s = {hex(value)} }}}},")
            else:
                if fmt == 0:  # int
                    shape.print(f"    {{ .key = {hex(key)}, .dataType = {fmt}, .data = {{ .s = {hex(value)} }}}},")
                elif fmt == 1:  # float
                    temp = struct.pack(">I", value)
                    (f,) = struct.unpack(">f", temp)
                    shape.print(f"    {{ .key = {hex(key)}, .dataType = {fmt}, .data = {{ .f = {f} }}}},")
                elif fmt == 2:  # pointer
                    shape.print(
                        f'    {{ .key = {hex(key)}, .dataType = {fmt}, .data = {{ .p = "{shape.get_symbol(value)}" }}}},'
                    )
                else:
                    raise Exception(f"Invalid property: 0x{key:08X} 0x{fmt:08X} 0x{value:08X}")

        shape.print("};")


class GroupDataSegment(Segment):
    def __init__(self, addr: int, name: str, model_name: str):
        super().__init__(addr, name)
        self.model_name = model_name

    def scan(self, shape):
        start = self.addr - BASE_ADDR
        (
            self.ptr_transform_mtx,
            self.ptr_lights,
            self.num_lights,
            self.num_children,
            self.ptr_children,
        ) = struct.unpack(">IIIII", shape.file_bytes[start : start + 20])

        shape.push(NodeListSegment(self.ptr_children, "Children", self.model_name, self.num_children))
        shape.push(LightSetSegment(self.ptr_lights, "Lights", self.model_name, self.num_lights))
        shape.push(MatrixSegment(self.ptr_transform_mtx, "Mtx", self.model_name))

    def print(self, shape):
        shape.print(f"ModelGroupData {self.get_sym()} = {{")
        if self.ptr_transform_mtx != 0:
            shape.print(f"    .transformMatrix = (Mtx*) &{shape.get_symbol(self.ptr_transform_mtx)},")
        shape.print(f"    .lightingGroup = (Lightsn*) &{shape.get_symbol(self.ptr_lights)},")
        shape.print(f"    .numLights = {self.num_lights},")
        shape.print(f"    .childList = {shape.get_symbol(self.ptr_children)},")
        shape.print(f"    .numChildren = {self.num_children},")
        shape.print("};")


class LightSetSegment(Segment):
    def __init__(self, addr: int, name: str, model_name: str, count: int):
        super().__init__(addr, name)
        self.model_name = model_name
        self.count = count

    def print(self, shape):
        next = shape.get_segment_after(self)
        pos = self.addr - BASE_ADDR
        end = next.addr - BASE_ADDR

        shape.print(f"// num: {self.count}")
        shape.print(f"s32 {self.get_sym()}[] = {{")
        while pos < end:
            (v,) = struct.unpack(">I", shape.file_bytes[pos : pos + 4])
            pos += 4
            shape.print(f"    0x{v:08X},")
        shape.print("};")


class MatrixSegment(Segment):
    def __init__(self, addr: int, name: str, model_name: str):
        super().__init__(addr, name)
        self.model_name = model_name

    def print(self, shape):
        pos = self.addr - BASE_ADDR
        shape.print(f"Matrix4s {self.get_sym()} = {{")

        shape.print("    .whole = {")
        for i in range(4):
            (a, b, c, d) = struct.unpack(">hhhh", shape.file_bytes[pos : pos + 8])
            pos += 8
            shape.print(f"        {{ {hex(a):4}, {hex(b):4}, {hex(c):4}, {hex(d):4} }},")
        shape.print("    },")

        shape.print("    .frac = {")
        for i in range(4):
            (a, b, c, d) = struct.unpack(">hhhh", shape.file_bytes[pos : pos + 8])
            pos += 8
            shape.print(f"        {{ {hex(a):4}, {hex(b):4}, {hex(c):4}, {hex(d):4} }},")
        shape.print("    },")

        shape.print("};")


class DisplayDataSegment(Segment):
    def __init__(self, addr: int, name: str, model_name: str):
        super().__init__(addr, name)
        self.model_name = model_name

    def scan(self, shape):
        start = self.addr - BASE_ADDR
        (self.ptr_display_list,) = struct.unpack(">I", shape.file_bytes[start : start + 4])

        gfx_segment = shape.push(DisplayListSegment(self.ptr_display_list, "Gfx", self.model_name))
        # Gfx segments may have been already visited during root Gfx traversal
        # so we will now force the associated model name to be the current model
        gfx_segment.model_name = self.model_name

    def print(self, shape):
        start = self.addr - BASE_ADDR
        shape.print(f"ModelDisplayData {self.get_sym()} = {{")
        shape.print(f"    .displayList = {shape.get_symbol(self.ptr_display_list)},")
        shape.print("};")


class DisplayListSegment(Segment):
    def __init__(self, addr: int, name: str, model_name: str):
        super().__init__(addr, name)
        self.model_name = model_name

    def scan(self, shape):
        pos = self.addr - BASE_ADDR
        while True:
            (w1, w2) = struct.unpack(">II", shape.file_bytes[pos : pos + 8])
            pos += 8

            op = w1 >> 24
            if op == GFX_END_DL:
                break
            elif op == GFX_START_DL:
                shape.push(DisplayListSegment(w2, f"Gfx_{hex(w2)[2:].upper()}", self.model_name))
            elif op == GFX_LOAD_MATRIX:
                shape.push(MatrixSegment(w2, f"Mtx_{hex(w2)[2:]}", model_name=self.model_name))
            elif op == GFX_LOAD_VTX:
                num = (w1 >> 12) & 0xFFF
                idx = (w2 - shape.vtx_table.addr) // 0x10
                if shape.vtx_table.count < idx + num:
                    shape.vtx_table.count = idx + num

    def get_geometry_flags(self, bits: int) -> str:
        flags = []

        if (bits & 0x00000400) != 0:
            flags.append("G_CULL_BACK")

        if (bits & 0x00020000) != 0:
            flags.append("G_LIGHTING")

        if (bits & 0x00200000) != 0:
            flags.append("G_SHADING_SMOOTH")

        return " | ".join(flags)

    def print(self, shape):
        pos = self.addr - BASE_ADDR
        shape.print(f"Gfx {self.get_sym()}[] = {{")
        while True:
            (w1, w2) = struct.unpack(">II", shape.file_bytes[pos : pos + 8])
            pos += 8

            op = w1 >> 24

            if op == GFX_LOAD_VTX:
                num = (w1 >> 12) & 0x00000FFF
                end = (w1 & 0x00000FFF) // 2
                buf_pos = end - num
                index = (w2 - shape.vtx_table.addr) // 0x10
                shape.print(f"    gsSPVertex(&{shape.vtx_table.get_sym()}[{index}], {num}, {buf_pos}),")
            elif op == GFX_DRAW_TRI:
                i = (w1 & 0x00FF0000) >> 16
                j = (w1 & 0x0000FF00) >> 8
                k = w1 & 0x000000FF
                shape.print(f"    gsSP1Triangle({i // 2}, {j // 2}, {k // 2}, 0),")
            elif op == GFX_DRAW_TRIS:
                a = (w1 & 0x00FF0000) >> 16
                b = (w1 & 0x0000FF00) >> 8
                c = w1 & 0x000000FF
                d = (w2 & 0x00FF0000) >> 16
                e = (w2 & 0x0000FF00) >> 8
                f = w2 & 0x000000FF
                shape.print(f"    gsSP2Triangles({a // 2}, {b // 2}, {c // 2}, 0, {d // 2}, {e // 2}, {f // 2}, 0),")
            elif op == GFX_RDP_PIPE_SYNC:
                shape.print("    gsDPPipeSync(),")
            elif op == GFX_POP_MATRIX:
                shape.print("    gsSPPopMatrix(G_MTX_MODELVIEW),")
            elif op == GFX_GEOMETRYMODE:
                if w1 == 0xD9FFFFFF:
                    flags = self.get_geometry_flags(w2)
                    shape.print(f"    gsSPSetGeometryMode({flags}),")
                else:
                    flags = self.get_geometry_flags(~(w1 | 0xFF000000))
                    shape.print(f"    gsSPClearGeometryMode({flags}),")
            elif op == GFX_LOAD_MATRIX:
                shape.print(f"    gsSPMatrix(&{shape.get_symbol(w2)}, G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW),")
            elif op == GFX_START_DL:
                shape.print(f"    gsSPDisplayList({shape.get_symbol(w2)}),")
            elif op == GFX_END_DL:
                shape.print("    gsSPEndDisplayList(),")
                break

        shape.print("};")

        if self.model_name == "root":
            next = shape.get_segment_after(self)
            end = next.addr - BASE_ADDR

            shape.print(f"\ns32 N(PostGfxPad)[] = {{")
            while pos < end:
                (v,) = struct.unpack(">I", shape.file_bytes[pos : pos + 4])
                pos += 4
                shape.print(f"    0x{v:08X},")
            shape.print("};")


class ShapeFile:
    def __init__(self, map_name: str, file_bytes: bytes):
        self.map_name = map_name
        self.file_bytes = file_bytes
        self.out_file: TextIOWrapper
        self.pending: List[Segment] = []
        self.visited: Dict[int, Segment] = {}
        self.model_name_map: Dict[int, str] = {}
        self.root_node: Optional[Segment] = None
        self.vtx_table: Optional[Segment] = None
        self.model_names: Optional[StringListSegment] = None
        self.collider_names: Optional[Segment] = None
        self.zone_names: Optional[Segment] = None

    def push(self, segment: Segment):
        if segment.addr == 0:
            return None

        if segment.addr in self.visited:
            return self.visited[segment.addr]

        self.pending.append(segment)
        self.visited[segment.addr] = segment
        return segment

    def get_symbol(self, addr) -> str:
        if not addr in self.visited:
            raise Exception(f"Encountered unknown pointer: {hex(addr)}")

        return self.visited[addr].get_sym()

    def print(self, string: str):
        if self.out_file != None:
            self.out_file.write(string + "\n")
        else:
            print(string)

    # traverse the model tree and create a mapping from addr -> name which we will use during the second scan pass
    def build_model_name_map(self, node_addr: int, names: deque):
        node_start = node_addr - BASE_ADDR
        (
            node_type,
            ptr_display_list,
            num_properties,
            ptr_property_list,
            ptr_group_data,
        ) = struct.unpack(">IIIII", self.file_bytes[node_start : node_start + 20])

        if node_type == NODE_TYPE_MODEL:
            # set name for this model node
            self.model_name_map[node_addr] = names.pop()
            return

        group_start = ptr_group_data - BASE_ADDR
        (
            ptr_transform_mtx,
            ptr_lights,
            num_lights,
            num_children,
            ptr_children,
        ) = struct.unpack(">IIIII", self.file_bytes[group_start : group_start + 20])

        child_start = ptr_children - BASE_ADDR

        for i in range(num_children):
            (ptr_child,) = struct.unpack(">I", self.file_bytes[child_start : child_start + 4])
            self.build_model_name_map(ptr_child, names)
            child_start += 4

        # set name for this group node
        if node_type == NODE_TYPE_ROOT:
            self.model_name_map[node_addr] = "root"
        else:
            self.model_name_map[node_addr] = names.pop()

    def print_prologue(self, segments):
        assert self.root_node is not None
        assert self.vtx_table is not None
        assert self.model_names is not None
        assert self.collider_names is not None

        self.print('#include "common.h"')
        self.print('#include "model.h"')
        self.print("")
        self.print(f"#define NAMESPACE {self.map_name}_shape")
        self.print("")
        self.print(f"extern ModelNode {self.root_node.get_sym()};")
        self.print(f"extern Vtx_t {self.vtx_table.get_sym()}[];")
        self.print(f"extern char* {self.model_names.get_sym()}[];")
        self.print(f"extern char* {self.collider_names.get_sym()}[];")

        if self.zone_names is not None:
            self.print(f"extern char* {self.zone_names.get_sym()}[];")
        for segment in segments:
            if isinstance(segment, MatrixSegment):
                self.print(f"extern Matrix4s {segment.get_sym()};")
        self.print("")

    def digest(self):
        # first pass just scans the header and string lists
        self.push(HeaderSegment(BASE_ADDR, "Header"))

        while len(self.pending) > 0:
            segment = self.pending.pop()
            segment.scan(self)

        assert self.model_names is not None
        assert self.root_node is not None

        # traverse the model tree to create initial name map
        model_names = deque(self.model_names.list)
        model_names.reverse()
        self.build_model_name_map(self.root_node.addr, model_names)

        # second pass scans the model tree and subordinate data structures
        self.push(self.root_node)
        self.push(VectorListSegment(self.root_node.addr + 0x14, "UnknownVectors"))

        while len(self.pending) > 0:
            segment = self.pending.pop()
            segment.scan(self)

        # create a sorted segment map
        segment_addrs = list(self.visited.keys())
        segment_addrs.sort()
        self.sorted_segments = {i: self.visited[i] for i in segment_addrs}

    def get_segment_after(self, seg: Segment) -> Optional[Segment]:
        keys = list(self.sorted_segments.keys())
        idx = keys.index(seg.addr)
        if idx + 1 < len(keys):
            next_addr = keys[idx + 1]
            ret = self.sorted_segments[next_addr]
        else:
            ret = None
        return ret

    def write_to_c(self, out_file):
        self.out_file = out_file
        self.print_prologue(self.sorted_segments.values())

        for addr, seg in self.sorted_segments.items():
            self.print(f"// {hex(seg.addr - BASE_ADDR)}")
            seg.print(self)
            self.print("")


def run(in_bin: Path, out: Path) -> None:
    map_name = "_".join(in_bin.stem.split("_")[:-1])

    with open(in_bin, "rb") as f:
        file_bytes = f.read()
        shape = ShapeFile(map_name, file_bytes)
        shape.digest()

        with open(out, "w") as out_file:
            shape.write_to_c(out_file)


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("in_bin", type=Path, help="input binary file")
    parser.add_argument("out_c", type=Path, help="output text file")
    args = parser.parse_args()

    run(args.in_bin, args.out_c)
