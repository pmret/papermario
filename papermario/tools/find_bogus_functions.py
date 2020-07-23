#!/usr/bin/python3

import os
import re

script_dir = os.path.dirname(os.path.realpath(__file__))
asm_dir = script_dir + "/../asm/"

js = set()
jals = set()
bs = set()
bals = set()

debug = False

renames = []


def dprint(string):
    if debug:
        print(string)


def scan_file(path):
    with open(path) as f:
        file_lines = f.readlines()

    for line in file_lines:
        line = line.strip()
        if re.findall(r'\sj\s+.*', line):
            target = line.split()[-1]
            js.add(target)
        if re.findall(r'\sjal\s+.*', line):
            target = line.split()[-1]
            jals.add(target)
        if re.findall(r'\sb.*', line):
            target = line.split()[-1]
            bs.add(target)
        if re.findall(r'\sbal\s+.*', line):
            target = line.split()[-1]
            bals.add(target)


def get_linked_flags(label):
    return (label in js or label in bs), (label in jals or label in bals)


def process_file(path):
    print("Processing " + path)
    with open(path) as fi:
        file_lines = fi.readlines()

    skip_next = False
    to_delete = []
    for i, line in enumerate(file_lines):
        if skip_next:
            skip_next = False
            continue
        line = line.strip()

        if line.endswith(":") and not line.startswith(".L"):
            func_preamble = line.startswith("func_")
            label = line[:-1]
            linked_to, linked_al_to = get_linked_flags(label)

            if func_preamble:
                # func_12345689

                # Delete redundant label below
                # if file_lines[i + 1].strip() == ".L" + label[5:13] + ":":
                #     to_delete.append(i + 1)
                #     skip_next = True

                if linked_al_to:
                    # Seems to be legit. Do nothing for now
                    continue
                elif linked_to:
                    # j / b 'd to, rename as label
                    renames.append((label, ".L" + label[5:]))
                else:
                    # Not referenced by anything. Delete
                    to_delete.append(i)

    if len(to_delete) > 0:
        print("\tDeleting " + str(len(to_delete)) + " lines...")
        for i in reversed(to_delete):
            del file_lines[i]
        with open(path, "w") as fo:
            fo.writelines(file_lines)


# Collect all branches and jumps
for root, dirs, files in os.walk(asm_dir):
    for file in files:
        if file.endswith(".s"):
            scan_file(os.path.join(root, file))

print("Scanned all files")

# Process files
for root, dirs, files in os.walk(asm_dir):
    for file in files:
        if file.endswith(".s") and "boot" not in file:
            process_file(os.path.join(root, file))

if len(renames) > 0:
    print("Renaming " + str(len(renames)) + " labels...")
    for root, dirs, files in os.walk(asm_dir):
        for file in files:
            if file.endswith(".s"):
                file_path = os.path.join(root, file)
                with open(file_path) as f:
                    orig_file_text = f.read()
                file_text = orig_file_text
                for rename in renames:
                    file_text = file_text.replace(rename[0], rename[1])
                if file_text != orig_file_text:
                    with open(file_path, "w") as f:
                        f.write(file_text)
