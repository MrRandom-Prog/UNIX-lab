#include<iostream>
#include<unistd.h>

using namespace std;

// move is impoletemented using first link and then delete the first file

int main(int argc,char* argv[]){
    if(argc != 3){
        perror("Usage: ./a.out <sourcefile name> <destination file name>\n");{
        exit(EXIT_FAILURE);
        }
    }
    if(link(argv[1],argv[2])==-1){
        perror("Link Failed\n");
        exit(EXIT_FAILURE);
    }
    if(unlink(argv[1])==-1){
        perror("Delete Failed\n");
        exit(EXIT_FAILURE);
    }
    cout<<"FIle moved sucessfully\n";
    return 0;

}


//  unlink(filename) : This function deletes the file specified by filename.
// int main(int argc, char* argv[]){
//     int i;
//     if(argc<=1){
//         cout<<"No file to delete\n Usage : ./a.out <file 1 name> <file 2 name> ... <file n name>\n";
//         exit(EXIT_FAILURE);
//     }
//     else{
//         for(i=1;i<argc;i++){
//             if(unlink(argv[i])==-1){
//                 perror("Error in deleting file");
//             }
//             else{
//                 cout<<"File "<<argv[i]<< " deleted Sucessfully\n";
//             }
//         }
//     }
//     return 0;
// }


// int link(const char *oldpath, const char *newpath);
// int main(int argc,char* argv[]){
//     if (argc != 3){
//         cout<< "Usage: ./prog1 <source File name> <link file name> " << endl;
//         exit(EXIT_FAILURE);
//     }
//     else{
//         if((link(argv[1],argv[2]))==-1){
//             perror("Link Failed\n");
//         }
//         else{
//             cout<<"Link created successfully\n";
//         }
//     }
//     return 0;
// }
