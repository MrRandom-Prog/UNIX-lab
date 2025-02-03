# Write a shell program to prints the arguments in reverse order

rev=""
for var in $*
do
rev=$var" "$rev
done
echo $rev