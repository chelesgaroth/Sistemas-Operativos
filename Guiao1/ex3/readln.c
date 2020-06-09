#include <sys/types.h>
#include <unistd.h>   
#include <fcntl.h>   
#include <stdio.h> 



int readc (int fd , char *c){
	int res = read (fd,c,1);
	return res;
}

ssize_t main (int fd, char *buf, size_t size){
	int i=0;

	int res=0;

	while(((res = readc (fd, &buf[i])) > 0) && i< size){
		i++;
		if (buf [i-1] == '\n') {
			printf("%d\n",i);
			return i;
		}
	}
	return i;
}

