# Write a shell program that accepts one or more file names as arguments
#  and converts all of them to uppercase, 
# provided they exist in the current directory.

ls
for i in $*
do 
if [ -e $i ]
then 
new=`echo $i | tr "[a-z]" "[A-Z]"`
mv $i $new 
else
echo $i not found
fi
done
ls