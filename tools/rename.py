#!/usr/bin/env python3

import os
from tqdm import tqdm

import ahocorasick_rs
from ahocorasick_rs import *

script_dir = os.path.dirname(os.path.realpath(__file__))
root_dir = os.path.join(script_dir, "..")
src_dir = os.path.join(root_dir, "src")
include_dir = os.path.join(root_dir, "include")
asm_dir = os.path.join(root_dir, "ver", "us", "asm")

renames = {}
patterns = []
deletes = []


def handle_file(f_path, try_rename_file=False):
    with open(f_path) as f:
        f_text_orig = f.read()

    if try_rename_file:
        extless = f_path.split("/")[-1][:-2]
        if extless in renames:
            deletes.append(f_path)
            f_path = f_path.replace(extless, renames[extless])

    # find all matches in one pass with aho-corasick algorithm
    f_text = f_text_orig
    matches = ac.find_matches_as_indexes(f_text)
    if matches:
        to_join = []
        pos = 0
        # replace all matches
        for match in matches:
            # head part
            to_join.append(f_text[pos : match[1]])
            to_replace = patterns[match[0]]
            to_join.append(renames[to_replace])
            pos = match[2]
        # tail part
        to_join.append(f_text[pos:])
        f_text = "".join(to_join)
        # save changes
        with open(f_path, "w", newline="\n") as f:
            f.write(f_text)


# Read input file
# One valid whitespace-separated find-replace pair is given per line
with open(os.path.join(script_dir, "to_rename.txt")) as f:
    renames_text = f.readlines()

# Create dict of old -> new names
for line in renames_text:
    split = line.split()
    if len(split) == 2:
        if split[0] and split[1]:
            renames[split[0]] = split[1]
            patterns.append(split[0])
    elif len(split) != 0:
        raise Exception('input contains invalid rename pattern: \n"' + line.strip() + '"')

ac = ahocorasick_rs.AhoCorasick(patterns, matchkind=MATCHKIND_LEFTMOST_LONGEST)

# Walk through asm files and rename stuff
print("Walking through asm files")
asm_files = []
for root, dirs, files in os.walk(asm_dir):
    for f_name in files:
        asm_files.append(os.path.join(root, f_name))
for f_path in tqdm(asm_files):
    if f_path.endswith(".s"):
        handle_file(f_path, True)

# Walk through src files and rename stuff
print("Walking through src files")
c_files = []
for root, dirs, files in os.walk(src_dir):
    for f_name in files:
        c_files.append(os.path.join(root, f_name))
for f_path in tqdm(c_files):
    if f_name.endswith(".c") or f_name.endswith(".h"):
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
