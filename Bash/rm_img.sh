#! /bin/bash

#To do:
#Make a bash script to delete all files that do not have a resolution of 1080x1920,
#That is, they are portrait images


var_num_file=$(ls -1 | wc -l)
#make an array to store all the file names
file_name=()
echo ${var_num_file}

#add the filename to the array 
file_name+=(*) #this is known as globbing

#loop through the array and remove  all files that do not have a resolution of 1080x1920
for ((x=0 ; x < var_num_file; x+=1))
do
    is_correct_resolution=$(file "${file_name[x]}" | grep -c "1080x1920")
    #Korn shell syntax
    if (( $is_correct_resolution == 1 ))
    then
        echo "Incorrect resolution... Deleting "${file_name[x]}"" 
        rm "${file_name[x]}"
    else
        echo "Correct resolution"
    fi
    #Bash shell syntax
    # if (( $is_correct_resolution == 0 ))
    # then
    #     echo "Incorrect resolution... Deleting"
    # else
    #     echo "Correct resolution"
    # fi
    
done

