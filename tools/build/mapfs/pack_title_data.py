#! /usr/bin/python3

from sys import argv

if __name__ == "__main__":
    argv.pop(0) # python3
    out, img1, img2, img3 = argv

    with open(img1, "rb") as f:
        img1 = f.read()

    with open(img2, "rb") as f:
        img2 = f.read()

    with open(img3, "rb") as f:
        img3 = f.read()

    with open(out, "wb") as f:
        f.seek(0x10)

        pos2 = f.tell()
        f.write(img2)

        pos3 = f.tell()
        f.write(img3)

        pos1 = f.tell()
        f.write(img1)

        f.seek(0)
        f.write(pos1.to_bytes(4, byteorder="big"))
        f.write(pos2.to_bytes(4, byteorder="big"))
        f.write(pos3.to_bytes(4, byteorder="big"))
