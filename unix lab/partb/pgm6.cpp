// Write a program to demonstrate the process is Zombie
//  and to avoid the Zombie process.

#include<iostream>
#include<unistd.h>

using namespace std;
int main(){
    int status;
    pid_t pid;
    if((pid=fork())==-1){
        perror("Fork error\n");
        exit(EXIT_FAILURE);
    }
    if(pid==0){
        cout<<"CHild Process:"<<getpid()<<"parent:"<<getppid();
        exit(0);
    }
    if(pid>0){

        cout<<"Parent Process:"<<getpid()<<"Parent: "<<getppid();
        system("ps u");
    }
    return 0;

}