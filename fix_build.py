from pathlib import Path

symbol_map = {}
rom_starts = {}
map_ = (Path("ver") / "us" / "build" / "papermario.map").read_text().splitlines()
map2 = []
i = 0
while i < len(map_):
    if "_ROM_START = " in map_[i]:
        map_name = map_[i].split("_ROM_START",1)[0].split(" ")[-1]
        rom = int(map_[i].split("0x",1)[1].split(" ",1)[0], 16)
        rom_starts[map_name] = rom
        

    elif map_[i].startswith(" ver/us/../") and "src/world/area_" in map_[i] and i+1 < len(map_) and map_[i+1].startswith(" .text"):
        map_name = map_[i][map_[i].find("src/world/area_") + len("src/world/area_") + 4:
                           map_[i].find("/", map_[i].find("src/world/area_") + len("src/world/area_") + 4)]
        if len(map_name) < 6:
            i += 1
            continue
        i += 2
        #print(i, map_name, map_[i])
        while map_[i].startswith("   "):
            #print(map_[i])
            vram = int(map_[i].split("0x",1)[1].split(" ",1)[0], 16)
            rom = (vram - 0x80240000) + rom_starts[map_name]
            func_name = map_[i].split(" ")[-1]
            func_name = "N(" + func_name.replace(map_name + "_", "") + ")"
            if map_name not in symbol_map:
                symbol_map[map_name] = {}
            symbol_map[map_name][vram] = func_name
            symbol_map[map_name][rom] = func_name

            i += 1
        i -= 1
    i += 1

need_replace = {}

def parse_folder(path):
    for entry in path.iterdir():
        if "area" in str(entry.resolve()):
            if entry.is_dir():
                parse_folder(entry)
            else:
                print(f"Parsing {entry}")
                asm_file = entry.read_text()
                for map_name, funcs in need_replace.items():
                    if "v_01" in map_name:
                        continue
                    for func in funcs:
                        rom = int(func.split("_")[2], 16)
                        new_func_name = symbol_map[map_name][rom]
                        #print(f"Old name {func}, new name {new_func_name}")
                        nnew = map_name + "_" + new_func_name[2:-1]
                        asm_file = asm_file.replace(f"{new_func_name}", f"{nnew}")
                        #asm_file = asm_file.replace(func, new_func_name)
                entry.write_text(asm_file)

compile_text = Path("test.txt").read_text().splitlines()
for i,line in enumerate(compile_text):
    if line.startswith("mips-linux-gnu-ld") and "ver/us/../" in line:
        map_name = line.split("world/area_",1)[1].split(".s",1)[0].split(".data",1)[0]
        map_name = map_name.split("/",1)[1].split("/",1)[0]
        if map_name not in need_replace:
            need_replace[map_name] = []

    elif "undefined reference to " in line and "func_802" in line:
        func_name = "func_" + line.split("func_",1)[1].split("'",1)[0]
        need_replace[map_name].append(func_name)

parse_folder(Path("ver") / "us" / "asm" / "data" / "world")
        
