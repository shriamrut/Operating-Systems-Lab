#!/bin/bash
usr=`whoami`
echo "Enter file path ,/home/usr will be added: "
read f
f="/home/$usr$f"
echo "path $f"
echo "Enter line: "
read line
echo -n "Line number: "
echo `grep -n "$line" $f | awk -F  ":" '{print $1}'`