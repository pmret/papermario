# ninja -j1 | python3 tools/fix_bad_evt_changes.py

import fileinput
import requests

problems = []

for line in fileinput.input():
    if "undeclared here (not in a function)" in line:
        filename = line.split(":")[0].strip()
        line_number = int(line.split(":")[1].strip())
        bad_symbol_name = line.split("`")[1].split("'")[0]

        problems.append((filename, line_number, bad_symbol_name))

for filename, line_number, bad_symbol_name in problems:
    url = f"https://raw.githubusercontent.com/pmret/papermario/master/{filename}"
    old_lines = requests.get(url).text.splitlines()

    old_line = old_lines[line_number - 1].strip()

    with open(filename, "r") as f:
        lines = f.readlines()

    line = lines[line_number - 1]

    if "EVT_CALL" not in line and "EVT_EXEC" not in line:
        continue

    if old_line.startswith("N(") or old_line.startswith("await N("):
        good_symbol_name = old_line[old_line.find("N("):].split(")", 1)[0] + ")"
    else:
        good_symbol_name = old_line.split("(", 1)[0]

    print(filename, bad_symbol_name, "->", good_symbol_name)

    lines[line_number - 1] = line.replace(bad_symbol_name, good_symbol_name)

    with open(filename, "w") as f:
        f.writelines(lines)

