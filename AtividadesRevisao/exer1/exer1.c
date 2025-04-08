#include "exer1.h"

void imprimir(int vet[], int qtdElementos, int valor){
	int i;
	if(valor>0){
		for(i=0; i<qtdElementos; i++){
			printf("%d",vet[i]);
		}
	}else if(valor<0){
		for(i=qtdElementos-1; i>=0; i--){
			printf("%d",vet[i]);
		}
	}else{
		printf("Nenhuma opção encontrata! Valor nao pode ser 0");
	}
	printf("\n");
}
