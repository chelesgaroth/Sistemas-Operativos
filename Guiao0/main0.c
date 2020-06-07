#include <stdio.h>
#include "guiao0.h"


int main(){

	int r;
	int* v = malloc (sizeof (int)*500); // int v[500];
	fill(v,20,10);

	r=find(v,20,10);
	printf("O resultado é:%d\n",r);
	v[0] = 3;
	r=find(v,20,10);
	printf("O resultado é:%d\n",r);
}