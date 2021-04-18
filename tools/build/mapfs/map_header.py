#! /usr/bin/python3

from sys import argv, stderr
from os import path
from xml.dom.minidom import parse

def eprint(*args, **kwargs):
    print(*args, file=stderr, **kwargs)

if __name__ == "__main__":
    _, xml_path = argv
    xml = parse(xml_path)

    map_name = path.basename(xml_path)[:-4]

    print("#include \"common.h\"")
    print("#include \"map.h\"")
    print("")
    print("#ifndef NAMESPACE")
    print(f"#define NAMESPACE {map_name}")
    print("")

    seen_names = set()
    entrys = []
    npc_id = 0

    for marker in xml.getElementsByTagName("Marker"):
        marker_type = marker.getAttribute("type")
        if marker_type == "Root" or marker_type == "Group":
            continue

        map_object = marker.getElementsByTagName("MapObject")[0]
        name = marker_type + "_" + map_object.getAttribute("name")

        if name in seen_names:
            continue
        seen_names.add(name)

        x, y, z = [p for p in marker.getAttribute("pos").split(",")]
        yaw = marker.getAttribute("yaw") + "f"

        if marker_type == "NPC":
            npc_id += 1
            print(f"#define {name} {npc_id}")

        if marker_type == "Entry":
            entrys.append(name)

        print(f"#define {name}_x {x}")
        print(f"#define {name}_y {y}")
        print(f"#define {name}_z {z}")
        print(f"#define {name}_vec3d {x}, {y}, {z}")
        print(f"#define {name}_vec4d {x}, {y}, {z}, (((s32){yaw}))")
        print(f"#define {name}_vec3f {x}.0f, {y}.0f, {z}.0f")
        print(f"#define {name}_vec4f {x}.0f, {y}.0f, {z}.0f, {yaw}")
        print(f"#define {name}_yaw {yaw}")
        print("")

    for i, entry in enumerate(entrys):
        print(f"#define {entry} {i}")
    print(f"EntryList {map_name}_entryList = {{")
    for entry in entrys:
        print("    " + entry + "_vec4f,")
    print("};")

    print("")

    for collider in xml.getElementsByTagName("Collider"):
        map_object = collider.getElementsByTagName("MapObject")[0]
        name = map_object.getAttribute("name")
        idx = "0x" + map_object.getAttribute("id")

        if name in seen_names or " " in name:
            continue
        seen_names.add(name)

        print(f"#define Collider_{name} {idx}")

    print("")

    for model in xml.getElementsByTagName("Model"):
        map_object = model.getElementsByTagName("MapObject")[0]
        name = map_object.getAttribute("name")
        idx = "0x" + map_object.getAttribute("id")

        if name in seen_names or " " in name:
            continue
        seen_names.add(name)

        print(f"#define Model_{name} {idx}")

    print("")
    print("#endif")
    print("")

    for i, entry in enumerate(entrys):
        print(f"#define {map_name}_{entry[len('Entry_'):]} {i}")
