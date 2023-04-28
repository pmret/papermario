#! /usr/bin/python3

from sys import argv, path
from pathlib import Path

# allow importing splat_ext
path.append(str(Path(__file__).parent.parent.parent))

from splat_ext.pm_sbn import SBN

if __name__ == "__main__":
    out = argv[1]
    inputs = [Path(p) for p in argv[2:]]

    sbn = SBN()

    for input in inputs:
        # if input is a sbn.yaml, read its directory
        if input.suffix == ".yaml":
            sbn.read(input.parent)

    data = sbn.encode()

    with open(out, "wb") as f:
        f.write(data)
