// catch ignore accept signal SIGINT
#include<iostream>
#include<unistd.h>
#include<signal.h>
#include<cstdlib>
using namespace std;
// Catch
void handler(int signo){
    cout<<"\n Signal Handler:cached Signal nunm is => "<<signo<<endl;
    exit(0);
}

int main(){
    signal(SIGINT,handler);
    while(1) 
        cout<<"CUSTOM HELLO\t";
    return 0;
}

// // Default SIgnal
int main(){
    signal(SIGINT,SIG_DFL);
    while(1) cout<<"Default Hello\t";
}

// // IGnore the signal

int main(){
    signal(SIGINT,SIG_IGN);
    while(1) cout<<"IGNORE HELLO\t";
}

