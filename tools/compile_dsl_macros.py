#! /usr/bin/python3

from sys import stdin, stderr
from lark import Lark, exceptions, Tree, Transformer, Visitor, v_args
from lark.visitors import Discard
import traceback

def eprint(*args, **kwargs):
    print(*args, file=stderr, **kwargs)

def write(s):
    print(s, end="")

ANSI_RED = "\033[1;31;40m"
ANSI_RESET = "\u001b[0m"

def pairs(seq):
    i = iter(seq)
    prev = next(i)
    for item in i:
        yield prev, item
        prev = item

script_parser = Lark(r"""

    block: "{" NEWLINE* (stmt STMT_SEP)* NEWLINE* "}"

    ?stmt: call
         | label ":"            -> label_decl
         | "goto" label         -> label_goto
         | if_stmt
         | "return"             -> return_stmt
         | "break"              -> break_stmt
         | "sleep" expr         -> sleep_stmt
         | "spawn" expr         -> spawn_stmt
         | "await" expr         -> await_stmt
         | lhs "=" "spawn" expr -> spawn_set_stmt
         | lhs set_op expr      -> set_stmt
         | lhs ":=" expr        -> set_const_stmt
         | bind_stmt
         | bind_set_stmt
         | "unbind"             -> unbind_stmt
         | "group" expr         -> set_group
         | suspend_stmt
         | resume_stmt
         | kill_stmt
         | loop_stmt

    call: CNAME "(" [expr ("," expr)* [","]] ")"

    if_stmt: "if" expr if_op expr block ["else" block]
    ?if_op: "==" -> if_op_eq
          | "!=" -> if_op_ne

    suspend_stmt: "suspend" control_type expr ("," control_type expr)* [","]
    resume_stmt: "resume" control_type expr ("," control_type expr)* [","]
    kill_stmt: "kill" control_type expr ("," control_type expr)* [","]
    ?control_type: "group"    -> control_type_group
                 | "others"   -> control_type_others
                 | ["script"] -> control_type_script

    bind_stmt: "bind" expr "to" expr expr
    bind_set_stmt: lhs "=" "bind" expr "to" expr expr

    loop_stmt: "loop" [expr] block

    ?expr: c_const_expr
         | ESCAPED_STRING
         | SIGNED_INT
         | DECIMAL
         | HEX_INT
         | CNAME

    ?lhs: c_const_expr

    ?set_op: "="  -> set_op_eq
           | "+=" -> set_op_add
           | "-=" -> set_op_sub
           | "*=" -> set_op_mul
           | "/=" -> set_op_div
           | "%=" -> set_op_mod

    c_const_expr: c_const_expr_internal
    c_const_expr_internal: "(" (c_const_expr_internal | NOT_PARENS)+ ")"
    NOT_PARENS: /[^()]+/

    STMT_SEP: (NEWLINE+ | ";")

    label: /[a-zA-Z0-9_]+/

    %import common.CNAME
    %import common.SIGNED_INT
    %import common.DECIMAL
    %import common.HEXDIGIT
    %import common.ESCAPED_STRING

    HEX_INT: ["+"|"-"] "0x" HEXDIGIT+

    LINE_COMMENT: "//" /[^\n]*/ NEWLINE
    %ignore LINE_COMMENT

    %import common.WS_INLINE
    %import common.NEWLINE
    %ignore WS_INLINE

""", start="block", propagate_positions=True)#, parser="lalr", cache=True)

class Cmd():
    def __init__(self, opcode, *args, **kwargs):
        if opcode:
            self.opcode = opcode
        self.args = args
        self.meta = kwargs.get("meta", None)
        self.context = []

    def add_context(self, context):
        self.context.append(context)

    def to_bytecode(self):
        return [ self.opcode, len(self.args), *self.args ]

    def __str__(self):
        return f"Cmd({self.opcode:02X}, {', '.join(map(str, self.args))})"

class BreakCmd(Cmd):
    def __init__(self, **kwargs):
        super().__init__(None, **kwargs)

    @property
    def opcode(self):
        # are we in a switch or a loop?
        context = None
        for c in self.context:
            if c in ("switch", "loop"):
                context = c

        if not context:
            return 0x01 # END
        elif context == "loop":
            return 0x07 # SI_BREAK_LOOP
        elif context == "switch":
            return 0x22 # BREAK_CASE

    def __str__(self):
        return "BreakCmd"

