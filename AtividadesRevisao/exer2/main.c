#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	int array[10] = {1,2,3,4,5,6,7,8,9,10};
	
	printf("ANTES DE EMBARALHAR:\n");
	imprimirVet(array,10);
	
	printf("\n\n\n\n");
	
	embaralhar(array, 10);
	printf("DEPOIS DE EMBARALHAR:\n");
	imprimirVet(array,10);	
	
	
	return 0;
}
