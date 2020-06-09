#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>


#include <stdio.h>

int main (int argc , char* argv[]){
	int i;
	for(i=1; i < argc; i++){
		pid_t pid = fork();
		if(pid==0){
			execlp(argv[i],argv[i],NULL); //não têm argumentos próprios
			printf("hello\n");
			_exit(i);
		}
		int status;
		wait(&status);
        printf("%d\n", WEXITSTATUS(status));
	wait(NULL);
	}
	return 0;
}
