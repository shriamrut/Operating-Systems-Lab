#!/bin/bash
usr=`whoami`
echo "Enter file path,home/usr will be added: "
read f
echo "line count and file path: `wc -l /home/$usr$f`"
echo "word count and file path: `wc -w /home/$usr$f`"