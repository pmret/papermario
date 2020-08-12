#!/usr/bin/env python3

import os
import re
import stringcase


files = [filename for filename in os.listdir("./sr_enums") if filename.endswith(".enum")]
for filename in files:
    with open(f"./sr_enums/{filename}", "r") as file:
        lines = file.readlines()

        # Get enum attributes
        namespace = re.match(r"[^  \t]*", lines[0]).group(0)
        library_name = re.match(r"[^  \t]*", lines[1]).group(0)
        reverse = True if re.match(r"[^  \t]*", lines[2]).group(0) == "true" else False

        # Get a list of tuples containing (name, value)
        items = []
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
                        str_value = "-0x" + f"{value*-1:08x}".upper()
                    else:
                        str_value = "0x" + f"{value:08x}".upper()
                    items.append((name, str_value))
            elif "/%" in line:
                comment = True
            elif "%/" in line:
                comment = False
            
        # Create a header file for this enum
        with open(f"./c_enums/{namespace}.h", "w") as file:
            header = f"_{stringcase.constcase(namespace)}_"
            file.write(f"#ifndef {header}\n#define {header}\n")
            file.write("\n")
            file.write("#include \"ultra64.h\"\n#include \"types.h\"\n")
            file.write("\n")
            file.write(f"typedef enum {namespace} {'{'}\n")
            for i,(name,value) in enumerate(items):
                name_const = stringcase.constcase(name)
                if i < len(items) - 1:
                    file.write(f"\t{name_const} = {value},\n")
                else:
                    file.write(f"\t{name_const} = {value}\n")
            file.write(f"{'}'} {namespace};\n\n")
            file.write("#endif")
                

        