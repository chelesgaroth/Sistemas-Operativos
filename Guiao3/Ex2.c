#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

int main(void){
	pid_t pid = fork();
	if(pid==0){
		execlp("ls", "-l", NULL);
		_exit(0); 
	}
	else{
		wait(NULL);
	}
	return 0;
}