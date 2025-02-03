#include<iostream>
#include<unistd.h>
using namespace std;

int main(){
    pid_t pid;
    if((pid=vfork())==-1){
        perror("FOrk Error\n");
        exit(EXIT_FAILURE);
    }
    if(pid==0){
        cout<<"Child Process\t"<<getpid()<<"\tParent pid\t"<<getppid()<<endl;
    }
    if(pid>0){
        cout<<"Parent Process\t"<<getpid()<<"\tParent pid\t"<<getppid()<<endl;
    }
    return 0;
}
