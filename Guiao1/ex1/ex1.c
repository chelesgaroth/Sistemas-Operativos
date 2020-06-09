#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <stdio.h>

int copia (char* const source ,char* const target ,int buffer_size){

	int d1 = open(source,O_RDONLY);

	int d2 = open(target,O_WRONLY|O_CREAT|O_TRUNC, 0644); //(octal)6=rw , 4=r; -rw-rw-r-- 1

    //#define MAX 4046 //char buffer[MAX];
	char buf[buffer_size];
	int end;

	while((end = read(d1,buf,buffer_size))>0){
		write(d2,buf,end);

	}
	if(end <0) printf("ERROR\n");
	close(d1);
	close(d2);
	return 0;
}


