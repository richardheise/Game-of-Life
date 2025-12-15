#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>

/* struct do tabuleiro */
typedef struct board 
{
    int **matrix;
    int lin;
    int col;
} board_t; 

/* struct da celula */
typedef struct cell
{
    int posy;
    int posx;
} cell_t;

/* libera memória alocada dinamicamente */
void free_board (board_t *board);

/* função que cria o tabuleiro com bordas */
void create_board (board_t *board);

/* aloca memória para tabuleiros */
void alloc_board (board_t *board);

/* cria a população a partir de inputs. Se o usuário digitar um valor errado -- fora do tamanho da matriz -- ela retorna 0 */
int create_population (cell_t *cell, board_t *board);

/* conta quantos vizinhos cada célula tem e retorna esse valor */
int count_neighbors(board_t *board, int posx, int posy);

/* organiza quais células vão morrer, quais vão nascer e quais vão continuar vivas */
/* utiliza uma matriz auxiliar alocada dinamicamente e declarada em evolução() */
/* NÃO UTILIZE ESSA FUNÇÃO SEM CHAMAR EVOLUÇÃO() */
void next_generation (board_t *board, int **m);

/* realiza a evolução do tabuleiro. Utiliza uma matriz auxiliar alocada dinamicamente */
void evolve (board_t *board, cell_t *cell);

/* escreve o tabuleiro na tela */
void print_board (board_t *board);
