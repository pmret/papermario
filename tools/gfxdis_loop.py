import os, sys
import subprocess
import argparse
from struct import unpack_from
from pathlib import Path

parser = argparse.ArgumentParser()
parser.add_argument("baserom")
parser.add_argument("start", type=lambda x:int(x, 0))
parser.add_argument("end", type=lambda x:int(x, 0))
args = parser.parse_args()

baserom_path = Path(__file__).parent.parent / "baserom.z64"
baserom = baserom_path.read_bytes()
gfxdis_path = Path(__file__).parent / "gfxdis.f3dex2"

rom_start = 0xBFD880

i = args.start
while i < args.end:
    dis_start = i
    while unpack_from(">2I", baserom, i) != (0xDF000000, 0x0):
        i += 4
    i += 8
    while unpack_from("B", baserom, i)[0] == 0:
        i += 1

    #print(f"Start {hex(dis_start)} end {hex(i)}")
    gfxdis = subprocess.run(f"{gfxdis_path.resolve()} " + f"-x " + f"-dc " + f"-d {baserom[dis_start:i].hex()}",
                              capture_output=True, shell=True, text=True)

    commands = gfxdis.stdout.splitlines()[1:-1]
    new_commands = []
    for command in commands:
        if "unk_" in command:
            nn = []
            for s in command.split(","):
                if "unk_" in s:
                    vram = int(s.split("unk_")[1].split(")")[0], 16)
                    rom = rom_start + (vram - 0x80240000)
                    name = f"D_{vram:X}_{rom:X}"
                    nn.append(name)
                else:
                    nn.append(s)
            new_commands.append(", ".join(nn))
        else:
            new_commands.append(command)

    vram = 0x80240000 + (dis_start - rom_start)
    print(f"Gfx D_{vram:X}[] = {{")
    print("\n".join(new_commands))
    print(f"}};\n")
