import sys
from pathlib import Path

files = sys.stdin.read().splitlines()[1:]

map_file = (Path(__file__).parent.parent / "ver" / "current" / "build" / "papermario.map").read_text().splitlines()
# cut out half the map
map_ = []
found_header = False
for line in map_file:
    if line.startswith(".header"):
        found_header = True
    if found_header:
        map_.append(line)

del map_file

for file in files:
    if file:
        file = file.split(" - ",1)[1]
        if "(decompiled)" in file:
            file = file.split(" ",1)[0]
        file = file.strip()

        file_name = ""
        for i,line in enumerate(map_):
            if file in line:
                x = i
                while not map_[x].startswith(" .text"):
                    x -= 1
                x -= 1
                file_name = map_[x].split(".o",1)[0].split("build/",1)[1].strip()
                break

        if not file_name:
            print(f"Failed to find {file}")
        else:
            file_path = (Path(__file__).parent.parent / file_name).resolve()
            func_file = file_path.read_text().splitlines()


