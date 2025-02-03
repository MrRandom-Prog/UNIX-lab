#include<iostream>
#include<unistd.h>
#include<sys/types.h>


using namespace std;

int main(){
    pid_t pid;
    cout<<"Get pid: "<<getpid()<<endl;
    if((pid = vfork())==-1){
        perror("Fork error");
        exit(EXIT_FAILURE);
    }
    if(pid==0){
        cout<<"Child processs\n"<<getpid()<<"\nParent pid "<<getppid()<<endl;
    }
    if(pid>0){
        cout<<"Parent process\n"<<getpid()<<"\nNo parent Parent pid "<<getppid()<<endl;
    }
    return 0;
}