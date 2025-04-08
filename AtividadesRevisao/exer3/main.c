#include <stdio.h>
#include <stdlib.h>
#include "exercicio3.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {

int vetor[5]={5,2,6,7,1};
int i;

for(i=0; i<5; i++){
	printf("%i",vetor[i]);
	printf("\n");
}	

ordenar(vetor, 5);
	
printf("VETOR ORDENADO\n");

for(i=0; i<5; i++){
	printf("%i",vetor[i]);
	printf("\n");
}	
	return 0;
}
