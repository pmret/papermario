#! /usr/bin/python3
import sys, os

#Under normal compilation we rely on splat to use a discard option in the ldscript
#to not include sections in the elf then just output all sections, however under debug we want
#to have debug sections.
#In debugging mode splat is told to output a list of sections it is custom creating, which are
#all of the sections we export to the z64 file with an objcopy. The below chunk of code is
#responsible for adding -j to each of the names and outputting a file for objcopy to use
#so we can still generate a elf file with all the extra debugging sections and still output
# the required sections to the .z64 without outputting everything.

if __name__ == "__main__":
	infile, outfile = sys.argv[1:]

	#generate output based on input
	file_data = open(infile,"r").read().split("\n")
	if len(file_data[-1]) == 0:
		file_data.pop()

	outdata = "-j " + " -j ".join(file_data)
	with open(outfile, "w") as f:
		f.write(outdata)
