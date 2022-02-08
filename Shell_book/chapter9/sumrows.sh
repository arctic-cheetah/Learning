awk '{ j=0; for(i=1; i<=NF;i++) j+=$i; print j;}' numbers.txt

