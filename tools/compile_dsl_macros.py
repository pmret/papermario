#! /usr/bin/python3

from sys import stdin, stderr
from lark import Lark, exceptions, Transformer, v_args

def eprint(*args, **kwargs):
    print(*args, file=stderr, **kwargs)

"""
write_buf = ""
def write(s):
    global write_buf
    write_buf += s
def flush():
    global write_buf
    print(write_buf, end="")
    write_buf = ""
"""
def write(s):
    print(s, end="")
def flush():
    pass
#"""

script_parser = Lark(r"""

    block: "{" line* "}"

    ?line: call
         | if_stmt
         | "return"        -> return_stmt
         | "setgroup" expr -> setgroup

    call: CNAME "(" [expr ("," expr)* [","]] ")"

    if_stmt: "if" expr if_op expr block ["else" block]

    ?if_op: "==" -> if_op_eq

    ?expr: c_const_expr
         | ESCAPED_STRING
         | SIGNED_INT
         | DECIMAL
         | HEX_INT
         | CNAME

    c_const_expr: "(" (c_const_expr | NOT_PARENS)+ ")"
    NOT_PARENS: /[^()]+/

    %import common.CNAME
    %import common.SIGNED_INT
    %import common.DECIMAL
    %import common.HEXDIGIT
    %import common.ESCAPED_STRING

    HEX_INT: ["+"|"-"] "0x" HEXDIGIT+

    LINE_COMMENT: "//" /[^\n]*/ NEWLINE
    %ignore LINE_COMMENT

    %import common.WS
    %import common.NEWLINE
    %ignore WS

""", start="block")#, parser="lalr", cache=True)

def si_cmd(opcode, *args):
    return [opcode, len(args), *args]

@v_args(inline=True)
class Compile(Transformer):
    SIGNED_INT = str
    DECIMAL = float # TODO: fixed
    HEX_INT = str
    ESCAPED_STRING = eval

    def CNAME(self, name):
        return f"(Bytecode)({name})"

    NOT_PARENS = str
    def c_const_expr(self, *args): # usually a macro expansion
        return f"(Bytecode)({' '.join(args)})"

    def block(self, *lines):
        flat = []
        for line in lines:
            if type(line) != list:
                eprint(f"uncompiled: {line}")
            else:
                flat += line
        return flat

    def call(self, func, *args):
        # TODO: type checking etc
        return si_cmd(0x43, func, *args)

    def if_stmt(self, a, op, b, block):
        return si_cmd(op, a, b) + block + si_cmd(0x13)
    def if_op_eq(self): return 0x0A

    def return_stmt(self): return si_cmd(0x02)

    def setgroup(self, group):
        return si_cmd(0x4D, group)

def compile_script(s):
    tree = script_parser.parse(s)
    #eprint(tree.pretty())
    return Compile().transform(tree) + si_cmd(0x02) + si_cmd(0x01)

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
                #with open("debug.i", "w") as i:
                #    i.write(write_buf)
                flush()
                exit(0)

        if char == "#" and (prev_char == "\n" or prev_char == ""):
            # cpp line/file marker
            line = read_line()
            line_split = line[1:].split(" ")

            line_no = int(line_split[0])
            file_info = line_split[1:]

            write("#" + line + "\n")
        elif char == "(":
            # SCRIPT(...)
            if macro_name == "SCRIPT":
                script_source = read_until_closing_paren(lex_strings=True)

                try:
                    bytecode = compile_script(script_source)

                    write("{")
                    for word in bytecode:
                        write(f"{word},")
                    write("}")
                except exceptions.UnexpectedToken as e:
                    line = e.line + line_no
                    filename = file_info[0][1:-1]

                    eprint(e.get_context(script_source))
                    eprint(f"{filename}:{line}: script parse error: unexpected `{e.token}'")

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
