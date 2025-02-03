# 6. Write a shell program to do the followings on strings:
# i. find length of a string 
# ii. check whether string is NULL 
# iii, check if two strings are equal or not.

read str1
echo length of $str1 is ${#str1}
read str2
echo length of $str2 is ${#str2}
echo $str1 
if [ ${#str1} -eq 0 ];then
echo NULL
else
echo Not NULL
fi
echo $str2 
if [ ${#str2} -eq 0 ];then
echo NULL
else
echo Not NULL
fi
if [ "$str2" == "$str1" ];then
echo same
else
echo Different
fi

