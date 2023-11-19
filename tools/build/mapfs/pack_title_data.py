#!/usr/bin/env python3

from sys import argv

if __name__ == "__main__":
    argv.pop(0)  # python3
    version = argv.pop(0)
    out = argv.pop(0)
    imgs = argv

    imgs_bytes = []
    for img in imgs:
        with open(img, "rb") as f:
            imgs_bytes.append(f.read())

    if version == "jp":
        # copyright, copyright pal, press start, logo
        write_order = (1, 3, 2, 0)
    elif version == "ique":
        # press start, copyright, logo
        write_order = (2, 1, 0)
    else:
        # copyright, press start, logo
        write_order = (1, 2, 0)

    with open(out, "wb") as f:
        f.seek(0x10)

        imgs_pos = [0] * len(imgs)
        for i in write_order:
            imgs_pos[i] = f.tell()
            f.write(imgs_bytes[i])

        if version == "jp":
            # jp padding?
            f.write(b"\x00" * 0x10)

        f.seek(0)
        for pos in imgs_pos:
            f.write(pos.to_bytes(4, byteorder="big"))
