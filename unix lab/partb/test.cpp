// // // // // #include<iostream>
// // // // // #include<unistd.h>
// // // // // using namespace std;
// // // // // int main(int argc,char*argv[]){
// // // // //     if(argc!=3){
// // // // //         cout<<"Usage";
// // // // //         exit(EXIT_FAILURE);
// // // // //     }
// // // // //     // move
// // // // //     link(argv[1],argv[2]);
// // // // //     unlink(argv[1]);
// // // // //     cout<<"Move sucessfully";

// // // // // }
// // // // #include<iostream>
// // // // #include<unistd.h>
// // // // #include<fcntl.h>
// // // // using namespace std;
// // // // int main(int argc,char*argv[]){
// // // //     int f1,f2,n;
// // // //     char buf[30];
// // // //     f1=open(argv[1],O_RDONLY);
// // // //     f2=open(argv[2],O_WRONLY|O_CREAT|O_TRUNC);
// // // //     while((n=read(f1,buf,1))>0){
// // // //         write(1,buf,n);
// // // //         write(f2,buf,n);
// // // //     }
// // // //     close(f1);
// // // //     close(f2);
// // // // }

// // // #include<iostream>
// // // #include<unistd.h>
// // // #include<fcntl.h>

// // // using namespace std;

// // // int main(int argc,char*argv[]){
// // //     int f,n=4,curr,next;
// // //     char c;
// // //     f=open(argv[1],O_RDONLY);
// // //     while((curr=read(f,&c,1))){
// // //         cout<<"Read char:"<<c<<endl;
// // //         next = lseek(f,n,1);
// // //         cout<<"Next:"<<next;
// // //     }
// // //     return 0;

// // // }

// // #include<iostream>
// // #include<sys/stat.h>
// // #include<unistd.h>

// // using namespace std;
// // int main(int argc,char* argv[]){
// //     if(argc!=2){
// //         cout<<"Usage";
// //         exit(EXIT_FAILURE);
// //     }
// //     struct stat s;
// //     lstat(argv[1],&s);
// //     cout<<s.st_ino;
// //     switch(s.st_mode&S_IFMT){
// //         case(S_IFBLK):cout<< "BLock" <<endl;break;
// //         case(S_IFCHR):cout<<  "CHar"<<endl;break;
// //         case(S_IFLNK):cout<< "LINK" <<endl;break;
// //         case(S_IFIFO):cout<< "FIFO" <<endl;break;
// //         case(S_IFREG):cout<< "REG" <<endl;break;
// //         case(S_IFDIR):cout<< "DIR" <<endl;break;
// //         default:cout<<"Unknown"<<endl;
// //     }


// // }


#include<iostream>
#include<unistd.h>
#include<signal.h>

using namespace std;

// void prexit(int status){
//     if(WIFSTOPPED(status)){
//         cout<<"Stopped Signal:"<<WSTOPSIG(status)<<endl;
//     }
//     if(WIFEXITED(status)){
//         cout<<"EXITED Signal:"<<WEXITSTATUS(status)<<endl;
//     }
//     if(WIFSIGNALED(status)){
//         cout<<"SEND Signal:"<<WTERMSIG(status)<<endl;
//     }

// }

// void printer(const char* str){
//     const char* ptr;
//     char c;
//     setbuf(stdout,NULL);
//     for(ptr=str;(c=*ptr++)!=0;putc(c,stdout)){
//         usleep(100);
//     }
// }
// void handler(int id){
//     cout<<"caught signal:"<<id;
//     exit(0);
// }
int main(){
    int pfds[2];
    char buf[30];

    pipe(pfds);
    // write(pfds[1],"Hare Krishna",15);
    // cout<<"Writing from #"<<pfds[1]<<"\nreading from:"<<pfds[0]<<endl;
    // read(pfds[0],buf,15);
    // cout<<buf;
    // return 0;

    pid_t pid;
   
    // int status;
    
    pipe(pfds);
        if((pid=fork())==-1){
            exit(EXIT_FAILURE);
        }
    if(pid>0){
        close(pfds[0]);
        write(pfds[1],"Hare Krishna",12);
        close(pfds[1]);
    }
    if(pid==0){
        close(pfds[1]);
        read(pfds[0],buf,12);

        cout<<buf;
        close(pfds[0]);
        }
            
    
    
    
    return 0;
}

