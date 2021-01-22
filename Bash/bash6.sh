#! /bin/bash

echo  "Enter the first string:"
read str1

echo  "Enter the second string:"
read str2

echo $str1" "$str2
echo "$str1" | tr '[:upper:]' '[:lower:]'
