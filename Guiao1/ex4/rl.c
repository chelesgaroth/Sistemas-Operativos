#include <sys/types.h>
#include <unistd.h>   
#include <fcntl.h>   
#include <stdio.h> 


char read_buffer[1024]; //MAX_READ_BUFFER
int read_buffer_pos = 0;
int read_buffer_end = 0; 

int readc (int fd , char *c){
	if (read_buffer_pos == read_buffer_end){
		read_buffer_end = read(fd ,read_buffer, 1024);
	}

	*c = read_buffer [read_buffer_pos++];
	return 1;
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


