#!/bin/bash

#A program to check if a string is a palindrome
read -p "Enter a string: " str

#Find the string length
str_len=`expr length $str`

#Get the middle
middle=$(($str_len / 2))

i=0
j=$(($str_len - 1))
while [[ $i -lt $middle ]]
do
	#check the left and right characters
	#Then meet up at the middle
	front=${str:i:1}
	rear=${str:j:1}
	if [[ $front != $rear ]]
	then
		echo "The string is not a palindrome"
		exit 1
	fi
	i=$(($i + 1))
	j=$(($j - 1))
done

echo "The string is a palindrome"