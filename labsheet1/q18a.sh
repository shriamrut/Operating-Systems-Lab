c=0
while [ $c -le $# ]  
do
c=`expr $c + 1`
done
c=`expr $c - 1 `
echo "Number of arguments: $c"
