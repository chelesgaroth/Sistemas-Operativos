#include <unistd.h>

/*programa  que  execute  o  comando ls -l.*/

int main(void){
	execlp("ls", "-l", NULL); 
    return 0;
}

//	A funçao EXECLP recorre aos caminhos registados na variável de ambiente 
//PATH. Daí não termos de identificar o caminho de ls, caso a função usada 
//fosse execl então usaríamos como 1º argumento /bin/ls.