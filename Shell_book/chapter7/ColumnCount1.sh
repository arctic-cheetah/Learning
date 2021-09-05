cat columns.txt | awk '
{ 
   if( NF % 2 == 0 ) { print $0 }
}
'

