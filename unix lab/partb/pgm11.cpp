// catch ignore accept signal sigint

#include<iostream>
#include<unistd.h>
#include<signal.h>
// #include<cstdlib>

using namespace std;

// void handler(int sig_no){
//     cout<<"\nSIgnal Handeler :catched SIgnal NO:"<<sig_no<<endl;
//     exit(0);
// }

// int main(){
//     signal(SIGINT,handler);
//     while(1)
//     cout<<"custom handler\t";
//     return 0;
// }

// int main(){
//     signal(SIGINT,SIG_DFL);
//     while(1) cout<<"Default Hello\n";
// }

int main(){
    signal(SIGINT,SIG_IGN);
    while(1) cout<<"IGNORE\t";
    return 0;
}