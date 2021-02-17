#!/usr/bin/env python3

import os
import re
import sys
from pathlib import Path

DIR = os.path.dirname(__file__)
NONMATCHINGS_DIR = Path(os.path.join(DIR, "asm", "nonmatchings"))

C_FILES = Path(os.path.join(DIR, "src")).rglob("*.c")
ASM_FILES = NONMATCHINGS_DIR.rglob("*.s")

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
    r"^(static\s+)?[^\s]+\s+([^\s(]+)\(([^;)]*)\)[^;]+{",
    re.MULTILINE
)
def funcs_in_c(text):
    return (match.group(2) for match in c_func_pattern.finditer(text))

asm_func_pattern = re.compile(
    r"INCLUDE_ASM\([^,]+, [^,]+, ([^,)]+)",
    re.MULTILINE
)
def include_asms_in_c(text):
    return (match.group(1) for match in asm_func_pattern.finditer(text))

matched = []
asm = []
for filename in C_FILES:
    with open(filename, "r") as file:
        text = strip_c_comments(file.read())
        matched.extend((m for m in funcs_in_c(text) if not m in matched))
        asm.extend((m for m in include_asms_in_c(text) if not m in asm))

non_matched = [os.path.splitext(os.path.basename(filename))[0] for filename in ASM_FILES]

partial_matched = [f for f in matched if f in asm]
matched = [f for f in matched if not f in partial_matched]
matched_but_undeleted_asm = set([f for f in matched if f in non_matched and not f in partial_matched])
orphan_asm = set(non_matched) - set(asm) - matched_but_undeleted_asm
missing_asm = set(asm) - set(non_matched)

to_delete = matched_but_undeleted_asm | orphan_asm

if __name__ == "__main__":
    if "--help" in sys.argv:
        print("--fail-undeleted            exit with error code 1 if obsolete .s functions exist")
        print("--delete                    delete obsolete .s functions without asking")
        exit()

    if len(matched_but_undeleted_asm) > 0:
        print(f"The following functions have been matched but their .s files remain: {matched_but_undeleted_asm}")
    if len(set(asm)) != len(set(non_matched)):
        if len(set(non_matched)) > len(set(asm)) and len(orphan_asm) > 0:
            print(f"The following functions are unmatched but are also unINCLUDEd: {orphan_asm}")
        elif len(missing_asm) > 0:
            print(f"warning: The following .s files are INCLUDEd but don't exist: {missing_asm}")

    if len(to_delete) > 0:
        if "--fail-undeleted" in sys.argv:
            exit(1)
        elif "--delete" in sys.argv or input("Delete them [y/N]? ").upper() == "Y":
            for func in to_delete:
                f = next(NONMATCHINGS_DIR.rglob(func + ".s"))
                os.remove(f)

            # Remove empty directories
            for folder in list(os.walk(NONMATCHINGS_DIR)):
                if not os.listdir(folder[0]):
                    os.removedirs(folder[0])
