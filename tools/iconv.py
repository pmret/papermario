#!/usr/bin/python3

import argparse
import sys

parser = argparse.ArgumentParser(description='Convert a file from one encoding to another')
parser.add_argument("f")
parser.add_argument("t")
parser.add_argument('infile', nargs='?', type=argparse.FileType('r'), default=sys.stdin)
parser.add_argument('outfile', nargs='?', type=argparse.FileType('w'), default=sys.stdout)

args = parser.parse_args()


def main(args):
    sys.stdin.reconfigure(encoding=args.f)
    in_data = args.infile.read()
    sys.stdout.reconfigure(encoding=args.t)
    args.outfile.write(in_data)


if __name__ == "__main__":
    main(parser.parse_args())
