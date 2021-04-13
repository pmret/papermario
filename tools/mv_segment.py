#!/usr/bin/python3

import argparse
import os
from pathlib import Path

parser = argparse.ArgumentParser()
parser.add_argument("src")
parser.add_argument("dest")
args = parser.parse_args()

# make dirs
Path(f"src/{args.dest}.c").parent.mkdir(parents=True, exist_ok=True)
Path(f"ver/current/asm/nonmatchings/{args.dest}").parent.mkdir(parents=True, exist_ok=True)
Path(f"ver/current/asm/data/{args.dest}").parent.mkdir(parents=True, exist_ok=True)

if os.path.exists(f"src/{args.src}.c"):
    print("moving c file")
    os.rename(f"src/{args.src}.c", f"src/{args.dest}.c")

    with open(f"src/{args.dest}.c") as f:
        content = f.read()

    with open(f"src/{args.dest}.c", "w") as f:
        f.write(content.replace(f'"{args.src}"', f'"{args.dest}"'))

if os.path.exists(f"ver/current/asm/nonmatchings/{args.src}"):
    print("moving asm/nonmatchings files")
    os.rename(f"ver/current/asm/nonmatchings/{args.src}", f"ver/current/asm/nonmatchings/{args.dest}")

if os.path.exists(f"ver/current/asm/data/{args.src}.data.s"):
    print("moving data file")
    os.rename(f"ver/current/asm/data/{args.src}.data.s", f"ver/current/asm/data/{args.dest}.data.s")

if os.path.exists(f"ver/current/asm/data/{args.src}.rodata.s"):
    print("moving rodata file")
    os.rename(f"ver/current/asm/data/{args.src}.rodata.s", f"ver/current/asm/data/{args.dest}.rodata.s")
