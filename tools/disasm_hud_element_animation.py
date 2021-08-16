#! /usr/bin/python3

import struct

def fmt_size(val):
    if val == 0:
        return 'HUD_ELEMENT_SIZE_8x8'
    elif val == 1:
        return 'HUD_ELEMENT_SIZE_16x16'
    elif val == 2:
        return 'HUD_ELEMENT_SIZE_24x24'
    elif val == 3:
        return 'HUD_ELEMENT_SIZE_32x32'
    elif val == 4:
        return 'HUD_ELEMENT_SIZE_48x48'
    elif val == 5:
        return 'HUD_ELEMENT_SIZE_64x64'
    elif val == 6:
        return 'HUD_ELEMENT_SIZE_8x16'
    elif val == 7:
        return 'HUD_ELEMENT_SIZE_16x8'
    elif val == 8:
        return 'HUD_ELEMENT_SIZE_16x24'
    elif val == 9:
        return 'HUD_ELEMENT_SIZE_16x32'
    elif val == 10:
        return 'HUD_ELEMENT_SIZE_64x32'
    elif val == 11:
        return 'HUD_ELEMENT_SIZE_32x16'
    elif val == 12:
        return 'HUD_ELEMENT_SIZE_12x12'
    elif val == 13:
        return 'HUD_ELEMENT_SIZE_48x24'
    elif val == 14:
        return 'HUD_ELEMENT_SIZE_32x8'
    elif val == 15:
        return 'HUD_ELEMENT_SIZE_24x8'
    elif val == 16:
        return 'HUD_ELEMENT_SIZE_64x16'
    elif val == 17:
        return 'HUD_ELEMENT_SIZE_16x64'
    elif val == 18:
        return 'HUD_ELEMENT_SIZE_192x32'
    elif val == 19:
        return 'HUD_ELEMENT_SIZE_40x40'
    elif val == 20:
        return 'HUD_ELEMENT_SIZE_24x16'
    elif val == 21:
        return 'HUD_ELEMENT_SIZE_32x40'
    elif val == 22:
        return 'HUD_ELEMENT_SIZE_40x16'
    elif val == 23:
        return 'HUD_ELEMENT_SIZE_40x24'
    elif val == 24:
        return 'HUD_ELEMENT_SIZE_32x24'
    else:
        return val

class HudElementScript():
    def __init__(self, symbol):
        self.symbol = symbol
        self.buffer = []

    def feed(self, word):
        self.buffer.append(word)

    def print(self):
        buf = iter(self.buffer)
        indent = "    "
        op = 99

        print(f"HudElementAnimation {self.symbol} = {{")

        while op:
            op = next(buf, -1)
            if op == -1:
                break

            if op == 0x00:
                print(f"{indent}he_End,")
            elif op == 0x01:
                print(f"{indent}he_SetRGBA({next(buf)}, {next(buf)}, {next(buf)}),")
            elif op == 0x02:
                print(f"{indent}he_SetCI({next(buf)}, {next(buf)}, {next(buf)}),")
            elif op == 0x03:
                indent = indent[4:]
                print(f"{indent}he_Restart,")
            elif op == 0x04:
                print(f"{indent}he_Loop,")
                indent = indent + "    "
            elif op == 0x05:
                print(f"{indent}he_SetTileSize({fmt_size(next(buf))}),")
            elif op == 0x06:
                print(f"{indent}he_SetSizesAutoScale({fmt_size(next(buf))}, {fmt_size(next(buf))}),")
            elif op == 0x07:
                print(f"{indent}he_SetSizesFixedScale({fmt_size(next(buf))}, {fmt_size(next(buf))}),")
            elif op == 0x08:
                print(f"{indent}he_SetVisible,")
            elif op == 0x09:
                print(f"{indent}he_SetHidden,")
            elif op == 0x0A:
                print(f"{indent}he_AddTexelOffsetX({next(buf)}),")
            elif op == 0x0B:
                print(f"{indent}he_AddTexelOffsetY({next(buf)}),")
            elif op == 0x0C:
                print(f"{indent}he_AddTexelOffset({next(buf)}, {next(buf)}),")
            elif op == 0x0D:
                print(f"{indent}he_SetImage({next(buf)}, {next(buf)}, {next(buf)}, {next(buf)}, {next(buf)}),")
            elif op == 0x0E:
                print(f"{indent}he_SetScale({next(buf)}),")
            elif op == 0x0F:
                print(f"{indent}he_SetAlpha({next(buf)}),")
            elif op == 0x10:
                print(f"{indent}he_RandomDelay({next(buf)}, {next(buf)}),")
            elif op == 0x11:
                print(f"{indent}he_Delete,")
            elif op == 0x12:
                print(f"{indent}he_UseIA8,")
            elif op == 0x13:
                print(f"{indent}he_SetCustomSize({next(buf)}, {next(buf)}),")
            elif op == 0x14:
                print(f"{indent}he_RandomRestart({next(buf)}, {next(buf)}),")
            elif op == 0x15:
                print(f"{indent}he_op_15({next(buf)}),")
            elif op == 0x17:
                count = next(buf)
                args = []
                for i in range(count):
                    args.append(next(buf))
                print(f"{indent}he_RandomBranch({', '.join(args)}),")
            elif op == 0x18:
                print(f"{indent}he_SetFlags({next(buf)}),")
            elif op == 0x19:
                print(f"{indent}he_ClearFlags({next(buf)}),")
            elif op == 0x1A:
                print(f"{indent}he_PlaySound({next(buf)}),")
            elif op == 0x1B:
                print(f"{indent}he_op_1B({next(buf)}),")
            else:
                print(f"{indent}{op},")

        print("};\n")

if __name__ == "__main__":
    import argparse

    parser = argparse.ArgumentParser()
    parser.add_argument("file", type=str, help=".data.s file to dissassemble")

    args = parser.parse_args()

    with open(args.file, "r") as f:
        lines = f.readlines()
        current_script = None

        for line in lines:
            line = line.strip()

            if line.startswith("glabel"):
                if current_script:
                    current_script.print()

                current_script = HudElementScript(line.split(" ")[1])
            elif line.startswith(".word"):
                words = line[6:].split(", ")

                for word in words:
                    try:
                        word = int(word, base=0)

                        if word > 0x8000000:
                            word = f"0x{word:X}"
                        else:
                            word, = struct.unpack(">i", struct.pack(">I", word))
                            print(word)
                    except ValueError:
                        pass

                    current_script.feed(word)

        if current_script:
            current_script.print()
