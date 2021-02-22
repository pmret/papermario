#! /usr/bin/python3

from sys import argv
import re
import png

if __name__ == "__main__":
    infile, outfile = argv[1:]

    img = png.Reader(infile)
    width, height, rows, info = img.read()

    cname = re.sub(r"[^0-9a-zA-Z_]", "_", infile)

    if cname.startswith("ver_"):
        cname = "_".join(cname.split("_")[2:])

    if cname.startswith("src_"):
        cname = cname[4:]
    elif cname.startswith("assets_"):
        cname = cname[7:]

    with open(outfile, "w") as f:
        f.write("// Generated file, do not edit.\n")
        f.write(f"#ifndef _{cname.upper()}_\n")
        f.write(f"#define _{cname.upper()}_\n")
        f.write(f"\n")
        f.write(f"#define {cname}_width {width}\n")
        f.write(f"#define {cname}_height {height}\n")
        f.write(f"\n")
        f.write(f"#endif\n")
