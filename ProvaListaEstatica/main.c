#include <stdlib.h>
#include <stdio.h>

# define MAX 20

// QUESTÃO 1 - DEFINIÇÃO DE ESTRUTURAS E TIPOS
typedef struct Atleta{
	char nome[20];
	float pontuacao;
}Atleta; 

typedef struct{
	Atleta itens[MAX];
	int tamanho;
}Lista;

// FIM DA QUESTÃO 1

Lista* criar_lista() {
	Lista *lista;
	lista = malloc(sizeof(Lista));
	if (lista != NULL) lista->tamanho = 0;
	return lista;
}

Lista* liberar_lista(Lista* lista) {
	free(lista);
	lista = NULL;	
	return lista;
}

int lista_cheia(Lista* lista) {
	if (lista == NULL) return -1;
	return (lista->tamanho == MAX);
}

int lista_vazia(Lista* lista) {
	if (lista == NULL) return -1;
	return (lista->tamanho == 0);
}


// QUESTÃO 2 - FUNÇÃO CLASSIFICAR
void classificar(Atleta novo, Lista* lista) {
    if (lista == NULL) return 0;             // Lista inv�lida
    if (lista->tamanho == MAX) return 0;      // Lista cheia

    int i = 0;
	int j=0;
    // Encontra a posi��o correta para inserir o novo atleta
    // Mesmo se a lista estiver vazia, esse la�o ser� ignorado (tamanho = 0)
    while (i < lista->tamanho && lista->itens[i].pontuacao < novo.pontuacao) {
        i++;
    }

    // Desloca os atletas da posi��o i em diante para a direita
    for (j = lista->tamanho; j > i; j--) {
        lista->itens[j] = lista->itens[j - 1];
    }

    // Insere o novo atleta na posi��o correta
    lista->itens[i] = novo;

    // Aumenta o tamanho da lista
    lista->tamanho++;

}

// FIM DA QUESTÃO 2



// QUESTÃO 3 - FUNÇÃO LISTAR
void listar(Lista* lista){
	if(lista_vazia(lista)){
		printf("LISTA ESTA VAZIA, IMPOSSIVEL LISTAR");
		return;
	}
	int i;
	printf("Lista:\n");
	for(i=0; i<lista->tamanho; i++){
		printf("Nome: %s | Pontuacao: %f\n",lista->itens[i].nome,lista->itens[i].pontuacao);
	}
}

// FIM DA QUESTÃO 3



// QUESTÃO 4 - FUNÇÃO ELIMINAR
void eliminar(Lista* lista){
	if(lista_vazia(lista)){
		printf("LISTA ESTA VAZIA, IMPOSSIVEL ELIMINAR\n");
		return;
	}
	int i;
	for(i=0; i<lista->tamanho-1; i++){
		lista->itens[i]=lista->itens[i+1];
	}
	lista->tamanho--;
	printf("ATLETA REMOVIDO!\n");
}

// FIM DA QUESTÃO 4

int main() {
   Lista* lista = criar_lista();
   if (lista == NULL) {
      printf("Erro ao criar a lista...");
      return 1;
   }

   Atleta elesbao = {"Elesbao", 82};
   Atleta genoveva = {"Genoveva", 87};
   Atleta raoni = {"Raoni", 63};
   Atleta estela = {"Estela", 63};
   Atleta marvin = {"Marvin", 123};
   Atleta mucio = {"Mucio", 59};
   Atleta lenora = {"Lenora", 85};


   classificar(elesbao, lista);
   classificar(genoveva, lista);
   classificar(raoni, lista);
   classificar(estela, lista);
   classificar(marvin, lista);
   
   listar(lista);

   printf("Primeiro elemento (menor pontuação): %s\n", lista->itens[0].nome);
   printf("Último elemento (maior pontuação): %s\n\n", lista->itens[lista->tamanho - 1].nome);

   eliminar(lista);
   classificar(mucio, lista);
   classificar(lenora, lista);
   eliminar(lista);
   
   listar(lista);

   liberar_lista(lista);
   return 0;
}
