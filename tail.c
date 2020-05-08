#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"
#include "fs.h"

void baris(char* path, long long int toprint,int jumlah){
    int x, f1;
    char line[1];
    long long int lines=0;
    x = open(path, 0);
    while((f1 = read(x, line, sizeof(line))) > 0){
        if(line[0] == '\n')
            lines++;
    }
    if(f1 < 0){
        printf(1, "tail : error reading %s\n", path);
        return;
    }
    long long int skip = lines - toprint;
    if(skip < 0)
		skip = 0;
    if(jumlah > 1){
        printf(1, "==> %s <==\n", path);
    }
    close(x);
    x = open(path, 0);
    while(skip > 0){
        f1 = read(x, line, sizeof(line));
        if(line[0] == '\n'){
            skip--;
        }
    }
    while((f1 = read(x, line, sizeof(line))) > 0){
        printf(1, "%c", line[0]);
    }
    close(x);
    printf(1,"\n");
}

int main(int argc, char* argv[])
{
    int x = -1;
    if(argc <= 1)
        printf(1, "Usage: tail <mode> <filename>");
    else if(argc > 1){
        int i;
        for(i = 1; i < argc; i++){
            x = open(argv[i], 0);
            if(x < 0)
                printf(1, "tail : error opening %s\n", argv[i]);
            else{
                close(x);
                baris(argv[i], 10, argc-1);
            }
        }
    }
    exit();
}
