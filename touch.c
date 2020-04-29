#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int main (int argc, char *argv[]){
    int file_input;
    if(argc<2){
       printf(1,"touch : Missing one argument...\n"); 
       exit();
    }
    for(int i=1;i<argc;i++){
        if((file_input=open(argv[i],O_CREATE | O_RDWR)) < 0 ){
            printf(1,"touch : Error creating file %s\n",argv[i]);
        }
        close(file_input);
    }
    exit();
}
