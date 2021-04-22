#! /usr/bin/python3

from sys import argv, stdin, stderr
from lark import Lark, exceptions, Tree, Transformer, Visitor, v_args, Token
from lark.visitors import Discard
import traceback

DEBUG_OUTPUT = None # "debug.i"



def eprint(*args, **kwargs):
    print(*args, file=stderr, **kwargs)

#write_buf = ""
def write(s):
    #global write_buf
    #write_buf += s
    print(s, end="")

    if DEBUG_OUTPUT:
        print(s, file=DEBUG_OUTPUT, end="")

ANSI_RED = "\033[1;31;40m"
ANSI_RESET = "\u001b[0m"

def pairs(seq):
    i = iter(seq)
    prev = next(i)
    for item in i:
        yield prev, item
        prev = item

script_parser = Lark(r"""

    block: "{" (_block SEMICOLON*)? "}"

    _block: stmt SEMICOLON _block
          | stmt_no_semi SEMICOLON? _block
          | stmt SEMICOLON
          | stmt_no_semi

    ?stmt: call
         | var_decl
         | "goto" label         -> label_goto
         | "return"             -> return_stmt
         | "break"              -> break_stmt
         | "break match"        -> break_match_stmt
         | "break loop"         -> break_loop_stmt
         | "sleep" expr         -> sleep_stmt
         | "sleep" expr "secs"  -> sleep_secs_stmt
         | "spawn" expr         -> spawn_stmt
         | "await" expr         -> await_stmt
         | "jump" expr          -> jump_stmt
         | lhs "=" "spawn" expr -> spawn_set_stmt
         | lhs set_op expr      -> set_stmt
         | lhs set_op "f" expr  -> set_float_stmt
         | lhs set_op "c" expr  -> set_const_stmt
         | bind_stmt
         | bind_set_stmt
         | "unbind"             -> unbind_stmt
         | "group" expr         -> set_group
         | suspend_stmt
         | resume_stmt
         | kill_stmt

    ?stmt_no_semi: label ":" -> label_decl
                 | if_stmt
                 | match_stmt
                 | loop_stmt
                 | loop_until_stmt
                 | ["await"] block     -> block_stmt
                 | "spawn" block       -> spawn_block_stmt
                 | "parallel" block    -> parallel_block_stmt

    call: (c_identifier | HEX_INT) "(" [expr ("," expr)* [","]] ")"

    if_stmt: "if" "(" expr cond_op expr ")" block ["else" block]

    ?cond_op: "==" -> cond_op_eq
           | "!=" -> cond_op_ne
           | ">" -> cond_op_gt
           | "<" -> cond_op_lt
           | ">=" -> cond_op_ge
           | "<=" -> cond_op_le
           | "&" -> cond_op_flag
           | "!&" -> cond_op_not_flag

    match_stmt: "match" expr "{" (match_cases SEMICOLON*)? "}"
    match_const_stmt: "matchc" expr "{" (match_cases SEMICOLON*)? "}"
    match_cases: match_case SEMICOLON* match_cases
               | match_case
    ?match_case: "else" block -> case_else
               | cond_op expr ["," multi_case] block -> case_op
               | expr ".." expr ["," multi_case] block -> case_range
               | multi_case block -> case_multi
    multi_case: expr ("," expr)*

    suspend_stmt: "suspend" control_type expr ("," control_type expr)* [","]
    resume_stmt: "resume" control_type expr ("," control_type expr)* [","]
    kill_stmt: "kill" control_type expr ("," control_type expr)* [","]
    ?control_type: "group"    -> control_type_group
                 | "others"   -> control_type_others
                 | ["script"] -> control_type_script

    bind_stmt: "bind" expr "to" expr expr
    bind_set_stmt: lhs "=" "bind" expr "to" expr expr

    loop_stmt: "loop" [expr] block
    loop_until_stmt: "loop" block "until" "(" expr cond_op expr ")"

    var_decl: ("int"|"float") variable

    ?expr: c_const_expr
         | ESCAPED_STRING
         | SIGNED_INT
         | SIGNED_DECIMAL
         | HEX_INT
         | variable
         | c_identifier

    ?lhs: c_const_expr
        | variable

    ?set_op: "="  -> set_op_eq
           | "+=" -> set_op_add
           | "-=" -> set_op_sub
           | "*=" -> set_op_mul
           | "/=" -> set_op_div
           | "%=" -> set_op_mod
           | "&=" -> set_op_and
           | "|=" -> set_op_or

    variable: "$" CNAME

    c_identifier: CNAME

    c_const_expr: "(" c_const_expr_internal ")"
    c_const_expr_internal: "(" (c_const_expr_internal | NOT_PARENS)+ ")"
    NOT_PARENS: /[^()]+/

    SEMICOLON: ";"

    label: /[a-zA-Z0-9_]+/

    %import common.CNAME
    %import common.SIGNED_INT
    %import common.DECIMAL
    %import common.HEXDIGIT
    %import common.ESCAPED_STRING

    SIGNED_DECIMAL: ["+"|"-"] DECIMAL
    HEX_INT: ["+"|"-"] "0x" HEXDIGIT+

    LINE_COMMENT: "//" /[^\n]*/ NEWLINE
    %ignore LINE_COMMENT

    %import common.WS_INLINE
    %import common.NEWLINE
    %ignore WS_INLINE
    %ignore NEWLINE

""", start="block", propagate_positions=True)#, parser="lalr", cache=True)

