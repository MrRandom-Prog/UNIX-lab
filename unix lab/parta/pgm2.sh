# Write a shell program which takes two file names as arguments, 
# if their contents are the same then remove the second file.

a=$(cat $1)
b=$(cat $2)

if [ "$a" = "$b" ]
then 
echo same content
rm -r $2

else
echo differenct content
echo $1 content 
echo $a
echo $2 content
echo $b
fi
