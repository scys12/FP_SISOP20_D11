#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"
#include "date.h"
#include "fs.h"
int main (int argc, char *argv[]){
    int file_input;
    
    //struct stat st;
    if(argc<2){
       printf(1,"touch : Missing one argument...\n"); 
       exit();
    }
    for(int i=1;i<argc;i++){
        if((file_input=open(argv[i],O_RDWR)) < 0 ){
            file_input=open(argv[i],O_CREATE |O_RDWR);
            if(file_input<0)
                printf(1,"touch : Error creating file %s\n",argv[i]);
        }
        else{
            struct stat st;
            fstat(file_input,&st);
            char buf[st.size];
            read(file_input, buf,sizeof(buf));
            close(file_input);
            unlink(argv[i]);
            
            if((file_input=open(argv[i],O_RDWR|O_CREATE)) < 0 ){
                printf(1,"touch : Error creating file %s\n",argv[i]);
            }
            else{
                write(file_input,buf,sizeof(buf));
            }
        }
        close(file_input);
    }
    exit();
}
