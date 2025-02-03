# Write a shell program that takes a command line argument and 
# reports on whether it is directory, a file, or something else.

if [ -L $1 ]
then 
echo Link
elif [ -c $1 ];then
echo char file
elif [ -b $1 ];then
echo block device
elif [ -d $1 ];then
echo directory
elif [ -f $1 ];then
echo file
else
echo Unknown
fi
