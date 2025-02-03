// RAce Condition

#include<iostream>
#include<unistd.h>

using namespace std;

void charatatime(const char* str){
    const char* ptr;
    int c;
    setbuf(stdout,NULL);
    for(ptr=str;(c=*ptr++)!=0;putc(c,stdout)){
        usleep(100);
    }
}

int main(){
    pid_t pid;
    if((pid=fork())==-1){
        printf("Fork Error!!!\n");
    }
    if(pid==0){
        charatatime("This is chould process\n");
    }
    if(pid>0){
        charatatime("THis is Praent Process\n");
    }
    return 0;
}