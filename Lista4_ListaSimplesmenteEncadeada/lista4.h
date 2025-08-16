 /*1. Crie os tipos de dados adequados: trata-se de uma lista simplesmente encadeada. Cada elemento 
da lista é um registro composto pelos seguintes campos: matrícula (inteiro), nome (vetor de char 
com 20 posições) e media (float);*/
 
 typedef struct elemento{
 	int matricula;
 	char nome[20];
 	float media;
 	struct elemento* proximo;
 }Elemento;
 
 typedef struct{
 	Elemento* inicio;
 }Lista;
 
  Lista* criar_lista();
  Lista* criar_lista();
  int procurar(Lista* lista, int matricula);
  inserir(Lista* lista, Elemento aluno);
  void imprimir(Lista* lista);
  void remover(Lista* lista, int matricula);
  void liberar_lista(Lista* lista);
