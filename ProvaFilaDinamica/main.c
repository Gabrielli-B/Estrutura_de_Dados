#include <stdlib.h>
#include <stdio.h>

//
// QUESTÃO 1 - Estruturas e tipos
//

typedef struct documento{
	char nome[31];
	int paginas;
}Documento;

typedef struct elemento{
	Documento documento;
	struct elemento* proximo;
}Elemento;

typedef struct{
	Elemento* inicio;
	Elemento* fim;
	int tamanho;
}Fila;

// FIM DA QUESTÃO 1

Fila* criar_fila() {
    Fila* fila = malloc(sizeof(Fila)); 
    if (fila == NULL) {
        printf("Erro ao alocar a fila.\n");
        return NULL;
    }
    fila->inicio = NULL;
    fila->fim = NULL;
    fila->tamanho = 0;
    return fila; 
}

int fila_vazia(Fila* fila) {
    if (fila == NULL) {
        printf("Fila inexistente\n");
        return 1;
    }
    return (fila->inicio == NULL);
}

//
// QUESTÃO 2 - Função enviar()
//

int enviar(Fila* fila, Documento documento){
	if(fila==NULL){
		return 0;
	}
	
	Elemento* novo = malloc(sizeof(Elemento));
	
	if(novo==NULL){
		return 0;
	} 
	
	novo->documento = documento;
	novo->proximo = NULL;
	
	if(fila->inicio==NULL){
		fila->inicio = novo;
		fila->fim = novo;
		fila->tamanho++;
	}else{
		fila->fim->proximo=novo;
		fila->fim=novo;
	}	
	
	fila->tamanho++;
	
	printf("Documento %s com %d paginas enviado para impressao \n",documento.nome,documento.paginas);
	
	return 1; 
}

// FIM DA QUESTÃO 2



//
// QUESTÃO 3 - Função imprimir()
//

int imprimir(Fila* fila){
	if(fila==NULL){
		return 0;
	}
	
	if(fila_vazia(fila)){
		return 0;
	}
	
	Elemento* temp = fila->inicio;
	printf("Imprimindo %d paginas de %s .... \n",temp->documento.paginas,temp->documento.nome);
	fila->inicio = temp->proximo;
	free(temp);
	fila->tamanho--;
	
	if(fila->inicio == NULL){  // fila ficou vazia
        fila->fim = NULL;
	}
	return 1; 
}


// FIM DA QUESTÃO 3



//
// QUESTÃO 4 - Função proximo()
//

void proximo(Fila* fila){
	if(fila==NULL){
		printf("Fila inexistente!\n");
		return;
	}
	
	if(fila_vazia(fila)){
		printf("Nao ha documento na fila de impressao!\n");
		return;
	}
	
	printf("Proxima impressao: %s com %d paginas\n",fila->inicio->documento.nome,fila->inicio->documento.paginas);
}

// FIM DA QUESTÃO 4

void liberar_fila(Fila* fila) {
    if (fila == NULL) {
        return;
    }
    while (!fila_vazia(fila)) {
        imprimir(fila);
    }
    free(fila);
}

int main() {
    Fila* fila = criar_fila();
    Documento doc1 = {"prova1a.pdf", 4};
    Documento doc2 = {"prova2a.pdf", 3};
    Documento doc3 = {"notas.xls", 2};
    Documento doc4 = {"gabarito.c", 5};
    Documento doc5 = {"reavaliacao.docx", 35};
    enviar(fila, doc1);
    enviar(fila, doc2);
    enviar(fila, doc3);
    imprimir(fila);
    proximo(fila);
    enviar(fila, doc4);
    enviar(fila, doc5);
    imprimir(fila);
    imprimir(fila);
    imprimir(fila);
    imprimir(fila);
    proximo(fila);
    liberar_fila(fila);
    return 0;
}
