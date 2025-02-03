# Write a shell program that creates a student database 
# file which consists of sid, sname, ssem, dept. Display only 
# Student Name, Department, and frequency of occurrences of students
#  belonging to respective departments.
echo "Name | USN | SEM | DEPT"
cat > db.txt
echo "Student Name | Dept"
cut -d '|' -f1,4 db.txt
echo "Dept | NO of students"
cut -d '|' -f4 db.txt |sort | uniq -c

