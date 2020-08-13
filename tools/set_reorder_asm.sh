#!/bin/bash

shopt -s globstar

LIST=$(ls asm/**/*.s)

for i in $LIST
do	
	printf "\n.set reorder\n" >> $i
done
