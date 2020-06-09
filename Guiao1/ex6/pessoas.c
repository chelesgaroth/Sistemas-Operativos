#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

typedef struct Person{
	char name[200];
	int age;
} Person;

#define FICHEIRO teste;

int new_person(const char *nome,const int idade){
	puts ("insert mode");

	int fd = open ("registo", O_WRONLY | O_CREAT | O_APPEND , 0644);
	if(fd == -1) {
        puts("ERROR - Couldn't open or create registry file.");
        return 1;
    }
    Person person;
    strcpy(person.name,nome);
    person.age = idade;

    write(fd, &person, sizeof(struct Person));
    int rej = lseek(fd,sizeof(struct Person),SEEK_CUR);//seek_cur posição atual
	close(fd);
	/*struct Person;
	Person Nova;

	strcpy(Nova.name,name);
	Nova.age = age;
	write (fd , &Nova , sizeof(Person));
	close(fd);*/
	rej=(rej/sizeof (Person));
	printf("registo nº %d \n",rej);
	return rej;
}

int new_age(int idade, int rej){
	puts("change age method 2");

	Person person;
	int fd = open ("registo", O_RDWR , 0644);
	int i=0;
	lseek(fd,(sizeof(struct Person))*rej,SEEK_SET); //multiplicamos pelo numero de registo para irmos para esse rej
	person.age = idade;

}

//orphan black , profissao de risco

int person_change_age(const char *name, const int age){
	puts ("user change mode");

	Person p;
	int bytes_read;
	int fd = open ("registo", O_RDWR , 0644);
	if(fd == -1) {
        perror("ERROR - open file");
        return 1;
    }
    while((bytes_read=(read(fd, &p, sizeof(struct Person)))>0)){
    	if (strcmp(p.name,name)==0){
    		p.age= age;
    		break;
    	}
    }
    write(fd, &p, sizeof(struct Person));
    close(fd);
    return 0;
}


int main(int argc, char const *argv[]){
	if(argc != 4){
		perror ("Nº de argumentos inválidos.");
		return -1;
	} //verifica se o comando foi passado com os devidos argumentos 
	//pessoas -i "José" 55
	

	if (strcmp(argv[1] ,"-i")==0) new_person(argv[2],(atoi(argv[3])));
	if (strcmp(argv[1] ,"-u")==0) person_change_age(argv[2],(atoi(argv[3])));
	if (strcmp(argv[1] ,"-y")==0) new_age((atoi (argv[2])),(atoi (argv[3])));
	return 0;
}