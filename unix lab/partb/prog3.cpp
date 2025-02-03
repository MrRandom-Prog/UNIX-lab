// Write a C program that reads every 5th byte from the file, where
// the file name is given as command -line argument

#include<iostream>
#include<unistd.h>
#include<fcntl.h>
using namespace std;
int main(int argc,char*argv[]){
    int n=4,fd,next,curr;
    char c;
    if(argc!=2){
        perror("Usage:./a.out <filename>");
    }

    if((fd=open(argv[1],O_RDONLY))==-1){
        perror("Error opeing file");
        exit(EXIT_FAILURE);
    }
    
    while((curr=read(fd,&c,1))==1){
        cout<<"Char : "<<c<<endl;
        next=lseek(fd,n,1);
        cout<<"New seek: "<<next<<endl;
    }
    cout<<endl;
    return 0;

}