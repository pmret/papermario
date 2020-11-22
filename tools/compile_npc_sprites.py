#! /usr/bin/python3

from sys import argv

if __name__ == "__main__":
    if len(argv) < 4:
        print("usage: compile_npc_sprites.py [OUTBIN] [INFILES]")
        exit(1)

    _, outfile, *infiles = argv

    with open(outfile, "wb") as f:
        offsets = []

        f.seek(4 * (len(infiles) + 1))

        for filename in infiles:
            with open(filename, "rb") as spritef:
                offsets.append(f.tell())
                f.write(spritef.read())

            # align
            while f.tell() % 8 != 0:
                f.write(bytes([0]))

        offsets.append(f.tell())

        f.seek(0)
        for offset in offsets:
            f.write(offset.to_bytes(4, byteorder="big"))
