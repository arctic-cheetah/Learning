#/bin/bash
#A program to demonstrate the internal field seperator

data="age,gender,street,state"
IFS=$","

for item in $data
do
    echo Item: $item
done

