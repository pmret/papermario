#!/usr/bin/env python3

import argparse
import os
import re
from pathlib import Path
from unicodedata import name

script_dir = os.path.dirname(os.path.realpath(__file__))
root_dir = script_dir + "/../"
src_dir = root_dir + "src/"
asm_dir = root_dir + "ver/current/asm/"

parser = argparse.ArgumentParser(description="Replace many functions with one")
parser.add_argument(
    "from_list",
    help="path to line-separated file of functions to be replaced. first line is the string to replace them with",
)

args = parser.parse_args()

from_funcs = []

with open(args.from_list) as f:
    from_text = f.readlines()

to_line = """
extern s32 N(ItemChoice_HasSelectedItem);
extern s32 N(ItemChoice_SelectedItemID);

ApiStatus N(ItemChoice_SaveSelected)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    N(ItemChoice_SelectedItemID) = evt_get_variable(script, *args++);
    N(ItemChoice_HasSelectedItem) = TRUE;
    return ApiStatus_DONE2;
}
"""
func_name = "ItemChoice_SaveSelected"

for from_line in from_text:
    if len(from_line.strip()) > 0:
        from_funcs.append(from_line.rstrip().split(" ")[-1])

for root, dirs, files in os.walk(src_dir):
    for f_name in files:
        if f_name.endswith(".c"):
            f_path = os.path.join(root, f_name)
            with open(f_path) as f:
                f_text_orig = f.read()

            f_text = f_text_orig
            for func in from_funcs:
                search_pattern = re.compile("\n.*" + func + "\).*\n")
                f_text = re.sub(search_pattern, to_line, f_text)
            if f_text != f_text_orig:
                with open(f_path, "w", newline="\n") as f:
                    f.write(f_text)

# # Rename symbols in from_funcs to namespace equivalents
# for root, dirs, files in os.walk

to_replace = []

for root, dirs, files in os.walk(asm_dir):
    for f_name in files:
        if f_name.endswith(".s"):
            f_path = os.path.join(root, f_name)
            with open(f_path) as f:
                f_text_orig = f.read()

            f_text = f_text_orig

            namespace = Path(f_path).parent.name
            non_matching = "nonmatchings" in str(Path(f_path))

            if non_matching:
                namespace = Path(f_path).parent.name
                if "world" not in str(Path(f_path)):
                    namespace = Path(f_path).parent.name

            namespace = "dead_" + namespace

            for func in from_funcs:
                f_text = f_text.replace(func, namespace + "_" + func_name)
            if f_text != f_text_orig:
                if non_matching:
                    syms = sorted(set(re.findall(r"D_[0-9A-F]{8}_[0-9A-F]{6}", f_text)))
                    to_replace.append(syms[0] + " " + namespace + "_ItemChoice_HasSelectedItem\n")
                    to_replace.append(syms[1] + " " + namespace + "_ItemChoice_SelectedItemID\n")

                with open(f_path, "w", newline="\n") as f:
                    f.write(f_text)

with open("to_rename.txt", "w") as f:
    f.writelines(to_replace)
