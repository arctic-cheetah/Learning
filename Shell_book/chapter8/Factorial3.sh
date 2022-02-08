#!/bin/bash
#Factorials with arrays 
#Memoisation
factorial()
{
   num=$1
   result=1
   for (( i=2; i<=${num}; i++ ));
   do
     result=$((${result}*$i))
     factvalues[$i]=$result
   done
}

printf "Enter a number: "
read num

#The lack of proper data scope is disturbing
for (( i=1; i<=${num}; i++ ));
do
  factvalues[$i]=1
done

factorial $num

# print each element via a loop:
for (( i=1; i<=${num}; i++ ));
do
  echo "Factorial of $i : " ${factvalues[$i]}
done

