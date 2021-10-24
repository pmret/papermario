#! /usr/bin/python3
import sys, os

if __name__ == "__main__":
	infile, outfile = sys.argv[1:]

	#generate output based on input
	file_data = open(infile,"r").read().split("\n")
	if len(file_data[-1]) == 0:
		file_data.pop()

	outdata = "-j " + " -j ".join(file_data)
	with open(outfile, "w") as f:
		f.write(outdata)
