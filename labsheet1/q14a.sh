#!/bin/bash
echo "/home/usr will be added"
echo "Enter file path 1: "
usr=`whoami`
read f1
echo "Enter file path 2"
read f2
f1="/home/$usr$f1"
f2="/home/$usr$f2"
`cat $f2 >> $f1`