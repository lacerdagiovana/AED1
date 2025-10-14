//ex 1068 | balanco de parenteses - pilha usando vetores

#include <stdio.h>
#include <string.h>

#define MAX 1000  // tamanho máximo da pilha

struct pilha {
    char elementos[MAX];
    int topo;
};

void inicializa(struct pilha *p) {
    p->topo = -1;
}

int empty(struct pilha *p) {
    return p->topo == -1;
}

void push(struct pilha *p, char valor) {
    if (p->topo < MAX - 1) {
        p->elementos[++p->topo] = valor; // incrementa topo e adiciona elemento
    }
}

void pop(struct pilha *p) {
    if (!empty(p)) {
        p->topo--; // remove elemento (decrementa topo)
    }
}

char top(struct pilha *p) {
    return p->elementos[p->topo];
}

int main() {
    struct pilha p;
    char expressao[1001];
    int i, tam;

    while (scanf("%s", expressao) != EOF) {
        inicializa(&p);
        tam = strlen(expressao);

        for (i = 0; i < tam; i++) {
            if (expressao[i] == '(') {
                push(&p, '(');
            } else if (expressao[i] == ')') {
                if (empty(&p)) break; // erro: fecha sem abrir
                pop(&p);
            }
        }

        if (i == tam && empty(&p))
            printf("correct\n");
        else
            printf("incorrect\n");
    }

    return 0;
}