class BaseCmd():
    def __init__(self, *args, **kwargs):
        self.args = args
        self.meta = kwargs.get("meta", None)
        self.context = [RootCtx()]

    def add_context(self, ctx):
        if not isinstance(ctx, CmdCtx):
            raise Exception()
        self.context.insert(0, ctx)

    # must be overloaded
    def opcode(self):
        raise Exception()

    def to_bytecode(self):
        return [ self.opcode(), len(self.args), *self.args ]

    def __str__(self):
        return f"Cmd({self.opcode()}, {', '.join(map(str, self.args))})"

class Cmd(BaseCmd):
    def __init__(self, opcode, *args, **kwargs):
        super().__init__(*args, **kwargs)
        self._opcode = opcode

    def opcode(self):
        return self._opcode

class BreakCmd(BaseCmd):
    def __init__(self, **kwargs):
        super().__init__(**kwargs)

    def opcode(self):
        for ctx in self.context:
            opcode = ctx.break_opcode(self.meta)
            if opcode:
                return opcode

    def __str__(self):
        return "BreakCmd"

class CmdCtx():
    def break_opcode(self, meta):
        pass

class RootCtx(CmdCtx):
    def break_opcode(self, meta):
        return "ScriptOpcode_END"

class IfCtx(CmdCtx):
    pass

class MatchCtx(CmdCtx):
    def break_opcode(self, meta):
        return "ScriptOpcode_BREAK_MATCH"

class LoopCtx(CmdCtx):
    def break_opcode(self, meta):
        return "ScriptOpcode_BREAK_LOOP"

class LoopUntilCtx(CmdCtx):
    def break_opcode(self, meta):
        raise CompileError("breaking out of a loop..until is not supported (hint: use a label)", meta)

class LabelCtx(CmdCtx):
    def __init__(self, label):
        super().__init__()
        self.label = label

    # TODO: implement break_opcode so you can do lbl: loop { break lbl }

class BlockCtx(CmdCtx):
    pass

class SpawnCtx(CmdCtx):
    pass

class ParallelCtx(CmdCtx):
    pass

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
        self.variables = []

    def label_decl(self, tree):
        name = tree.children[0].children[0]
        if name in self.labels:
            raise CompileError(f"label `{name}' already declared", tree.meta)

        try:
            label_idx = int(name)

            while len(self.labels) <= label_idx:
                self.labels.append(None)

            self.labels[label_idx] = name
        except ValueError:
            self.labels.append(name)

    def variable(self, tree):
        name = tree.children[0]

        if name not in self.variables:
            self.variables.append(name)

            if len(self.variables) > 16:
                raise CompileError("too many variables (max 16)", tree.meta)

    def gen_label(self):
        self.labels.append("$generated")
        return len(self.labels) - 1

