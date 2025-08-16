#include <stdio.h>
#include <stdlib.h>

/// QUESTÃO 1 - DEFINIÇÃO DE ESTRUTURAS E TIPOS

typedef struct jogador{
	char nome[21];
	int numero;
}Jogador;

typedef struct elemento{
	Jogador jogador;
	struct elemento* anterior;
	struct elemento* proximo;
}Elemento;

typedef struct{
	Elemento* inicio;
	Elemento* fim;
	int tamanho;
}Lista;

/// FIM DA QUESTÃO 1

Lista* criar_lista() {
   Lista* lista = (Lista*) malloc(sizeof(Lista));
   if (lista != NULL) {
      lista->inicio = NULL;
      lista->fim = NULL;
   }
   return lista;
}

/// QUESTÃO 2 - IMPLEMENTAÇÃO DA FUNÇÃO ESCALAR
void escalar(Lista* lista, Jogador jogador){
	if(lista==NULL){
		printf("Erro: lista inexistente.\n");
		return;
	}
	
	Elemento* novo = (Elemento*) malloc(sizeof(Elemento));
	
	if(novo==NULL){
		printf("Erro ao escalar o jogador.\n");
		return;
	}
	
	novo->jogador = jogador;
	novo->proximo = NULL;
	novo->anterior = NULL;
	
	if(lista->inicio==NULL){
		lista->inicio = novo;
		lista->fim = novo;
	}else{
		novo->anterior = lista->fim;
		novo->anterior->proximo=novo;
		lista->fim = novo;
	}
	
	lista->tamanho++;
	printf("%d - %s escalado para partida.\n",jogador.numero,jogador.nome);
}
/// FIM DA QUESTÃO 2


/// QUESTÃO 3 - IMPLEMENTAÇÃO DA FUNÇÃO SUBSTITUIR

void substituir(Lista* lista,int numero, Jogador jogador){
	if(lista==NULL){
		printf("Erro: lista inexistente.\n");
		return;
	}
	if(lista->inicio == NULL){
		printf("N�o h� jogadores escalados.\n");
		return;
	}
	
	Elemento* atual = lista->inicio;
	
	while(atual != NULL){
		if(atual->jogador.numero == numero){
			printf("%d - %s subistitu�do por %d - %s. \n",atual->jogador.numero, atual->jogador.nome,jogador.numero,jogador.nome);
			atual->jogador = jogador;
			return;
		}
		atual = atual->proximo;
	}
	if(atual==NULL){
		printf("Jogador n�o encontrado.\n");
		return;
	}
}

/// FIM DA QUESTÃO 3



void listar(Lista* lista) {
   if (lista == NULL || lista->inicio == NULL) {
      printf("Lista vazia ou inexistente.\n");
      return;
   }

   Elemento* atual = lista->inicio;
   printf("Jogadores escalados:\n");
   while (atual != NULL) {
      printf("%d - %s\n", atual->jogador.numero, atual->jogador.nome);
      atual = atual->proximo;
   }
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

   Jogador elesbao = {"Elesbao", 11};
   Jogador genoveva = {"Genoveva", 1};
   Jogador raoni = {"Raoni", 7};
   Jogador estela = {"Estela", 5};
   Jogador marvin = {"Marvin", 9};

   substituir(lista, 2, marvin);    
   escalar(lista, elesbao);
   escalar(lista, genoveva);
   escalar(lista, raoni);
   escalar(lista, estela);

   substituir(lista, 2, marvin);
   substituir(lista, 7, marvin);

   listar(lista);

   liberar_lista(lista);
   return 0;
}
