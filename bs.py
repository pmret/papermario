with open("out.txt") as f:
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

for k, v in sorted(renames.items()):
    print(f"{k} : {v}")
