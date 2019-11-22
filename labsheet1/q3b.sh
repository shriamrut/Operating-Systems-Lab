#!/bin/bash
n=$1
l=$2
counter=1
while [ $counter -le $l ]
	do
    a=`echo "$n * $counter" | bc`
	echo "$n * $counter = $a"
    ((counter++))
    done