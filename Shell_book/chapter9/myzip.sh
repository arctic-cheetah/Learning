#A program to search if a document contains SVG files
#in a zip
foundlist=""
notfoundlist=""

for f in `ls *zip`
do
  found=`unzip -v $f |grep "svg$"`
  if [ "$found" != "" ]
  then
   #echo "$f contains SVG documents:"
   #echo "$found"
    foundlist="$f ${foundlist}"
  else
    notfoundlist="$f ${notfoundlist}"
  fi
done

echo "Files containing SVG documents:"
echo $foundlist| tr ' ' '\n'

echo "Files not containing SVG documents:"
echo $notfoundlist |tr ' ' '\n'

