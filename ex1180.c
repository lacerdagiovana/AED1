//direto

#include <stdio.h>

int main() {
    int n, pos = 0;
    scanf("%d", &n);
    int x[n];
    for (int i = 0; i < n; i++) scanf("%d", &x[i]);
    int menor = x[0];
    for (int i = 1; i < n; i++) {
        if (x[i] < menor) {
            menor = x[i];
            pos = i;
        }
    }
    printf("Menor valor: %d\nPosicao: %d\n", menor, pos);
    return 0;
}
