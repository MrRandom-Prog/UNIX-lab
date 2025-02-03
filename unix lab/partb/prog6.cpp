#include<iostream>
#include<unistd.h>
#include<sys/types.h>

using namespace std;

int main(){
    pid_t pid;
    int status;
    cout << "Get Pid : "<<getpid()<<endl;

    if((pid = fork()) == -1){
        perror("Fork error");
        exit(EXIT_FAILURE);
    }
    if(pid == 0){
        cout<<"CHild process\n"<<getpid()<<"\nParent pid "<<getppid()<<endl;
        exit(0);
    }
    if(pid>0){
        wait(&status);
        cout<<"Parent process\n"<<getpid()<<"\nNo parent Parent pid "<<getppid()<<endl;
        system("ps u");
    }
    return 0;
}