#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>


int main(int argc, char const *argv[]){
	pid_t pid;
	switch (pid = fork()){
		case -1:
			perror("fork");
			break;
		case 0:
			printf("PROCESSO FILHO: PID processo %d, PID pai %d\n",getpid(),getppid());
		default:
			printf("PROCESSO PAI: PID FILHO %d, PID processo %d, PID pai %d\n",pid,getpid(),getppid());
	}
	return 0;
}