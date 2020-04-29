#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int length(char *input){
    int length = 0;
    while(input[length]!='\0')  
    {
        length++;
    }
    return length;
}

int main(int argc, char *argv[]){
	int f1;
	char hasil[1000], buf[1000];
	
	if((f1 = open(argv[1], O_RDONLY)) < 0){
		printf(1, "failed to read %s\n", argv[1]);
		exit();
	}
	int n, p, i,counter, counterb;
	counter = 0; counterb=0;
	n = read(f1, buf, sizeof(buf));
	p = length(buf);
	if(n > 0){
		while(p > 0){
			if(buf[counterb] != '\t'){
				hasil[counter] = buf[counterb];
				counter++; counterb++;
			}
			else if(buf[counterb] == '\t'){
				for(i=1; i<=3;i++){
					hasil[counter] = ' ';
					counter++;
				}
				counterb++;
			}
			p--;
			//printf(1, "%d\n", p);
			//printf(1, "%s\n", hasil);
		}
	}
	
	close(f1);
	printf(1, "%s", hasil);
	exit();
}
