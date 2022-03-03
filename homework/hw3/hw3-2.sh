read -p "Please enter 2 inegers: " a b

if [ $a -gt $b ];then
    echo "The greater is: $a, the less is $b"
elif [ $a -eq $b ];then
    echo "$a is equal to $b"
else
    echo "The greater is: $b, the less is $a"
fi