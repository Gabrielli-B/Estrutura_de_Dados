
/*a) Uma lista estática de produtos, com no máximo 80 itens, 
onde cada produto possui código (até 13 caracteres), 
nome (até 20 caracteres), preço e estoque (valor inteiro);*/
#define MAX 80
typedef struct produtos{
	char codigo[14];
	char nome[21];
	int preco;
	int estoque;	
}Produtos;

typedef struct{
	Produtos itens[MAX];
	int tamanho;
}Lista;

/*b) Uma lista encadeada com o itens que devem ser comprados. Cada item 
possui nome (até 20 caracteres) e quantidade (valor inteiro);*/

typedef struct compra{
	char nome[21];
	int quantidade;	
}Compra;

typedef struct elemento{
	Compra compra;
	struct elemento* proximo;
}Elemento;

typedef struct{
	Elemento* inicio;
}Lista;

/*c) Uma lista duplamente encadeada de clientes, onde cada cliente 
possui nome (até 30 caracteres) e idade (valor inteiro);*/

typedef struct cliente{
	char nome[31];
	int idade;
}Cliente;

typedef struct elemento{
	Cliente cliente;
	struct elemento* proximo;
	struct elemento* anterior;
}Elemento;

typedef struct{
	Elemento* inicio;
	Elemento* fim;
}Lista;

/*d) Um fila estática de tarefas, com no máximo 20 tarefas, 
onde cada tarefa possui um título (até 30 caracteres) e uma duração (valor decimal);*/

#define MAX 20
typedef struct tarefa{
	char titulo[31];
	float duracao;
}Tarefa;

typedef struct fila{
	int inicio;
	int fim;
	int tamanho;
	Tarefa tarefas [MAX];
}Fila;

/*e) Um fila dinâmica de mensagens, onde cada mensagem possui remetente 
(até 20 caracteres), destinatário (até 20 caracteres) e conteúdo (até 100 caracteres);*/

typedef struct mensagem{
	char remetente[21];
	char destinatario[21];
	char conteudo[101];	
}Mensagem;

typedef struct elemento{
	Mensagem mensagem;
	struct elemento* proximo;
}Elemento;

typedef struct{
	Elemento* inicio;
	Elemento* fim;
	int tamanho;
}Fila;

/*f) Uma pilha estática de livros, com no máximo 50 livros, onde cada livro 
possui isbn (até 17 caracteres) e número de páginas (valor inteiro);*/
#define MAX 50

typedef struct livro{
	char isbn[18];
	int numPag;
}Livro;

typedef struct{
	Livro livros[MAX];
	int tamanho;
}Pilha;

/*g) Um pilha dinâmica de processos, em que cada processo 
possuim pid (valor inteiro) e prioridade (valor inteiro).*/

typedef struct processo{
	int pid;
	int prioridade;
}Processo;

typedef struct elemento{
	Processo processo;
	struct elemento* proximo;
}Elemento;

typedef struct{
	Elemento* topo;
	int tamanho;
}Pilha;
