#!/usr/bin/env python3

from os import path
from glob import glob
import re

DIR = path.dirname(__file__)
SR_DATABASE = path.join(DIR, "star-rod/database")

# SR currently defines a struct with the "name" struct. This causes
# problems, so we'll call it the following instead.
STRUCT_STRUCT_ALIAS = "texture_header"

STRUCT_FILES = (
    # structs which need to be forward declared (because they're used
    # without indirection in other structs)
    glob(path.join(SR_DATABASE, f"structs/**/matrix4f.struct")) +
    glob(path.join(SR_DATABASE, f"structs/**/matrix4s.struct")) +
    glob(path.join(SR_DATABASE, f"structs/**/cam_pos_settings.struct")) +
    glob(path.join(SR_DATABASE, f"structs/**/partner_data.struct")) +
    glob(path.join(SR_DATABASE, f"structs/**/npc_blur_data.struct")) +

    # other structs
    glob(path.join(SR_DATABASE, f"structs/**/*.struct"))
)

def convert_type(type, structs):
    size = 1
    suffix = ""

    # replace basic types
    basic_types = [
        ("ubyte", "u8", 1),
        ("byte", "s8", 1),
        ("uchar", "u8", 1),
        ("char", "s8", 1),

        ("ushort", "u16", 2),
        ("short", "s16", 2),

        ("uint", "u32", 4),
        ("int", "s32", 4),

        ("ulong", "u64", 8),
        ("long", "s64", 8),

        ("float", "f32", 4),
        ("double", "f64", 8),

        ("ptr", "UNK_PTR", 4),

        ("struct", f"struct {STRUCT_STRUCT_ALIAS}", 0x30),
    ]
    for name, size in structs:
        basic_types.append((name, f"struct {name}", size))
    for sr_name, decomp_name, basic_size in basic_types:
        match = re.search(f"(\\b|^)({sr_name})(\\b|$)", type)
        if match:
            size = basic_size
            start, end = match.span(2)
            type = type[:start] + decomp_name + type[end:]
            break

    # array
    while array_match := re.search(r"\[(([0-9]+)`|([a-fA-F0-9]+))\]", type):
        bin_len_str = array_match.group(2)
        hex_len_str = array_match.group(3)

        array_len = int(bin_len_str) if bin_len_str else int(hex_len_str, 16)
        size *= array_len
        suffix += f"[{array_len}]"

        # strip match from type
        start, end = array_match.span()
        type = type[:start] + type[end:]

    # pointer
    if "*" in type:
        size = 4

    return type, size, suffix

# read struct names and their sizes in advance
structs = []
for filename in STRUCT_FILES:
    struct_name = path.splitext(path.basename(filename))[0]
    if struct_name == "struct":
        struct_name = STRUCT_STRUCT_ALIAS

    with open(filename) as file:
        for line in file.readlines():
            if line.startswith("%"):
                continue

            parts = [x.strip() for x in line.split(":")]
            if len(parts) == 0:
                continue

            if parts[0] == "size":
                struct_size = int(parts[1], 16)
                structs.append((struct_name, struct_size))
                continue

with open(path.join(DIR, f"../include/common_structs.h"), "w") as h:
    h.write(f"""#ifndef _COMMON_STRUCTS_H_
#define _COMMON_STRUCTS_H_

#include "ultra64.h"
#include "types.h"

""")
    # write all structs out to common_structs.h
    struct_names_seen = []
    for filename in STRUCT_FILES:
        struct_name = path.splitext(path.basename(filename))[0]
        struct_size = None
        offset_len = 2 # string length for hex offsets

        if struct_name == "struct":
            struct_name = STRUCT_STRUCT_ALIAS
        
        # avoid repeat declarations
        if struct_name.startswith("_") or struct_name.startswith("OS") or "." in struct_name or struct_name == "sprite":
            continue
        if struct_name in struct_names_seen:
            continue
        struct_names_seen.append(struct_name)

        h.write(f"typedef struct {struct_name} {{\n")

        with open(filename) as file:
            in_fields = False

            cur_offset = 0
            def update_offset(offset):
                global cur_offset
                delta = offset - cur_offset

                ofs_str = ("%X" % cur_offset).zfill(2)
                ofs_str_z = ofs_str.zfill(offset_len)

                # insert unknown char array
                if delta == 1:
                    h.write(f"    /* 0x{ofs_str_z} */ char unk_{ofs_str};\n")
                elif delta > 0:
                    h.write(f"    /* 0x{ofs_str_z} */ char unk_{ofs_str}[{delta}];\n")
                
                cur_offset += delta

            for line in file.readlines():
                # read and strip line comment
                comment = re.search(r"%(.*)$", line)
                if comment:
                    pos = comment.span()[0]
                    line = line[0:pos]
                    comment = comment.group(1).strip()

                parts = [x.strip() for x in line.split(":")]
                if len(parts) == 0:
                    continue

                if in_fields:
                    if parts[0] == "}":
                        in_fields = False
                    else:
                        offset, name, type = parts

                        # clean name
                        name = re.sub(r"[^a-zA-Z0-9_]", "", name)

                        offset = int(offset, 16)
                        ofs_str = ("%X" % offset).zfill(offset_len)
                        update_offset(offset)

                        if type == "code":
                            h.write(f"    /* 0x{ofs_str} */ UNK_FUN_PTR({name});")
                            cur_offset += 4
                        else:
                            type, size, suffix = convert_type(type, structs)

                            h.write(f"    /* 0x{ofs_str} */ {type} {name}{suffix};")
                            cur_offset += size
                        
                        if comment:
                            h.write(f" /* {comment} */")
                        h.write("\n")
                else:
                    if parts[0] == "size":
                        struct_size = int(parts[1], 16)
                        structs.append((struct_name, struct_size))
                        offset_len = max(2, len(parts[1]))
                    elif parts[0] == "{":
                        in_fields = True

        update_offset(struct_size)
        h.write(f"}} {struct_name}; // size = 0x{('%X' % struct_size).zfill(offset_len)}\n\n")

    h.write("#endif\n")