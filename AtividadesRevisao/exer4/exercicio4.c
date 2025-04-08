
void imprimir(float vet[], int qtdElementos){
	int i;
	for(i=0; i<qtdElementos; i++){
		printf("%.2f",vet[i]);
		printf("\n");
	}
	printf("\n");
}

void preencherVetor(float vet[], int qtdElementos){
	int i;
	for(i=0; i<qtdElementos; i++){
		float aux;
		printf("Informe o valor %i:\n",i+1);
		scanf("%f",&aux);
		while(aux>10.0 || aux<0.0){
			printf("VALOR INVALIDO!Nota tem que estar entre 0 e 10\n");
			printf("Informe o valor %i:\n",i+1);
			scanf("%f",&aux);
			
		}
		vet[i]=aux;	
	}
}

void ordenar(float vetor[], int n) {  
	int i;
	int j;
	for (i=0; i<n-1; i++) {
		int swapped = 0;
		for (j=0; j<n-i-1; j++) {
			if (vetor[j] > vetor[j + 1]) {
				float temp = vetor[j];
				vetor[j] = vetor[j + 1];
				vetor[j + 1] = temp;
				swapped = 1;
			}
		}
		if (swapped == 0) break;
	}
}

