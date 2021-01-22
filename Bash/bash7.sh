#! /bin/bash

echo "enter file name from which you want to read"
read fileName

if [ -f "$fileName" ]
then
    while read line
    do
        echo "$line"
    done < $fileName
else
    echo "$fileName doesn't exist"
fi
