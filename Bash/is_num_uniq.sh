#A program to determine whether a number contains unique digits
#Use an array to check whether a digit is present in the number
arr=(0 0 0 0 0 0 0 0 0 0)

#Function to check if a digit is unique
function is_digit_unique () {
    if [ ${arr[$1]} -eq 1 ] 
    then
        return 0
    #If unique, mark it as seen
    else
        arr[$1]=1
    fi
    return 1
}

read -p "Enter a number: " val
num_digits=`expr length $val`


#If the number of digits exceed ten, then you are 
#guaranteed that there is at least two duplicated digits
if [ $num_digits -gt 10 ]
then
    echo "The number does not contain unique digits"
    exit 1
fi

i=0
while [ $i -lt $num_digits ]
do
    curr_digit=${val:i:1}
    is_digit_unique $curr_digit

    #Is the digit unique?
    if [ $? -eq 0 ]
    then
        echo "The number does not contain unique digits"
        exit 1
    fi
    i=$((i + 1))
done
echo "The number contains unique digits"
