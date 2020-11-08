#! /usr/bin/python3

import sys

_script_lib = None
def script_lib():
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

        # symbol_addrs.txt
        with open(Path(path.dirname(__file__), "symbol_addrs.txt"), "r") as file:
            for line in file.readlines():
                line = line.split(";")[0]

                s = [s.strip() for s in line.split("=", 1)]
                name = s[0]
                addr = s[1]
                _script_lib[int(addr, 16)] = name

    return _script_lib

class ScriptDisassembler:
    def __init__(self, bytes, script_name = "script", symbol_map = {}):
        self.bytes = bytes
        self.script_name = script_name
        self.symbol_map = symbol_map

        self.out = ""
        self.prefix = ""

        self.indent = 1
        self.indent_used = False

        self.done = False

    def disassemble(self):
        while True:
            opcode = self.read_word()
            argc = self.read_word()

            if opcode > 0xFF or argc > 0xFF:
                raise Exception(f"script '{script_name}' is malformed")

            argv = []
            for i in range(0, argc):
                argv.append(self.read_word())

            self.disassemble_command(opcode, argc, argv)

            if self.done:
                return self.prefix + self.out

    def write_line(self, line):
        if self.indent < 0: self.indent = 0
        if self.indent > 1: self.indent_used = True

        self.out += "    " * self.indent
        self.out += line
        self.out += "\n"

    def prefix_line(self, line):
        self.prefix += line
        self.prefix += "\n"

    def var(self, arg):
        if arg in self.symbol_map:
            return self.symbol_map[arg]

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
            return self.symbol_map[addr]
        return script_lib().get(addr, f"0x{addr:08X}")

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
        return trigger

    def read_word(self):
        return int.from_bytes(self.bytes.read(4), byteorder="big")

    def disassemble_command(self, opcode, argc, argv):
        if opcode == 0x01:
            self.write_line("SI_END(),")
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
        elif opcode == 0x02: self.write_line(f"SI_RETURN(),")
        elif opcode == 0x03: self.write_line(f"SI_LABEL({self.var(argv[0])}),")
        elif opcode == 0x04: self.write_line(f"SI_GOTO({self.var(argv[0])}),")
        elif opcode == 0x05:
            self.write_line(f"SI_LOOP({self.var(argv[0])}),")
            self.indent += 1
        elif opcode == 0x06:
            self.indent -= 1
            self.write_line("SI_END_LOOP(),")
        elif opcode == 0x07: self.write_line(f"SI_BREAK_LOOP(),")
        elif opcode == 0x08: self.write_line(f"SI_WAIT_FRAMES({self.var(argv[0])}),")
        elif opcode == 0x09: self.write_line(f"SI_WAIT_SECS({self.var(argv[0])}),")
        elif opcode == 0x0A:
            self.write_line(f"SI_IF_EQ({self.var(argv[0])}, {self.var(argv[1])}),")
            self.indent += 1
        elif opcode == 0x0B:
            self.write_line(f"SI_IF_NE({self.var(argv[0])}, {self.var(argv[1])}),")
            self.indent += 1
        elif opcode == 0x0C:
            self.write_line(f"SI_IF_LT({self.var(argv[0])}, {self.var(argv[1])}),")
            self.indent += 1
        elif opcode == 0x0D:
            self.write_line(f"SI_IF_GT({self.var(argv[0])}, {self.var(argv[1])}),")
            self.indent += 1
        elif opcode == 0x0E:
            self.write_line(f"SI_IF_LE({self.var(argv[0])}, {self.var(argv[1])}),")
            self.indent += 1
        elif opcode == 0x0F:
            self.write_line(f"SI_IF_GE({self.var(argv[0])}, {self.var(argv[1])}),")
            self.indent += 1
        elif opcode == 0x10:
            self.write_line(f"SI_IF_BITS_ON({self.var(argv[0])}, {self.var(argv[1])}),")
            self.indent += 1
        elif opcode == 0x11:
            self.write_line(f"SI_IF_BITS_OFF({self.var(argv[0])}, {self.var(argv[1])}),")
            self.indent += 1
        elif opcode == 0x12:
            self.indent -= 1
            self.write_line(f"SI_ELSE(),")
            self.indent += 1
        elif opcode == 0x13:
            self.indent -= 1
            self.write_line(f"SI_END_IF(),")
        elif opcode == 0x14:
            self.write_line(f"SI_SWITCH({self.var(argv[0])}),")
            self.indent += 2
        elif opcode == 0x15:
            self.write_line(f"SI_SWITCH_CONST(0x{argv[0]:X}),")
            self.indent += 2
        elif opcode == 0x16:
            self.indent -= 1
            self.write_line(f"SI_CASE_EQ({self.var(argv[0])}),")
            self.indent += 1
        elif opcode == 0x17:
            self.indent -= 1
            self.write_line(f"SI_CASE_NE({self.var(argv[0])}),")
            self.indent += 1
        elif opcode == 0x18:
            self.indent -= 1
            self.write_line(f"SI_CASE_LT({self.var(argv[0])}),")
            self.indent += 1
        elif opcode == 0x19:
            self.indent -= 1
            self.write_line(f"SI_CASE_GT({self.var(argv[0])}),")
            self.indent += 1
        elif opcode == 0x1A:
            self.indent -= 1
            self.write_line(f"SI_CASE_LE({self.var(argv[0])}),")
            self.indent += 1
        elif opcode == 0x1B:
            self.indent -= 1
            self.write_line(f"SI_CASE_GE({self.var(argv[0])}),")
            self.indent += 1
        elif opcode == 0x1C:
            self.indent -= 1
            self.write_line(f"SI_CASE_DEFAULT(),")
            self.indent += 1
        elif opcode == 0x1D:
            self.indent -= 1
            self.write_line(f"SI_CASE_OR_EQ({self.var(argv[0])}),")
            self.indent += 1
        # opcode 0x1E?
        elif opcode == 0x1F:
            self.indent -= 1
            self.write_line(f"SI_CASE_BITS_ON({self.var(argv[0])}),")
            self.indent += 1
        elif opcode == 0x20:
            self.indent -= 1
            self.write_line(f"SI_END_MULTI_CASE(),")
            self.indent += 1
        elif opcode == 0x21:
            self.indent -= 1
            self.write_line(f"SI_CASE_RANGE({self.var(argv[0])}, {self.var(argv[1])}),")
            self.indent += 1
        elif opcode == 0x22: self.write_line(f"SI_BREAK_CASE(),")
        elif opcode == 0x23:
            self.indent -= 2
            self.write_line(f"SI_END_SWITCH(),")
        elif opcode == 0x24: self.write_line(f"SI_SET({self.var(argv[0])}, {self.var(argv[1])}),")
        elif opcode == 0x25: self.write_line(f"SI_SET_CONST({self.var(argv[0])}, 0x{argv[1]:X}),")
        elif opcode == 0x26: self.write_line(f"SI_SET_F({self.var(argv[0])}, {self.var(argv[1])}),")
        elif opcode == 0x27: self.write_line(f"SI_ADD({self.var(argv[0])}, {self.var(argv[1])}),")
        elif opcode == 0x28: self.write_line(f"SI_SUB({self.var(argv[0])}, {self.var(argv[1])}),")
        elif opcode == 0x29: self.write_line(f"SI_MUL({self.var(argv[0])}, {self.var(argv[1])}),")
        elif opcode == 0x2A: self.write_line(f"SI_DIV({self.var(argv[0])}, {self.var(argv[1])}),")
        elif opcode == 0x2B: self.write_line(f"SI_MOD({self.var(argv[0])}, {self.var(argv[1])}),")
        elif opcode == 0x2C: self.write_line(f"SI_ADD_F({self.var(argv[0])}, {self.var(argv[1])}),")
        elif opcode == 0x2D: self.write_line(f"SI_SUB_F({self.var(argv[0])}, {self.var(argv[1])}),")
        elif opcode == 0x2E: self.write_line(f"SI_MUL_F({self.var(argv[0])}, {self.var(argv[1])}),")
        elif opcode == 0x2F: self.write_line(f"SI_DIV_F({self.var(argv[0])}, {self.var(argv[1])}),")
        elif opcode == 0x30: self.write_line(f"SI_USE_BUFFER({self.var(argv[0])}),")
        # TODO: SI_BUF commands
        elif opcode == 0x3C: self.write_line(f"SI_USE_ARRAY({self.var(argv[0])}),")
        elif opcode == 0x3D: self.write_line(f"SI_NEW_ARRAY({self.var(argv[0])}, {self.var(argv[1])}),")
        elif opcode == 0x3E: self.write_line(f"SI_USE_FLAGS({self.var(argv[0])}),")
        elif opcode == 0x3F: self.write_line(f"SI_AND({self.var(argv[0])}, {self.var(argv[1])}),")
        elif opcode == 0x40: self.write_line(f"SI_OR({self.var(argv[0])}, {self.var(argv[1])}),")
        elif opcode == 0x41: self.write_line(f"SI_AND_CONST({self.var(argv[0])}, 0x{argv[1]:X})")
        elif opcode == 0x42: self.write_line(f"SI_OR_CONST({self.var(argv[0])}, 0x{argv[1]:X})")
        elif opcode == 0x43:
            argv_str = ""
            for arg in argv[1:]:
                argv_str += ", "
                argv_str += self.var(arg)

            self.write_line(f"SI_CALL({self.addr_ref(argv[0])}{argv_str}),")
        elif opcode == 0x44: self.write_line(f"SI_EXEC({self.addr_ref(argv[0])}),")
        elif opcode == 0x45: self.write_line(f"SI_EXEC_GET_ID({self.addr_ref(argv[0])}, {self.var(argv[1])}),")
        elif opcode == 0x46: self.write_line(f"SI_EXEC_WAIT({self.addr_ref(argv[0])}),")
        elif opcode == 0x47:
            assert argv[3] == 1
            self.write_line(f"SI_BIND({self.addr_ref(argv[0])}, {self.trigger(argv[1])}, {self.var(argv[2])}, {'NULL' if argv[4] == 0 else self.var(argv[4])}),")
        elif opcode == 0x48: self.write_line(f"SI_UNBIND_ME(),")
        elif opcode == 0x49: self.write_line(f"SI_KILL({self.var(argv[0])}),")
        elif opcode == 0x4A: self.write_line(f"SI_JUMP({self.var(argv[0])}),")
        elif opcode == 0x4B: self.write_line(f"SI_PRIORITY({self.var(argv[0])}),")
        elif opcode == 0x4C: self.write_line(f"SI_TIMESCALE({self.var(argv[0])}),")
        elif opcode == 0x4D: self.write_line(f"SI_GROUP({self.var(argv[0])}),")
        elif opcode == 0x4E:
            assert argv[4] == 0
            assert argv[5] == 1
            self.write_line(f"SI_BIND_PADLOCK({self.addr_ref(argv[0])}, {self.trigger(argv[1])}, {self.var(argv[2])}, {self.var(argv[3])}),")
        elif opcode == 0x4F: self.write_line(f"SI_SUSPEND_GROUP({self.var(argv[0])}),")
        elif opcode == 0x50: self.write_line(f"SI_RESUME_GROUP({self.var(argv[0])}),")
        elif opcode == 0x51: self.write_line(f"SI_SUSPEND_GROUP_NOT_ME({self.var(argv[0])}),")
        elif opcode == 0x52: self.write_line(f"SI_RESUME_GROUP_NOT_ME({self.var(argv[0])}),")
        elif opcode == 0x53: self.write_line(f"SI_SUSPEND({self.var(argv[0])}),")
        elif opcode == 0x54: self.write_line(f"SI_RESUME({self.var(argv[0])}),")
        elif opcode == 0x55: self.write_line(f"SI_EXISTS({self.var(argv[0])}),")
        elif opcode == 0x56:
            self.write_line("SI_THREAD(),")
            self.indent += 1
        elif opcode == 0x57:
            self.indent -= 1
            self.write_line("SI_END_THREAD(),")
        elif opcode == 0x58:
            self.write_line("SI_CHILD_THREAD(),")
            self.indent += 1
        elif opcode == 0x59:
            self.indent -= 1
            self.write_line("SI_END_CHILD_THREAD(),")
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

        self.in_case = False

    def var(self, arg):
        if arg in self.symbol_map:
            return self.symbol_map[arg]

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

    def verify_float(self, var):
        try:
            float(var)
        except Exception:
            # not a float!
            raise UnsupportedScript("non-float used in float command")

        return var

    def disassemble_command(self, opcode, argc, argv):
        if opcode == 0x01:
            if self.out.endswith("return\n"):
                # implicit return; break
                self.out = self.out[:-7].rstrip() + "\n"
            else:
                self.write_line("break")

            self.indent -= 1

            self.prefix_line(f"Script {self.script_name} = SCRIPT({{")
            self.write_line("});")

            self.done = True
        elif opcode == 0x02: self.write_line(f"return")
        elif opcode == 0x03: self.write_line(f"lbl{self.var(argv[0])}:")
        elif opcode == 0x04: self.write_line(f"goto lbl{self.var(argv[0])}")
        elif opcode == 0x05:
            if argv[0] == 0:
                self.write_line("loop {")
            else:
                self.write_line(f"loop {self.var(argv[0])} {{")
            self.indent += 1
        elif opcode == 0x06:
            self.indent -= 1
            self.write_line("}")
        elif opcode == 0x07: self.write_line(f"break")
        elif opcode == 0x08: self.write_line(f"sleep {self.var(argv[0])}")
        elif opcode == 0x09: self.write_line(f"sleep {self.var(argv[0])} secs")
        elif opcode == 0x0A:
            self.write_line(f"if {self.var(argv[0])} == {self.var(argv[1])} {{")
            self.indent += 1
        elif opcode == 0x0B:
            self.write_line(f"if {self.var(argv[0])} != {self.var(argv[1])} {{")
            self.indent += 1
        elif opcode == 0x0C:
            self.write_line(f"if {self.var(argv[0])} < {self.var(argv[1])} {{")
            self.indent += 1
        elif opcode == 0x0D:
            self.write_line(f"if {self.var(argv[0])} > {self.var(argv[1])} {{")
            self.indent += 1
        elif opcode == 0x0E:
            self.write_line(f"if {self.var(argv[0])} <= {self.var(argv[1])} {{")
            self.indent += 1
        elif opcode == 0x0F:
            self.write_line(f"if {self.var(argv[0])} >= {self.var(argv[1])} {{")
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
            self.indent += 2
            self.in_case = False
        # elif opcode == 0x15:
        #     self.write_line(f"SI_SWITCH_CONST(0x{argv[0]:X}),")
        #     self.indent += 2
        elif opcode == 0x16:
            self.indent -= 1
            if self.in_case: self.write_line("}")
            self.in_case = True
            self.write_line(f"{self.var(argv[0])} {{")
            self.indent += 1
        elif opcode == 0x17:
            self.indent -= 1
            if self.in_case: self.write_line("}")
            self.in_case = True
            self.write_line(f"!= {self.var(argv[0])} {{")
            self.indent += 1
        elif opcode == 0x18:
            self.indent -= 1
            if self.in_case: self.write_line("}")
            self.in_case = True
            self.write_line(f"< {self.var(argv[0])} {{")
            self.indent += 1
        elif opcode == 0x19:
            self.indent -= 1
            if self.in_case: self.write_line("}")
            self.in_case = True
            self.write_line(f"> {self.var(argv[0])} {{")
            self.indent += 1
        elif opcode == 0x1A:
            self.indent -= 1
            if self.in_case: self.write_line("}")
            self.in_case = True
            self.write_line(f"<= {self.var(argv[0])} {{")
            self.indent += 1
        elif opcode == 0x1B:
            self.indent -= 1
            if self.in_case: self.write_line("}")
            self.in_case = True
            self.write_line(f">= {self.var(argv[0])} {{")
            self.indent += 1
        elif opcode == 0x1C:
            self.indent -= 1
            if self.in_case: self.write_line("}")
            self.in_case = True
            self.write_line(f"else {{")
            self.indent += 1
        # elif opcode == 0x1D:
        #     self.indent -= 1
        #     self.write_line(f"SI_CASE_OR_EQ({self.var(argv[0])}),")
        #     self.indent += 1
        # opcode 0x1E?
        elif opcode == 0x1F:
            self.indent -= 1
            self.write_line(f"? {self.var(argv[0])}")
            self.indent += 1
        # elif opcode == 0x20:
        #     self.indent -= 1
        #     self.write_line(f"SI_END_MULTI_CASE(),")
        #     self.indent += 1
        elif opcode == 0x21:
            self.indent -= 1
            self.write_line(f"{self.var(argv[0])}..{self.var(argv[1])} {{")
            self.indent += 1
        elif opcode == 0x22: self.write_line("break")
        elif opcode == 0x23:
            self.indent -= 1
            if self.in_case: self.write_line("}")
            self.in_case = False
            self.indent -= 1
            self.write_line("}")
        elif opcode == 0x24: self.write_line(f"{self.var(argv[0])} = {self.var(argv[1])}")
        #elif opcode == 0x25: self.write_line(f"{self.var(argv[0])} #= 0x{argv[1]:X}")
        elif opcode == 0x26: self.write_line(f"{self.var(argv[0])} = {self.verify_float(self.var(argv[1]))}")
        elif opcode == 0x27: self.write_line(f"{self.var(argv[0])} += {self.var(argv[1])}")
        elif opcode == 0x28: self.write_line(f"{self.var(argv[0])} -= {self.var(argv[1])}")
        elif opcode == 0x29: self.write_line(f"{self.var(argv[0])} *= {self.var(argv[1])}")
        elif opcode == 0x2A: self.write_line(f"{self.var(argv[0])} /= {self.var(argv[1])}")
        elif opcode == 0x2B: self.write_line(f"{self.var(argv[0])} %= {self.var(argv[1])}")
        elif opcode == 0x2C: self.write_line(f"{self.var(argv[0])} += {self.verify_float(self.var(argv[1]))}")
        elif opcode == 0x2D: self.write_line(f"{self.var(argv[0])} -= {self.verify_float(self.var(argv[1]))}")
        elif opcode == 0x2E: self.write_line(f"{self.var(argv[0])} *= {self.verify_float(self.var(argv[1]))}")
        elif opcode == 0x2F: self.write_line(f"{self.var(argv[0])} /= {self.verify_float(self.var(argv[1]))}")
        elif opcode == 0x3F: self.write_line(f"{self.var(argv[0])} &= {self.var(argv[1])}")
        elif opcode == 0x40: self.write_line(f"{self.var(argv[0])} |= {self.var(argv[1])}")
        #elif opcode == 0x41: self.write_line(f"{self.var(argv[0])} #&= {argv[1]:X})")
        #elif opcode == 0x42: self.write_line(f"{self.var(argv[0])} #|= {argv[1]:X})")
        elif opcode == 0x43:
            argv_str = ", ".join(self.var(arg) for arg in argv[1:])
            self.write_line(f"{self.addr_ref(argv[0])}({argv_str})")
        elif opcode == 0x44: self.write_line(f"spawn {self.addr_ref(argv[0])}")
        elif opcode == 0x45: self.write_line(f"{self.var(argv[1])} = spawn ({self.addr_ref(argv[0])}")
        elif opcode == 0x46: self.write_line(f"await {self.addr_ref(argv[0])}")
        elif opcode == 0x47:
            assert argv[3] == 1
            if argv[4] != 0:
                self.write_line(f"{self.var(argv[4])} = bind {self.addr_ref(argv[0])} to {self.trigger(argv[1])} {self.var(argv[2])}")
            else:
                self.write_line(f"bind {self.addr_ref(argv[0])} to {self.trigger(argv[1])} {self.var(argv[2])}")
        elif opcode == 0x48: self.write_line(f"unbind")
        elif opcode == 0x49: self.write_line(f"kill {self.var(argv[0])}")
        elif opcode == 0x4D: self.write_line(f"group {self.var(argv[0])}")
        elif opcode == 0x4F: self.write_line(f"suspend group {self.var(argv[0])}")
        elif opcode == 0x50: self.write_line(f"resume group {self.var(argv[0])}")
        elif opcode == 0x51: self.write_line(f"suspend others {self.var(argv[0])}")
        elif opcode == 0x52: self.write_line(f"resume others {self.var(argv[0])}")
        elif opcode == 0x53: self.write_line(f"suspend {self.var(argv[0])}")
        elif opcode == 0x54: self.write_line(f"resume {self.var(argv[0])}")
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
            raise UnsupportedScript(f"DSL does not support script opcode {opcode:X}")

if __name__ == "__main__":
    if len(sys.argv) <= 1:
        print("usage: ./disasm_script.py <file> [offset]")
        exit()

    file = sys.argv[1]
    offset = eval(sys.argv[2]) if len(sys.argv) >= 3 else 0

    with open(file, "rb") as f:
        f.seek(offset)

        try:
            print(ScriptDSLDisassembler(f).disassemble(), end="")
        except UnsupportedScript:
            print(ScriptDisassembler(f).disassemble(), end="")
