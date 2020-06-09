#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int main(int argc, const char * argv[]){

	/*Redirecionar o input, o output e o error para os seguintes ficheiros*/
	int input = open("/etc/passwd", O_RDONLY);
	int output = open("saida.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	int error = open("erros.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

	if( input < 0 || output < 0 || error < 0 ){
        perror("Can´t open files!");
        return -1;
    }

    dup2(input,0); // 0 = STDIN_FILENO
    dup2(output,1); // 1 = STDOUT_FILENO
    dup2(error,2); // 2 = STDERR_FILENO

    close(input);
    close(output);
    close(error);

    /*  ler uma linha a partir do seu standard input e repeti-la nos
     descritores de output e error usando directamente read() e write() */
    char buffer[10];
	int bytes = 0;
	while((bytes = read(0, &buffer, 10)) > 0){
		write(1, &buffer, bytes);
		write(2, &buffer, bytes);
	}

	/* o que acontece quando usamos funçoes como o printf? */
	printf("Hello World\n");
	/* resposta : Fica escrito no ficheiro de saída.txt */
	return 0;
}