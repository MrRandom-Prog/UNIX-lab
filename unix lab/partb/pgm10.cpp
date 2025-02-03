// Write a program to implement UNIX system (), using APIs.
#include<iostream>
#include<unistd.h>
#include<sys/types.h>

using namespace std;

int status;
int system(const char* cmd){
    pid_t pid;
    if (cmd==NULL){
        return (1);
    }
    if((pid=fork())==-1){
        perror("FOrk error|||\n");
        status=-1;
        exit(EXIT_FAILURE);
    }
    if(pid==0){
        execl("/bin/sh","sh","-c",cmd,(char*)0);
        _exit(127);
    }
    if(pid>0){
        while(waitpid(pid,&status,0)<0){
            if(errno!=EINTR){
                status=-1;
                break;
            }
        }

    }
    return status;
}

int main(){
    if((system("date;exit 0"))<0){
        perror("system eror 1");
    }
    if((system("who;exit 0"))<0){
        perror("system eror 2");
    }
    if((system("daaaate;exit 0"))<0){
        perror("system eror 3");
    }
    exit(0);
}