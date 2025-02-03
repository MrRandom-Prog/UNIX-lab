# # Write a shell program to search the given key element using linear
# read size
# declare -a a
# i=0
# while [ $size -gt 0 ] ;do
# read a[i]
# i=$((i+1))
# size=$((size-1))
# done

# echo ${a[@]}
# read key
# while [ $i -gt -1 ]
# do 
# if [ $key == $a[$i] ]
# then 
# echo Element Found at Key: $i
# fi
# done


declare -a a
read size
i=0
while [ $size -gt $i ];do
read a[i]
i=$((i+1))
done
i=0
read key
flag=1
while [ $size -gt $i ];do
if [ "${a[i]}" == "$key" ];then
echo $key is at $((i+1)) position in array
flag=0
fi
i=$((i+1))
done

if [ $flag -gt 0 ]
then
echo Not Found
fi
