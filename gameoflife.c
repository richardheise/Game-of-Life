#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <unistd.h> 
#include "life.h"

int main(int argc, char **argv) {
    initscr(); /*inicia a tela*/
    /* declaração das variáveis */
    int control;
    int generations;
    int rows, cols;
    board_t board;
    cell_t cell;
    /* pega o tamanho da tela */
    getmaxyx(stdscr, rows, cols); 
    endwin(); /*encerra a tela */

    /* checa por erros de argumentos */
    if (argc != 3) {
        printf("Número de parametros errado.\n");
        return 1;
    }

    /* transforma os parametros em inteiros */
    board.lin = atoi(argv[1]);
    board.col = atoi(argv[2]);

    if (board.lin > rows || board.col > cols) {
        printf("Erro. Terminal muito pequeno.\n");
        return 2;
    }
    /* fim da checagem */

    alloc_board(&board);
    create_board(&board);
    /* verifica se o usuário digitou um valor dentro do esperado */
    if (create_population(&cell, &board) == 0) {
        printf("Você digitou um valor invalido. \n");
        return 3;
    }

    printf("Quantas gerações você quer?: ");
    scanf("%d", &generations);
    /* realiza a passagem de tempo na matriz e escreve na tela */
    for (control = 0; control < generations; ++control) { 
        print_board(&board);
        usleep(99999); 
        printf("\033[H\033[J");
        evolve(&board, &cell);
    }
        
    free_board(&board);

    return 0;
}
