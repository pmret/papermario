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


def replace_move_addu(match):
    match = match.group()
    match = re.sub("\\s+", " ", match)
    match_split = match.split(" ")
    ret = "addu  " + match_split[1] + " " + match_split[2] + ", $zero"
    return ret


def replace_move_or(match):
    match = match.group()
    match = re.sub("\\s+", " ", match)
    match_split = match.split(" ")
    ret = "or    " + match_split[1] + " " + match_split[2] + ", $zero"
    return ret


adds = ["4a140", "4a1b0"]
ors = ["4a360"]

range_start = int("3bde0", 16)
range_end = int("48be0", 16)

for root, dirs, files in os.walk(asm_dir):
    for file in files:
        if file.endswith(".s"):
            dumb_split = file.split("_")
            if len(dumb_split) > 2:
                file_num = dumb_split[1]
                try:
                    test = int(file_num, 16)
                except ValueError:
                    file_num = ""
            else:
                file_num = ""
            with open(os.path.join(root, file)) as f:
                file_text_orig = f.read()
                file_text = file_text_orig

                # Fix instructions
                if file == "boot.s" or file_num in ors:
                    file_text = re.sub("move\\s+\\$.+,\\s\\$.+", replace_move_or, file_text)
                elif file_num != "" and ((range_start <= int(file_num, 16) <= range_end) or file_num in adds):
                    file_text = re.sub("move\\s+\\$.+,\\s\\$.+", replace_move_addu, file_text)
                else:
                    file_text = re.sub("move\\s+\\$.+,\\s\\$.+", replace_move_daddu, file_text)

                if file_text != file_text_orig:
                    with open(os.path.join(root, file), "w") as f:
                        f.write(file_text)
