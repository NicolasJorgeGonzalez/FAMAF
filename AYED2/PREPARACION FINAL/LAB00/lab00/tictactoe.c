#include <stdlib.h>  /* exit() y EXIT_FAILURE */
#include <stdio.h>   /* printf(), scanf()     */
#include <stdbool.h> /* Tipo bool             */

#include <assert.h> /* assert() */

#define CELL_MAX (3 * 3 - 1)

void print_sep(int length)
{
    printf("\t ");
    for (int i = 0; i < length; i++)
        printf("................");
    printf("\n");
}

void print_board(char board[3][3])
{
    int cell = 0;

    print_sep(3);
    for (int row = 0; row < 3; ++row)
    {
        for (int column = 0; column < 3; ++column)
        {
            printf("\t | %d: %c ", cell, board[row][column]);
            ++cell;
        }
        printf("\t | \n");
        print_sep(3);
    }
}

char get_winner(char board[3][3])
{
    char winner = '-';
    // char aux_board[3][3]
    // for (unsigned int i = 0; i < 3; i++)
    // {
    //     for (unsigned int j = 0; j < 3; j++)
    //     {
    //         aux_board[i][j] = board[i][j];
    //     }
    // }
    if ((board[0][0] == 'X' && board[0][4] == 'X' && board[0][9] == 'X') || (board[0][2] == 'X' && board[0][4] == 'X' && board[0][6] == 'X'))
    {
        winner = 'X';
    }
    else if ((board[0][0] == 'O' && board[0][4] == 'O' && board[0][9] == 'O') || (board[0][2] == 'O' && board[0][4] == 'O' && board[0][6] == 'O'))
    {
        winner = 'O';
    }
    else if ((board[0][0] == 'X' && board[0][1] == 'X' && board[0][2] == 'X') || (board[1][0] == 'X' && board[1][1] == 'X' && board[1][2] == 'X') || (board[2][0] == 'X' && board[2][1] == 'X' && board[2][2] == 'X') || (board[0][0] == 'X' && board[1][0] == 'X' && board[2][0] == 'X') || (board[0][1] == 'X' && board[1][1] == 'X' && board[2][1] == 'X') || (board[0][2] == 'X' && board[1][2] == 'X' && board[2][2] == 'X'))
    {
        winner = 'X';
    }
    else if ((board[0][0] == 'O' && board[0][1] == 'O' && board[0][2] == 'O') || (board[1][0] == 'O' && board[1][1] == 'O' && board[1][2] == 'O') || (board[2][0] == 'O' && board[2][1] == 'O' && board[2][2] == 'O') || (board[0][0] == 'O' && board[1][0] == 'O' && board[2][0] == 'O') || (board[0][1] == 'O' && board[1][1] == 'O' && board[2][1] == 'O') || (board[0][2] == 'O' && board[1][2] == 'O' && board[2][2] == 'O'))
    {
        winner = 'O';
    }

    return winner;
}

// Otra manera de realizarlo
// char get_winner(char board[3][3]) {
//     const int winning_combinations[8][3][2] = {
//         // Filas
//         {{0, 0}, {0, 1}, {0, 2}},
//         {{1, 0}, {1, 1}, {1, 2}},
//         {{2, 0}, {2, 1}, {2, 2}},
//         // Columnas
//         {{0, 0}, {1, 0}, {2, 0}},
//         {{0, 1}, {1, 1}, {2, 1}},
//         {{0, 2}, {1, 2}, {2, 2}},
//         // Diagonales
//         {{0, 0}, {1, 1}, {2, 2}},
//         {{0, 2}, {1, 1}, {2, 0}}
//     };
//     for (int i = 0; i < 8; ++i) {
//         char first = board[winning_combinations[i][0][0]][winning_combinations[i][0][1]];
//         char second = board[winning_combinations[i][1][0]][winning_combinations[i][1][1]];
//         char third = board[winning_combinations[i][2][0]][winning_combinations[i][2][1]];
//         if (first != '-' && first == second && first == third) {
//             return first; // Devuelve el ganador ('X' o 'O')
//         }
//     }
// return '-'; // No hay ganador
// }

bool has_free_cell(char board[3][3])
{
    bool free_cell = false;
    for (unsigned int i = 0; i < 3; i++)
    {
        for (unsigned int j = 0; j < 3; j++)
        {
            if (board[i][j] == '-')
            {
                free_cell = true;
            }
        }
    }
    return free_cell;
}

int main(void)
{
    char board[3][3] = {
        {'-', '-', '-'},
        {'-', '-', '-'},
        {'-', '-', '-'}};

    char turn = 'X';
    char winner = '-';
    int cell = 0;
    while (winner == '-' && has_free_cell(board))
    {
        print_board(board);
        printf("\nTurno %c - Elija posición (número del 0 al %d): ", turn,
               CELL_MAX);
        int scanf_result = scanf("%d", &cell);
        if (scanf_result <= 0)
        {
            printf("Error al leer un número desde teclado\n");
            exit(EXIT_FAILURE);
        }
        if (cell >= 0 && cell <= CELL_MAX)
        {
            int row = cell / 3;
            int colum = cell % 3;
            if (board[row][colum] == '-')
            {
                board[row][colum] = turn;
                turn = turn == 'X' ? 'O' : 'X';
                winner = get_winner(board);
            }
            else
            {
                printf("\nCelda ocupada!\n");
            }
        }
        else
        {
            printf("\nCelda inválida!\n");
        }
    }
    print_board(board);
    if (winner == '-')
    {
        printf("Empate!\n");
    }
    else
    {
        printf("Ganó %c\n", winner);
    }
    return 0;
}
