//ex 1069 - Diamantes e Areia

#include <stdio.h>
#include <string.h>

int main() {
    int n;
    char mina[1001];

    scanf("%d", &n);
    getchar(); // consome '\n'

    while (n--) {
        fgets(mina, 1001, stdin);

        int i, abertos = 0, diamantes = 0;
        for (i = 0; mina[i] != '\0'; i++) {
            if (mina[i] == '<') {
                abertos++;
            } else if (mina[i] == '>' && abertos > 0) {
                abertos--;
                diamantes++;
            }
        }
        printf("%d\n", diamantes);
    }

    return 0;
}
