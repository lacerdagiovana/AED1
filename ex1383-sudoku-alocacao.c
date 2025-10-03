//sudoku - alocação dinamica 

#include <stdio.h>
#include <stdlib.h>

#define TAM 9

int **sudoku; // ponteiro para matriz dinâmica

int verificaLinha(int linha) {
    int numeros[TAM + 1] = {0};
    for (int j = 0; j < TAM; j++) {
        int valor = sudoku[linha][j];
        if (numeros[valor]) return 0;
        numeros[valor] = 1;
    }
    return 1;
}

int verificaColuna(int coluna) {
    int numeros[TAM + 1] = {0};
    for (int i = 0; i < TAM; i++) {
        int valor = sudoku[i][coluna];
        if (numeros[valor]) return 0;
        numeros[valor] = 1;
    }
    return 1;
}

int verificaQuadrado(int indice) {
    int numeros[TAM + 1] = {0};
    int linhaInicial = 3 * (indice / 3);
    int colunaInicial = 3 * (indice % 3);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int valor = sudoku[linhaInicial + i][colunaInicial + j];
            if (numeros[valor]) return 0;
            numeros[valor] = 1;
        }
    }
    return 1;
}

int main() {
    int n;
    scanf("%d", &n);

    // aloca matriz dinamicamente
    sudoku = malloc(TAM * sizeof(int*));
    for (int i = 0; i < TAM; i++) {
        sudoku[i] = malloc(TAM * sizeof(int));
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 0; i < TAM; i++) {
            for (int j = 0; j < TAM; j++) {
                scanf("%d", &sudoku[i][j]);
            }
        }

        int valido = 1;
        for (int i = 0; i < TAM; i++) {
            if (!verificaLinha(i) || !verificaColuna(i) || !verificaQuadrado(i)) {
                valido = 0;
                break;
            }
        }

        printf("Instancia %d\n", k);
        if (valido) printf("SIM\n\n");
        else printf("NAO\n\n");
    }

    // libera memória alocada
    for (int i = 0; i < TAM; i++) {
        free(sudoku[i]);
    }
    free(sudoku);

    return 0;
}
