// Write a C program to create an Orphan Process.
#include<iostream>
#include<unistd.h>

using namespace std;

int main(){
    pid_t pid;
    cout<<"ORiginal Process:"<<getpid()<<endl;
     if ((pid = fork())==-1){
        perror("Fork error");
        exit(EXIT_FAILURE);
    }
    if(pid==0){
        cout<<"Child Process\n"<<getpid()<<" P :"<<getppid()<<endl;
        sleep(5);//Orphan
        cout<<"Orphan Process\n"<<getpid()<<" P :"<<getppid()<<endl;
        system("ps -l");
    }
    else{
        cout<<"Parent process\n"<<getpid()<<" No parent Parent pid "<<getppid()<<endl;
        system("ps -l");
        exit(0);
    }
    return 0;
}