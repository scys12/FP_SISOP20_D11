#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int panjang(char* teks){
    int panjang;
    panjang = 0;
    while(teks[panjang]!='\0'){
        panjang++;
    }
    return panjang;
}

int main(int argc, char *argv[]){
	int x;
	if((x = open(argv[1], O_RDONLY)) < 0){
		printf(1, "failed to read %s\n", argv[1]);
		exit();
	}
	char buff[1000], hasil[1000];
	int y, z;
	int count = 0; count1=0;
	int i;
	y = read(x, buff, sizeof(buf));
	z = panjang(buff);
	if(y > 0){
		while(z > 0){
			if(buff[counterb] != '\t'){
				hasil[count] = buff[count1];
				count++;
				count1++;
			}
			else if(buff[count1] == '\t'){
				for(i = 1; i <= 3; i++){
					hasil[count] = ' ';
					count++;
				}
				count1++;
			}
			z--;
		}
	}
	close(x);
	printf(1, "%s", hasil);
	exit();
}
