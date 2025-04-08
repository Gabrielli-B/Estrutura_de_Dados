#include <stdio.h>
#include <stdlib.h>
#include "exercicio4.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	int num;
	int i;
	printf("Informe a quantidade de alunos:\n");
	scanf("%i",&num);
	
	float notas[num];
	
	preencherVetor(notas,num);
	
	printf("NOTAS ORDEM ORIGINAL:\n");
	imprimir(notas, num);
	
	printf("ORDENANDO NOTAS:\n");
	ordenar(notas, num);
	imprimir(notas, num);
	
	return 0;
}
