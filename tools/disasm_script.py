#! /usr/bin/python3

import sys

_star_rod_lib = None
def star_rod_lib():
    global _star_rod_lib

    if not _star_rod_lib:
        _star_rod_lib = {}

        from pathlib import Path
        from os import path
        import re

        LIB_LINE_RE = re.compile(r"\s+:\s+")
        NAME_RE = re.compile(r"({[^}]*})?\s*([a-zA-Z0-9_]+)")

        for filename in Path(path.dirname(__file__), "star-rod", "database").rglob("*.lib"):
            with open(filename, "r") as file:
                for line in file.readlines():
                    parts = LIB_LINE_RE.split(line)

                    if len(parts) >= 3:
                        try:
                            kind = parts[0]
                            vaddr = int(parts[1].split(", ")[0], 16)
                            if name := NAME_RE.match(parts[2]):
                                name = name.group(2)

                                _star_rod_lib[vaddr] = name

                                """
                                if "map" in str(filename):
                                    if kind == "api":
                                        print(f"ApiStatus {name}(ScriptInstance* script, s32 isInitialCall);")
                                    elif kind == "scr":
                                        print(f"extern Bytecode {name}[];")
                                """
                        except:
                            pass

    return _star_rod_lib

def addr_ref(addr):
    func_name = star_rod_lib().get(addr)
    if func_name:
        func_name = "&" + func_name
    else:
        func_name = f"0x{addr:08X}"
    return func_name

