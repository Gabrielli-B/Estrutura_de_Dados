#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/// QUESTÃO 1 - DEFINIÇÃO DE ESTRUTURAS E TIPOS
/// Crie as estruturas e tipos para Paciente, Elemento e Lista

typedef struct paciente{
	char nome[20];
	int prioridade;
}Paciente;

typedef struct elemento{
	Paciente paciente;
	struct elemento* proximo;
}Elemento;

typedef struct{
	Elemento* inicio;
}Lista;

/// FIM DA QUESTÃO 1

Lista* criar_lista() {
   Lista* lista = (Lista*) malloc(sizeof(Lista));
   if (lista != NULL) {
      lista->inicio = NULL;
   }
   return lista;
}

/// QUESTÃO 2 - IMPLEMENTAÇÃO DA FUNÇÃO REGISTRAR
/// Crie uma função que recebe um paciente e o insere na lista de espera
/// respeitando a ordem decrescente de prioridade e a ordem de chegada.
/// Retorne 1 se a inserção for bem sucedida ou 0 caso contrário.
int registrar(Paciente paciente, Lista* lista) {
	Elemento* novo = (Elemento*) malloc(sizeof(Elemento));;
	//Elemento* anterior=NULL;
	//novo->paciente.prioridade=paciente.prioridade;
    //strcpy(novo->paciente->nome,paciente.nome);
    //COPIA TUDO DE UMA VEZ 
	novo->paciente = paciente;
    
    if(lista->inicio==NULL || paciente.prioridade > lista->inicio->paciente.prioridade){
    	novo->proximo=lista->inicio;
    	lista->inicio=novo;
    	return 1;
	}
	
	Elemento* atual = lista->inicio;
	while (atual->proximo != NULL && paciente.prioridade <= atual->proximo->paciente.prioridade) {
    	atual = atual->proximo;
	}
    novo->proximo=atual->proximo;
    atual->proximo=novo;
    return 1;
}
/// FIM DA QUESTÃO 2


/// QUESTÃO 3 - IMPLEMENTAÇÃO DA FUNÇÃO ATENDER
/// Crie uma função que remove o primeiro paciente da lista de espera.
/// Retorne 1 se a remoção for bem sucedida ou 0 caso contrário.
int atender(Lista *lista) {
	if(lista==NULL || lista->inicio==NULL){
		return 0;
	}
	
	Elemento* temp = lista->inicio;
	lista->inicio=temp->proximo;
	free(temp);
	return 1;

}
/// FIM DA QUESTÃO 3

void listar(Lista* lista) {
   if (lista == NULL || lista->inicio == NULL) {
       printf("Lista de espera vazia.\n");
       return;
   }

   Elemento* atual = lista->inicio;
   printf("Lista de Espera: ");
   while (atual != NULL) {
       printf("\n%d - %s", atual->paciente.prioridade, atual->paciente.nome);
       atual = atual->proximo;
   }
   printf("\n\n");
}

void liberar_lista(Lista* lista) {
   if (lista == NULL) return;

   Elemento* atual = lista->inicio;
   while (atual != NULL) {
       Elemento* temp = atual;
       atual = atual->proximo;
       free(temp);
   }

   free(lista);
}

int main() {
   Lista* lista = criar_lista();
   if (lista == NULL) {
      printf("Erro ao criar a lista...");
      return 1;
   }

   Paciente elesbao = {"Elesbao", 3};
   Paciente genoveva = {"Genoveva", 4};
   Paciente raoni = {"Raoni", 3};
   Paciente estela = {"Estela", 2};
   Paciente marvin = {"Marvin", 5};
   Paciente mucio = {"Mucio", 1};
   Paciente lenora = {"Lenora", 3};

   registrar(elesbao, lista);
   registrar(genoveva, lista);
   registrar(raoni, lista);
   registrar(estela, lista);
   registrar(marvin, lista);
   
   listar(lista);
   
   atender(lista);
   atender(lista);
   atender(lista);
   registrar(mucio, lista);
   registrar(lenora, lista);

   listar(lista);

   liberar_lista(lista);
   return 0;
}
