#include <stdlib.h>
#include <stdio.h>

//
// QUESTÃO 1 - Estruturas e tipos
//

typedef struct metodo{
	char nome[21];
	int bytes;
}Metodo;

typedef struct elemento{
	Metodo metodo;
	struct elemento* proximo;
}Elemento;

typedef struct{
	Elemento* topo;
	int tamanho;
}Pilha;

// FIM DA QUESTÃO 1

Pilha* criar_pilha() {
    Pilha* pilha = malloc(sizeof(Pilha)); 
    if (pilha == NULL) {
        printf("Erro ao alocar a pilha.\n");
        return NULL;
    }
    pilha->topo = NULL;
    pilha->tamanho = 0;
    return pilha;
}

int pilha_vazia(Pilha* pilha) {
    if (pilha == NULL) {
        printf("Pilha inexistente!\n");
        return 1;
    }
    return (pilha->topo == NULL);
}

//
// QUESTÃO 2 - FUNÇÃO invocar()
//

int invocar(Pilha* pilha, Metodo metodo){
	if(pilha==NULL){
		return 0;
	}
	
	Elemento* novo = malloc(sizeof(Elemento));
	
	if(novo==NULL){
		return 0;
	}
	
	novo->metodo = metodo;
	
	novo->proximo=pilha->topo;
	pilha->topo=novo;
	pilha->tamanho++;
	
	 printf("%d bytes alocados para o m�todo %s\n", metodo.bytes, metodo.nome);
	return 1;	
}

// FIM DA QUESTÃO 2



//
// QUESTÃO 3 - FUNÇÃO retornar()
//

int retornar(Pilha* pilha){
	if(pilha==NULL){
		return 0;
	}
	
	if(pilha_vazia(pilha)){
		return 0;
	}
	
	Elemento* removido = pilha->topo;
	
	printf("Encerrando a execu��o do m�todo %s\n", removido->metodo.nome);	
	pilha->topo = removido->proximo; 
	pilha->tamanho--;
	free(removido);
	
	return 1;
}

// FIM DA QUESTÃO 3



//
// QUESTÃO 4 - FUNÇÃO imprimir()
//

void imprimir(Pilha* pilha){
	if(pilha==NULL){
		printf("Pilha inexistente!\n");
		return ;
	}
	if(pilha_vazia(pilha)){
		printf("Pilha vazia!\n");
		return ;
	}
	
	Elemento* atual = pilha->topo;
	
	printf("Pilha de execucao:\n");
	
	while(atual!=NULL){
		printf("%s \n",atual->metodo.nome);
		atual= atual->proximo;
	}
	return ;
}

// FIM DA QUESTÃO 4

void liberar_pilha(Pilha* pilha) {
    if (pilha == NULL) {
        printf("Pilha inexistente!\n");
        return;
    }
    while (!pilha_vazia(pilha)) {
        retornar(pilha); 
    }
    free(pilha);
}

int main() {
    Pilha* pilha = criar_pilha();
    Metodo get = {"getUsers()", 724};
    Metodo fetch = {"fetch()", 498};
    Metodo decode = {"decode()", 317};
    Metodo process = {"process()", 890};
    Metodo show = {"show()", 442};
    Metodo table = {"table()", 163};
    invocar(pilha, get);
    invocar(pilha, fetch);
    invocar(pilha, decode);
    retornar(pilha);
    invocar(pilha, process);
    retornar(pilha);
    retornar(pilha);
    invocar(pilha, show);
    invocar(pilha, table);
    imprimir(pilha);
    retornar(pilha);
    liberar_pilha(pilha);
    return 0;
}
