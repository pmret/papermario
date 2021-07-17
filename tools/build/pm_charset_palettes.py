#! /usr/bin/python3

from sys import argv

if __name__ == "__main__":
    argv.pop(0) # python3
    out = argv.pop(0)

    with open(out, "wb") as f:
        for path in argv:
            with open(path, "rb") as j:
                f.write(j.read())
