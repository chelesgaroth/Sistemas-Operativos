#include <stdio.h>
#include <unistd.h>     /*chamadas ao sistema: defs e decls essenciais*/
#include <sys/wait.h>   /*chamadas wait*() e macros relacionadas*/

int main(int argc, char const *argv[]){
	int status;
    for(int i = 1; i <= 10; i++){
    	printf("Filho %d: %d  Pai: %d\n",i,getpid(),getppid());
    	if(fork()){
    		int terminated_pid = wait(&status);
    		printf("Process %d exited, exit code %d.\n", terminated_pid, WEXITSTATUS(status));
            _exit(i);
    	}
    }
}