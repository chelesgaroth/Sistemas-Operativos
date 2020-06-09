#include <unistd.h>
#include <stdio.h> //Fake
#include <string.h>
#include <sys/wait.h>

int Fake(int argc , const char* argv[]){
	char buffer[1024];
	char* args[1024];
	/* vamos copiar aquilo que é dado no input para args*/
	args[0] = "./Ex3";
	size_t i = 1;
	while(fgets(buffer, 1024, stdin)) {
		strtok(buffer, "\n\r");
		args[i++] = strdup(buffer);
	}
	args[i] = NULL;
	execvp("./Ex3",args);
	return 0;
}

/* Deste modo não vamos conseguir resolver. Porque temos dois programas
em execução por isso temos de aplicar o que aprendemos sobre gestão de 
processos. E usar a funçao fork(). */

int main (int argc , char* argv[]){

	pid_t pid = fork();
	if(pid==0){
		/* processo filho*/
		argv[0]= "já não é ./run";
		execvp("./Ex3",argv);
		_exit(0);
	}
	else{
		/* processo pai*/
		wait(NULL);
	}
	return 0;
}
