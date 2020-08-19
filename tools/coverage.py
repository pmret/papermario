#!/usr/bin/env python3

from os import path
from os import remove
from sys import argv
import re
from glob import glob

DIR = path.dirname(__file__)
C_FILES = glob(path.join(DIR, "../src/*.c"))
ASM_FILES = glob(path.join(DIR, "../asm/nonmatchings/**/*.s"))

def strip_c_comments(text):
    def replacer(match):
        s = match.group(0)
        if s.startswith('/'):
            return " "
        else:
            return s
    pattern = re.compile(
        r'//.*?$|/\*.*?\*/|\'(?:\\.|[^\\\'])*\'|"(?:\\.|[^\\"])*"',
        re.DOTALL | re.MULTILINE
    )
    return re.sub(pattern, replacer, text)

c_func_pattern = re.compile(
    r"^[^\s]+\s+([^\s(]+)\(([^\n)]*)\)\s+{",
    re.MULTILINE
)
def funcs_in_c(text):
    text = strip_c_comments(text)
    return [match.group(1) for match in c_func_pattern.finditer(text)]

matched = []
for filename in C_FILES:
    with open(filename, "r") as file:
        matched += funcs_in_c(file.read())

non_matched = [path.splitext(path.basename(filename))[0] for filename in ASM_FILES]
matched_but_undeleted_asm = [f for f in matched if f in non_matched]

if __name__ == "__main__":
    if "--help" in argv:
        print("--fail-matched-undeleted    exit with error code 1 if matched function(s) exist in asm/nonmatchings/")
        print("--delete-matched            delete matched function(s) from asm/nonmatchings/ without asking")
        exit()

    total = len(matched) + len(non_matched)
    print(f"{len(matched)}/{total} ({(len(matched) / total) * 100:.2f}%)")

    if len(matched_but_undeleted_asm) > 0:
        print(f"The following functions have been matched but still exist in asm/nonmatchings/: {' '.join(matched_but_undeleted_asm)}")

        if "--fail-matched-undeleted" in argv:
            print(f"The following functions have been matched but still exist in asm/nonmatchings/: {' '.join(matched_but_undeleted_asm)}")
            exit(1)
        else:
            if "--delete-matched" in argv or input("Delete them [y/N]? ").upper() == "Y":
                for func in matched_but_undeleted_asm:
                    file = glob(path.join(DIR, f"../asm/nonmatchings/*/{func}.s"))[0]
                    remove(file)
