#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/*	Um programa que imprima a lista de argumentos recebidos na sua linha de 
comando. 
* De modo a evitar o uso de printf's. */

int main (int argc, const char* argv[]){
	for(size_t i = 0; i < argc; i++) {
		puts(argv[i]);
		printf("hello\n");
		//puts("hello"); ->para testar o ex5
	}
	return 0;
}