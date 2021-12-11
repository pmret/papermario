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


parser = argparse.ArgumentParser(description="Tool to translate .data.s files into .c compatible data arrays")
#parser.add_argument("query", help="data file")

#args = parser.parse_args()

for root, dirs, files in os.walk(data_dir):
    for f in files:
        file_path = os.fspath(os.path.join(root, f))
        file = open(file_path)
        s = file.read()

        output = ""
        pattern = re.compile(r"dlabel (D_.*)\n.\w+ (.*)")

        for (symbol, data) in re.findall(pattern, s):
            output += "s32 " + symbol + "[] = {" + data + "};\n\n"

        file.close()

        output_dir = os.path.join(os.getcwd(), "data2c")
        if not os.path.exists(output_dir):
            os.mkdir(output_dir)

        print(file_path)
        file_name = file_path[file_path.rfind("/"):-7]
        print(file_name)
        file = open("data2c/" + file_name + ".c", "w+")
        file.write(output)
        file.close()

#path_to_file = os.fspath(find_dir(args.query))

#file = open(path_to_file)
#s = file.read()
#
#output = ""
#pattern = re.compile(r"dlabel (D_.*)\n.\w+ (.*)")
#
#for (symbol, data) in re.findall(pattern, s):
#    output += "s32 " + symbol + "[] = {" + data + "};\n\n"
#
#file.close()
#
#output_dir = os.path.join(os.getcwd(), "data2c")
#if not os.path.exists(output_dir):
#    os.mkdir(output_dir)
#
#file_name = args.query[:args.query.find(".")]
#file = open("data2c/" + file_name + ".c" , "w+")
#file.write(output)
#file.close()
