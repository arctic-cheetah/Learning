#A program to find the largest integer out of three numbers
read -p "Enter val1: " val1
read -p "Enter val2: " val2
read -p "Enter val3: " val3

if [ $val1 -gt $val2 ]
then
    if [ $val1 -gt $val3 ]
    then
        echo "Val1 is the highest"
    else
        echo "Val3 is the highest"
    fi
else 
    if [ $val2 -gt $val3 ]
    then
        echo "Val2 is the highest"
    else
        echo "Val3 is the highest"
    fi
fi
