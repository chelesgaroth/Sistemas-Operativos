/*
Escreva um programa "redir2 que permita executar um comando, opcionalmente 
redireccionando a entrada e/ou a saída. O programa podera ser invocado,
com:

redir [-i fich_entrada] [-o fich_saida] comando arg1 arg2 ...

*/
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>


int main(int argc, char const *argv[]){
	if(argc < 6){
		perror("Not enough arguments!!");
		exit(1);
	}
	int input_fd;
    int output_fd;

    /*Verificando se os argumentos estão certos*/
    if(strcmp(argv[1], "-i") == 0) {
        input_fd = open(argv[2], O_RDONLY);
    } else exit(1);

    if(strcmp(argv[3], "-o") == 0) {
        output_fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    } else exit(1);

    /*Redirecionar para os ficheiros*/
    dup2(input_fd, 0);
    dup2(output_fd, 1);

    close(input_fd);
    close(output_fd);

    /*Execução do comando - processo filho*/
    argv[argc] = NULL;

    if(fork() == 0) {
        execlp(argv[5],argv[5],NULL);
        _exit(1);
    } else wait(NULL);

    return 0;
}