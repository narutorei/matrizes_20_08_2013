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

	var i, j;

	puts("+--------------------------------------------------------------------+");
	puts("|         Exercícios do dia 20/08/13                                 |");
	puts("+--------------------------------------------------------------------+");
	puts("\n\t+---+---+---+---+---+");
	puts("\t|   | 1 | 2 | 3 | 4 | <-- Colunas");
	puts("\t+---+---+---+---+---+");

	for(i = 0; i < MAX; i++) {
		printf("\t|   | ");
		for(j = 0; j < MAX; j++) {
			if(!matriz[i][j])
				putchar(' ');
			else
				printf("%d", matriz[i][j]);
			prints(" |");
		}
		putchar('\n');
		puts("\t+---+---+---+---+---+");
	}

	putchar('\n');

	puts("+--------------------------------------------------------------------+");

}

/**
 * verifica se a matriz passada tem espaços vazios
 */
int tem_espacos_vazios(int matriz[][]) {
	int i, j;

	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			if(!matriz[i][j])
				return 1;
		}
	}

}

/**
 *  Preenche a matriz com valores de 1 a 16
 */
void fill_matrix(int matriz[][]) {
	int i, j, count = 1;

	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			matriz[i][j] = count++;
		}
	}
}

/**
 * Sai do programa
 */
void encerra() {
	puts("\tSaindo...");
	exit(0);
}

/**
 * Para o menu
 */
void para_menu() {
	char c;
	puts("\tPressione enter para continuar");
	getchar();
	while((c = getchar()) != \n && c != EOL);
}

/**
 * Programa
 */
void programa(int matriz[][]) {
	puts("IÉIÉ, pegadinha do malandro");
}

int main() {

	int matriz[MAX][MAX];
	char c;

	fill_matrix(matriz);

	while(1) {

		system("clear");

		cabecalho(matriz);

		puts("\t Escolha uma opção:\n");
		puts("\t[ 1 ] Realiza programa");
		puts("\t[ 2 ] Sair do programa");

		c = getchar();

		switch (c) {
		case '1':
			programa(matriz);
			break;
		case '2':
			encerra();
			break;
		}

		para_menu();
		
	}

}