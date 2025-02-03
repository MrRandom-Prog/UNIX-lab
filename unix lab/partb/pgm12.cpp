//Pipeline
#include<unistd.h>
#include<iostream>

using namespace std;
/*
int main(){
    int pfds[2];
    char buf[30];
    if(pipe(pfds)==-1){
        perror("Pipe");
        exit(1);
    }
    cout<<"Writing into File descreptor # "<<pfds[1]<<endl;
    write(pfds[1],"Hare Krishna",10);
    cout<<"Reading from file descreptor # "<<pfds[0]<<endl;
    read(pfds[0],buf,10);
    cout<<"Read: "<<buf<<endl;
    return 0;
}
*/

int main(){
    int pfds[2];
    int n;
    char buf[30];
    pid_t pid;

    if((pipe(pfds))==-1){
        perror("Pipe");
        exit(0);
    }
    if((pid=fork())==-1){
        perror("FOrk error");
        exit(1);
    }
    if(pid==0){
        close(pfds[1]);
        n=read(pfds[0],buf,12);

        cout<<buf;
    }
    if(pid>0){
        close(pfds[0]);
        write(pfds[1],"Hare Krishna",12);
    }
    return 0;
}