@v_args(tree=True)
class Compile(Transformer):
    SIGNED_INT = str
    HEX_INT = str

    def transform(self, tree):
        self.alloc = LabelAllocation()
        self.alloc.visit_topdown(tree)
        return super().transform(tree)

    def c_identifier(self, tree):
        if "_" in tree.children[0] and tree.children[0].isupper():
            return f"{tree.children[0]}"
        return f"(Bytecode)(&{tree.children[0]})"

    def ESCAPED_STRING(self, str_with_quotes):
        return f"(Bytecode)({str_with_quotes})"

    NOT_PARENS = str
    def c_const_expr_internal(self, tree):
        return f"({' '.join(tree.children)})"
    def c_const_expr(self, tree):
        return f"(Bytecode){tree.children[0]}"

    def SIGNED_DECIMAL(self, v):
        # fixed-point
        return int((float(v) * 1024) - 230000000)

    def block(self, tree):
        # flatten children list
        flat = []
        for node in tree.children:
            if type(node) is list:
                flat += node
            elif isinstance(node, BaseCmd):
                flat.append(node)
            elif isinstance(node, Token) and (node.value.startswith("\n") or node.value == ";"):
                pass
            else:
                raise Exception(f"block statment {type(node)} is not a BaseCmd: {node}")
        return flat
    def _block(self, tree):
        if len(tree.children) == 1:
            return [tree.children[0]]
        else:
            return [tree.children[0], *tree.children[2]]

    def call(self, tree):
        # TODO: type checking etc
        return Cmd("ScriptOpcode_CALL", *tree.children, meta=tree.meta)

    def if_stmt(self, tree):
        if len(tree.children) == 4: # no else
            a, op, b, block = tree.children
            for cmd in block:
                if isinstance(cmd, BaseCmd):
                    cmd.add_context(IfCtx())
            return [ Cmd(op["if"], a, b, meta=tree.meta), *block, Cmd("ScriptOpcode_END_IF") ]
        else:
            a, op, b, block, else_block = tree.children
            for cmd in block:
                if isinstance(cmd, BaseCmd):
                    cmd.add_context(IfCtx())
            for cmd in else_block:
                if isinstance(cmd, BaseCmd):
                    cmd.add_context(IfCtx())
            return [ Cmd(op["if"], a, b, meta=tree.meta), *block, Cmd("ScriptOpcode_ELSE"), *else_block, Cmd("ScriptOpcode_END_IF") ]

    def cond_op_eq(self, tree): return { "if": "ScriptOpcode_IF_EQ", "case": "ScriptOpcode_CASE_EQ" }
    def cond_op_ne(self, tree): return { "if": "ScriptOpcode_IF_NE", "case": "ScriptOpcode_CASE_NE" }
    def cond_op_lt(self, tree): return { "if": "ScriptOpcode_IF_LT", "case": "ScriptOpcode_CASE_LT" }
    def cond_op_gt(self, tree): return { "if": "ScriptOpcode_IF_GT", "case": "ScriptOpcode_CASE_GT" }
    def cond_op_le(self, tree): return { "if": "ScriptOpcode_IF_LE", "case": "ScriptOpcode_CASE_LE" }
    def cond_op_ge(self, tree): return { "if": "ScriptOpcode_IF_GE", "case": "ScriptOpcode_CASE_GE" }
    def cond_op_flag(self, tree): return { "__op__": "&", "if": "ScriptOpcode_IF_FLAG", "case": "ScriptOpcode_CASE_FLAG" }
    def cond_op_not_flag(self, tree): return { "__op__": "!&", "if": "ScriptOpcode_IF_NOT_FLAG" }

    def match_stmt(self, tree):
        expr = tree.children[0]

        cases = []
        for node in tree.children[1:]:
            if type(node) is list:
                for el in node:
                    if type(el) is list:
                        cases += el
                    else:
                        cases.append(el)

        for cmd in cases:
            if isinstance(cmd, BaseCmd):
                cmd.add_context(MatchCtx())
            else:
                raise Exception(f"uncompiled match case: {cmd}")

        return [
            Cmd("ScriptOpcode_MATCH", expr, meta=tree.meta),
            *cases,
            Cmd("ScriptOpcode_END_MATCH"),
        ]
    def match_const_stmt(self, tree):
        commands = self.match_stmt(tree)
        commands[0].opcode = "ScriptOpcode_MATCH_CONST"
        return commands
    def match_cases(self, tree):
        if len(tree.children) == 1:
            return [tree.children[0]]
        else:
            return [tree.children[0], *tree.children[1]]

    def case_else(self, tree):
        return [Cmd("ScriptOpcode_CASE_ELSE"), *tree.children[0]]
    def case_op(self, tree):
        if len(tree.children) == 4:
            op, expr, multi_case, block = tree.children

            if not "case" in op:
                raise CompileError(f"operation `{opcodes['__op__']}' not supported in match cases", tree.meta)

            return [Cmd(op["case"], expr), *multi_case, *block, Cmd("ScriptOpcode_END_CASE_MULTI")]
        else:
            op, expr, block = tree.children

            if not "case" in op:
                raise CompileError(f"operation `{opcodes['__op__']}' not supported in match cases", tree.meta)

            return [Cmd(op["case"], expr), *block]
    def case_range(self, tree):
        if len(tree.children) == 4:
            a, b, multi_case, block = tree.children
            return [Cmd("ScriptOpcode_CASE_RANGE", a, b), *multi_case, *block, Cmd("ScriptOpcode_END_CASE_MULTI")]
        else:
            a, b, block = tree.children
            return [Cmd("ScriptOpcode_CASE_RANGE", a, b), *block]
    def case_multi(self, tree):
        multi_case, block = tree.children
        return [*multi_case, *block, Cmd("ScriptOpcode_END_CASE_MULTI")]

    def multi_case(self, tree):
        return [Cmd("ScriptOpcode_CASE_MULTI_OR_EQ", expr) for expr in tree.children]

    def loop_stmt(self, tree):
        expr = tree.children.pop(0) if len(tree.children) > 1 else 0
        block = tree.children[0]

        for cmd in block:
            if isinstance(cmd, BaseCmd):
                cmd.add_context(LoopCtx())

        return [ Cmd("ScriptOpcode_LOOP", expr, meta=tree.meta), *block, Cmd("ScriptOpcode_END_LOOP") ]

    # loop..until pseudoinstruction
    def loop_until_stmt(self, tree):
        block, a, op, b = tree.children

        for cmd in block:
            if isinstance(cmd, BaseCmd):
                cmd.add_context(LoopUntilCtx())

        label = self.alloc.gen_label()

        return [
            Cmd("ScriptOpcode_LABEL", label, meta=tree.meta),
            *block,
            Cmd(op["if"], a, b, meta=tree.meta),
            Cmd("ScriptOpcode_GOTO", label, meta=tree.meta),
            Cmd("ScriptOpcode_END_IF", meta=tree.meta),
        ]

    def return_stmt(self, tree):
        return Cmd("ScriptOpcode_RETURN", meta=tree.meta)

    def break_stmt(self, tree):
        return BreakCmd(meta=tree.meta)

    def break_match_stmt(self, tree):
        return Cmd("ScriptOpcode_BREAK_MATCH", meta=tree.meta)

    def break_loop_stmt(self, tree):
        return Cmd("ScriptOpcode_BREAK_LOOP", meta=tree.meta)

    def set_group(self, tree):
        return Cmd("ScriptOpcode_SET_GROUP", tree.children[0], meta=tree.meta)

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
            "suspend": "ScriptOpcode_SUSPEND_GROUP",
            "resume": "ScriptOpcode_RESUME_GROUP",
        }
    def control_type_others(self, tree):
        return {
            "__control_type__": "others",
            "suspend": "ScriptOpcode_SUSPEND_OTHERS",
            "resume": "ScriptOpcode_RESUME_OTHERS",
        }
    def control_type_script(self, tree):
        return {
            "__control_type__": "script",
            "suspend": "ScriptOpcode_SUSPEND_SCRIPT",
            "resume": "ScriptOpcode_RESUME_SCRIPT",
            "kill": "ScriptOpcode_KILL_SCRIPT",
        }

    def sleep_stmt(self, tree):
        return Cmd("ScriptOpcode_SLEEP_FRAMES", tree.children[0], meta=tree.meta)
    def sleep_secs_stmt(self, tree):
        return Cmd("ScriptOpcode_SLEEP_SECS", tree.children[0], meta=tree.meta)

    def bind_stmt(self, tree):
        script, trigger, target = tree.children
        return Cmd("ScriptOpcode_BIND_TRIGGER", script, trigger, target, 1, 0, meta=tree.meta)
    def bind_set_stmt(self, tree):
        ret, script, trigger, target = tree.children
        return Cmd("ScriptOpcode_BIND_TRIGGER", script, trigger, target, 1, ret, meta=tree.meta)
    def unbind_stmt(self, tree):
        return Cmd("ScriptOpcode_UNBIND", meta=tree.meta)

    def spawn_stmt(self, tree):
        return Cmd("ScriptOpcode_SPAWN_SCRIPT", tree.children[0], meta=tree.meta)
    def spawn_set_stmt(self, tree):
        lhs, script = tree.children
        return Cmd("ScriptOpcode_SPAWN_GET_ID", script, lhs, meta=tree.meta)
    def await_stmt(self, tree):
        return Cmd("ScriptOpcode_AWAIT_SCRIPT", tree.children[0], meta=tree.meta)
    def jump_stmt(self, tree):
        return Cmd("ScriptOpcode_JUMP", tree.children[0], meta=tree.meta)

    def set_stmt(self, tree):
        lhs, opcodes, rhs = tree.children
        if is_fixed_var(rhs):
            opcode = opcodes.get("float", None)
            if not opcode:
                raise CompileError(f"float operation `{opcodes['__op__']}' not supported", tree.meta)
        else:
            opcode = opcodes.get("int", None)
            if not opcode:
                raise CompileError(f"int operation `{opcodes['__op__']}' not supported", tree.meta)
        return Cmd(opcode, lhs, rhs)
    def set_float_stmt(self, tree):
        lhs, opcodes, rhs = tree.children
        opcode = opcodes.get("float", None)
        if not opcode:
            raise CompileError(f"float operation `{opcodes['__op__']}' not supported", tree.meta)
        return Cmd(opcode, lhs, rhs)
    def set_const_stmt(self, tree):
        lhs, opcodes, rhs = tree.children
        opcode = opcodes.get("const", None)
        if not opcode:
            raise CompileError(f"const operation `{opcodes['__op__']}' not supported", tree.meta)
        return Cmd(opcode, lhs, rhs)
    def set_op_eq(self, tree):
        return {
            "__op__": "=",
            "int": "ScriptOpcode_SET",
            "const": "ScriptOpcode_SET_CONST",
            "float": "ScriptOpcode_SET_F",
        }
    def set_op_add(self, tree):
        return {
            "__op__": "+",
            "int": "ScriptOpcode_ADD",
            "float": "ScriptOpcode_ADD_F",
        }
    def set_op_sub(self, tree):
        return {
            "__op__": "-",
            "int": "ScriptOpcode_SUB",
            "float": "ScriptOpcode_SUB_F",
        }
    def set_op_mul(self, tree):
        return {
            "__op__": "*",
            "int": "ScriptOpcode_MUL",
            "float": "ScriptOpcode_MUL_F",
        }
    def set_op_div(self, tree):
        return {
            "__op__": "/",
            "int": "ScriptOpcode_DIV",
            "float": "ScriptOpcode_DIV_F",
        }
    def set_op_mod(self, tree):
        return {
            "__op__": "%",
            "int": "ScriptOpcode_MOD",
        }
    def set_op_and(self, tree):
        return {
            "__op__": "&",
            "int": "ScriptOpcode_AND",
            "const": "ScriptOpcode_AND_CONST",
        }
    def set_op_or(self, tree):
        return {
            "__op__": "|",
            "int": "ScriptOpcode_OR",
            "const": "ScriptOpcode_OR_CONST",
        }

    def variable(self, tree):
        name = tree.children[0]
        return self.alloc.variables.index(name) - 30000000

    def var_decl(self, tree):
        return []

    def label_decl(self, tree):
        if len(tree.children) == 1:
            label = tree.children[0]
            return Cmd("ScriptOpcode_LABEL", label, meta=tree.meta)
        else:
            label, cmd_or_block = tree.children

            if type(cmd_or_block) is not list:
                cmd_or_block = [cmd_or_block]

            for cmd in cmd_or_block:
                if isinstance(cmd, BaseCmd):
                    cmd.add_context(LabelCtx(label))

            return [
                Cmd("ScriptOpcode_LABEL", label, meta=tree.meta),
                *cmd_or_block
            ]
    def label_goto(self, tree):
        label = tree.children[0]
        return Cmd("ScriptOpcode_GOTO", label, meta=tree.meta)
    def label(self, tree):
        name = tree.children[0]
        if name in self.alloc.labels:
            return self.alloc.labels.index(name)
        raise CompileError(f"label `{name}' is undeclared", tree.meta)

    def block_stmt(self, tree):
        block, = tree.children
        for cmd in block:
            if isinstance(cmd, BaseCmd):
                cmd.add_context(BlockCtx())
        return block
    def spawn_block_stmt(self, tree):
        block, = tree.children
        for cmd in block:
            if isinstance(cmd, BaseCmd):
                cmd.add_context(SpawnCtx())
        return [ Cmd("ScriptOpcode_SPAWN_THREAD", meta=tree.meta), *block, Cmd("ScriptOpcode_END_SPAWN_THREAD") ]
    def parallel_block_stmt(self, tree):
        block, = tree.children
        for cmd in block:
            if isinstance(cmd, BaseCmd):
                cmd.add_context(ParallelCtx())
        return [ Cmd("ScriptOpcode_PARALLEL_THREAD", meta=tree.meta), *block, Cmd("ScriptOpcode_END_PARALLEL_THREAD") ]

