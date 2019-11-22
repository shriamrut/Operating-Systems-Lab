c=0
for var in "$@"
do
c=`expr $c + 1`
done
echo "Number of arguements: $c"
