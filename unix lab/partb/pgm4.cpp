// Write a C program to display information of a given file which
//  determines type of file and Inode
// information, where the file name is given as command line argument.
#include<iostream>
#include<unistd.h>
#include<sys/stat.h>


using namespace std;

int main(int argc,char*argv[]){
    if(argc!=2){
        cout<<"ERROR usage ./a.out filename\n";
        exit(EXIT_FAILURE);
    }
    struct stat s;
    if(lstat(argv[1],&s)==-1){
        cout<<"Error getting file information\n";
        exit(EXIT_FAILURE);
    }
    cout<<s.st_mode<<" "<<S_IFMT<<" "<<s.st_ino<<endl;
    switch(s.st_mode & S_IFMT){
        case S_IFCHR:cout<<"Character device\n";break;
        case S_IFBLK:cout<<"Block device\n";break;
        case S_IFDIR:cout<<"Directory\n";break;
        case S_IFREG:cout<<"Regular file\n";break;
        case S_IFLNK:cout<<"Link\n";break;
        case S_IFIFO:cout<<"Fifo pipeline\n";break;
        default:cout<<"UNKOWN\n"<<endl;
    }
    cout<<"INODE no: "<<s.st_ino<<endl;
    return 0;
}