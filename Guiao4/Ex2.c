/* programa igual ao anterior , depois de realizar os redireccionamentos,  
seja criado um novo processo que realize operações de leitura e escrita
*/

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char * const argv[]){

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
    /* fim dos redirecionamentos */

    char buffer[1024];
    int bytes = 0;
    pid_t pid = fork();
    if(pid==0){
    	/*processo filho*/
    	while((bytes = read(0, &buffer, 10)) > 0){
		write(1, &buffer, bytes);
		write(2, &buffer, bytes);
		}
        printf("Hello, World!\n"); //Não aparece no ficheiro da saída
    	execvp("cat",argv); //Também não ? Aparece no ficheiro de erros.txt
    	_exit(0);
    }
    else{
    	/*processo pai*/
	printf("olá");
    	wait(NULL);
    }
    return 0;
}
