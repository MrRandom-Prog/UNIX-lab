# # # # fibo=""
# # # # i=0
# # # # f0=0
# # # # f1=1
# # # # while [ $i -lt 25 ];do
# # # # fn=$((f0+f1))
# # # # fibo=$fibo" "$f0 
# # # # f0=$f1

# # # # f1=$fn
# # # # i=$((i+1))
# # # # done
# # # # echo $fibo
# # # read min
# # # read max
# # # flag=0
# # # prime=""
# # # if [ $min -lt 2 ]
# # # then 
# # # min=2
# # # fi

# # # while [ $min -lt $max ]
# # # do 
# # # flag=0
# # # i=2
# # # while [ $i -lt $min ]
# # # do

# # # if [ $((min%i)) -eq 0 ]
# # # then
# # # flag=1
# # # break

# # # fi
# # # i=$((i+1))

# # # done
# # # if [ $flag -eq 0 ];then
# # # prime=$prime" "$min
# # # fi
# # # min=$((min+1))
# # # done
# # # echo $prime

# # read size
# # declare -a a
# # i=0
# # while [ $i -lt $size ]
# # do 
# # read a[i]
# # i=$((1+i))
# # done
# # read key
# # i=0
# # while [ $i -lt $size ]
# # do 
# # if [ ${a[i]} -eq $key ]
# # then 
# # echo Key found at i $i
# # fi
# # i=$((i+1))
# # done

# max(){
#     if [ $1 -gt $2 ]
#     then
#     echo $1
#     else
#     echo $2
#     fi
# }

# read a
# read b
# read c

# max_ab=$(max $a $b)
# echo $(max $max_ab $c)

