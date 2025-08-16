#define MAX 50

typedef struct Aluno{
	int matricula;
	char nome[20];
	float media;
} Aluno;

typedef struct{
	Aluno itens[MAX];
	int tamanho;
}Lista;

Lista* criar_lista();
int lista_cheia(Lista* lista);
int procurar(Lista* lista, int matricula);
int inserir(Aluno aluno, Lista* lista);
void imprimir(Lista* lista);



