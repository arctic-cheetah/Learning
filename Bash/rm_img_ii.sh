#! /bin/bash

#To do:
#Make a bash script to delete all files that do not have a resolution of 1080x1920,
#That is, they are portrait images.
#Second implementation


var_num_file=$(ls -1 | wc -l)
#make an array to store all the file names
file_name=()

#add the filename to the array 
file_name+=(*) #this is known as globbing

#loop through the array and keep keep all files with a resolution less than 1920x1080
for (( x=0 ; x < var_num_file; x+=1 ))
do
    is_correct_resolution=$(file "${file_name[x]}" | grep -Eo ", [0-9]{1,}x[0-9]{1,}," | grep -Eo "[0-9]{1,}x[0-9]{1,}" )
    echo $is_correct_resolution
    #syntax for getting a substring is: expr substr $
    width=$(expr substr $is_correct_resolution 1 4)
    height=$(expr substr $is_correct_resolution 6 4)

    if [ "$width" -ge "1920" ] && [ "$height" -ge "1080" ]
    then
        echo "Correct resolution"
    else
        echo "Incorrect resolution... Deleting "${file_name[x]}"" 
        rm "${file_name[x]}"
    fi
done

