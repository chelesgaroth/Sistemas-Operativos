#include <stdio.h>
#include <unistd.h>     /*chamadas ao sistema: defs e decls essenciais*/
#include <sys/wait.h>   /*chamadas wait*() e macros relacionadas*/

int main(int argc, char const *argv[]){
	pid_t pid = fork();
	if(pid==0){
		pid_t filho = getpid();
		pid_t pai = getppid();
		printf("Depois de criar um processo filho.\nPID do filho: %d  PID do pai: %d\n", filho, pai);
		_exit(0);
	}
	else{
		pid_t ppid = getpid();
		pid_t avo = getppid();
		pid_t filhopid = pid;
		printf("Criando outra vez um filho.\nPID do processo:%d PID do avo:%d PID do filho:%d\n",ppid,avo,filhopid);
		wait(NULL);
	}

}

/*  gcc -c main.c -o main.o
	gcc main.o -o main
*/
