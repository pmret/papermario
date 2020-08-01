import os
import re

def replace_func(match):
    match = match.group()

    if match.startswith("."):
        return match
    return "glabel " + match[:-1]

for root, dirs, files in os.walk("papermario/asm"):
    for file in files:
        for file in files:
            if file.endswith(".s"):
                with open(os.path.join(root, file)) as f:
                    old_file_text = f.read()

                new_file_text = re.sub(".*:", replace_func, old_file_text)

                if old_file_text != new_file_text:
                    with open(os.path.join(root, file), "w", newline="\n") as f:
                        f.write(new_file_text)
