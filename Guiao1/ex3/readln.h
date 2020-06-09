#include <sys/types.h>
#include <unistd.h>   
#include <fcntl.h>

ssize_t readln (int fd, void *buf, size_t size);

int readc (int fd , char *c);