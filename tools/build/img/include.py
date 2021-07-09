#! /usr/bin/python3

from sys import argv
import re
import png

if __name__ == "__main__":
    infile, outfile = argv[1:]

    cname = re.sub(r"[^0-9a-zA-Z_]", "_", outfile)

    if cname.startswith("ver_"):
        cname = "_".join(cname.split("_")[2:])

    cname = re.sub(r"^build_include_", "", cname)

    with open(outfile, "w") as f:
        f.write(f"unsigned char {cname}[] = {{")

        with open(infile, "rb") as i:
            for char in i.read():
                f.write(f"{char},")

        f.write(f"}};\n")
