#include <stdio.h>
#include <stdlib.h>
#include "lista3.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	Lista* listaCriada = criar_lista();
	
	Aluno mucio = {1, "Mucio", 6.2}; 
	Aluno elesbao = {2, "Elesbao", 8.5}; 
	Aluno raoni = {3, "Raoni", 4.4}; 
	Aluno genoveva = {4, "Genoveva", 3.7}; 
	Aluno estela = {5, "Estela", 6.8}; 
	Aluno willy = {6, "Willy", 9.2}; 
	Aluno marvin = {4, "Marvin", 10}; 
	
	inserir(mucio, listaCriada);
	inserir(elesbao, listaCriada);
	inserir(raoni, listaCriada);
	inserir(genoveva, listaCriada);
	inserir(estela, listaCriada);
	inserir(willy, listaCriada);
	inserir(marvin, listaCriada);
	
	imprimir(listaCriada);
	
	remover(listaCriada, 1);   
	remover(listaCriada, 20);  
	
	return 0;
}
