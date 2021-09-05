#inputfile="quotes1.csv"
#inputfile="quotes2.csv"
inputfile="quotes3.csv"

 
#Clean csv where fields can be nested with random depth

grep -v "^$" $inputfile | awk '
{
   print "LINE #" NR ": " $0
   printf ("-------------------------\n")
   for (i = 1; i <= NF; i +=1)
     printf "field #%d : %s\n", i, $i
 printf ("\n")
}' FPAT='([^,]+)|("[^"]+")'