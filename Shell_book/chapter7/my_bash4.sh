#A program to realign all data in a csv file

#------------------------------------
# 1) remove blank lines
# 2) remove line feeds
# 3) print a LF after every fourth field
# 4) remove trailing ',' from each row
#------------------------------------

awk '{printf("%s", $0)}' mixed-data.csv | awk '{
    col_size = 4
    for (i = 1; i <= NF; i +=1) {
        #Remove comma at the end
        if (i % col_size == 0) {
            #trimmed_comma = sub(/(,)/ , "", $i) #This does not work to seprate commas
            split($i, arr, ",")
            printf("%s ", arr[1])
            print""
        }
        #Otherwise print word
        else {
            printf("%s ", $i)
            
        }
    }
}' > test.txt