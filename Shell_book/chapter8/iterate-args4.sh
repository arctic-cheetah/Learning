
function iterate() { 
  for ((i=2; i <= "$#"; i++))
  do
    echo "arg position: ${i}"
    echo "arg value:    ${!i}"
    echo 
  done
}

iterate a b c d e

