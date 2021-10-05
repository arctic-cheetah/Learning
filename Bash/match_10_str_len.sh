
#A program that prints all the words of length 10, given as an input
read -p "Enter a line: " line

for i in $line
do
    str_len=`expr length $i`
    if [ $str_len -eq 10 ]
    then
        echo $i
    fi
done