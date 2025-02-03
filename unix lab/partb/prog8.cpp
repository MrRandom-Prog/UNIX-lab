#include <iostream>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
using namespace std;

void prExit(int status){
    if(WIFSTOPPED(status)){
        cout<<"Chhild stopped ,signal number = "<<WSTOPSIG(status)<<endl;
    }
    if (WIFEXITED(status)){
        cout<<" Normal termination,exit status = "<<WEXITSTATUS(status)<<endl;
    }
    if(WIFSIGNALED(status)){
        cout<<"Abnormal termination,signal number = "<<WTERMSIG(status)<<endl;
    }
}

int main(){
    pid_t pid;
    int status;
    cout<<"Original process pid: "<<getpid()<<endl;

    if((pid = fork())==-1){
        perror("Fork error");
        exit(EXIT_FAILURE);
    }
    if(pid ==0){
        exit(23);
    }
    if (pid>0){
        wait(&status);
        cout<<"Parent Process "<<getpid()<<" child status "<<endl;
        prExit(status);
    }



    if((pid = fork())==-1){
        perror("Fork error");
        exit(EXIT_FAILURE);
    }
    if(pid ==0){
        abort();

    }
    if (pid>0){
        wait(&status);
        cout<<"Parent Process "<<getpid()<<" child status "<<endl;
        prExit(status);
    }


    if((pid = fork())==-1){
        perror("Fork error");
        exit(EXIT_FAILURE);
    }
    if(pid ==0){
        int a = 0;
        if (a == 0) {
            cout << "Division by zero error" << endl;
            exit(EXIT_FAILURE);
        }
        int b = 5 / a;
        cout << b << endl;
        cout<<a<<endl;
        abort();
    }
    if (pid>0){
        wait(&status);
        cout<<"Parent Process "<<getpid()<<" child status"<<endl;
        prExit(status);
    }

    

}