#include <stdio.h>
#include <stdlib.h>
#include "life.h"

void create_board (board_t *board) {
    int i;
    int j;
    /* escreve zero na matriz inteira */
    for (i = 0; i <= board->lin; ++i) {
        for (j = 0; j <= board->col; ++j) {
            board->matrix[i][j] = 0;
        }
    }
    /* coloca -8 nas bordas */
    /* -8 é um valor aleatório. Qualquer valor negativo seria equivalente */
    for (i = 0; i <= board->lin; ++i) {
        board->matrix[i][0] = -8;
        board->matrix[i][board->col-1] = -8;
    } 
    for (i = 0; i <= board->col; ++i) {
        board->matrix[0][i] = -8;
        board->matrix[board->lin-1][i] = -8;
    }
}

void print_board (board_t *board) {
    int i, j;
    for (i = 0; i <= board->lin; ++i){
        for (j = 0; j <= board->col; ++j) {
            /* ajeita a forma como o usuário vê o tabuleiro */
            if (board->matrix[i][j] == 0 || board->matrix[i][j] == -8) 
                printf(" ");
            else 
                printf("#"); 
        }
    printf("\n");
    }
}

void alloc_board (board_t *board) {
    int i;
    /* aloca dinamicamente a matrix do struct board */
    board->matrix = NULL; 
    board->matrix = malloc(board->lin * sizeof(int *)+1);
    for (i = 0; i <= board->lin; ++i) {
        board->matrix[i] = malloc(board->col * sizeof(int)+1);
    /* +1 evita alguns seg fault */
    }
}

void free_board (board_t *board) {
    free(board->matrix);
}

int create_population (cell_t *cell, board_t *board) {
    /* variaveis */
    int input;
    int error = 0;
    /* inputs */
    printf("Digite -1 para parar.\n");
    printf("Entre com as posições iniciais das populações: ");
    scanf("%d", &input);
    if (input > board->lin || input > board->col) {
        error = 1; /* controle de input */
    }
    while (input != -1 && !error) {
        /* escreve na posição de linhas da celula */
        cell->posx = input;
        /* nova entrada será lida */
        scanf("%d", &input);
        /* realiza o controle da entrada lida */
        if (input > board->lin || input > board->col) {
            error = 1;
            break;
        }
        /* escreve a nova entrada na posição de colunas da celula */
        cell->posy = input;
        /* torna a celula "viva" */
        board->matrix[cell->posx][cell->posy] = 1;
        /* escreve o tabuleiro em tempo real */
        print_board(board);
        printf("Entre com as posições iniciais das populações: ");
        scanf("%d", &input);
        /* controle da entrada */
        if (input > board->lin || input > board->col) {
            error = 1;
            break;
        }
    }
    if (error) {
        return 0;
    }
    return 1;
}

int count_neighbors(board_t *board, int posx, int posy) {
    int count = 0;
    /* conta os vizinhos por força bruta */
    if (board->matrix[posx][posy+1] == 1)
        ++count;
    if (board->matrix[posx][posy-1] == 1)
        ++count;
    if (board->matrix[posx-1][posy+1] == 1)
        ++count;
    if (board->matrix[posx-1][posy-1] == 1)
        ++count;
    if (board->matrix[posx-1][posy] == 1)
        ++count;
    if (board->matrix[posx+1][posy+1] == 1)
        ++count;
    if (board->matrix[posx+1][posy-1] == 1)
        ++count;
    if (board->matrix[posx+1][posy] == 1)
        ++count;
    return count;
}

void next_generation (board_t *board, int **m) {
    int i;
    int j;
    /* decide, a partir da matrix passada, */
    /* o que acontece com as celulas do tabuleiro */
    for (i = 1; i < board->lin; ++i) {
        for (j = 1; j < board->col; ++j) {
            /* se a celula era morta e cumpre o requerimento de vida */
            /* ela passa a ser viva */
            if (board->matrix[i][j] == 0 && m[i][j] == 3) {
                board->matrix[i][j] = 1;
            }
            /* se a celula era viva e cumpre o requerimento de morte. */
            /* Então ela passa a ser morta */
            else if (board->matrix[i][j] == 1 && (m[i][j] < 2 || m[i][j] >= 4)) {
                board->matrix[i][j] = 0;
            }
        }
    }
}

void evolve (board_t *board, cell_t *cell) {
    (void)cell;
    int i;
    int j;
    /* matrix auxiliar */
    int **Maux;
    /* alocação dinamica da matriz auxiliar */
    Maux = malloc(board->lin * sizeof(int *));
    for (i = 0; i < board->lin; ++i)
        Maux[i] = malloc(board->col * sizeof(int));

    /* essa matriz guarda os valores de vizinhos */
    /* em cada posição do tabuleiro */
    /* essencialmente é uma matriz de vizinhos de cada celula */
    for (i = 1; i < board->lin; ++i) {
        for (j = 1; j < board->col; ++j) {
            Maux[i][j] = count_neighbors(board, i, j);
        }
    }
    next_generation(board, Maux); 
}
