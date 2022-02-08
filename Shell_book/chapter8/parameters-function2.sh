#!/bin/sh

function1 ()
{
   echo "param count: $#" 
   echo "all params:  $@" 
   echo ""
}

# invoke function1 here:
function1 a 
function1 a b
function1 a b c
function1 a b c d
function1 1 2 3 4 5

echo "File name is: $0"
