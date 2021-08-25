#!/usr/bin/python3

def get_variable(arg):
    v = arg - 2**32 # convert to s32
    if v > -250000000:
        if v <= -220000000: return f"SI_FIXED({(v + 230000000) / 1024})"
        elif v <= -200000000: return f"SI_ARRAY_FLAG({v + 210000000})"
        elif v <= -180000000: return f"SI_ARRAY({v + 190000000})"
        elif v <= -160000000: return f"SI_SAVE_VAR({v + 170000000})"
        elif v <= -140000000: return f"SI_AREA_VAR({v + 150000000})"
        elif v <= -120000000: return f"SI_SAVE_FLAG({v + 130000000})"
        elif v <= -100000000: return f"SI_AREA_FLAG({v + 110000000})"
        elif v <= -80000000: return f"SI_MAP_FLAG({v + 90000000})"
        elif v <= -60000000: return f"SI_FLAG({v + 70000000})"
        elif v <= -40000000: return f"SI_MAP_VAR({v + 50000000})"
        elif v <= -20000000: return f"SI_VAR({v + 30000000})"

    if arg == 0xFFFFFFFF:
        return "-1"
    elif (arg & 0xFF000000) == 0x80000000:
        return f"0x{arg:X}"
    elif arg >= 0x80000000:
        return f"{arg - 0x100000000}"
    else:
        return f"{arg}"

if __name__ == "__main__":
    import sys
    print(get_variable(int(sys.argv[1], 0)))
