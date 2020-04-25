#!/usr/bin/python3

import os
import re

script_dir = os.path.dirname(os.path.realpath(__file__))
asm_dir = script_dir + "/asm/"


def replace_move_daddu(match):
    match = match.group()
    match = re.sub("\\s+", " ", match)
    match_split = match.split(" ")
    ret = "daddu " + match_split[1] + " " + match_split[2] + ", $zero"
    return ret


def replace_move_or(match):
    match = match.group()
    match = re.sub("\\s+", " ", match)
    match_split = match.split(" ")
    ret = "or    " + match_split[1] + " " + match_split[2] + ", $zero"
    return ret


for root, dirs, files in os.walk(asm_dir):
    for file in files:
        if file.endswith(".s"):
            with open(os.path.join(root, file)) as f:
                file_text_orig = f.read()
                file_text = file_text_orig

                # Fix instructions
                if file == "boot.s":
                    file_text = re.sub("move\\s+\\$.+,\\s\\$.+", replace_move_or, file_text)
                else:
                    file_text = re.sub("move\\s+\\$.+,\\s\\$.+", replace_move_daddu, file_text)

                if file_text != file_text_orig:
                    with open(os.path.join(root, file), "w") as f:
                        f.write(file_text)
