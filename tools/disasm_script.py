#! /usr/bin/python3

import sys

_script_lib = None
def script_lib(offset):
    global _script_lib

    if not _script_lib:
        _script_lib = {}

        from pathlib import Path
        from os import path
        import re

        # star rod database
        """
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

                                _script_lib[vaddr] = name
                        except:
                            pass
        """

        repo_root = Path(__file__).resolve().parent.parent
        symbols = Path(repo_root / "ver" / "current" / "symbol_addrs.txt")
        with open(symbols, "r") as file:
            for line in file.readlines():
                s = [s.strip() for s in line.split("=", 1)]
                name = s[0]
                vaddr = int(s[1].split(";")[0].split(" ")[0], 16)

                raddr = "0xFFFFFFFF"
                if "rom:" in line:
                    raddr = line.split("rom:",1)[1]
                    if " " in raddr:
                        raddr = raddr.split(" ",1)[0]
                raddr = raddr.strip()

                if vaddr not in _script_lib:
                    _script_lib[vaddr] = []
                _script_lib[vaddr].append([int(raddr, 16), name])

        # Sort the symbols for each vram address by the difference 
        # between their rom address and the offset passed in.
        # If offset - rom address goes below 0, it's part of the
        # previous file, so treat it as min priority, same as a default.
        # After sorting, the first rom address and name should be the best candidate.
        for k in _script_lib.keys():
            for i,entry in enumerate(_script_lib[k]):
                diff = offset - entry[0]
                entry[0] = 0xFFFFFFFF if diff < 0 else diff
                _script_lib[k][i][0] = entry[0]
            _script_lib[k] = sorted(_script_lib[k], key=lambda x: x[0])
    return _script_lib

