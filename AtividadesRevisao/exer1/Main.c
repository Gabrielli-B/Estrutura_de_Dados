#include<stdio.h>

int main(){
	
	printf("Exercicio 1:\n--------------- \n");
	
	int vet[5] = {1,2,3,4,5};
	
	imprimir(vet,5,-3);
	imprimir(vet,5,3);
	imprimir(vet,5,0);
	
	return 0;
}
