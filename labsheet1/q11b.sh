#!/bin/bash
usr=`whoami`
f=$1
echo "line count and file path: `wc -l /home/$usr$f`"
echo "word count and file path: `wc -w /home/$usr$f`"