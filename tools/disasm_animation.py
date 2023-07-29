#!/usr/bin/env python3

import struct


def read(f):
    return struct.unpack(">h", f.read(2))[0]


def i2f(x):
    return round(x * 180 / 32767 * 200) / 200


def parse(f):
    print("AnimScript script = {")
    indent = "    "
    while True:
        op = read(f)
        if op == 0:
            print(f"{indent}AS_END,")
            break
        if op == 1:
            print(f"{indent}AS_WAIT, {read(f)},")
        elif op == 3:
            indent = indent[:-4]
            print(f"{indent}AS_END_LOOP,")
        elif op == 5:
            print(
                f"{indent}AS_SET_ROTATION, {read(f)}, AS_F({i2f(read(f))}), AS_F({i2f(read(f))}), AS_F({i2f(read(f))}),"
            )
        elif op == 6:
            print(
                f"{indent}AS_ADD_ROTATION, {read(f)}, AS_F({i2f(read(f))}), AS_F({i2f(read(f))}), AS_F({i2f(read(f))}),"
            )
        elif op == 8:
            print(f"{indent}AS_SET_POS, {read(f)}, {read(f)}, {read(f)}, {read(f)},")
        elif op == 10:
            print(f"{indent}AS_LOOP,")
            indent += "    "
        elif op == 14:
            print(f"{indent}AS_SET_FLAGS, {read(f)},")
        elif op == 15:
            print(f"{indent}AS_SET_NODE_FLAGS, {read(f)}, {read(f)},")
        elif op == 16:
            print(f"{indent}AS_CLEAR_NODE_FLAGS, {read(f)}, {read(f)},")
        elif op == 17:
            print(f"{indent}AS_SET_SCALE, {read(f)}, AS_F({i2f(read(f))}), AS_F({i2f(read(f))}), AS_F({i2f(read(f))}),")
        elif op == 18:
            print(f"{indent}AS_SET_RENDER_MODE, {read(f)},")
        elif op == 19:
            print(f"{indent}AS_OP_19,")
        else:
            raise Exception(str(f"Unknown opcode {op}"))
    print("};")


if __name__ == "__main__":
    import argparse

    parser = argparse.ArgumentParser()
    parser.add_argument("file", type=str, help="File to dissassemble from")
    parser.add_argument("offset", help="Offset to start dissassembling from")
    args = parser.parse_args()
    offset = int(args.offset, 16)
    with open(args.file, "rb") as f:
        f.seek(offset)
        parse(f)
