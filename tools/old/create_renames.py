with open("errs.txt") as f:
    inlines = f.readlines()

renames = {}

for line in inlines:
    components = line.split()

    area = None
    for c in components:
        if area:
            break
        if "src" in c:
            subcomponents = c.split("/")
            for i, sc in enumerate(subcomponents):
                if "area" in sc:
                    area = subcomponents[i + 1]
                    break

    if area:
        fname = line[line.rfind("`") + 1:line.rfind("'")]
        renames[fname] = area

pairs = []
for k, v in sorted(renames.items()):
    pairs.append((k, v))

with open("bloop.txt") as f:
    blooplines = f.readlines()


with open("duplicate_renames.txt", "w", newline="\n") as f:
    for pair in pairs:
        first = pair[0]
        second = pair[1]
        addr = first.split("_")[1].upper()

        for l in blooplines:
            if l.upper().startswith(addr) and second in l and " g " in l and " F" in l:
                func = l.rstrip().split()[-1]
                if first != func:
                    f.write(f"{first},{func}\n")
