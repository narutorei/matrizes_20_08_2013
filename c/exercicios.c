/**
 *  1) Escreva um programa em linguagem C que execute as seguintes operações:
 *  a) Declare uma matriz quadrada, com dimensões 4x4, de valores inteiros, inicializada com
 *	os valores de 01 a 16
 *  b) Exiba a matriz, e a seguir, faça as seguintes trocas de conteúdos:
 *  c) Conteúdos da 2º linha com os da 4º Linha
 *  d) Conteúdos da 3º coluna com os da 4º coluna
 *  e) Conteúdos da diagonal principal com os da secundária
 *  f) Conteúdos da 1º linha com os da 4º coluna;
 *  g) Exibir a matriz modificada
 */
#include <stdlib.h>
#include <strings.h>
#include <stdio.h>

#define MAX 4

/**
 * Preenche matriz
 */
void preenche_matriz(int matriz[][]) {

}
/**
 * Imprime cabeçalho
 */
void cabecalho(int matriz[][]) {

	var i;

	puts("+--------------------------------------------------------------------+");
	puts("|         Exercícios do dia 20/08/13                                 |");
	puts("+--------------------------------------------------------------------+");
	puts("\n\t+---+---+---+---+---+");
	puts("\t|   | 1 | 2 | 3 | 4 | <-- Colunas");
	puts("\t+---+---+---+---+---+");

	for(i = 0; i < MAX; i++) {
		printf("|   | %d | %d | %d | %d |\n", matriz[i][0], matriz[i][1], matriz[i][2], matriz[i][3]);
		puts("\t+---+---+---+---+---+");
	}

	putchar('\n');

	puts("+--------------------------------------------------------------------+");
	
}