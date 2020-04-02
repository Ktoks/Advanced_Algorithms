#!/bin/bash
FILES=~/code/adv_alg/chapter_hw/6_chapter/words/*
for f in $FILES
do	
	echo $f
	./sequences $f numout.txt -c
	less numout.txt >> out.txt
done
