string=`uptime | awk '{print int($12)}'`

while true
do
    echo "Check time:"
    date
    if [ $string -gt 1 ];then
        echo "System overload within 15 minute avg load of $string." | mail -s "System Overload warning" andyliu
        echo "Alarm mail sent."
    fi
    sleep 300s
done