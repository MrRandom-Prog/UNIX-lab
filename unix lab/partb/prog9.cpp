// Race Condition
#include<iostream>
#include<unistd.h>


using namespace std;

void c(const char*str){
    const char* ptr;
    int c;
    setbuf(stdout,NULL);

    for(ptr=str;(c=*ptr++)!=0;putc(c,stdout));
}

int main(){
    pid_t pid;
    if((pid=fork())==-1){
        printf("Fork Error!!!\n");
    }
    if(pid ==0){
        c("This is Child Process\n");
    }
    else if(pid>0){
        c("This is Parent Process\n");
    }
    return 0;
}