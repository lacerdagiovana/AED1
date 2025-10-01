#include <string.h>
#include <stdlib.h>
#include <stdio.h>

struct pilhaNo{
    char valor;                     // valor armazenado
    struct pilhaNo* abaixo;         // próximo nó abaixo
};

struct pilha{
    int tamanho;                    // quantidade de elementos
    struct pilhaNo* topo;           // nó do topo
};

void push(struct pilha* p, int valor){
    p->tamanho += 1;                                     // incrementa tamanho
    struct pilhaNo* novoTopo = (struct pilhaNo*) malloc(sizeof(struct pilhaNo)); // cria novo nó

    novoTopo->valor = valor;                             // define valor
    novoTopo->abaixo = p->topo;                          // aponta para topo anterior
    p->topo = novoTopo;                                  // atualiza topo
}

void pop(struct pilha* p){
    if(p->tamanho > 0){                                  // só remove se não vazia
        p->tamanho -= 1;                                 // decrementa tamanho
        struct pilhaNo* velhoTopo = p->topo;             // guarda topo atual
        p->topo = p->topo->abaixo;                       // ajusta topo
        free(velhoTopo);                                 // libera memória
    }
}

char top(struct pilha* p){
    return p->topo->valor;                               // retorna valor do topo
}

int size(struct pilha* p){
    return p->tamanho;                                   // retorna tamanho
}

int empty(struct pilha* p){
    return p->tamanho == 0;                              // verifica vazio
}

void inicializa(struct pilha* p){
    p->tamanho = 0;                                      // zera tamanho
    p->topo = NULL;                                      // topo nulo
}

void destroi(struct pilha* p){
    while(!empty(p)){                                    // remove até esvaziar
        pop(p);
    }
}

int main(){
    int i, tam;
    struct pilha p;
    char expressao[1001];

    while(scanf("%s\n", &expressao) != EOF){             // lê até EOF
        inicializa(&p);                                  // inicia pilha
        tam = strlen(expressao);                         // tamanho string

        for(i = 0; i < tam; ++i){                        // percorre expressão
            if(expressao[i] == '('){                     // abre parêntese
                push(&p, '(');
            }else if(expressao[i] == ')'){               // fecha parêntese
                if(empty(&p))   break;                   // pilha vazia -> erro
                else            pop(&p);                 // senão desempilha
            }
        }

        if(i == tam && empty(&p))   printf("correct\n"); // correto se percorreu tudo e pilha vazia
        else                        printf("incorrect\n"); // senão incorreto

        destroi(&p);                                    // limpa pilha
    }

    return 0;
}
