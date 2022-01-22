#!/usr/bin/python3

import os
import re
from tqdm import tqdm

script_dir = os.path.dirname(os.path.realpath(__file__))
root_dir = os.path.join(script_dir, "..")
src_dir = os.path.join(root_dir, "src")
include_dir = os.path.join(root_dir, "include")
asm_dir = os.path.join(root_dir, "ver", "us", "asm")

renames = {}
deletes = []

def handle_file(f_path, try_rename_file=False):
    with open(f_path) as f:
        f_text_orig = f.read()

    if try_rename_file:
        extless = f_path.split("/")[-1][:-2]
        if extless in renames:
            deletes.append(f_path)
            f_path = f_path.replace(extless, renames[extless])

    f_text = f_text_orig
    for rename in renames:
        if "(" in rename or "," in rename:
            f_text = f_text.replace(rename, renames[rename])
        else:
            f_text = re.sub(r"(?:\b)" + re.escape(rename) + r"(?:\b)", renames[rename], f_text)

    with open(f_path, "w", newline="\n") as f:
        f.write(f_text)


# Read Star Rod's output file (one rename per line, old and new, delimited by a space)
with open(os.path.join(script_dir, "to_rename.txt")) as f:
    renames_text = f.readlines()

# Create dict of old -> new names
for line in renames_text:
    split = line.split()
    renames[split[0]] = split[1]

# Walk through asm files and rename stuff
print("Walking through asm files")
asm_files = []
for root, dirs, files in os.walk(asm_dir):
    for f_name in files:
        asm_files.append(f_name)
for f_name in tqdm(asm_files):
    if f_name.endswith(".s"):
        f_path = os.path.join(root, f_name)

        handle_file(f_path, True)

# Walk through src files and rename stuff
print("Walking through src files")
for root, dirs, files in os.walk(src_dir):
    for f_name in files:
        if f_name.endswith(".c") or f_name.endswith(".h"):
            f_path = os.path.join(root, f_name)

            handle_file(f_path, True)

# Walk through include files and rename stuff
print("Walking through include files")
for root, dirs, files in os.walk(include_dir):
    for f_name in files:
        f_path = os.path.join(root, f_name)

        handle_file(f_path)

# Delete old versions of newly saved files
print("Deleting old files")
for d in deletes:
    os.remove(d)

# Walk through asm dirs and rename stuff
print("Walking through asm dirs")
for root, dirs, files in os.walk(asm_dir):
    for dir_name in dirs:
        for rename in renames:
            if rename == dir_name:
                os.rename(os.path.join(root, dir_name), os.path.join(root, renames[rename]))

# Rename stuff in symbol_addrs.txt
handle_file(os.path.join(root_dir, "ver", "current", "symbol_addrs.txt"))

# splat.yaml
handle_file(os.path.join(root_dir, "ver", "current", "splat.yaml"))

# effects.yaml
handle_file(os.path.join(root_dir, "ver", "current", "effects.yaml"))
