overlays = {}

with open("fxdata.txt") as f:
    i = 0
    for line in f:
        _, main_start, main_end, dest, gfx_start, gfx_end = line.rstrip().split(", ")

        if main_start != "0x00000000":
            main_start = int(main_start, 16)
            main_end = int(main_end, 16)
            gfx_start = int(gfx_start, 16)
            gfx_end = int(gfx_end, 16)
            dest = int(dest, 16)

            overlays[main_start] = {
                "main_start": main_start,
                "main_end": main_end,
                "dest": dest,
                "effect_num": i,
            }

            if gfx_start not in overlays:
                overlays[gfx_start] = {
                    "gfx_start": gfx_start,
                    "gfx_end": gfx_end,
                    "used_by": [],
                }
            overlays[gfx_start]["used_by"].append(str(i))

        i += 1

for key in sorted(overlays):
    if "dest" in overlays[key]:
        print(f"  - name: effect_{overlays[key]['effect_num']}")
        print(f"    dir: effects")
        print(f"    type: code")
        print(f"    start: 0x{overlays[key]['main_start']:X}")
        print(f"    vram: 0x{overlays[key]['dest']:X}")
        print(f"    subsegments:")
        print(f"    - [0x{overlays[key]['main_start']:X}, c, effect_{overlays[key]['effect_num']}]:")
        print(f"    - [0xREPLACE, data]:")
    else:
        print(f"  - [0x{overlays[key]['gfx_start']:X}, bin] # effect {','.join(overlays[key]['used_by'])} gfx")
