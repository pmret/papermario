#!/usr/bin/python3

import argparse
import sys
import re
import os

parser = argparse.ArgumentParser(description='Convert a StarRod enum into an enum that is in decomp format')
parser.add_argument("query", help="StarRod enum file")
parser.add_argument("--prefix", help="specify a prefix for the enum elements", type=str, required=False)

args = parser.parse_args()


def create_enum(file_content, prefix, ordering):
    ret = ""
    max_size = 0

    if ordering:
        for (key, value) in re.findall(r'(\S+)\s+=\s+(\S+)', file_content):
            if len(key) > max_size:
                max_size = len(key)
    else:
        for (key, value) in re.findall(r'(\S+)\s+=\s+(\S+)', file_content):
            if len(value) > max_size:
                max_size = len(value)

    if prefix is not None:
        max_size += len(prefix)
    else:
        prefix = ""

    for (key, value) in re.findall(r'(\S+)\s+=\s+(\S+)', file_content):
        if ordering:
            key = '_'.join(re.sub(r'([A-Z])', r' \1', key).split()).replace("H_P", "HP").replace("F_P", "FP").replace("J_P", "JP").replace("N_P_C", "NPC").replace("__", "_")
            key = prefix.upper() + '_{:<{width}}'.format(key, width=max_size + 2).upper()
            ret += "    " + key + " = 0x" + '{:>{fill}{width}}'.format(value, fill=0, width=8) + ",\n"
        else:
            value = '_'.join(re.sub(r'([A-Z])', r' \1', value).split()).replace("H_P", "HP").replace("F_P", "FP").replace("J_P", "JP").replace("N_P_C", "NPC").replace("__", "_")
            value = prefix.upper() + '_{:<{width}}'.format(value, width=max_size + 2).upper()
            ret += "    " + value + " = 0x" + '{:>{fill}{width}}'.format(key, fill=0, width=8) + ",\n"

    ret += "};\n"

    return ret


def main(args):
    ret = ""

    try:
        file = open(args.query)
        file_content = file.read()
    except:
        print("File not found at the given path.")
        return

    enum_name = re.search(r'(\w*)\s+%\s+library name', file_content).group(1)
    reversed_order = re.search(r'(\w*)\s+%\s+reversed', file_content).group(1)
    ret += "enum " + enum_name + " {\n"

    if reversed_order == "true":
        ret += create_enum(file_content, args.prefix, True)
    else:
        ret += create_enum(file_content, args.prefix, False)

    file = open("" + enum_name + ".txt", "w+")
    file.write(ret)
    file.close()


if __name__ == "__main__":
    main(parser.parse_args())
