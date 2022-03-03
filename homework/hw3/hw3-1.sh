starttime=`date +'%Y-%m-%d %H:%M:%S:%N'`

sum=0
for i in $(seq 1 2 100000)
do
    sum=$((sum + i))
done
echo $sum

endtime=`date +'%Y-%m-%d %H:%M:%S:%N'`
echo "start time: $starttime"
echo "end time:   $endtime"
echo "Execution time: "$((end_seconds-start_seconds))"s"