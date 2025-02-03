// // WAP create write and read from pipe line
// // a
#include<errno.h>
#include<sys/types.h>
#include<unistd.h>
#include<iostream>
using namespace std;

// int main(){
//     int pfds[2];
//     char buf[30];
//     if(pipe(pfds)==-1){
//         perror("Pipe");
//         exit(1);
//     }
//     cout<<"Writinng to file descripter # "<<pfds[1]<<endl;
//     write(pfds[1],"text",5);
//     cout<<"Reading from file descriptor # "<<pfds[0]<<endl;
//     read(pfds[0],buf,5);
//     cout<<"Read: "<<buf<<endl;
//     return 0;
// }

// Pipeline from child
int main(){
    int n,pfds[2];
    char buf[30];
    pid_t pid;

    if(pipe(pfds)==-1){
        perror("Pipe");
        exit(1);
    }
    if((pid = fork())==-1){
        perror("FOrk Error\n");
        exit(0);
    }
    if(pid>0){
        close(pfds[0]);
        write(pfds[1],"Hello \n",7);
    }
    if(pid==0){
        close(pfds[1]);
        n=read(pfds[0],buf,7);
        write(1,buf,n);
    }
    return 0;
}