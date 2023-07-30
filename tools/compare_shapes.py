#!/usr/bin/env python3

import filecmp
import os
from pathlib import Path

total = 0
matching = 0

for root, dirs, files in os.walk("assets/us/mapfs/geom"):
    for file in files:
        if file.endswith("_shape.bin"):
            total += 1
            shape_file = os.path.join(root, file)
            built_data_file = Path("ver/us/build") / shape_file.replace("_shape.bin", "_shape_data.bin")

            if filecmp.cmp(shape_file, built_data_file, shallow=False):
                matching += 1
            else:
                if total - matching == 10:
                    print("...")
                if total - matching < 10:
                    print(file, "X")

print()
print(f"{matching} of {total} files match")
