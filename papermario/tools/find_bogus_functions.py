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
        if re.findall(r'\sb\s+.*', line):
            target = line.split()[-1]
            bs.add(target)
        if re.findall(r'\sbal\s+.*', line):
            target = line.split()[-1]
            bals.add(target)


def process_file(path):
    print("Processing " + path)
    with open(path) as f:
        file_lines = f.readlines()

    cur_fun = None
    to_delete = []
    for i, line in enumerate(file_lines):
        line = line.strip()
        if cur_fun is None:
            if line.endswith(":") and not line.startswith(".L"):
                cur_fun = line[:-1]
                continue
        else:
            if re.findall(r'jr\s+\$..', line):
                cur_fun = None
                continue
            if line.endswith(":") and not line.startswith(".L"):
                linked_to = False
                linked_al_to = False
                func_preamble = line.startswith("func_")
                bogus_label = line[:-1]
                # print("Found dubious func: " + bogus_label)
                if bogus_label in jals or bogus_label in bals:
                    linked_al_to = True
                    dprint("\t in jal/bal instruction - eek!")
                if bogus_label in js or bogus_label in bs:
                    linked_to = True
                    dprint("\t in j/b instruction - change to label")
                if not linked_to:
                    dprint(" not referenced anywhere")

                if func_preamble:
                    # func_12345689
                    if linked_al_to:
                        # Seems to be legit. Do nothing for now
                        dog = 5
                    elif linked_to:
                        # j / b 'd to, rename as label
                        renames.append((bogus_label, ".L" + bogus_label[5:]))
                    else:
                        # Not referenced by anything. Delete
                        to_delete.append(i)

    if len(to_delete) > 0:
        dog = 5


# Collect all branches and jumps
for root, dirs, files in os.walk(asm_dir):
    for file in files:
        if file.endswith(".s"):
            scan_file(os.path.join(root, file))

print("Scanned all files")

# Process files
for root, dirs, files in os.walk(asm_dir):
    for file in files:
        if file.endswith(".s"):
            process_file(os.path.join(root, file))

if len(renames) > 0:
    print("Renaming " + str(len(renames)) + " labels...")
    for root, dirs, files in os.walk(asm_dir):
        for file in files:
            if file.endswith(".s") and "giant" not in file:
                file_path = os.path.join(root, file)
                with open(file_path) as f:
                    orig_file_text = f.read()
                file_text = orig_file_text
                for rename in renames:
                    file_text = file_text.replace(rename[0], rename[1])
                if file_text != orig_file_text:
                    with open(file_path, "w") as f:
                        f.write(file_text)
