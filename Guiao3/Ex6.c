/*
* Implemente uma versão simplificada da função system().
* O unico argumento devera ser uma string que especifica um programa 
executavel e uma eventual lista de argumentos.
* Procure que o comportamento e valor de retorno da sua funcao sejam 
compativeis com a original.
*/

#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>

#define N 1024

int my_system(char* command){
	char* args[N];
	char* token;
	char* rest = command;
	size_t i = 0;
	while(token = strtok_r(rest, " ", &rest)){
		args[i++] = strdup(token);
	}
	args[i] = NULL;
	if(fork() == 0) {
		execvp(args[0], args);
		_exit(0);
	}
}


int main(int argc, const char * argv[]) {
	char buffer[N];
	puts("Insert a command:");
	fgets(buffer, N, stdin);
	strtok(buffer, "\n\r");
	int res =my_system(buffer);
	return 0;
}