def disassemble(bytes, indent = 0):
    out = ""
    prefix = ""

    indent += 1
    indent_used = False

    def write_line(line):
        nonlocal out, indent, indent_used
        if indent < 0: indent = 0
        if indent > 1: indent_used = True
        out += "    " * indent
        out += line
        out += "\n"
    def prefix_line(line):
        nonlocal prefix
        prefix += line
        prefix += "\n"

    def var(arg):
        v = arg - 2**32 # convert to s32
        if v > -250000000:
            if v <= -220000000: return f"SI_FIXED({(v + 230000000) / 1024}f)"
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
        elif ((arg & 0xFF000000) == 0x80000000) or arg > 10000:
            return f"0x{arg:X}"
        else:
            return f"{arg}"

    def trigger(trigger):
        if trigger == 0x00000080: trigger = "TriggerFlag_FLOOR_TOUCH"
        if trigger == 0x00800000: trigger = "TriggerFlag_FLOOR_ABOVE"
        if trigger == 0x00000800: trigger = "TriggerFlag_FLOOR_INTERACT"
        if trigger == 0x00000200: trigger = "TriggerFlag_FLOOR_JUMP"
        if trigger == 0x00000400: trigger = "TriggerFlag_WALL_TOUCH"
        if trigger == 0x00000040: trigger = "TriggerFlag_WALL_PUSH"
        if trigger == 0x00000100: trigger = "TriggerFlag_WALL_INTERACT"
        if trigger == 0x00001000: trigger = "TriggerFlag_WALL_HAMMER"
        if trigger == 0x00040000: trigger = "TriggerFlag_CEILING_TOUCH"
        if trigger == 0x00010000: trigger = "TriggerFlag_SAVE_FLAG_SET"
        if trigger == 0x00020000: trigger = "TriggerFlag_AREA_FLAG_SET"
        if trigger == 0x00100000: trigger = "TriggerFlag_BOMB"
        return trigger

    def read_word():
        return int.from_bytes(bytes.read(4), byteorder="big")

    while True:
        opcode = read_word()
        argc = read_word()
        argv = []
        for i in range(0, argc):
            argv.append(read_word())

        if opcode == 0x01:
            write_line("SI_END(),")
            indent -= 1

            if indent_used:
                prefix_line("Bytecode script[] = { // *INDENT-OFF*")
                write_line("}; // *INDENT-ON*")
            else:
                prefix_line("Bytecode script[] = {")
                write_line("};")

            return prefix + out
        elif opcode == 0x02: write_line(f"SI_RETURN(),")
        elif opcode == 0x03: write_line(f"SI_LABEL({var(argv[0])}),")
        elif opcode == 0x04: write_line(f"SI_GOTO({var(argv[0])}),")
        elif opcode == 0x05:
            write_line(f"SI_LOOP({var(argv[0])}),")
            indent += 1
        elif opcode == 0x06:
            indent -= 1
            write_line("SI_END_LOOP(),")
        elif opcode == 0x07: write_line(f"SI_BREAK_LOOP(),")
        elif opcode == 0x08: write_line(f"SI_WAIT_FRAMES({var(argv[0])}),")
        elif opcode == 0x09: write_line(f"SI_WAIT_SECS({var(argv[0])}),")
        elif opcode == 0x0A:
            write_line(f"SI_IF_EQ({var(argv[0])}, {var(argv[1])}),")
            indent += 1
        elif opcode == 0x0B:
            write_line(f"SI_IF_NE({var(argv[0])}, {var(argv[1])}),")
            indent += 1
        elif opcode == 0x0C:
            write_line(f"SI_IF_LT({var(argv[0])}, {var(argv[1])}),")
            indent += 1
        elif opcode == 0x0D:
            write_line(f"SI_IF_GT({var(argv[0])}, {var(argv[1])}),")
            indent += 1
        elif opcode == 0x0E:
            write_line(f"SI_IF_LE({var(argv[0])}, {var(argv[1])}),")
            indent += 1
        elif opcode == 0x0F:
            write_line(f"SI_IF_GE({var(argv[0])}, {var(argv[1])}),")
            indent += 1
        elif opcode == 0x10:
            write_line(f"SI_IF_BITS_ON({var(argv[0])}, {var(argv[1])}),")
            indent += 1
        elif opcode == 0x11:
            write_line(f"SI_IF_BITS_OFF({var(argv[0])}, {var(argv[1])}),")
            indent += 1
        elif opcode == 0x12: write_line(f"SI_ELSE(),")
        elif opcode == 0x13:
            indent -= 1
            write_line(f"SI_END_IF(),")
        elif opcode == 0x14:
            write_line(f"SI_SWITCH({var(argv[0])}),")
            indent += 1
        elif opcode == 0x15:
            write_line(f"SI_SWITCH_CONST(0x{argv[0]:X}),")
            indent += 2
        elif opcode == 0x16:
            indent -= 1
            write_line(f"SI_CASE_EQ({var(argv[0])}),")
            indent += 1
        elif opcode == 0x17:
            indent -= 1
            write_line(f"SI_CASE_NE({var(argv[0])}),")
            indent += 1
        elif opcode == 0x18:
            indent -= 1
            write_line(f"SI_CASE_LT({var(argv[0])}),")
            indent += 1
        elif opcode == 0x19:
            indent -= 1
            write_line(f"SI_CASE_GT({var(argv[0])}),")
            indent += 1
        elif opcode == 0x1A:
            indent -= 1
            write_line(f"SI_CASE_LE({var(argv[0])}),")
            indent += 1
        elif opcode == 0x1B:
            indent -= 1
            write_line(f"SI_CASE_GE({var(argv[0])}),")
            indent += 1
        elif opcode == 0x1C:
            indent -= 1
            write_line(f"SI_CASE_DEFAULT({var(argv[0])}),")
            indent += 1
        elif opcode == 0x1D:
            indent -= 1
            write_line(f"SI_CASE_OR_EQ({var(argv[0])}),")
            indent += 1
        # opcode 0x1E?
        elif opcode == 0x1F:
            indent -= 1
            write_line(f"SI_CASE_BITS_ON({var(argv[0])}),")
            indent += 1
        elif opcode == 0x20:
            indent -= 1
            write_line(f"SI_END_MULTI_CASE(),")
            indent += 1
        elif opcode == 0x21:
            indent -= 1
            write_line(f"SI_CASE_RANGE({var(argv[0])}, {var(argv[1])}),")
            indent += 1
        elif opcode == 0x22: write_line(f"SI_BREAK_CASE(),")
        elif opcode == 0x23:
            indent -= 2
            write_line(f"SI_END_SWITCH(),")
        elif opcode == 0x24: write_line(f"SI_SET({var(argv[0])}, {var(argv[1])}),")
        elif opcode == 0x25: write_line(f"SI_SET_CONST({var(argv[0])}, 0x{argv[1]:X}),")
        elif opcode == 0x26: write_line(f"SI_SET_F({var(argv[0])}, {var(argv[1])}),")
        elif opcode == 0x27: write_line(f"SI_ADD({var(argv[0])}, {var(argv[1])}),")
        elif opcode == 0x28: write_line(f"SI_SUB({var(argv[0])}, {var(argv[1])}),")
        elif opcode == 0x29: write_line(f"SI_MUL({var(argv[0])}, {var(argv[1])}),")
        elif opcode == 0x2A: write_line(f"SI_DIV({var(argv[0])}, {var(argv[1])}),")
        elif opcode == 0x2B: write_line(f"SI_MOD({var(argv[0])}, {var(argv[1])}),")
        elif opcode == 0x2C: write_line(f"SI_ADD_F({var(argv[0])}, {var(argv[1])}),")
        elif opcode == 0x2D: write_line(f"SI_SUB_F({var(argv[0])}, {var(argv[1])}),")
        elif opcode == 0x2E: write_line(f"SI_MUL_F({var(argv[0])}, {var(argv[1])}),")
        elif opcode == 0x2F: write_line(f"SI_DIV_F({var(argv[0])}, {var(argv[1])}),")
        elif opcode == 0x30: write_line(f"SI_USE_BUFFER({var(argv[0])}),")
        # TODO: SI_BUF commands
        elif opcode == 0x3C: write_line(f"SI_USE_ARRAY({var(argv[0])}),")
        elif opcode == 0x3D: write_line(f"SI_NEW_ARRAY({var(argv[0])}, {var(argv[1])}),")
        elif opcode == 0x3E: write_line(f"SI_USE_FLAGS({var(argv[0])}),")
        elif opcode == 0x3F: write_line(f"SI_AND({var(argv[0])}, {var(argv[1])}),")
        elif opcode == 0x40: write_line(f"SI_OR({var(argv[0])}, {var(argv[1])}),")
        elif opcode == 0x41: write_line(f"SI_AND_CONST({var(argv[0])}, 0x{argv[1]:X})")
        elif opcode == 0x42: write_line(f"SI_OR_CONST({var(argv[0])}, 0x{argv[1]:X})")
        elif opcode == 0x43:
            argv_str = ""
            for arg in argv[1:]:
                argv_str += ", "
                argv_str += var(arg)

            write_line(f"SI_CALL({addr_ref(argv[0])}{argv_str}),")
        elif opcode == 0x44: write_line(f"SI_EXEC({addr_ref(argv[0])}),")
        elif opcode == 0x45: write_line(f"SI_EXEC_GET_ID({addr_ref(argv[0])}, {var(argv[1])}),")
        elif opcode == 0x46: write_line(f"SI_EXEC_WAIT({addr_ref(argv[0])}),")
        elif opcode == 0x47:
            if argv[3] != 1:
                raise "BIND argv[3] != 1"

            write_line(f"SI_BIND({addr_ref(argv[0])}, {trigger(argv[1])}, {var(argv[2])}, {'NULL' if argv[4] == 0 else var(argv[4])}),")
        elif opcode == 0x48: write_line(f"SI_UNBIND_ME(),")
        elif opcode == 0x49: write_line(f"SI_KILL({var(argv[0])}),")
        elif opcode == 0x4A: write_line(f"SI_JUMP({var(argv[0])}),")
        elif opcode == 0x4B: write_line(f"SI_PRIORITY({var(argv[0])}),")
        elif opcode == 0x4C: write_line(f"SI_TIMESCALE({var(argv[0])}),")
        elif opcode == 0x4D: write_line(f"SI_GROUP({var(argv[0])}),")
        elif opcode == 0x4E:
            if argv[4] != 0:
                raise "BIND_PADLOCK argv[4] != NULL"
            if argv[5] != 0:
                raise "BIND_PADLOCK argv[5] != 1"

            write_line(f"SI_BIND_PADLOCK({addr_ref(argv[0])}, {trigger(argv[1])}, {var(argv[2])}, {var(argv[3])}),")
        elif opcode == 0x4F: write_line(f"SI_SUSPEND_GROUP({var(argv[0])}),")
        elif opcode == 0x50: write_line(f"SI_RESUME_GROUP({var(argv[0])}),")
        elif opcode == 0x51: write_line(f"SI_SUSPEND_GROUP_NOT_ME({var(argv[0])}),")
        elif opcode == 0x52: write_line(f"SI_RESUME_GROUP_NOT_ME({var(argv[0])}),")
        elif opcode == 0x53: write_line(f"SI_SUSPEND({var(argv[0])}),")
        elif opcode == 0x54: write_line(f"SI_RESUME({var(argv[0])}),")
        elif opcode == 0x55: write_line(f"SI_EXISTS({var(argv[0])}),")
        elif opcode == 0x56:
            write_line("SI_THREAD(),")
            indent += 1
        elif opcode == 0x57:
            indent -= 1
            write_line("SI_END_THREAD(),")
        elif opcode == 0x58:
            write_line("SI_CHILD_THREAD(),")
            indent += 1
        elif opcode == 0x59:
            indent -= 1
            write_line("SI_END_CHILD_THREAD(),")
        else:
            # unknown opcode
            argv_str = ""
            for arg in argv:
                argv_str += ", "
                argv_str += f"0x{arg:X}"
            write_line(f"SI_CMD(0x{opcode:02X}{argv_str}),")

    raise "Reached end of data before END command"

if __name__ == "__main__":
    if len(sys.argv) <= 1:
        print("usage: ./disasm_script.py <file> [offset]")
        exit()

    file = sys.argv[1]
    offset = eval(sys.argv[2]) if len(sys.argv) >= 3 else 0

    with open(file, "rb") as f:
        f.seek(offset)
        print(disassemble(f), end="")