class ScriptDisassembler:
    def __init__(self, bytes, script_name = "script", symbol_map = {}):
        self.bytes = bytes
        self.script_name = script_name

        self.symbol_map = { **script_lib(self.bytes.tell()), **symbol_map }

        self.out = ""
        self.prefix = ""

        self.indent = 1
        self.indent_used = False

        self.done = False

        self.start_pos = self.bytes.tell()
        self.end_pos = 0
        self.instructions = 0

    def disassemble(self):
        while True:
            opcode = self.read_word()
            argc = self.read_word()

            if opcode > 0xFF or argc > 0xFF:
                raise Exception(f"script '{self.script_name}' is malformed")

            argv = []
            for i in range(0, argc):
                argv.append(self.read_word())

            self.disassemble_command(opcode, argc, argv)

            self.instructions += 1

            if self.done:
                self.end_pos = self.bytes.tell()
                return self.prefix + self.out

    def write(self, line):
        if self.indent < 0: self.indent = 0
        if self.indent > 1: self.indent_used = True

        self.out += "    " * self.indent
        self.out += line

    def write_line(self, line):
        self.write(line)
        self.out += "\n"

    def prefix_line(self, line):
        self.prefix += line
        self.prefix += "\n"

    def var(self, arg):
        if arg in self.symbol_map:
            return self.symbol_map[arg][0][1]

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
        elif ((arg & 0xFF000000) == 0x80000000) or arg > 10000:
            return f"0x{arg:X}"
        else:
            return f"{arg}"

    def addr_ref(self, addr):
        if addr in self.symbol_map:
            return self.symbol_map[addr][0][1]
        return f"0x{addr:08X}"

    def trigger(self, trigger):
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
        return f"0x{trigger:X}" if type(trigger) is int else trigger

    def read_word(self):
        return int.from_bytes(self.bytes.read(4), byteorder="big")

    def disassemble_command(self, opcode, argc, argv):
        if opcode == 0x01:
            self.write_line("SI_CMD(ScriptOpcode_END)")
            self.indent -= 1

            if self.indent_used:
                self.prefix_line("// *INDENT-OFF*")
                self.prefix_line(f"Script {self.script_name} = {{")
                self.write_line("};")
                self.write_line("// *INDENT-ON*")
            else:
                self.prefix_line(f"Script {self.script_name} = {{")
                self.write_line("};")

            self.done = True
        elif opcode == 0x02: self.write_line(f"SI_CMD(ScriptOpcode_RETURN),")
        elif opcode == 0x03: self.write_line(f"SI_CMD(ScriptOpcode_LABEL, {self.var(argv[0])}),")
        elif opcode == 0x04: self.write_line(f"SI_CMD(ScriptOpcode_GOTO, {self.var(argv[0])}),")
        elif opcode == 0x05:
            self.write_line(f"SI_CMD(ScriptOpcode_LOOP, {self.var(argv[0])}),")
            self.indent += 1
        elif opcode == 0x06:
            self.indent -= 1
            self.write_line("SI_CMD(ScriptOpcode_END_LOOP),")
        elif opcode == 0x07: self.write_line(f"SI_CMD(ScriptOpcode_BREAK_LOOP),")
        elif opcode == 0x08: self.write_line(f"SI_CMD(ScriptOpcode_SLEEP_FRAMES, {self.var(argv[0])}),")
        elif opcode == 0x09: self.write_line(f"SI_CMD(ScriptOpcode_SLEEP_SECS, {self.var(argv[0])}),")
        elif opcode == 0x0A:
            self.write_line(f"SI_CMD(ScriptOpcode_IF_EQ, {self.var(argv[0])}, {self.var(argv[1])}),")
            self.indent += 1
        elif opcode == 0x0B:
            self.write_line(f"SI_CMD(ScriptOpcode_IF_NE, {self.var(argv[0])}, {self.var(argv[1])}),")
            self.indent += 1
        elif opcode == 0x0C:
            self.write_line(f"SI_CMD(ScriptOpcode_IF_LT, {self.var(argv[0])}, {self.var(argv[1])}),")
            self.indent += 1
        elif opcode == 0x0D:
            self.write_line(f"SI_CMD(ScriptOpcode_IF_GT, {self.var(argv[0])}, {self.var(argv[1])}),")
            self.indent += 1
        elif opcode == 0x0E:
            self.write_line(f"SI_CMD(ScriptOpcode_IF_LE, {self.var(argv[0])}, {self.var(argv[1])}),")
            self.indent += 1
        elif opcode == 0x0F:
            self.write_line(f"SI_CMD(ScriptOpcode_IF_GE, {self.var(argv[0])}, {self.var(argv[1])}),")
            self.indent += 1
        elif opcode == 0x10:
            self.write_line(f"SI_CMD(ScriptOpcode_IF_FLAG, {self.var(argv[0])}, {self.var(argv[1])}),")
            self.indent += 1
        elif opcode == 0x11:
            self.write_line(f"SI_CMD(ScriptOpcode_IF_NOT_FLAG, ({self.var(argv[0])}, {self.var(argv[1])}),")
            self.indent += 1
        elif opcode == 0x12:
            self.indent -= 1
            self.write_line(f"SI_CMD(ScriptOpcode_ELSE),")
            self.indent += 1
        elif opcode == 0x13:
            self.indent -= 1
            self.write_line(f"SI_CMD(ScriptOpcode_END_IF),")
        elif opcode == 0x14:
            self.write_line(f"SI_CMD(ScriptOpcode_MATCH, {self.var(argv[0])}),")
            self.indent += 2
        elif opcode == 0x15:
            self.write_line(f"SI_CMD(ScriptOpcode_MATCH_CONST, 0x{argv[0]:X}),")
            self.indent += 2
        elif opcode == 0x16:
            self.indent -= 1
            self.write_line(f"SI_CMD(ScriptOpcode_CASE_EQ, {self.var(argv[0])}),")
            self.indent += 1
        elif opcode == 0x17:
            self.indent -= 1
            self.write_line(f"SI_CMD(ScriptOpcode_CASE_NE, {self.var(argv[0])}),")
            self.indent += 1
        elif opcode == 0x18:
            self.indent -= 1
            self.write_line(f"SI_CMD(ScriptOpcode_CASE_LT, {self.var(argv[0])}),")
            self.indent += 1
        elif opcode == 0x19:
            self.indent -= 1
            self.write_line(f"SI_CMD(ScriptOpcode_CASE_GT, {self.var(argv[0])}),")
            self.indent += 1
        elif opcode == 0x1A:
            self.indent -= 1
            self.write_line(f"SI_CMD(ScriptOpcode_CASE_LE, {self.var(argv[0])}),")
            self.indent += 1
        elif opcode == 0x1B:
            self.indent -= 1
            self.write_line(f"SI_CMD(ScriptOpcode_CASE_GE, {self.var(argv[0])}),")
            self.indent += 1
        elif opcode == 0x1C:
            self.indent -= 1
            self.write_line(f"SI_CMD(ScriptOpcode_CASE_ELSE),")
            self.indent += 1
        elif opcode == 0x1D:
            self.indent -= 1
            self.write_line(f"SI_CMD(ScriptOpcode_CASE_MULTI_OR_EQ, {self.var(argv[0])}),")
            self.indent += 1
        elif opcode == 0x1E:
            self.indent -= 1
            self.write_line(f"SI_CMD(ScriptOpcode_CASE_MULTI_AND_EQ, {self.var(argv[0])}),")
            self.indent += 1
        elif opcode == 0x1F:
            self.indent -= 1
            self.write_line(f"SI_CMD(ScriptOpcode_CASE_FLAG, {self.var(argv[0])}),")
            self.indent += 1
        elif opcode == 0x20:
            self.indent -= 1
            self.write_line(f"SI_CMD(ScriptOpcode_END_CASE_MULTI),")
            self.indent += 1
        elif opcode == 0x21:
            self.indent -= 1
            self.write_line(f"SI_CMD(ScriptOpcode_CASE_RANGE, {self.var(argv[0])}, {self.var(argv[1])}),")
            self.indent += 1
        elif opcode == 0x22: self.write_line(f"SI_CMD(ScriptOpcode_BREAK_CASE),")
        elif opcode == 0x23:
            self.indent -= 2
            self.write_line(f"SI_CMD(ScriptOpcode_END_MATCH),")
        elif opcode == 0x24: self.write_line(f"SI_CMD(ScriptOpcode_SET, {self.var(argv[0])}, {self.var(argv[1])}),")
        elif opcode == 0x25: self.write_line(f"SI_CMD(ScriptOpcode_SET_CONST, {self.var(argv[0])}, 0x{argv[1]:X}),")
        elif opcode == 0x26: self.write_line(f"SI_CMD(ScriptOpcode_SET_F, {self.var(argv[0])}, {self.var(argv[1])}),")
        elif opcode == 0x27: self.write_line(f"SI_CMD(ScriptOpcode_ADD, {self.var(argv[0])}, {self.var(argv[1])}),")
        elif opcode == 0x28: self.write_line(f"SI_CMD(ScriptOpcode_SUB, {self.var(argv[0])}, {self.var(argv[1])}),")
        elif opcode == 0x29: self.write_line(f"SI_CMD(ScriptOpcode_MUL, {self.var(argv[0])}, {self.var(argv[1])}),")
        elif opcode == 0x2A: self.write_line(f"SI_CMD(ScriptOpcode_DIV, {self.var(argv[0])}, {self.var(argv[1])}),")
        elif opcode == 0x2B: self.write_line(f"SI_CMD(ScriptOpcode_MOD, {self.var(argv[0])}, {self.var(argv[1])}),")
        elif opcode == 0x2C: self.write_line(f"SI_CMD(ScriptOpcode_ADD_F, {self.var(argv[0])}, {self.var(argv[1])}),")
        elif opcode == 0x2D: self.write_line(f"SI_CMD(ScriptOpcode_SUB_F, {self.var(argv[0])}, {self.var(argv[1])}),")
        elif opcode == 0x2E: self.write_line(f"SI_CMD(ScriptOpcode_MUL_F, {self.var(argv[0])}, {self.var(argv[1])}),")
        elif opcode == 0x2F: self.write_line(f"SI_CMD(ScriptOpcode_DIV_F, {self.var(argv[0])}, {self.var(argv[1])}),")
        elif opcode == 0x30: self.write_line(f"SI_CMD(ScriptOpcode_USE_BUFFER, {self.var(argv[0])}),")
        elif opcode == 0x31:
            args = ["ScriptOpcode_BUFFER_READ_1",*map(self.var, argv)]
            self.write_line(f"SI_CMD({', '.join(args)}),")
        elif opcode == 0x32:
            args = ["ScriptOpcode_BUFFER_READ_2",*map(self.var, argv)]
            self.write_line(f"SI_CMD({', '.join(args)}),")
        elif opcode == 0x33:
            args = ["ScriptOpcode_BUFFER_READ_3",*map(self.var, argv)]
            self.write_line(f"SI_CMD({', '.join(args)}),")
        elif opcode == 0x34:
            args = ["ScriptOpcode_BUFFER_READ_4",*map(self.var, argv)]
            self.write_line(f"SI_CMD({', '.join(args)}),")
        elif opcode == 0x35:
            args = ["ScriptOpcode_BUFFER_PEEK",*map(self.var, argv)]
            self.write_line(f"SI_CMD({', '.join(args)}),")
        elif opcode == 0x36: self.write_line(f"SI_CMD(ScriptOpcode_USE_BUFFER_f, {self.var(argv[0])}),")
        elif opcode == 0x37:
            args = ["ScriptOpcode_BUFFER_READ_1_F",*map(self.var, argv)]
            self.write_line(f"SI_CMD({', '.join(args)}),")
        elif opcode == 0x38:
            args = ["ScriptOpcode_BUFFER_READ_2_F",*map(self.var, argv)]
            self.write_line(f"SI_CMD({', '.join(args)}),")
        elif opcode == 0x39:
            args = ["ScriptOpcode_BUFFER_READ_3_F",*map(self.var, argv)]
            self.write_line(f"SI_CMD({', '.join(args)}),")
        elif opcode == 0x3A:
            args = ["ScriptOpcode_BUFFER_READ_4_F",*map(self.var, argv)]
            self.write_line(f"SI_CMD({', '.join(args)}),")
        elif opcode == 0x3B:
            args = ["ScriptOpcode_BUFFER_PEEK_F",*map(self.var, argv)]
            self.write_line(f"SI_CMD({', '.join(args)}),")
        elif opcode == 0x3C: self.write_line(f"SI_CMD(ScriptOpcode_USE_ARRAY, {self.var(argv[0])}),")
        elif opcode == 0x3D: self.write_line(f"SI_CMD(ScriptOpcode_NEW_ARRAY, {self.var(argv[0])}, {self.var(argv[1])}),")
        elif opcode == 0x3E: self.write_line(f"SI_CMD(ScriptOpcode_USE_FLAGS, {self.var(argv[0])}),")
        elif opcode == 0x3F: self.write_line(f"SI_CMD(ScriptOpcode_AND, {self.var(argv[0])}, {self.var(argv[1])}),")
        elif opcode == 0x40: self.write_line(f"SI_CMD(ScriptOpcode_OR, {self.var(argv[0])}, {self.var(argv[1])}),")
        elif opcode == 0x41: self.write_line(f"SI_CMD(ScriptOpcode_AND_CONST, {self.var(argv[0])}, 0x{argv[1]:X})")
        elif opcode == 0x42: self.write_line(f"SI_CMD(ScriptOpcode_OR_CONST, {self.var(argv[0])}, 0x{argv[1]:X})")
        elif opcode == 0x43:
            args = ["ScriptOpcode_CALL", self.addr_ref(argv[0]), *map(self.var, argv[1:])]
            self.write_line(f"SI_CMD({', '.join(args)}),")
        elif opcode == 0x44: self.write_line(f"SI_CMD(ScriptOpcode_SPAWN, {self.addr_ref(argv[0])}),")
        elif opcode == 0x45: self.write_line(f"SI_CMD(ScriptOpcode_SPAWN_GET_ID, {self.addr_ref(argv[0])}, {self.var(argv[1])}),")
        elif opcode == 0x46: self.write_line(f"SI_CMD(ScriptOpcode_AWAIT_SCRIPT, {self.addr_ref(argv[0])}),")
        elif opcode == 0x47:
            args = ["ScriptOpcode_BIND_TRIGGER", self.addr_ref(argv[0]), self.trigger(argv[1]), *map(self.var, argv[2:])]
            self.write_line(f"SI_CMD({', '.join(args)}),")
        elif opcode == 0x48: self.write_line(f"SI_CMD(ScriptOpcode_UNBIND),")
        elif opcode == 0x49: self.write_line(f"SI_CMD(ScriptOpcode_KILL_SCRIPT, {self.var(argv[0])}),")
        elif opcode == 0x4A: self.write_line(f"SI_CMD(ScriptOpcode_JUMP, {self.var(argv[0])}),")
        elif opcode == 0x4B: self.write_line(f"SI_CMD(ScriptOpcode_SET_PRIORITY, {self.var(argv[0])}),")
        elif opcode == 0x4C: self.write_line(f"SI_CMD(ScriptOpcode_SET_TIMESCALE, {self.var(argv[0])}),")
        elif opcode == 0x4D: self.write_line(f"SI_CMD(ScriptOpcode_SET_GROUP, {self.var(argv[0])}),")
        elif opcode == 0x4E:
            args = ["ScriptOpcode_BIND_TRIGGER", self.addr_ref(argv[0]), self.trigger(argv[1]), *map(self.var, argv[2:])]
            self.write_line(f"SI_CMD({', '.join(args)}),")
        elif opcode == 0x4F: self.write_line(f"SI_CMD(ScriptOpcode_SUSPEND_GROUP, {self.var(argv[0])}),")
        elif opcode == 0x50: self.write_line(f"SI_CMD(ScriptOpcode_RESUME_GROUP, {self.var(argv[0])}),")
        elif opcode == 0x51: self.write_line(f"SI_CMD(ScriptOpcode_SUSPEND_OTHERS, {self.var(argv[0])}),")
        elif opcode == 0x52: self.write_line(f"SI_CMD(ScriptOpcode_RESUME_OTHERS, {self.var(argv[0])}),")
        elif opcode == 0x53: self.write_line(f"SI_CMD(ScriptOpcode_SUSPEND_SCRIPT, {self.var(argv[0])}),")
        elif opcode == 0x54: self.write_line(f"SI_CMD(ScriptOpcode_RESUME_SCRIPT, {self.var(argv[0])}),")
        elif opcode == 0x55: self.write_line(f"SI_CMD(ScriptOpcode_SCRIPT_EXISTS, {self.var(argv[0])}, {self.var(argv[1])}),")
        elif opcode == 0x56:
            self.write_line("SI_CMD(ScriptOpcode_SPAWN_THREAD),")
            self.indent += 1
        elif opcode == 0x57:
            self.indent -= 1
            self.write_line("SI_CMD(ScriptOpcode_END_SPAWN_THREAD),")
        elif opcode == 0x58:
            self.write_line("SI_CMD(ScriptOpcode_PARALLEL_THREAD),")
            self.indent += 1
        elif opcode == 0x59:
            self.indent -= 1
            self.write_line("SI_CMD(ScriptOpcode_END_PARALLEL_THREAD),")
        else:
            # unknown opcode
            argv_str = ""
            for arg in argv:
                argv_str += ", "
                argv_str += f"0x{arg:X}"
            self.write_line(f"SI_CMD(0x{opcode:02X}{argv_str}),")

