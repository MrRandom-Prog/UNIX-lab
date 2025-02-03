# Write a shell program to print the given number in reversed
read num
rev=0
cpy=$num
while [ $cpy -gt 0 ];do
digit=$((cpy%10))
rev=$((rev*10+digit))

cpy=$((cpy/10))
done
echo $rev