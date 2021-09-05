input_file="namepairs.csv"
output_file="reverse_names.csv"
fnames="fnames"
lnames="lnames"
cat $input_file | cut -d"," -f2 > $lnames
cat $input_file | cut -d"," -f1 > $fnames
paste -d"," $lnames $fnames > $output_file