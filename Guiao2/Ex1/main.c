#include <stdio.h>
#include <unistd.h>     /*chamadas ao sistema: defs e decls essenciais*/
#include <sys/wait.h>   /*chamadas wait*() e macros relacionadas*/

/*programa que imprima o seu identificador de processo e o do seu pai*/

int main (int argc, char const *agrv[]){
	pid_t filho = getpid();
	pid_t pai = getppid();
	printf("O pid do processo é %d, e o pid do processo pai é %d.\n",(int)filho,(int)pai);
	return 0;
}

/*  gcc -c main.c -o main.o
	gcc main.o -o main
*/