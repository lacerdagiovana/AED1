//Jogando Cartas Fora- 1110 - pilha 

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Nó da pilha
typedef struct tipoNo{
    int numero;                // valor da carta
    struct tipoNo *proximo;    // próximo nó
} tipoNo;

// Estrutura da pilha
typedef struct tipoPilha{
    tipoNo *topo;              // ponteiro para o topo
} tipoPilha;

void pop(tipoPilha *pilha, int *descartes);
void push(tipoPilha *pilha, int numero);
void moveTopo(tipoPilha *pilha);
void stack(tipoPilha *pilha);
void erase(tipoPilha *pilha);

short qtsDescartes; // quantidade de cartas descartadas

int main () {
    unsigned short carta;
    tipoPilha pilha;
    short i;

    while (true) {
        scanf("%hu", &carta);

        if (carta == 0 || carta > 50) // condição de parada
            return 0;

        stack(&pilha); // inicializa pilha
        int descartes[carta]; // vetor de descartes

        // empilha as cartas em ordem decrescente
        for (i = carta; i > 0; i--)
            push(&pilha, i);

        qtsDescartes = 0;
        pop(&pilha, descartes); // descarta as cartas

        printf("Discarded cards:");
        for (i = 0; i < qtsDescartes; i++) {
            printf(" %d", descartes[i]);
            if (i != qtsDescartes - 1)
                printf(",");
        }

        printf("\nRemaining card: %d\n", pilha.topo->numero); // carta final
        erase(&pilha); // libera memória
    }
}

// cria pilha vazia
void stack(tipoPilha *pilha) {
    pilha->topo = NULL;
}

// insere elemento no topo
void push(tipoPilha *pilha, int carta) {
    tipoNo *auxiliar = (tipoNo *) malloc(sizeof(tipoNo));
    if (!auxiliar) exit(1);
    auxiliar->proximo = pilha->topo;
    pilha->topo = auxiliar;
    auxiliar->numero = carta;
}

// retira cartas e registra descartes
void pop(tipoPilha *pilha, int *descartes) {
    tipoNo *auxiliar;

    if (pilha->topo) { // só executa se não vazia
        // se só tem uma carta, não descarta
        if (!pilha->topo->proximo)
            return;

        do {
            auxiliar = pilha->topo;
            descartes[qtsDescartes++] = auxiliar->numero;
            pilha->topo = pilha->topo->proximo;
            free(auxiliar);
            moveTopo(pilha); // move nova carta do topo para base
        } while (pilha->topo->proximo);
    }
}

// move o topo para a base
void moveTopo(tipoPilha *pilha) {
    tipoNo *auxiliar, *base;
    base = pilha->topo;
    auxiliar = pilha->topo;

    if (base->proximo) {
        while (base->proximo) // vai até a última carta
            base = base->proximo;

        pilha->topo = pilha->topo->proximo;
        auxiliar->proximo = NULL;
        base->proximo = auxiliar;
    }
}

// apaga a pilha
void erase(tipoPilha *pilha) {
    tipoNo *auxiliar;
    while (pilha->topo) { // libera todos os nós
        auxiliar = pilha->topo;
        pilha->topo = pilha->topo->proximo;
        free(auxiliar);
    }
}
