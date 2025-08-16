#include <stdio.h>
#include <stdlib.h>
#include "lista4.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	Lista* alunos= criar_lista();
	
	Elemento mucio = {1, "Múcio", 6.2}; 
    Elemento elesbao = {2, "Elesbao", 8.5}; 
    Elemento raoni = {3, "Raoni", 4.4}; 
    Elemento genoveva = {4, "Genoveva", 3.7}; 
    Elemento estela = {5, "Estela", 6.2}; 
    Elemento willy = {6, "Willy", 9.2}; 
    Elemento marvin = {7, "Marvin", 10};
	
	inserir(alunos,mucio);
	inserir(alunos,elesbao);
	inserir(alunos,raoni);
	inserir(alunos,genoveva);
	inserir(alunos,estela);
	inserir(alunos,willy);
	inserir(alunos,marvin); 
	
	imprimir(alunos);
	
	remover(alunos, 1);  // deve encontrar e remover
	remover(alunos, 7);  // deve encontrar e remover
	remover(alunos, 9);  // não existe ? deve exibir "MATRICULA NAO ENCONTRADA!"
	imprimir(alunos);
	
	liberar_lista(alunos);
	return 0;
}
