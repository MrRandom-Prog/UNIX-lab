// Write a C program that reads every 100th byte from the file,
//  where the file name is given as command -line argument
#include<iostream>
#include<fcntl.h>
#include<unistd.h>

using namespace std;

int main(int argc,char* argv[]){
    int fd,n=4,next,curr;
    char c;
    if(argc != 2){
        cout<<"USage ./a.out <filename>\n";
        exit(EXIT_FAILURE);
    }
    if((fd=open(argv[1],O_RDONLY))==-1){
        cout<<"ERror opeing file"<<endl;
        exit(EXIT_FAILURE);
    }
    while(read(fd,&c,1)==1){
        cout<<"CHar read:"<<c<<endl;
        next = lseek(fd,n,1);
        cout<<"newSeek: "<<next<<endl;

    }
    return 0;
}