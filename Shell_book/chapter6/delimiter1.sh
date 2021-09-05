inputfile="delimiter1.txt"
cat $inputfile | sed -e 's/:/,/g' -e 's/|/,/g' -e 's/\^/,/g'

