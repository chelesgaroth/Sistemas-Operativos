/*dez processos filhos que dever ̃ao executar em concorrência
  O pai devera esperar pelo fim da execuc ̧ ̃ao de todos os seus filhos, imprimindo os respectivos c ́odigos de sa ́ıda.
  */

#include <stdio.h>
#include <unistd.h>     /*chamadas ao sistema: defs e decls essenciais*/
#include <sys/wait.h>   /*chamadas wait*() e macros relacionadas*/

int main(int argc, char const *argv[]) {
    for(int i = 1; i < 11; i++) {
        if(fork()==0){
            _exit(i);
        }
	else printf("Pai %d\n",getppid());
    }
    int exit_status;
    while(wait(&exit_status) != -1) {
        printf("Filho %d\n", WEXITSTATUS(exit_status));
    }
    return 0;
}
