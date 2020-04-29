#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"
#include "fs.h"
void tailline(char* path, long long int linestoprint,int total)
{
    int fd;
    char line[1];
    int status;
    long long int totline=0;
    fd = open(path, 0);
    while((status = read(fd, line, sizeof(line))) > 0)
    {
        if(line[0] == '\n')
            totline++;
    }
    if(status<0)
    {
        printf(1, "tail : error reading %s\n", path);
        return;
    }
    long long int skip = totline - linestoprint;
    if(skip<0) skip = 0;
    if(total > 1)
    {
        printf(1, "==> %s <==\n", path);
    }
    close(fd);
    fd = open(path, 0);
    while(skip>0)
    {
        status = read(fd, line, sizeof(line));
        if(line[0] == '\n')
        {
            skip--;
        }

    }
    while((status = read(fd, line, sizeof(line))) > 0)
    {
        printf(1, "%c", line[0]);
    }
    close(fd);
    printf(1,"\n");
}


int main(int argc, char* argv[])
{
    int fd = -1;
    if(argc <=1)
        printf(1, "Usage: tail <mode> <filename>");
    else if(argc > 1)
    {
        int i;
        for(i=1;i<argc;i++)
        {
            fd = open(argv[i], 0);
            if(fd < 0)
                printf(1, "tail : error opening %s\n", argv[i]);
            else
            {
                close(fd);
                tailline(argv[i], 10, argc-1);
            }
        }
    }
    exit();
}
