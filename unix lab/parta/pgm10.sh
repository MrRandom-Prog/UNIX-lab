# Write a shell program to print the prime numbers between the specified

read low
read high
prime=""
flag=0
if [ $low -lt 2 ];then
low=2
fi

while [ $low -lt $high ];do
i=2
flag=0
while [ $i -lt $low ];do
if [ $((low%i)) -eq 0 ]
then
flag=1
break
fi
i=$((i+1))
done
if [ $flag -eq 0 ];then
echo Prime $low
fi
low=$((low+1))
done
echo $prime
