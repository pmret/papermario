#! /usr/bin/python3

from pathlib import Path
from sys import argv
import re

if __name__ == "__main__":
    infile, outfile, cname = argv[1:]

    #fname = Path(infile).stem

    # cname = re.sub(r"[^0-9a-zA-Z_]", "_", outfile)

    # if cname.startswith("ver_"):
    #     cname = "_".join(cname.split("_")[2:])

    # cname = re.sub(r"^build_include_", "", cname)
    # cname = re.sub(r"_inc_c$", "", cname)

    with open(outfile, "w") as f:
        f.write(f"unsigned char {cname}[] = {{")

        with open(infile, "rb") as i:
            for char in i.read():
                f.write(f"{char},")

        f.write(f"}};\n")
