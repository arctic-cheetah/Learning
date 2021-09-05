#A program that only shows the first column
awk '{ for (i=1; i<=1; i++) printf "%s ", $i; printf "\n"; }' products.txt

#A program that excludes the first column
awk '{for (i=2; i <= NF; i+=1) printf("%s ", $i); printf("\n")}' products.txt