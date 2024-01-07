import os
import re
import sys

IMG_C_RE = re.compile(r"#include \".*png\.inc\.c\"")
PAL_C_RE = re.compile(r"#include \".*pal\.inc\.c\"")


def img_replacer(match):
    s = match.group(0)

    png_inc_c_path = s.split('"')[1]
    png_inc_c_content = None

    for version in ["us", "pal", "ique", "jp"]:
        try:
            with open(f"ver/{version}/build/include/" + png_inc_c_path, "r") as f:
                png_inc_c_content = f.read()
            break
        except FileNotFoundError:
            pass

    if png_inc_c_content is None:
        print(f"Could not find {png_inc_c_path} in any version")
        return s

    symbol_name = png_inc_c_content.split()[2][:-2]
    path_bin = png_inc_c_path.replace(".inc.c", ".bin")

    inc_type = "INCLUDE_IMG" if ".png" in png_inc_c_path else "INCLUDE_PAL"

    return f'{inc_type}("{path_bin}", {symbol_name});'


for dirs, subdirs, files in os.walk("src"):
    for file in files:
        if file.endswith(".c"):
            with open(os.path.join(dirs, file), "r") as f:
                source_lines = f.readlines()

            if any(IMG_C_RE.match(l) or PAL_C_RE.match(l) for l in source_lines):
                # Find first empty line in file and put the include there
                first_line_idx = 0

                if "effects/gfx" in dirs:
                    source_lines.insert(0, '#include "include_asset.h"\n')
                    source_lines.insert(1, "\n")
                else:
                    try:
                        first_line_idx = source_lines.index("\n")
                        if first_line_idx > 11:
                            print("File {} has more than 11 lines before first empty line".format(file))
                            continue
                    except ValueError:
                        first_line_idx = 0
                    source_lines.insert(first_line_idx, '#include "include_asset.h"\n')

                for i in range(len(source_lines)):
                    source_lines[i] = re.sub(IMG_C_RE, img_replacer, source_lines[i])
                    source_lines[i] = re.sub(PAL_C_RE, img_replacer, source_lines[i])

                with open(os.path.join(dirs, file), "w") as f:
                    f.writelines(source_lines)
