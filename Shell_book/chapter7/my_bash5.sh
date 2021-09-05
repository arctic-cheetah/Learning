
input_file="mixed-data.csv"

#Extract First name and val column for every even row
#Problem: SUBSETS OF COLUMNS ALIGNED ROWS IN DATASETS 
#Convert csv into a single line
awk '{printf("%s", $0)}' $input_file | awk '{
    k = 0
    for (i=1; i <= NF; i+=1) {
        
        #Get the even row First name
        if (k%2 == 0 && i%4 == 1) {
            printf("%s ", $i)
        }
        #Get the even row value
        if (k%2 == 0 && i%4 == 3)  {
            #Need to remove trailing comma
            split($i, arr, ",")
            printf("%s\n", arr[1])
        }
        
        #Only include every even row
        if (i%4 == 0) {
            k +=1
        }
    }
}'