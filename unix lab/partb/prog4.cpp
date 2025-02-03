// Write a C program to display information of a given file which
// determines type of file and Inode information, where the file name
// is given as command line argument.

#include<iostream>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>


using namespace std;
int main(int argc,char*argv[]){
    if(argc != 2){
        perror("Usage: ./a.out <filename>");
        exit(EXIT_FAILURE);
    }
    struct stat s;

    if(stat(argv[1],&s)==-1){
        perror("Error getting file information\n");
        exit(EXIT_FAILURE);
    }

    cout<<s.st_mode<<" "<<S_IFMT<<" "<<s.st_ino<<endl;
    switch (s.st_mode & S_IFMT){
        case S_IFLNK:cout<<"Symbolik link\n";break;
        case S_IFREG:cout<<"REG FILE\n";break;
        case S_IFIFO:cout<<"FIFO PIPELINE\n";break;
        case S_IFCHR:cout<<"CHARRACTER DEVICE\n";break;
        case S_IFBLK:cout<<"Block Device\n";break;
        
        case S_IFDIR:cout<<"DIRECTORY\n";break;
        default: cout<<"Unknown\n";break;
    }
    cout<<"Inode no: "<<s.st_ino<<endl;
    return 0;

}