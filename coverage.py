#!/usr/bin/env python3

from os import path
from os import remove
from sys import argv
import re
from glob import glob

DIR = path.dirname(__file__)
C_FILES = glob(path.join(DIR, "src/*.c"))
ASM_FILES = glob(path.join(DIR, "asm/nonmatchings/**/*.s"))

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
    return (match.group(1) for match in c_func_pattern.finditer(text))

asm_func_pattern = re.compile(
    r"INCLUDE_(?:API_)?ASM\([^,]+, ([^,)]+)",
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

non_matched = [path.splitext(path.basename(filename))[0] for filename in ASM_FILES]

partial_matched = [f for f in matched if f in asm]
matched = [f for f in matched if not f in partial_matched]
matched_but_undeleted_asm = [f for f in matched if f in non_matched and not f in partial_matched]

if __name__ == "__main__":
    if "--help" in argv:
        print("--fail-matched-undeleted    exit with error code 1 if matched function(s) exist in asm/nonmatchings/")
        print("--delete-matched            delete matched function(s) from asm/nonmatchings/ without asking")
        exit()

    total = len(matched) + len(non_matched)
    print(f"{len(matched)}+{len(partial_matched)} / {total} functions ({(len(matched) / total) * 100:.2f}% matched)")

    if len(matched_but_undeleted_asm) > 0:
        print(f"The following functions have been matched but still exist in asm/nonmatchings/: {' '.join(matched_but_undeleted_asm)}")

        if "--fail-matched-undeleted" in argv:
            exit(1)
        elif "--delete-matched" in argv or input("Delete them [y/N]? ").upper() == "Y":
            for func in matched_but_undeleted_asm:
                file = glob(path.join(DIR, f"asm/nonmatchings/*/{func}.s"))[0]
                remove(file)
    elif len(asm) != len(non_matched):
        print(f"warning: number of INCLUDE_ASM macros ({len(asm)}) != number of asm files ({len(non_matched)})")
