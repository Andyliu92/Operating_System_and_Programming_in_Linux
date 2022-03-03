string=`top -n1 | fgrep "Cpu(s)" | tail -1 | awk '{print int($8)}'`

while true
do
    echo "Check time:"
    date
    if [ $string -lt 100 ];then
        echo "CPU overload within 15 minute avg load of $((100 - $string))%." | mail -s "CPU Overload warning" andyliu
        echo "Alarm mail sent."
    fi
    sleep 300s
done