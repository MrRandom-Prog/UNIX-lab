//orphan process
#include <iostream>
#include <unistd.h>
#include<sys/types.h>

using namespace std;

int main(){
    pid_t pid;
    cout<<"Original Process pid: "<<getpid()<<endl;
    if ((pid = fork())==-1){
        perror("Fork error");
        exit(EXIT_FAILURE);
    }
    if(pid ==0){
        cout<< "child process\n"<<getpid()<<" Parent pid "<<getppid()<<endl;
        sleep(5);//orphan creation
        cout<< "child process\n"<<getpid()<<" after sleep New Parent pid "<<getppid()<<endl;
        system("ps -l");
    }
    else{
        cout<<"Parent process\n"<<getpid()<<" No parent Parent pid "<<getppid()<<endl;
        system("ps -l");
        exit(0);
    }
    return 0;
}