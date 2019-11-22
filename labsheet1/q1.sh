#!/bin/bash
echo -n "Enter length of rectangle:  "
read l
echo -n "Enter breadth of rectangle: "
read b
area=`echo "$l*$b" | bc -l`
perimeter=`echo "2*($l+$b)" | bc -l`
echo "Area : $area"
echo "Perimeter : $perimeter"
echo -n "Enter radius of the circle: "
read r
pi=3.14
area=`echo "$pi*$r*$r" | bc -l`
perimeter=`echo "2*$pi*$r" | bc -l`
echo "Area : $area"
echo "Perimeter : $perimeter"