class UnsupportedScript(Exception):
    pass

class ScriptDSLDisassembler(ScriptDisassembler):
    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs)

        # True: case block
        # CASE: single condition
        # MULTI: multi-condition(s)
        # MATCH: match block
        self.case_stack = []

        self.was_multi_case = False

    @property
    def in_case(self):
        return self.case_stack[-1] if self.case_stack else False

    def var(self, arg):
        if arg in self.symbol_map:
            return self.symbol_map[arg][0][1]

        v = arg - 2**32 # convert to s32
        if v > -250000000:
            if v <= -220000000: return str((v + 230000000) / 1024)
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

    def is_float(self, var):
        try:
            float(var)
            return True
        except Exception:
            return False

    def disassemble_command(self, opcode, argc, argv):
        # write case block braces
        if self.in_case == "CASE" or self.in_case == "MULTI":
            if opcode == 0x1D: # multi case
                pass
            elif 0x16 <= opcode <= 0x21: # standard case conditions
                # open and close empty case
                self.out += " {}\n"

                self.case_stack.pop()
                assert self.in_case == "MATCH"

                self.was_multi_case = False
            else:
                # open case
                self.out += " {\n"

                self.case_stack.append(True)

                self.indent += 1
        elif self.in_case != "MATCH" and 0x16 <= opcode <= 0x21: # new case, not including the first
            assert self.case_stack.pop() == True
            self.was_multi_case = self.case_stack.pop() == "MULTI"
            assert self.in_case == "MATCH"

            self.indent -= 1
            self.write_line("}")

        if opcode == 0x01:
            if self.out.endswith("return;\n"):
                # implicit return; break
                self.out = self.out[:-8].rstrip() + "\n"
            else:
                self.write_line("break;")

            self.indent -= 1

            self.prefix_line(f"Script {self.script_name} = SCRIPT({{")
            self.write_line("});")

            self.done = True
        elif opcode == 0x02: self.write_line(f"return;")
        elif opcode == 0x03:
            self.indent -= 1
            self.write_line(f"{self.var(argv[0])}:")
            self.indent += 1
        elif opcode == 0x04: self.write_line(f"goto {self.var(argv[0])};")
        elif opcode == 0x05:
            if argv[0] == 0:
                self.write_line("loop {")
            else:
                self.write_line(f"loop {self.var(argv[0])} {{")
            self.indent += 1
        elif opcode == 0x06:
            self.indent -= 1
            self.write_line("}")
        elif opcode == 0x07: self.write_line(f"break;")
        elif opcode == 0x08: self.write_line(f"sleep {self.var(argv[0])};")
        elif opcode == 0x09: self.write_line(f"sleep {self.var(argv[0])} secs;")
        elif opcode == 0x0A:
            self.write_line(f"if ({self.var(argv[0])} == {self.var(argv[1])}) {{")
            self.indent += 1
        elif opcode == 0x0B:
            self.write_line(f"if ({self.var(argv[0])} != {self.var(argv[1])}) {{")
            self.indent += 1
        elif opcode == 0x0C:
            self.write_line(f"if ({self.var(argv[0])} < {self.var(argv[1])}) {{")
            self.indent += 1
        elif opcode == 0x0D:
            self.write_line(f"if ({self.var(argv[0])} > {self.var(argv[1])}) {{")
            self.indent += 1
        elif opcode == 0x0E:
            self.write_line(f"if ({self.var(argv[0])} <= {self.var(argv[1])}) {{")
            self.indent += 1
        elif opcode == 0x0F:
            self.write_line(f"if ({self.var(argv[0])} >= {self.var(argv[1])}) {{")
            self.indent += 1
        elif opcode == 0x10:
            self.write_line(f"if ({self.var(argv[0])} & {self.var(argv[1])}) {{")
            self.indent += 1
        elif opcode == 0x11:
            self.write_line(f"if ({self.var(argv[0])} !& {self.var(argv[1])}) {{")
            self.indent += 1
        elif opcode == 0x12:
            self.indent -= 1
            self.write_line("} else {")
            self.indent += 1
        elif opcode == 0x13:
            self.indent -= 1
            self.write_line("}")
        elif opcode == 0x14:
            self.write_line(f"match {self.var(argv[0])} {{")
            self.indent += 1
            self.case_stack.append("MATCH")
        elif opcode == 0x15:
            self.write_line(f"matchc {self.var(argv[0])} {{")
            self.indent += 1
            self.case_stack.append("MATCH")
        elif opcode == 0x16:
            self.case_stack.append("CASE")
            self.write(f"== {self.var(argv[0])}")
        elif opcode == 0x17:
            self.case_stack.append("CASE")
            self.write(f"!= {self.var(argv[0])}")
        elif opcode == 0x18:
            self.case_stack.append("CASE")
            self.write(f"< {self.var(argv[0])}")
        elif opcode == 0x19:
            self.case_stack.append("CASE")
            self.write(f"> {self.var(argv[0])}")
        elif opcode == 0x1A:
            self.case_stack.append("CASE")
            self.write(f"<= {self.var(argv[0])}")
        elif opcode == 0x1B:
            self.case_stack.append("CASE")
            self.write(f">= {self.var(argv[0])}")
        elif opcode == 0x1C:
            self.case_stack.append("CASE")
            self.write(f"else")
        elif opcode == 0x1D:
            if self.in_case == "CASE" or self.in_case == "MULTI":
                self.out += f", {self.var(argv[0])}"

                # replace(!) CASE with MULTI
                self.case_stack.pop()
                self.case_stack.append("MULTI")
            else:
                self.write(f"{self.var(argv[0])}")
                self.case_stack.append("MULTI")
        # opcode 0x1E?
        elif opcode == 0x1F:
            self.case_stack.append("CASE")
            self.write_line(f"? {self.var(argv[0])}")
        elif opcode == 0x20:
            if not self.was_multi_case:
                raise UnsupportedScript("unexpected SI_END_MULTI_CASE")
        elif opcode == 0x21:
            self.indent -= 1
            self.write_line(f"{self.var(argv[0])}..{self.var(argv[1])}")
            self.indent += 1
        elif opcode == 0x22: self.write_line("break")
        elif opcode == 0x23:
            # close open case if needed
            if self.in_case != "MATCH":
                self.case_stack.pop() == True
                self.case_stack.pop() in ["MULTI", "CASE"]

                self.indent -= 1
                self.write_line("}")

            assert self.case_stack.pop() == "MATCH"

            self.indent -= 1
            self.write_line("}")
        elif opcode == 0x24: self.write_line(f"{self.var(argv[0])} = {self.var(argv[1])};")
        elif opcode == 0x25: self.write_line(f"{self.var(argv[0])} =c 0x{argv[1]:X};")
        elif opcode == 0x26:
            lhs = self.var(argv[1])
            if self.is_float(lhs):
                self.write_line(f"{self.var(argv[0])} = {lhs};")
            else:
                self.write_line(f"{self.var(argv[0])} =f {lhs};")
        elif opcode == 0x27: self.write_line(f"{self.var(argv[0])} += {self.var(argv[1])};")
        elif opcode == 0x28: self.write_line(f"{self.var(argv[0])} -= {self.var(argv[1])};")
        elif opcode == 0x29: self.write_line(f"{self.var(argv[0])} *= {self.var(argv[1])};")
        elif opcode == 0x2A: self.write_line(f"{self.var(argv[0])} /= {self.var(argv[1])};")
        elif opcode == 0x2B: self.write_line(f"{self.var(argv[0])} %= {self.var(argv[1])};")
        elif opcode == 0x2C:
            lhs = self.var(argv[1])
            if self.is_float(lhs):
                self.write_line(f"{self.var(argv[0])} += {lhs};")
            else:
                self.write_line(f"{self.var(argv[0])} +=f {lhs};")
        elif opcode == 0x2D:
            lhs = self.var(argv[1])
            if self.is_float(lhs):
                self.write_line(f"{self.var(argv[0])} -= {lhs};")
            else:
                self.write_line(f"{self.var(argv[0])} -=f {lhs};")
        elif opcode == 0x2E:
            lhs = self.var(argv[1])
            if self.is_float(lhs):
                self.write_line(f"{self.var(argv[0])} *= {lhs};")
            else:
                self.write_line(f"{self.var(argv[0])} *=f {lhs};")
        elif opcode == 0x2F:
            lhs = self.var(argv[1])
            if self.is_float(lhs):
                self.write_line(f"{self.var(argv[0])} /= {lhs};")
            else:
                self.write_line(f"{self.var(argv[0])} /=f {lhs};")
        elif opcode == 0x3F: self.write_line(f"{self.var(argv[0])} &= {self.var(argv[1])};")
        elif opcode == 0x40: self.write_line(f"{self.var(argv[0])} |= {self.var(argv[1])};")
        elif opcode == 0x41: self.write_line(f"{self.var(argv[0])} &=c {argv[1]:X};")
        elif opcode == 0x42: self.write_line(f"{self.var(argv[0])} |=c {argv[1]:X};")
        elif opcode == 0x43:
            addr = argv[0]
            if addr in self.symbol_map:
                func_name = self.symbol_map[addr][0][1]

                argv_str = ", ".join(self.var(arg) for arg in argv[1:])
                self.write_line(f"{func_name}({argv_str});")
            else:
                print(f"script API function {addr:X} is not present in symbol_addrs.txt, please add it")
                exit(1)
        elif opcode == 0x44: self.write_line(f"spawn {self.addr_ref(argv[0])};")
        elif opcode == 0x45: self.write_line(f"{self.var(argv[1])} = spawn {self.addr_ref(argv[0])};")
        elif opcode == 0x46: self.write_line(f"await {self.addr_ref(argv[0])};")
        elif opcode == 0x47:
            assert argv[3] == 1
            if argv[4] != 0:
                self.write_line(f"{self.var(argv[4])} = bind {self.addr_ref(argv[0])} to {self.trigger(argv[1])} {self.var(argv[2])};")
            else:
                self.write_line(f"bind {self.addr_ref(argv[0])} to {self.trigger(argv[1])} {self.var(argv[2])};")
        elif opcode == 0x48: self.write_line(f"unbind;")
        elif opcode == 0x49: self.write_line(f"kill {self.var(argv[0])};")
        elif opcode == 0x4D: self.write_line(f"group {self.var(argv[0])};")
        elif opcode == 0x4F: self.write_line(f"suspend group {self.var(argv[0])};")
        elif opcode == 0x50: self.write_line(f"resume group {self.var(argv[0])};")
        elif opcode == 0x51: self.write_line(f"suspend others {self.var(argv[0])};")
        elif opcode == 0x52: self.write_line(f"resume others {self.var(argv[0])};")
        elif opcode == 0x53: self.write_line(f"suspend {self.var(argv[0])};")
        elif opcode == 0x54: self.write_line(f"resume {self.var(argv[0])};")
        elif opcode == 0x56:
            self.write_line("spawn {")
            self.indent += 1
        elif opcode == 0x57:
            self.indent -= 1
            self.write_line("}")
        elif opcode == 0x58:
            self.write_line("parallel {")
            self.indent += 1
        elif opcode == 0x59:
            self.indent -= 1
            self.write_line("}")
        else:
            raise UnsupportedScript(f"DSL does not support script opcode 0x{opcode:X}")

if __name__ == "__main__":
    if len(sys.argv) <= 1:
        print("usage: ./disasm_script.py <file> [offset]")
        exit()

    file = sys.argv[1]
    offset = eval(sys.argv[2]) if len(sys.argv) >= 3 else 0

    with open(file, "rb") as f:
        f.seek(offset)

        try:
            script = ScriptDSLDisassembler(f)
            script_text = script.disassemble()

            print(f"Script read from 0x{script.start_pos:X} to 0x{script.end_pos - 4:X} "
                  f"(0x{script.end_pos - script.start_pos:X} bytes, {script.instructions} instructions)")
            print()
            print(script_text, end="")
        except UnsupportedScript:
            print(ScriptDisassembler(f).disassemble(), end="")
