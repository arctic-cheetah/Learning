#A program to move a file from src to dest
#with error checking

if [[ $# -lt 2 ]]
then
    echo -n `mv`
    echo "Please enter the <source filename> and <destination filename>"
else
    mv $1 $2
fi