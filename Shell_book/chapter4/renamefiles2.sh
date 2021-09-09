newsuffix="txt"

for f in `ls *sh`
do
   base=`echo $f |cut -d"." -f1`
   suffix=`echo $f |cut -d"." -f2`
   newfile="$base.$newsuffix"
   echo "file: $f new: $newfile"

  #either 'cp' or 'mv' the file
  #mv $f $newfile
  #cp $f $newfile
done