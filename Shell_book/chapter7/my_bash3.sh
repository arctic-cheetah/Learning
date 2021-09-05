#A program to demonstrate printing a data set in a fixed number of columns

#print everything in one line
awk '{printf("%s ", $0)}' VariableColumns.txt | awk '
{
    columnCount = 3
    #For every three words, make a new line
    #NF means number of fields

    for (i = 1; i <= NF; i+=1) {
        printf("%s ", $i)
        if (i % columnCount == 0) {
            print"" #Automatically prints a '\n'
        }
    }
    print""
}' 