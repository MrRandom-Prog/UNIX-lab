#include<iostream>
#include<stdio.h>
#include<unistd.h>

using namespace std;

int main(int argc,char*argv[]){
    if(argc<=1){
        perror("No file to delete\nUsage ./a.out <filename1 filename2 ...>\n");
        exit(EXIT_FAILURE);
    }
    for(int i=0;i<argc;i++){
        if(unlink(argv[i])==-1){
            perror("Unlink failed\n");
        }
        else {
            cout<<"deleted "<<argv[i]<<endl;
        }
    }
    return 0;
}