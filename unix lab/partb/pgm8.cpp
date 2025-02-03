#include<iostream>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<csignal>

using namespace std;

void prExit(int status){
    if(WIFSTOPPED(status)){
        cout << "Child stopped, signal no: " << WSTOPSIG(status) << endl;
        sleep(2);  // Give some time before resuming
        cout << "Parent resuming child...\n";
        kill(getppid(), SIGCONT);
    }
    if(WIFEXITED(status)){
        cout<<"NORMAL termination signal no:"<<WEXITSTATUS(status)<<endl;
    }
    if(WIFSIGNALED(status)){
        cout<<"Abmnormal trmeinatipn signal no:"<<WTERMSIG(status)<<endl;
    }
}

int main(){
    pid_t pid;
    int status;
    for(int i=0;i<3;i++){
    if((pid = fork())==-1){
        perror("Fork error");
        exit(EXIT_FAILURE);
    }
    if(pid==0){
        cout<<"Chlid"<<getpid()<<" p: "<<getppid();
        switch(i){
        case(0):exit(23);break;
        case(1):abort();break;
        case(2):raise(SIGSTOP);break;
        }

    }
    if(pid>0){
        wait(&status);
        cout<<"Parent"<<getpid();
        prExit(status);
    }
    }

    return 0;
}
