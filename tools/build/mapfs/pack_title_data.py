#! /usr/bin/python3

from sys import argv

if __name__ == "__main__":
    argv.pop(0) # python3

    if len(argv) > 4:
        out, img1, img2, img3, img2_pal = argv
    else:
        out, img1, img2, img3 = argv
        img2_pal = None

    with open(img1, "rb") as f:
        img1 = f.read()

    with open(img2, "rb") as f:
        img2 = f.read()

    with open(img3, "rb") as f:
        img3 = f.read()

    if img2_pal:
        with open(img2_pal, "rb") as f:
            img2_pal = f.read()

    with open(out, "wb") as f:
        f.seek(0x10)

        pos2 = f.tell()
        f.write(img2)

        if img2_pal:
            pos2_pal = f.tell()
            f.write(img2_pal)
        else:
            pos2_pal = None

        pos3 = f.tell()
        f.write(img3)

        pos1 = f.tell()
        f.write(img1)

        if img2_pal:
            # jp padding?
            f.write(b"\x00" * 0x10)

        f.seek(0)
        f.write(pos1.to_bytes(4, byteorder="big"))
        f.write(pos2.to_bytes(4, byteorder="big"))
        f.write(pos3.to_bytes(4, byteorder="big"))
        if pos2_pal:
            f.write(pos2_pal.to_bytes(4, byteorder="big"))
