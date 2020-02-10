#!/bin/bash

reps=1000000
for i in 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16; do
    ./sample $i $reps
done

reps=10000
for i in 17 18 19 20 21 22 23 24; do
    ./sample $i $reps
done

reps=10
for i in 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40; do
    ./sample $i $reps
done

# reps=1
# for i in 10000 20000 40000 80000 1000000 2000000 4000000; do
#     ./sample $i $reps
# done
