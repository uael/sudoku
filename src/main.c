/*
  +----------------------------------------------------------------------+
  | sudoku                                                               |
  +----------------------------------------------------------------------+
  | Copyright (c) IUT Team 2016                                          |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author: Valentin Nahim                                               |
  | Author: Valentin Lajeunesse                                          |
  | Author: Abel Lucas                                                   |
  +----------------------------------------------------------------------+
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../sudoku.h"

void print_help() {
    printf(
        "\n"
        "sudoku - as a learning exercise.\n"
        "   generate: generate and print a full 9*9 grid\n"
        "   puzzle:   generate and print a full 9*9 puzzle\n"
    );
}

int main (int argc, char *argv[]) {
    int empty;
    sudoku_t *sudoku;

    for (int i = 1; i < argc; i++) {
        printf("argument %d: %s\n", i, argv[i]);
    }

    if (argc >= 1 && argv[1]) {
        if (strcmp(argv[1], "generate") == 0) {
            sudoku = sudoku_ctor();

            sudoku_generate(sudoku);
            sudoku_print_grid(sudoku);
            sudoku_dtor(sudoku);
        } else if (strcmp(argv[1], "puzzle") == 0) {
            sudoku = sudoku_ctor();
            empty = argc >= 2 && argv[2] ? strtol(argv[2], NULL, 10) : 54;

            sudoku_puzzle(sudoku, empty);
            sudoku_print_puzzle(sudoku);
            sudoku_solve_backtracking(sudoku);
            printf("\n");
            sudoku_print_puzzle(sudoku);
            sudoku_dtor(sudoku);
        } else {
            print_help();
        }
    } else {
        print_help();
    }

    return EXIT_SUCCESS;
}

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */