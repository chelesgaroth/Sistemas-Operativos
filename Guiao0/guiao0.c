#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "guiao0.h"

void fill (int* vector, int size, int value){
	for(int i =0; i< size; i++) vector[i]= value;
}


int find (int* vector, int size, int value){
	for (int i=0; i<size; i++)
		if (vector[i]==value) return (i);
    return -1;
}