class CompileError(Exception):
    def __init__(self, message, meta):
        super().__init__(message)
        self.meta = meta

def is_fixed_var(v):
    if type(v) == int:
        if v <= -250000000:
            return False
        elif v <= -220000000:
            return True
    return False

class LabelAllocation(Visitor):
    def __init__(self):
        super().__init__()
        self.labels = []

    def label_decl(self, tree):
        name = tree.children[0].children[0]
        if name in self.labels:
            raise CompileError(f"label `{name}' already declared", tree.meta)
        self.labels.append(name)

@v_args(tree=True)
class Compile(Transformer):
    SIGNED_INT = str
    HEX_INT = str
    ESCAPED_STRING = str

    def transform(self, tree):
        self.alloc = LabelAllocation()
        self.alloc.visit_topdown(tree)
        return super().transform(tree)

    def CNAME(self, name):
        return f"(Bytecode)(&{name})"

    NOT_PARENS = str
    def c_const_expr_internal(self, tree):
        return f"({' '.join(tree.children)})"
    def c_const_expr(self, tree):
        return f"(Bytecode){tree.children[0]}"

    def DECIMAL(self, v):
        # fixed-point
        return int((float(v) * 1024) - 230000000)

    def block(self, tree):
        # flatten children list
        flat = []
        for node in tree.children:
            if type(node) == list:
                flat += node
            elif isinstance(node, Cmd):
                flat.append(node)
        return flat

    def call(self, tree):
        # TODO: type checking etc
        return Cmd(0x43, *tree.children, meta=tree.meta)

    def if_stmt(self, tree):
        a, op, b, block = tree.children
        for cmd in block:
            if type(cmd) == Cmd:
                cmd.add_context("if")
        return [ Cmd(op, a, b, meta=tree.meta), *block, Cmd(0x13) ]
    def if_op_eq(self, tree): return 0x0A
    def if_op_ne(self, tree): return 0x0B

    def loop_stmt(self, tree):
        expr = tree.children.pop(0) if len(tree.children) > 1 else 0
        block = tree.children[0]

        for cmd in block:
            if type(cmd) == Cmd:
                cmd.add_context("loop")

        return [ Cmd(0x05, expr, meta=tree.meta), *block, Cmd(0x06) ]

    def return_stmt(self, tree): return Cmd(0x02, meta=tree.meta)

    def break_stmt(self, tree):
        return BreakCmd(meta=tree.meta)

    def set_group(self, tree): return Cmd(0x4D, tree.children[0], meta=tree.meta)

    def suspend_stmt(self, tree):
        commands = []
        for opcodes, expr in pairs(tree.children):
            if not "suspend" in opcodes:
                raise CompileError(f"`suspend {opcodes['__control_type__']}' not supported", meta=tree.meta)
            commands.append(Cmd(opcodes["suspend"], expr, meta=tree.meta))
        return commands
    def resume_stmt(self, tree):
        commands = []
        for opcodes, expr in pairs(tree.children):
            if not "resume" in opcodes:
                raise CompileError(f"`resume {opcodes['__control_type__']}' not supported", meta=tree.meta)
            commands.append(Cmd(opcodes["resume"], expr, meta=tree.meta))
        return commands
    def kill_stmt(self, tree):
        commands = []
        for opcodes, expr in pairs(tree.children):
            if not "kill" in opcodes:
                raise CompileError(f"`kill {opcodes['__control_type__']}' not supported", meta=tree.meta)
            commands.append(Cmd(opcodes["kill"], expr, meta=tree.meta))
        return commands
    def control_type_group(self, tree):
        return {
            "__control_type__": "group",
            "suspend": 0x4F,
            "resume": 0x50,
        }
    def control_type_others(self, tree):
        return {
            "__control_type__": "others",
            "suspend": 0x51,
            "resume": 0x52,
        }
    def control_type_script(self, tree):
        return {
            "__control_type__": "script",
            "suspend": 0x53,
            "resume": 0x54,
            "kill": 0x49,
        }

    def sleep_stmt(self, tree):
        return Cmd(0x08, tree.children[0], meta=tree.meta)

    def bind_stmt(self, tree):
        script, trigger, target = tree.children
        return Cmd(0x47, script, trigger, target, 1, 0, meta=tree.meta)
    def bind_set_stmt(self, tree):
        ret, script, trigger, target = tree.children
        return Cmd(0x47, script, trigger, target, 1, ret, meta=tree.meta)
    def unbind_stmt(self, tree):
        return Cmd(0x48, meta=tree.meta)

    def spawn_stmt(self, tree):
        return Cmd(0x44, tree.children[0], meta=tree.meta)
    def spawn_set_stmt(self, tree):
        lhs, script = tree.children
        return Cmd(0x45, script, lhs, meta=tree.meta)
    def await_stmt(self, tree):
        return Cmd(0x46, tree.children[0], meta=tree.meta)

    def set_stmt(self, tree):
        lhs, opcodes, rhs = tree.children
        if is_fixed_var(rhs):
            opcode = opcodes.get("float", None)
            if not opcode:
                raise CompileError(f"operation `{opcodes['__op__']}' not supported for floats", tree.meta)
        else:
            opcode = opcodes.get("int", None)
            if not opcode:
                raise CompileError(f"operation `{opcodes['__op__']}' not supported for ints", tree.meta)
        return Cmd(opcode, lhs, rhs)
    def set_const_stmt(self, tree):
        lhs, rhs = tree.children
        return Cmd(0x25, lhs, rhs)
    def set_op_eq(self, tree):
        return {
            "__op__": "=",
            "int": 0x24,
            "float": 0x26,
        }
    def set_op_add(self, tree):
        return {
            "__op__": "+",
            "int": 0x27,
            "float": 0x2C,
        }
    def set_op_sub(self, tree):
        return {
            "__op__": "-",
            "int": 0x28,
            "float": 0x2D,
        }
    def set_op_mul(self, tree):
        return {
            "__op__": "*",
            "int": 0x29,
            "float": 0x2E,
        }
    def set_op_div(self, tree):
        return {
            "__op__": "/",
            "int": 0x2A,
            "float": 0x2F,
        }
    def set_op_mod(self, tree):
        return {
            "__op__": "%",
            "int": 0x2B,
        }

    def label_decl(self, tree):
        label = tree.children[0]
        return Cmd(0x03, label, meta=tree.meta)
    def label_goto(self, tree):
        label = tree.children[0]
        return Cmd(0x04, label, meta=tree.meta)
    def label(self, tree):
        name = tree.children[0]
        if name in self.alloc.labels:
            return self.alloc.labels.index(name)
        raise CompileError(f"label `{name}' is undeclared", tree.meta)

