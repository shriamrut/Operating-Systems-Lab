#!/bin/bash
filename="$1"
while read -r line; do
    n="$line"
done < $1
l=10
counter=1
while [ $counter -le $l ]
	do
    a=`echo "$n * $counter" | bc`
	echo "$n * $counter = $a"
    ((counter++))
    done
