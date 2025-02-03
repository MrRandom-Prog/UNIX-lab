//SYSTEM() copy
#include<iostream>
#include<sys/types.h>
#include<unistd.h>
using namespace std;

int status;

int system(const char* cmd){
    pid_t pid;
    if(cmd==NULL){
        return (1);
    }
    if((pid=fork())==-1){
        status=-1;
    }
    else if(pid==0){
        execl("/bin/sh","sh","-c",cmd,(char*)0);
        _exit(127);
    }
    else {
        while(waitpid(pid,&status,0)<0){
            if(errno!=EINTR){
                status = -1;
                break;
            }
        }
    }return status;
}
int main(){
    if((status=system("date;exit 0"))<0){
        perror("System() Error");
    }
    if((status=system("ls;exit 0"))<0)
        perror("System() Error");
    if((status=system("who;exit 44"))<0)
        perror("System() Error");
    exit(0);
}