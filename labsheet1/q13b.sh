#!/bin/bash
usr=`whoami`
f=$1
f="/home/$usr$f"
echo "path $f"
line=$2
echo -n "Line number: "
echo `grep -n "$line" $f | awk -F  ":" '{print $1}'`