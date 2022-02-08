#!/bin/sh

iterate() 
{ 
  #Bash implicity knows that the function arguments
  #will be iterated from the code below
  for x 
  do 
    echo "value: $x"; 
  done
}

iterate a b c d e

