#! /usr/bin/python3

import sys
from compile_script import read_until_closing_paren

def read_scripts_in_file(in_file):
    line_no = 1

    macro_name = "" # captures recent UPPER_CASE identifier
    prev_char = ""
    while True:
        char = in_file.read(1)

        if len(char) == 0:
            # EOF
            break

        if char == "#" and (prev_char == "\n" or prev_char == ""):
            pass
        elif char == "(":
            # SCRIPT(...)
            if macro_name == "SCRIPT":
                pos_before = in_file.tell()
                read_data = read_until_closing_paren(in_file, lex_strings=True)
                line_no += read_data.count("\n")
                assert read_data[0] == '{'
                yield pos_before, in_file.tell(), read_data

            macro_name = ""
        elif char == "_" or (char >= 'A' and char <= 'Z'):
            macro_name += char
        else:
            macro_name = ""

        if char == "\n":
            line_no += 1

        prev_char = char

def process_script(script):
    # TODO
    return script

def process_file(filename):
    with open(filename, "r") as f:
        scripts = [k for k in read_scripts_in_file(f)]
        f.seek(0)
        file_content = f.read()

    pos_delta = 0

    for start_pos, end_pos, script in scripts:
        start_pos = start_pos - pos_delta
        end_pos = end_pos - pos_delta

        script_len_before = len(script)
        script = process_script(script)
        script_len_after = len(script)

        pos_delta += script_len_before - script_len_after

        file_content = file_content[:start_pos] + script + file_content[end_pos-1:]

    with open(filename, "w") as f:
        f.write(file_content)

if __name__ == "__main__":
    for filename in sys.argv[1:]:
        process_file(filename)
