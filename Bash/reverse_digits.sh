#!/bin/bash

#A program to reverse the order of a number
read -p "Enter a number: " val

#Take the remainder
i=0
while [[ val -gt 0 ]]
do
	i=$((10 * $i))
	i=$((i + val % 10))
	val=$((val / 10)) #Need to do floor division
done
	echo $i