def compile_script(s):
    tree = script_parser.parse(s)

    #eprint(tree.pretty())

    commands = Compile().transform(tree)

    # add RETURN END if no explicit END (top-level `break') was given
    if next((cmd for cmd in commands if cmd.opcode() == "ScriptOpcode_END"), None) == None:
        commands += (Cmd("ScriptOpcode_RETURN"), Cmd("ScriptOpcode_END"))

    return commands

def read_until_closing_paren(f, depth=1, lex_strings=False):
    text = ""

    in_string = False
    string_escape = False

    while True:
        char = f.read(1)

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

def read_line(f):
    line = ""

    while True:
        char = f.read(1)

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

# Expects output from C preprocessor on argv
SINGLE_FILE = False
import sys

if __name__ == "__main__":
    if DEBUG_OUTPUT is not None:
        DEBUG_OUTPUT = open(DEBUG_OUTPUT, "w")
        '''
        while char := stdin.read(1):
            DEBUG_OUTPUT.write(char)
        exit()
        '''

    in_file = stdin
    if SINGLE_FILE:
        in_file = open(sys.argv[1], "r")

    line_no = 1
    char_no = 1
    file_info = []
    error = False

    macro_name = "" # captures recent UPPER_CASE identifier
    prev_char = ""
    while not error:
        char = in_file.read(1)

        if len(char) == 0:
            # EOF
            write(macro_name)
            break

        if char == "#" and (prev_char == "\n" or prev_char == ""):
            # cpp line/file marker
            line = read_line(in_file)
            line_split = line[1:].split(" ")

            line_no = int(line_split[0])
            file_info = line_split[1:]

            write("#" + line + "\n")
        elif char == "(":
            if SINGLE_FILE:
                filename = sys.argv[1]
            else:
                filename = file_info[0][1:-1]

            # SCRIPT(...)
            if macro_name == "SCRIPT":
                read_data = read_until_closing_paren(in_file, lex_strings=True)
                script_source, line_map = gen_line_map(read_data, source_line_no=line_no)

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
                                raise Exception(f"{command}.to_bytecode() gave {type(word)} {word}")
                            write(", ")
                        write("\n")
                    write("}")
                except exceptions.UnexpectedEOF as e:
                    eprint(f"{filename}:{line_no}: {ANSI_RED}error{ANSI_RESET}: unterminated SCRIPT(...) macro")
                    error = True
                except exceptions.UnexpectedCharacters as e:
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
                        eprint(f"{filename}:{line_no}: {ANSI_RED}internal script transform error{ANSI_RESET}")
                        traceback.print_exc()
                    error = True
                except CompileError as e:
                    line = line_map[e.meta.line]
                    eprint(f"{filename}:{line}: {ANSI_RED}script compile error{ANSI_RESET}: {e}")
                    error = True
                except Exception as e:
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

    if error:
        write("{ 1 / 0 };")
        exit(1)
    else:
        exit(0)
