#Seperate words, integers and alphanumeric

x="ghi abc Ghi 123 #def5 123z"

#Need to put the variables all the strings on 
#a seperate line for awk to work with

# echo "Only words"
# echo $x | tr -s " " "\n" | awk '{
#     if ($0 ~ /^[A-Za-z]+$/) {
#         printf("%s\n", $0)
#     }
# }'

# echo "Only numbers"
# echo $x | tr -s " " "\n" | awk '{
#     if ($0 ~ /^[0-9]+$/) {
#         printf("%s\n", $0)
#     }
# }'

# echo "Only alphanumeric"
# echo $x | tr -s " " "\n" | awk '{
#     if ($0 ~ /^[A-Za-z0-9]+$/) {
#         printf("%s\n", $0)
#     }
# }'


#Solution using POSIX regex
echo "Only words"
echo $x | tr -s " " "\n" | awk '{
    if ($0 ~ /^[[:alpha:]]+$/) {
        printf("%s\n", $0)
    }
}'

echo "Only numbers"
echo $x | tr -s " " "\n" | awk '{
    if ($0 ~ /^[[:digit:]]+$/) {
        printf("%s\n", $0)
    }
}'

echo "Only alphanumeric"
echo $x | tr -s " " "\n" | awk '{
    if ($0 ~ /^[[:alnum:]]+$/) {
        printf("%s\n", $0)
    }
}'

