// Write a program in C/C++ to display the contents of a named file on
// standard output device., Also Write a program to copy the contents
// of one file to another

#include<iostream>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>

using namespace std;

int main(int argc,char* argv[]){
    int n,fd1,fd2;
    char buff[10];
    if(argc!=3){
        perror("Usage: ./a.out <source> <destination>");
    }
    if((fd1 = open(argv[1],O_RDONLY))==-1){
        perror("Error opening the file");
        exit(EXIT_FAILURE);
    }
    
    if((fd2 = open(argv[2],O_WRONLY|O_CREAT|O_TRUNC,0644))==-1){
        perror("Error opening the destination file");
        exit(EXIT_FAILURE);
    }
    
    while((n=read(fd1,buff,1))>0){
        write(1,buff,n);
        write(fd2,buff,n);
    }
    close(fd1);
    close(fd2);
    return 0;

}
