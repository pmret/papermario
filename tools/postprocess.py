#!/usr/bin/python3
import fileinput
import os

script_dir = os.path.dirname(os.path.realpath(__file__))
asm_dir = script_dir + "/../asm/"


def tohex(val, nbits):
    return hex((val + (1 << nbits)) % (1 << nbits))


def gen_lui_addiu(line):
    line = line.strip()
    line_bits = line.split("\t")[1]
    reg, addr = line_bits.split(",")
    upper_addr = tohex(int(addr) >> 16, 16)
    lower_addr = tohex(int(addr) & 0xFFFF, 16)
    ret = "lui\t" + reg + "," + upper_addr + "\n" + \
          "addiu\t" + reg + ", $zero, " + lower_addr
    return ret


def main():
    skip_next = False
    for line in fileinput.input():
        line = line.strip()
        if skip_next:
            skip_next = False
            continue

        # Don't print the line after this
        if line == "#NO_APP":
            skip_next = True

        # Transform la
        if line.startswith("la\t"):
            print(gen_lui_addiu(line))
            continue

        print(line)


if __name__ == '__main__':
    main()
