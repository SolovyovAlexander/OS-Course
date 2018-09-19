#!/bin/bash
for i in {1..1000}
do
	number=$(tail -n 1 "f1.txt")
	echo "$(($number+1))" >> "f1.txt"
done
