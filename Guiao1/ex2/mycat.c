#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <stdio.h>

int mycat (char* stdin, int buffer_size){

	int f1 = open(stdin,O_RDONLY);

	char buf[buffer_size];
	int end;
	int* stdout[20000];
	int f2;

	while((end = read(f1,buf,buffer_size))>0){
		write(stdout,buf,end);
	}
	close(f1);
}

int main(int argc, char* argv[]){

	mycat(argv[1],64);
	return 0;
}