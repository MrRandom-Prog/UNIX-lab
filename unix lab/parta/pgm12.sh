# Write a shell program to find the largest of three numbers using a function.
max(){
    if [ $1 -gt $2 ]
    then 
    echo $1
    else 
    echo $2
    fi
}

read a
read b
read c

max_ab=$(max $a $b)
max_abc=$(max $max_ab $c)
echo $max_abc