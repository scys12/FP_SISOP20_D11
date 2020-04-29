#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"
char buf[512];

void catMode(int fd){
  int n, p, counter, counter2;
  char hasil[1000];
  counter = counter2 =0;
  n = read(fd,buf,sizeof(buf));
  p = strlen(buf);
  if (n>0)
  {
    while (p>0)
    {
      if(buf[counter2] !='\t' && buf[counter2] !='\n'){
        hasil[counter] = buf[counter2];
        counter++;
        counter2++;
      } else if (buf[counter2] == '\t')
      {
        hasil[counter++] = '^';
        hasil[counter++] = 'I';
        counter2++;
      }else if (buf[counter2] == '\n')
      {
        hasil[counter++] = '$';
        counter2++;
      }
      
      p--;
    }
    printf(1,"%s", hasil);
  }
  
}

void cat(int fd)
{
  int n;

  while ((n = read(fd, buf, sizeof(buf))) > 0)
  {
    if (write(1, buf, n) != n)
    {
      printf(1, "cat: write error\n");
      exit();
    }
  }
  if (n < 0)
  {
    printf(1, "cat: read error\n");
    exit();
  }
}

int main(int argc, char *argv[])
{
  int fd, i;

  if (argc <= 1)
  {
    cat(0);
    exit();
  }

  if (argv[1][0] == '-')
  {
    if (argv[1][1] == 'A')
    {
      for (i = 2; i < argc; i++)
      {
        if ((fd =open(argv[i], O_RDONLY)) < 0)
        {
          printf(1, "cat: cannot open %s\n", argv[i]);
          exit();
        }
        catMode(fd);
        close(fd);
      }
      exit();
    }
  }
  else
  {
    for (i = 1; i < argc; i++)
    {
      if ((fd = open(argv[i], 0)) < 0)
      {
        printf(1, "cat: cannot open %s\n", argv[i]);
        exit();
      }
      cat(fd);
      close(fd);
    }
    exit();
  }
}
