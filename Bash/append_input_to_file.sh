#A program to append input to data.txt
read -p "Enter a first name: " f_name
read -p "Enter a last name: " l_name
read -p "Enter an age: " age


if [ -w data.txt ]
then
    echo $f_name,$l_name,$age >> data.txt 
else
    chmod 764 data.txt
    ./append_input_to_file.sh
fi