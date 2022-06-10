#!/bin/bash

count_pos=$(find data/ -maxdepth 1 -name "pos_*_in.txt" | wc -l)
count_neg=$(find data/ -maxdepth 1 -name "neg_*_in.txt" | wc -l)

for ((i = 1; i <= $count_pos; i++))
do
    if [ "$i" -le 9 ]
	then ../app.exe data/tests/pos_in_0${i}.txt < data/"pos_0${i}_in.txt" > data/"pos_0${i}_out.txt"
	else ../app.exe data/tests/pos_in_${i}.txt < data/"pos_${i}_in.txt" > data/"pos_${i}_out.txt"
	fi
done

for ((i = 1; i <= $count_neg; i++))
do
    if [ "$i" -le 9 ]
	then ../app.exe data/tests/neg_in_0${i}.txt < data/"neg_0${i}_in.txt" > data/"neg_0${i}_out.txt"
	else ../app.exe data/tests/neg_in_${i}.txt < data/"neg_${i}_in.txt" > data/"neg_${i}_out.txt"
	fi
done

exit 0