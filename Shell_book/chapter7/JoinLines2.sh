cat columns2.txt | awk '
BEGIN { count = 1 }
{ 
   printf("%s",$0) 
   if( count % 2 == 0) { print " " }
   count +=1
}
'

