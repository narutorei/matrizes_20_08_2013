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

#define LXL 0
#define CXC 1
#define DXD 2
#define LXC 3

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
 * Inverte linhas
 */
void inverte_linhas(int linha1, int linha2, int matriz[MAX][MAX]) {
    printf("Iniciando a inversão das linhas nº %d com a nº %d\n", linha1 + 1, linha2 + 1);

    int aux, i;

    for(i = 0; i < MAX; i++) {
        aux = matriz[linha1][i];
        matriz[linha1][i] = matriz[linha2][i];
        matriz[linha2][i] = aux;
    }
}

/**
 * Inverte colunas
 */
void inverte_colunas(int coluna1, int coluna2, int matriz[MAX][MAX]) {
    printf("Iniciando a inversão das colunas nº %d com a nº %d\n", coluna1 + 1, coluna2 + 1);

    int aux, i;

    for(i = 0; i < MAX; i++) {
        aux = matriz[i][coluna1];
        matriz[i][coluna1] = matriz[i][coluna2];
        matriz[i][coluna2] = aux;
    }
}

/**
 * Inverte diagonais
 */
void inverte_diagonais(int matriz[MAX][MAX]) {
    printf("Iniciando a inversão das diagonais:\n");

    int aux, i, j = (MAX - 1), k = 0;

    for(i = 0; i < MAX; i++) {
        aux = matriz[i][i];
        matriz[i][i] = matriz[k][j];
        matriz[k][j] = aux;
        j--;
        k++;
    }
}

/**
 * Inverte linha com coluna
 */
void inverte_lin_col(int linha, int coluna, int matriz[MAX][MAX]) {
    printf("Iniciando a inversão da linha nº %d com a coluna nº %d\n", linha + 1, coluna + 1);

    int aux, i, max = (MAX - 1);

    for(i = 0; i < MAX; i++) {
        if((linha == (max - i)) && (i == coluna))
            continue;

        aux = matriz[linha][i];
        matriz[linha][i] = matriz[max - i][coluna];
        matriz[max - i][coluna] = aux;
    }
}

/**
 * Inverter
 *
 */
int inverte(int param1, int param2, int matriz[MAX][MAX], int type) {

    if(type != DXD && !valida_parametros(param1, param2))
        return 0;

    param1--;
    param2--;

    switch (type) {
    case LXL:
        inverte_linhas(param1, param2, matriz);
        break;
    case CXC:
        inverte_colunas(param1, param2, matriz);
        break;
    case DXD:
        inverte_diagonais(matriz);
        break;
    case LXC:
        inverte_lin_col(param1, param2, matriz);
        break;
    }

    puts("\n\tResultado da inversão\n");

    imprime_matriz(matriz);

    return 1;

}

/**
 * Programa
 */
void programa(int matriz[MAX][MAX]) {
    /*puts("IÉIÉ, pegadinha do malandro");*/

    if(!inverte(2, 4, matriz, LXL))
        puts("Parâmetros inválidos para inverter linhas");

    if(!inverte(3, 4, matriz, CXC))
        puts("Parâmetros inválidos para inverter colunas");

    if(!inverte(0, 0, matriz, DXD))
        puts("Parâmetros inválidos para inverter diagonais");

    if(!inverte(1, 4, matriz, LXC))
        puts("Parâmetros inválidos para inverter linha com coluna");

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