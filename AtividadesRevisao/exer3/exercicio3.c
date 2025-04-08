

void ordenar(int vetor[], int n) {  
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


