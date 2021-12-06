#!/usr/bin/python3

import sys

with open(sys.argv[1]) as f:
    lines = f.readlines()

    label = None
    bytes = []
    words = []

    def print_data():
        if label:
            if len(words) != 0:
                join = ", ".join(words)
                typedef = "s32"
            else:
                join = ", ".join(bytes)
                typedef = "s8"
            print(f"{typedef} {label}[] = {{ {join} }};")

    for line in lines:
        line = line.strip()

        if line.startswith("dlabel "):
            print_data()
            label = line.split(" ")[-1]
            words = []
            bytes = []
        elif line.startswith(".word "):
            words += line[6:].split(", ")
        elif line.startswith(".byte "):
            bytes += line[6:].split(", ")

    print_data()