#define SI_SET_CONST(var, value) SI_CMD(0x25, var, value) // Does not get_variable
#define SI_SUB(a, b) SI_CMD(0x28, a, b) // -=
#define SI_MUL(a, b) SI_CMD(0x29, a, b) // *=
#define SI_DIV(a, b) SI_CMD(0x2A, a, b) // /=
#define SI_MOD(a, b) SI_CMD(0x2B, a, b) // %=

#define SI_SET_F(var, value) SI_CMD(0x26, var, value)
#define SI_SUB_F(a, b) SI_CMD(0x2D, a, b) // -=
#define SI_MUL_F(a, b) SI_CMD(0x2E, a, b) // *=
#define SI_DIV_F(a, b) SI_CMD(0x2F, a, b) // /=

def compile_script(s):
    tree = script_parser.parse(s)

    #eprint(tree.pretty())

    commands = Compile().transform(tree)

    for cmd in commands:
        if not isinstance(cmd, Cmd):
            raise Exception(f"uncompiled {cmd}")

    # add RETURN END if no explicit END (top-level `break') was given
    if next((cmd for cmd in commands if cmd.opcode == 0x01), None) == None:
        commands += (Cmd(0x02), Cmd(0x01))

    return commands

def read_until_closing_paren(depth=1, lex_strings=False):
    text = ""

    in_string = False
    string_escape = False

    while True:
        char = stdin.read(1)

        if len(char) == 0:
            # EOF
            return text

        if string_escape == True:
            string_escape = False
        elif char == "(" and not in_string:
            depth += 1
        elif char == ")" and not in_string:
            depth -= 1
            if depth == 0:
                break
        elif char == '"' and lex_strings:
            in_string = not in_string
        elif char == "\\" and in_string:
            string_escape = True

        text += char

    return text

