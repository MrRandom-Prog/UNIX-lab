# Write a shell program to print the first 25 Fibonacci numbers.
fibo=" "
i=0
f1=0
f2=1
while [ $i -lt 25 ];do
fn=$((f1+f2))
fibo=$fibo" "$fn
f1=$f2
f2=$fn
i=$((i+1))
done
echo $fibo