inputfile="dates2.csv"
outputfile="formatteddates2.csv"

 


rm -f $outputfile; touch $outputfile
 


for line in `cat $inputfile`
do
    fname=`echo $line |cut -d"," -f1`
    lname=`echo $line |cut -d"," -f2`
    date1=`echo $line |cut -d"," -f3`

    # convert to new date format
    newdate=`echo $date1 | awk '{ print substr($0,1,4)"-"substr($0,5,2)"-"substr($0,7,2)" "substr($0,9,2)":"substr($0,11,2)":"substr($0,13,2)}'`



    # append newly formatted row to output file
    echo "${newdate},${fname},${lname}" >> $outputfile 
done