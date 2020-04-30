#!/usr/bin/python3

import os
import re

script_dir = os.path.dirname(os.path.realpath(__file__))
asm_dir = script_dir + "/../asm/"

js = set()
jals = set()
bs = set()
bals = set()


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
    for i, line in enumerate(file_lines):
        line = line.strip()
        if cur_fun is None:
            if line.endswith(":"):
                cur_fun = line[:-1]
                continue
        else:
            if re.findall(r'jr\s+\$..', line):
                cur_fun = None
                continue
            if line.endswith(":") and not line.startswith(".L"):
                linked_to = False
                bogus_label = line[:-1]
                print("Found dubious func: " + bogus_label)
                if bogus_label in jals or bogus_label in bals:
                    linked_to = True
                    print("\t in jal/bal instruction - eek!")
                if bogus_label in js or bogus_label in bs:
                    linked_to = True
                    print("\t in j/b instruction - change to label")
                if not linked_to:
                    print(" not referenced anywhere")


# Collect all branches and jumps
for root, dirs, files in os.walk(asm_dir):
    for file in files:
        if file.endswith(".s"):
            scan_file(os.path.join(root, file))
            dog = 5

print("Scanned all files")

# Process files
for root, dirs, files in os.walk(asm_dir):
    for file in files:
        if file.endswith(".s") and "giant" not in file:
            process_file(os.path.join(root, file))
            dog = 5
