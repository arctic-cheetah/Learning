#! /bin/bash

count=30


if ((count > 10)) && ((count < 20))
then
	echo "The number is greater than 10"
elif((count == 10))
then
	echo "The number is 10"
else
	echo "The number is less than 10"
fi