def read_line():
    line = ""

    while True:
        char = stdin.read(1)

        if len(char) == 0:
            # EOF
            return line

        if char == "\n":
            break

        line += char

    return line

def gen_line_map(source, source_line_no = 1):
    line_map = {}
    output = ""

    output_line_no = 1

    for line in source.splitlines(True):
        if line[0] == "#":
            parts = line[2:-1].split(" ")
            source_line_no = int(parts[0])
        else:
            line_map[output_line_no] = source_line_no
            output += line
            output_line_no += 1
            source_line_no += 1

    return output, line_map

# Expects output from C preprocessor on stdin
if __name__ == "__main__":
    line_no = 1
    char_no = 1
    file_info = []
    error = False

    macro_name = "" # captures recent UPPER_CASE identifier
    prev_char = ""
    while True:
        char = stdin.read(1)

        if len(char) == 0:
            # EOF
            write(macro_name)
            if error:
                exit(1)
            else:
                exit(0)

        if char == "#" and (prev_char == "\n" or prev_char == ""):
            # cpp line/file marker
            line = read_line()
            line_split = line[1:].split(" ")

            line_no = int(line_split[0])
            file_info = line_split[1:]

            write("#" + line + "\n")
        elif char == "(":
            filename = file_info[0][1:-1]

            # SCRIPT(...)
            if macro_name == "SCRIPT":
                script_source, line_map = gen_line_map(read_until_closing_paren(lex_strings=True), source_line_no=line_no)

                try:
                    commands = compile_script(script_source)

                    write("{\n")
                    for command in commands:
                        if command.meta:
                            write(f"# {line_map[command.meta.line]} {file_info[0]}\n")
                        write("    ")
                        for word in command.to_bytecode():
                            if type(word) == str:
                                write(word)
                            elif type(word) == int:
                                write(f"0x{word & 0xFFFFFFFF:X}")
                            else:
                                raise Exception(f"uncompiled: {command}")
                            write(", ")
                        write("\n")
                    write("}")
                except exceptions.UnexpectedEOF as e:
                    eprint(f"{filename}:{line_no}: {ANSI_RED}error{ANSI_RESET}: unterminated SCRIPT(...) macro")
                    error = True
                except exceptions.UnexpectedCharacters as e:
                    eprint(e.line)
                    line = line_map[e.line]
                    char = script_source[e.pos_in_stream]
                    allowed = e.allowed

                    eprint(f"{filename}:{line}: {ANSI_RED}script parse error{ANSI_RESET}: unexpected `{char}', expected {' or '.join(allowed)}")
                    eprint(e.get_context(script_source))

                    error = True
                except exceptions.UnexpectedToken as e:
                    line = line_map[e.line]

                    eprint(f"{filename}:{line}: {ANSI_RED}script parse error{ANSI_RESET}: unexpected `{e.token}'")
                    eprint(e.get_context(script_source))

                    error = True
                except exceptions.VisitError as e:
                    if type(e.orig_exc) == CompileError:
                        line = line_map[e.orig_exc.meta.line]
                        eprint(f"{filename}:{line}: {ANSI_RED}script compile error{ANSI_RESET}: {e.orig_exc}")
                    else:
                        eprint(f"{filename}:{line_no}: {ANSI_RED}internal script compilation error{ANSI_RESET}")
                        traceback.print_exc()
                    error = True

                line_no += script_source.count("\n")
                write(f"\n# {line_no} {file_info[0]}\n")
            else:
                # leave non-macro in source
                write(macro_name + char)

            macro_name = ""
        elif char == "_" or (char >= 'A' and char <= 'Z'):
            macro_name += char
        else:
            write(macro_name + char)
            macro_name = ""

            if char == "\n":
                char_no = 0
                line_no += 1

        char_no += 1
        prev_char = char
