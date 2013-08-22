/**
 *  1) Escreva um programa em linguagem C que execute as seguintes operações:
 *  a) Declare uma matriz quadrada, com dimensões 4x4, de valores inteiros, inicializada com
 *  os valores de 01 a 16
 *  b) Exiba a matriz, e a seguir, faça as seguintes trocas de conteúdos:
 *  c) Conteúdos da 2º linha com os da 4º Linha
 *  d) Conteúdos da 3º coluna com os da 4º coluna
 *  e) Conteúdos da diagonal principal com os da secundária
 *  f) Conteúdos da 1º linha com os da 4º coluna;
 *  g) Exibir a matriz modificada
 */
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define MAX 4

/**
 * Imprime matriz
 */
void imprime_matriz(int matriz[MAX][MAX]) {
    int i, j;

    puts("\n\t+----+----+----+----+----+");
    puts("\t|    |  1 |  2 |  3 |  4 | <-- Colunas");
    puts("\t+----+----+----+----+----+");

    for(i = 0; i < MAX; i++) {
        printf("\t| %2d |", i + 1);
        for(j = 0; j < MAX; j++) {
            if(!matriz[i][j])
                printf("  ");
            else
                printf("%3d", matriz[i][j]);
            printf(" |");
        }
        putchar('\n');
        puts("\t+----+----+----+----+----+");
    }

    puts("\t  |");
    puts("\t  +---- Linhas");

    putchar('\n');
}

/**
 * Imprime cabeçalho
 */
void cabecalho(int matriz[MAX][MAX]) {

    int i, j;

    puts("+--------------------------------------------------------------------+");
    puts("|         Exercícios do dia 20/08/13                                 |");
    puts("+--------------------------------------------------------------------+");
    
    imprime_matriz(matriz);

    puts("+--------------------------------------------------------------------+");

}

/**
 *  Preenche a matriz com valores de 1 a 16
 */
void fill_matrix(int matriz[MAX][MAX]) {
    int i, j, count = 1;

    for (i = 0; i < MAX; i++)
    {
        for (j = 0; j < MAX; j++)
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
    while((c = getchar()) != '\n');
}

/**
 * Valida linhas, colunas
 */
int valida_parametros(int param1, int param2) {
    int cond1 = (param1 > MAX || param2 > MAX || param1 < 0 || param2 < 0),
        cond2 = (param1 == param2);
    if(cond1) {
        puts("Parâmetros que acessam posições fora da matriz inserida");
        return 0;
    } else if(cond2) {
        puts("Não é possível inverter as mesmas linhas ou não faz diferença");
        return 0;
    } else
        return 1;
    
}

/**
 * Inverte linhas da matriz
 *
 */
int inverte_linhas(int linha1, int linha2, int matriz[MAX][MAX]) {

    if(!valida_parametros(linha1, linha2))
        return 0;

    linha1--;
    linha2--;

    printf("Iniciando a inversão das linhas nº %d com a nº %d\n", linha1, linha2);

    int aux, i;

    for(i = 0; i < MAX; i++) {
        aux = matriz[linha1][i];
        matriz[linha1][i] = matriz[linha2][i];
        matriz[linha2][i] = aux;
    }

    puts("\n\tResultado da inversão\n");

    imprime_matriz(matriz);

    return 1;

}

/**
 * Inverte colunas
 */
int inverte_colunas(int coluna1, int coluna2, int matriz[MAX][MAX]) {

}

/**
 * Programa
 */
void programa(int matriz[MAX][MAX]) {
    /*puts("IÉIÉ, pegadinha do malandro");*/

    inverte_linhas(2, 4, matriz);



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