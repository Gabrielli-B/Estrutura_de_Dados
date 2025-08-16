#include "lista4.h"
#include <stdlib.h>
#include <string.h>

/*2. Crie a função criar_lista. Se a lista for criada com sucesso, deve imprimir a seguinte mensagem: A 
lista foi criada com sucesso!. Caso contrário, Erro: a lista não foi criada!. A função sempre retorna um 
ponteiro para a lista. Na função main(), declare e crie uma lista chamada alunos.*/

 Lista* criar_lista(){
 	Lista* lista = (Lista*) malloc(sizeof(Lista));
 	if(lista != NULL){
 		lista->inicio = NULL;
 		 printf("A lista foi criada com sucesso!\n");
	 }else{
	 	printf("Erro: a lista não foi criada!\n");
	 }
 	return lista;
 }
 
 /*3. Crie uma função (int) chamada procurar que busca um aluno na lista através da sua matrícula. Se 
encontrar, deve retornar um ponteiro para o elemento. Caso contrário, deve retornar NULL.*/ 
int procurar(Lista* lista, int matricula){
	Elemento* atual = lista->inicio;
	
	while(atual != NULL){
		if(atual->matricula == matricula){
			return atual;
		}
	}
	atual=atual->proximo;
	
	printf("MATRICULA NAO FOI ENCONTRADA!\n");
	return NULL;
}

/*4. Crie uma função (int) chamada inserir, que recebe um aluno como parâmetro e o insere na posição 
adequada da lista de modo a mantê-la ordenada em ordem decrescente de média. Observação: se já 
existir um aluno com a mesma média, a inserção deve ser feita depois desse aluno.*/
int inserir(Lista* lista, Elemento aluno){
	Elemento* novo = (Elemento*) malloc(sizeof(Elemento));
	if(novo== NULL) return 0;
	
	novo->matricula = aluno.matricula;
    strcpy(novo->nome, aluno.nome);
    novo->media = aluno.media;
    novo->proximo = NULL;
    
       // Caso a lista esteja vazia ou o novo tem média maior que o primeiro
    if (lista->inicio == NULL || aluno.media > lista->inicio->media) {
        novo->proximo = lista->inicio;
        lista->inicio = novo;
        return 1;
    }

    // Percorre a lista até encontrar a posição correta
    Elemento* atual = lista->inicio;
    while (atual->proximo != NULL && aluno.media <= atual->proximo->media) {
        atual = atual->proximo;
    }

    // Insere o novo elemento após o "atual"
    novo->proximo = atual->proximo;
    atual->proximo = novo;
    return 1;
} 

/*6. Crie um procedimento chamado imprimir que imprime a lista no formato abaixo. Teste-o!*/
void imprimir(Lista* lista){
	if(lista!=NULL){
		Elemento* atual = lista->inicio;
		printf("Lista: \n");
		while(atual != NULL){
			printf("%d | %s | %.2f\n",atual->matricula,atual->nome,atual->media);
			atual=atual->proximo;
		}	
	}else{
		printf("NAO HA ELEMENTOS NA LISTA PARA LISTAR!");
	}
} 

/*7. Crie um procedimento chamado remover para a excluir um aluno da lista a partir de sua matrícula. 
Observações: 
• Se a matrícula for encontrada, deve imprimir a mensagem Aluno removido com sucesso!; 
• Se a matrícula não for encontrada, deve imprimir a mensagem Matrícula não encontrada!; 
Considere que nunca haverá matrículas duplicadas! Na função main(), remova os alunos com 
matrículas 1, 7 e 9.*/
void remover(Lista* lista, int matricula) {
    if (lista == NULL || lista->inicio == NULL) {
        printf("MATRICULA NAO ENCONTRADA!\n");
        return;
    }

    Elemento* atual = lista->inicio;
    Elemento* anterior = NULL;

    // Caso especial: aluno está no início da lista
    if (atual->matricula == matricula) {
        lista->inicio = atual->proximo;
        free(atual);
        printf("ALUNO REMOVIDO COM SUCESSO!\n");
        return;
    }

    // Percorre a lista procurando a matrícula
    while (atual != NULL && atual->matricula != matricula) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual == NULL) {
        printf("MATRICULA NAO ENCONTRADA!\n");
        return;
    }

    // Remove o elemento "atual"
    anterior->proximo = atual->proximo;
    free(atual);
    printf("ALUNO REMOVIDO COM SUCESSO!\n");
}

/*8. Crie uma função chamada liberar_lista para destruir a lista e liberar a memória. Chame a função ao 
final da função main().*/
void liberar_lista(Lista* lista){
	if(lista==NULL) return;
	
		Elemento* atual = lista->inicio;
    	Elemento* temp;  
    
	  while (atual != NULL) {
        temp = atual->proximo;  // guarda o próximo
        free(atual);            // libera o atual
        atual = temp;           // passa para o próximo
   	 }
   

    free(lista);  // libera a estrutura Lista em si (caso tenha sido criada com malloc)
	
} 
