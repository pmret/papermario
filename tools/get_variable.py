#!/usr/bin/env python3

import sys


def get_variable(arg):
    v = arg - 2**32  # convert to s32
    if v > -250000000:
        if v <= -220000000:
            return f"EVT_FLOAT({(v + 230000000) / 1024})"
        elif v <= -200000000:
            return f"ArrayFlag({v + 210000000})"
        elif v <= -180000000:
            return f"ArrayVar({v + 190000000})"
        elif v <= -160000000:
            return f"GameByte({v + 170000000})"
        elif v <= -140000000:
            return f"AreaByte({v + 150000000})"
        elif v <= -120000000:
            return f"GameFlag({v + 130000000})"
        elif v <= -100000000:
            return f"AreaFlag({v + 110000000})"
        elif v <= -80000000:
            return f"MapFlag({v + 90000000})"
        elif v <= -60000000:
            return f"LocalFlag({v + 70000000})"
        elif v <= -40000000:
            return f"MapVar({v + 50000000})"
        elif v <= -20000000:
            return f"LocalVar({v + 30000000})"

    if arg == 0xFFFFFFFF:
        return "-1"
    elif (arg & 0xFF000000) == 0x80000000:
        return f"0x{arg:X}"
    elif arg >= 0x80000000:
        return f"{arg - 0x100000000}"
    else:
        return f"{arg}"


if __name__ == "__main__":
    try:
        print(get_variable(int(sys.argv[1], 0)))
    except:
        print("Invalid literal for numeric operation. Please input a hex/dec number.")
