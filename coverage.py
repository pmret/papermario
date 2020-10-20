#!/usr/bin/env python3

from os import path
from os import remove
from sys import argv
import re
from glob import glob
from pathlib import Path

DIR = path.dirname(__file__)
NONMATCHINGS_DIR = Path(path.join(DIR, "asm", "nonmatchings"))

C_FILES = Path(path.join(DIR, "src")).rglob("*.c")
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

def parse_map_file(p = Path(DIR, "build", "papermario.map")):
    addresses = []
    with open(p, "r") as f:
        for match in re.compile(f"^\s+0x([a-f0-9]+)\s+([_a-zA-Z0-9]+)", re.MULTILINE).finditer(f.read()):
            addr = int(match.group(1), 16)
            func = match.group(2)

            addresses.append((func, addr))

    addresses.sort(key=lambda x: x[1]) # sort by address

    sizes = {}
    for i in range(0, len(addresses) - 1):
        func, addr = addresses[i]
        next_addr = addresses[i + 1][1]

        sizes[func] = next_addr - addr

    return sizes

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
        print("--fail-unincluded           exit with error code 2 if unincluded assembly files exist")
        print("--delete-matched            delete matched function(s) from asm/nonmatchings/ without asking")
        print("--delete-unincluded         delete unincluded, unmatched assembly files")
        print("--skip-sizes                don't attempt to read build/papermario.map to determine sizes")
        exit()

    total = len(matched) + len(non_matched)
    print(f"{len(matched)}+{len(partial_matched)} / {total} functions ({(len(matched) / total) * 100:.2f}%)")

    if not "--skip-sizes" in argv:
        function_sizes = parse_map_file()
        size_matched = sum(function_sizes.get(f, 0) for f in matched)
        size_partial_matched = sum(function_sizes.get(f, 0) for f in partial_matched)
        size_non_matched = sum(function_sizes.get(f, 0) for f in non_matched)
        size_total = size_matched + size_non_matched
        print(f"{size_matched}+{size_partial_matched} / {size_total} bytes ({(size_matched / size_total) * 100:.2f}%)")

    if len(matched_but_undeleted_asm) > 0:
        print(f"The following functions have been matched but still exist in asm/nonmatchings/: {' '.join(matched_but_undeleted_asm)}")

        if "--fail-matched-undeleted" in argv:
            exit(1)
        elif "--delete-matched" in argv or input("Delete them [y/N]? ").upper() == "Y":
            for func in matched_but_undeleted_asm:
                f = next(NONMATCHINGS_DIR.rglob(func + ".s"))
                remove(f)
    elif len(set(asm)) != len(set(non_matched)):
        #print(f"warning: number of INCLUDE_ASM macros ({len(asm)}) != number of asm files ({len(non_matched)})")

        if len(set(non_matched)) > len(set(asm)):
            print(f"The following functions are unmatched but are also unINCLUDEd: {set(non_matched) - set(asm)}")

            if "--fail-unincluded" in argv:
                exit(2)
            elif "--delete-unincluded" in argv or input("Delete them [y/N]? ").upper() == "Y":
                for func in set(non_matched) - set(asm):
                    f = next(NONMATCHINGS_DIR.rglob(func + ".s"))
                    remove(f)
        else:
            print(f"warning: The following .s files are INCLUDEd but don't exist: {set(asm) - set(non_matched)}")
