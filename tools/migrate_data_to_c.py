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


def data_to_c(file_path):
    file = open(file_path)
    s = file.read()

    output = ""
    pattern = re.compile(r"(dlabel (jtbl_.*|.+_.*)\n.(\w+) (.*))")

    for (all, symbol, type, data) in re.findall(pattern, s):
        if type == "word":
            if symbol.startswith("jtbl_"):
                output += "dlabel " + symbol + "\n" + ".word " + data.replace("L", ".L") + "\n\n"
            else:
                output += "s32 " + symbol + "[] = {" + data + "};\n\n"
        elif type == "byte":
            output += "s8 " + symbol + "[] = {" + data + "};\n\n"
        else:
            output += all + "\n\n"

    file.close()
    return output


def out_to_file(output, file_path):
    output_dir = os.path.join(os.getcwd(), "data2c")
    if not os.path.exists(output_dir):
        os.mkdir(output_dir)

    file_name = file_path[file_path.rfind("/"):-7]
    file = open("data2c/" + file_name + ".c", "w+")
    file.write(output)
    file.close()


def get_all():
    for root, dirs, files in os.walk(data_dir):
        for f in files:
            file_path = os.fspath(os.path.join(root, f))
            out_to_file(data_to_c(file_path), file_path)

    print("Files have been translated successfully and stored at " + os.getcwd() + "/data2c/")


def query(file, to_file):
    for root, dirs, files in os.walk(data_dir):
        for f in files:
            if f == file:
                file_path = os.fspath(os.path.join(root, f))
                output = data_to_c(file_path)

                if to_file is True:
                    out_to_file(output, file_path)
                else:
                    print(output)
                return

    print("File not found: " + file)


parser = argparse.ArgumentParser(description="Tool to translate .data.s files to data arrays")
parser.add_argument("query", help="data file", nargs='?', default=None)
parser.add_argument("--all", help="translate all data files at once and output them into /data2c", action='store_true', required=False)
parser.add_argument("--to-file", help="redirect the output into a file. Can not be used in combination with --all", action='store_true', required=False)

args = parser.parse_args()


if args.query is None and args.all is False and args.to_file is False:
    parser.print_help()
    exit()

if args.query is not None and not args.query.endswith(".data.s"):
    args.query = args.query + ".data.s"

if args.all is False:
    if args.to_file is True:
        query(args.query, True)
    else:
        query(args.query, False)
else:
    get_all()
