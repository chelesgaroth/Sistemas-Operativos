#include <stdio.h>
#include <unistd.h>     /*chamadas ao sistema: defs e decls essenciais*/
#include <sys/wait.h>   /*chamadas wait*() e macros relacionadas*/

/*Implemente um programa que crie dez processos filhos que deverao executar sequencialmente*/

/*
int main(int argc, char const *argv[]){
	pid_t pid;
	if((pid=fork())==0){
		printf("Filho 1: %d\n",getpid());
		if((pid=fork())==0){
			printf("Filho 2: %d\n",getpid());
			wait(NULL);
			if((pid=fork())==0){
				printf("Filho 3: %d\n",getpid());
				wait(NULL);
				if((pid=fork())==0){
					printf("Filho 4: %d\n",getpid());
					
					wait(NULL);
					if((pid=fork())==0){
						printf("Filho 5: %d\n",getpid());
						wait(NULL);
					}
				}
			}
		}
	}
}*/
int main(int argc, char const *argv[]){
	for(int i = 1; i < 11; i++){
		if(fork()==0){
			printf("Filho %d: %d\n",i,getpid());
			 _exit(i);
		}
		else {
			printf("Pai %d\n", getppid());
		}
		int exit_status;
        wait(&exit_status);
        printf("Exit: %d\n",WEXITSTATUS(exit_status));
	}
	return 0;
}
