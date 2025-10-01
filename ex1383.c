//sudoku

#include <stdio.h>

#define TAM 9

int sudoku[TAM][TAM];

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
    return 0;
}
