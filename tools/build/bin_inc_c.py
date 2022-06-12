#! /usr/bin/python3

from pathlib import Path
from sys import argv
import re

if __name__ == "__main__":
    infile, outfile, cname = argv[1:]

    with open(outfile, "w") as f:
        f.write(f"unsigned char {cname}[] = {{")

        with open(infile, "rb") as i:
            for char in i.read():
                f.write(f"{char},")

        f.write(f"}};\n")
