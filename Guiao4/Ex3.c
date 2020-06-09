#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

/* As associações – e redireccionamentos – de descritores de ficheiros
são preservados pela primitiva exec() */

int main(int argc, const char * argv[]){

	int input = open("/etc/passwd", O_RDONLY);
	int output = open("saida.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	int error = open("erros.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

	if( input < 0 || output < 0 || error < 0 ){
        perror("Can´t open files!");
        return -1;
    }

    dup2(input,0); 
    dup2(output,1); 
    dup2(error,2); 

    close(input);
    close(output);
    close(error);

    execlp("wc","wc",NULL);
    /* Agora aparecem nos ficheiros o resultado da execucao de comando wc.
    Além disso, não temos nada no erros.txt porque nao ha erros. Portanto 
    foram redirecionados os resultados.
    Agora não escrevemos nos ficheiros os standard input, output e error.*/

    return 0;
}