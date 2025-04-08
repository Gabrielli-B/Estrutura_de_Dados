#include <stdlib.h>
#include <time.h>

void embaralhar(int vetor[], int n) {
	srand(time(NULL));
	int i;
	for (i=n-1; i>0; i--) {
		int j = rand() % (i + 1);
		int temp = vetor[i];
		vetor[i] = vetor[j];
		vetor[j] = temp;
	}
}

void imprimirVet(int vet[], int n){
	int i;
	for(i=0; i<n; i++){
		printf("Posicao: %d | valor: %d",i,vet[i]);
		printf("\n");
	}
}
