#!/bin/bash
echo -n "Enter the option,-a,-s,-m,-c,-r: "
read op
echo -n "Enter first number: "
read a
echo -n "Enter Second number: "
read b
case $op in
	-a): 
		ans=`echo "$a+$b" | bc`
		;;
	-s): 
		ans=`echo "$a-$b" | bc`
		;;
	-m):
		ans=`echo "$a*$b" | bc`
		;;
	-c):
		ans=`echo "scale=3; $a/$b" | bc -l`
		;;
	-r):
		ans=`echo "$a%$b" | bc`
		;;
	*):
		echo "Invalid operator"
		ans="Invalid"
		;;
esac
echo "Answer: $ans"