#!/bin/bash
while read line
do
    echo $line | grep -E "^[a-z]{12}$"
done < words.txt