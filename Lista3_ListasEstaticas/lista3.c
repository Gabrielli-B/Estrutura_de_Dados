#include<stdio.h>
#include "lista3.h"
#include<string.h>

Lista* criar_lista(){
	Lista* lista=(Lista*) malloc(sizeof(Lista));
	
	if(lista != NULL){
		lista -> tamanho = 0;
		printf("Sucesso... a lista foi criada!");
	}else{
		printf("Erro: a lista não foi criada!");
		
	}
	return lista;
}
int lista_cheia(Lista* lista){
	if(lista->tamanho == MAX){
		return 1;
	}else{
		return 0;
	}
}

int procurar(Lista* lista, int matricula){
	//if (lista == NULL) return -1;
	int i;
	for(i=0; i<lista->tamanho; i++){
		if(lista->itens[i].matricula == matricula){
			return i;
		}
	}
	return -1;
}

int inserir(Aluno aluno, Lista* lista){
	int i;
	if(lista->tamanho == MAX){
		printf("ERRO: a lista está cheia!");
		return -1;
	}
	for(i=0; i<lista->tamanho; i++){
		if(lista->itens[i].matricula==aluno.matricula){
			printf("ERRO: já existe um aluno com essa matrícula!");
			return -1;
		}
	}
	
	int pos = 0;
	int j;
	
    while (pos < lista->tamanho && strcmp(lista->itens[pos].nome, aluno.nome) < 0) {
        pos++;
    }
    
    for(j=lista->tamanho; j> pos; j--){
    	lista->itens[j] = lista->itens[j-1];
	}
	
	lista->itens[pos]=aluno;
	lista->tamanho++;
	
	printf("Sucesso... aluno inserido na posição %d!\n", pos);
    return pos;
}
void imprimir(Lista* lista){
	int i;
	printf("Lista de Alunos:\n");
	printf("------------------------------------------\n");
	for(i=0; i<lista->tamanho; i++){
		printf("%d - %s - %.2f \n",lista->itens[i].matricula,lista->itens[i].nome,lista->itens[i].media);	
	}
	printf("------------------------------------------\n");
}
int remover(Lista* lista, int matriculaAluno){
	int i,j;
	for(i=0; i<lista->tamanho; i++){
		if(lista->itens[i].matricula == matriculaAluno){
			for(j=0; j<lista->tamanho; j++){
				lista->itens[j]=lista->itens[j+1];
			}
			lista->tamanho--;
			printf(" Sucesso... aluno removido da posição  %d\n",i);
			return 0;
		}
	}
	printf("ERRO: matricula não encontrada!\n");
	return -1;
}
Lista* liberar_lista(Lista* lista){
	free(lista);
	lista=NULL;
	return lista;
}

