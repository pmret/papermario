#!/usr/bin/python3

import os

script_dir = os.path.dirname(os.path.realpath(__file__))
root_dir = script_dir + "/../"
src_dir = root_dir + "src/"
asm_dir = root_dir + "ver/current/asm/"

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
        f_text = f_text.replace(rename, renames[rename])

    if f_text != f_text_orig:
        with open(f_path, "w", newline="\n") as f:
            f.write(f_text)


# Read Star Rod's output file
with open(os.path.join(script_dir, "to_rename.txt")) as f:
    renames_text = f.readlines()

# Create dict of old -> new names
for line in renames_text:
    split = line.split()
    renames[split[0]] = split[1]

# Walk through asm files and rename stuff
print("Walking through asm files")
for root, dirs, files in os.walk(asm_dir):
    for f_name in files:
        if f_name.endswith(".s"):
            f_path = os.path.join(root, f_name)

            handle_file(f_path, True)

# Delete old names of renamed asm files
print("Deleting old asm files")
for d in deletes:
    os.remove(d)

# Walk through src files and rename stuff
print("Walking through src files")
for root, dirs, files in os.walk(src_dir):
    for f_name in files:
        if f_name.endswith(".c") or f_name.endswith(".h"):
            f_path = os.path.join(root, f_name)

            handle_file(f_path)

# Walk through include files and rename stuff
print("Walking through include files")
for root, dirs, files in os.walk(os.path.join(root_dir, "include")):
    for f_name in files:
        f_path = os.path.join(root, f_name)

        handle_file(f_path)

# Rename stuff in symbol_addrs.txt
handle_file(os.path.join(root_dir, "ver", "current", "symbol_addrs.txt"))

