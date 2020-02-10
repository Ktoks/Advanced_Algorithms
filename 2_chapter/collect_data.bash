#!/bin/bash

reps=10000000
for i in 1 2 3 4 5 6 7 8; do
    ./alg_2.16 $i $reps
done

reps=10000000
for i in 9 10 11 12 13 14 15 16; do
    ./alg_2.16 $i $reps
done

reps=1000000
for i in 17 18 19; do
    ./alg_2.16 $i $reps
done

reps=100000
for i in 20 21 22 23 24; do
    ./alg_2.16 $i $reps
done

reps=10000
for i in 25 26 27 28; do
    ./alg_2.16 $i $reps
done

reps=1000
for i in 29 30; do
    ./alg_2.16 $i $reps
done

# reps=1
# for i in 10000 20000 40000 80000 1000000 2000000 4000000; do
#     ./sample $i $reps
# done
