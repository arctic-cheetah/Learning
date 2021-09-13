
read -p "Enter val1: " val1
read -p "Enter an operator: " op
read -p "Enter val2: " val2

case $op in
    "+")
        expr $val1 + $val2
        ;;
    "-")
        expr $val1 - $val2
        ;;
    "*")
        expr $val1 * $val2
        ;;
    "/")
        expr $val1 / $val2
        ;;
    "%")
        expr $val1 % $val2
        ;;
esac
    
