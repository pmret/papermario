#!/usr/bin/python3

import re
import os
import argparse

data_dir = os.path.dirname(os.path.realpath(__file__)) + "/../ver/current/asm/data/"


def find_dir(query):
    for root, dirs, files in os.walk(data_dir):
        for f in files:
            if f == query:
                return os.path.join(root, f)
    return None
    

for root, dirs, files in os.walk(data_dir):
    for f in files:
        file_path = os.fspath(os.path.join(root, f))
        file = open(file_path)
        s = file.read()

        output = ""
        pattern = re.compile(r"(dlabel (D_.*)\n.(\w+) (.*))")

        for (all, symbol, type, data) in re.findall(pattern, s):
            if type == "word":
                output += "s32 " + symbol + "[] = {" + data + "};\n\n"
            else:
                output += all + "\n\n"

        file.close()

        output_dir = os.path.join(os.getcwd(), "data2c")
        if not os.path.exists(output_dir):
            os.mkdir(output_dir)

        file_name = file_path[file_path.rfind("/"):-7]
        file = open("data2c/" + file_name + ".c", "w+")
        file.write(output)
        file.close()
