import os


syms = []
groups = {}

with open("tools/symz.txt") as f:
    for line in f.readlines():
        name, addr = line.strip().strip(";").split(" = ")
        syms.append((name, int(addr, 0), set()))

# Search src for syms
for root, dirs, files in os.walk("src"):
    for file in files:
        if file.endswith(".c"):
            with open(os.path.join(root, file)) as f:
                text = f.read()
                for sym in syms:
                    if sym[0] in text:
                        sym[2].add(os.path.join(root, file).replace("src/", "")[:-2])

# Search asm for syms
for root, dirs, files in os.walk("ver/us/asm"):
    for file in files:
        if file.endswith(".s"):
            with open(os.path.join(root, file)) as f:
                text = f.read()
                for sym in syms:
                    if sym[0] in text:
                        sym[2].add(root.replace("ver/us/asm/nonmatchings/", ""))

for sym in syms:
    if len(sym[2]) == 0:
        group = ""
    elif len(sym[2]) > 1:
        group = "multig"
    else:
        group = next(iter(sym[2]))

    if group not in groups:
        groups[group] = []
    groups[group].append(sym)

for group in groups:
    if group == "":
        print("The following symbols can be simply removed from undefined_syms:")
    elif group == "multig":
        print("The following symbols are found in multiple locations:")
    else:
        print(group + ":")

    sorted_syms = sorted(groups[group], key=lambda tup: tup[1])

    for sym in sorted_syms:
        print(f"{sym[0]} = 0x{sym[1]:X}")
    print()
