#!/usr/bin/python3

import sys

with open(sys.argv[1]) as f:
    lines = f.readlines()

    label = None
    words = []

    def print_words():
        words_join = ", ".join(words)
        print(f"s32 {label}[] = {{ {words_join} }};")

    for line in lines:
        line = line.strip()

        if line.startswith("dlabel "):
            print_words()
            label = line.split(" ")[-1]
            words = []
        elif line.startswith(".word "):
            words += line[7:].split(", ")
