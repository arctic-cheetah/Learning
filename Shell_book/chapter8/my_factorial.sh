#A program to calculate factorial
#But then I researched that bash return values
#Exist only between 1 - 255
#Therefore bash is stupidly limited for recursion
#!/bin/sh

function factorial() {
    #base case recurse if value > 1
    if [[ $1 -gt 1 ]] 
    then

        decrement=`expr $1 - 1`
        returnval=`factorial $decrement`
        calc=$(( $returnval*$1 ))
        #You cannot return values greater than 255
        #According to bash
        #Try change the return value to 1000, and remove lines 12-14
        #And nothing will be printed to STDOUT
        return $calc
    #Otherwise return 1
    else 
        return 1
    fi
}

echo "Enter a number: "
read num

result=`factorial $num`
echo $result