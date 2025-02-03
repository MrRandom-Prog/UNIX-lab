# Write a shell script that accepts two file names as arguments,
# checks if the permissions for these files are identical and
#  if the permissions are identical, output common permission and 
#  otherwise output each file name followed by its
a=`ls -l $1|cut -c 2-10`
b=`ls -l $b|cut -c 2-10`

if [ "$a" == "$b" ];then
echo Same permission
echo $a
else
echo different permission
echo $a
echo $b
fi
