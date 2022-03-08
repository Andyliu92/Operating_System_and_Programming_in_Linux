export sum=0

for i in $@
do
    export sum=$((sum+i))
done

echo $sum