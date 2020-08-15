#!/usr/bin/env python3

import os
import re
from glob import glob
from stringcase import constcase # pip install stringcase

DIR = os.path.dirname(__file__)
SR_DATABASE = os.path.join(DIR, "star-rod/database")
FILES = (
    glob(os.path.join(SR_DATABASE, "types/*.enum")) +
    glob(os.path.join(SR_DATABASE, "types/**/*.enum")) +
    glob(os.path.join(SR_DATABASE, "types/*.flags")) +
    glob(os.path.join(SR_DATABASE, "types/**/*.flags"))
)

with open(os.path.join(DIR, "../include/enums.h"), "w") as h:
    h.write("""#ifndef _ENUMS_H_
#define _ENUMS_H_

#include "ultra64.h"
#include "types.h" 

""")

    for filename in FILES:
        with open(filename, "r") as file:
            lines = file.readlines()

            # Get enum attributes
            namespace = constcase(re.match(r"[^  \t]*", lines[0]).group(0))
            library_name = re.match(r"[^  \t]*", lines[1]).group(0)
            reverse = True if re.match(r"[^  \t]*", lines[2]).group(0) == "true" else False

            # Get a list of tuples containing (name, value)
            items = []
            name_max_len = 0
            comment = False
            for line in lines[4:]:
                line = line.rstrip("\n")
                if not comment and not line.startswith("%") and "=" in line:
                    m = re.match(r"[ \t]*?([^ \t]*)[ \t]*=[ \t]*([^ \t]*)", line)
                    if m:
                        if reverse:
                            name = m.group(1)
                            value = int(m.group(2), 16)
                        else:
                            name = m.group(2)
                            value = int(m.group(1), 16)
                        if value < 0:
                            str_value = f"{value}"
                        else:
                            str_value = "0x" + f"{value:08x}".upper()
                        
                        name = constcase(name)
                        items.append((name, str_value))
                        name_max_len = max(len(name), name_max_len)
                elif "/%" in line:
                    comment = True
                elif "%/" in line:
                    comment = False

            # Write a section to the header file for this enum
            h.write(f"typedef UNK_TYPE {namespace};\n")
            for (name, value) in items:
                h.write(f"#define {namespace}_{name.ljust(name_max_len)} {value}\n")
            h.write("\n")

    h.write("#endif\n")