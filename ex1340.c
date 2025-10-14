//ex 1340 - Eu Posso Adivinhar a Estrutura de Dados

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 1000

typedef struct NoFila {
    int dado;
    struct NoFila *proximo;
} NoFila;

typedef struct {
    NoFila *primeiro, *ultimo;
} Fila;

typedef struct NoPilha {
    int dado;
    struct NoPilha *proximo;
} NoPilha;

typedef struct {
    NoPilha *topo;
} Pilha;

typedef struct {
    int dado, prioridade;
} Item;

typedef struct {
    int qtd;
    Item dados[MAXSIZE];
} PQueue;

void iniciaFila(Fila *f){ f->primeiro = f->ultimo = NULL; }
void pushFila(Fila *f, int x){
    NoFila *n = malloc(sizeof(NoFila));
    n->dado = x; n->proximo = NULL;
    if (!f->primeiro) f->primeiro = n;
    else f->ultimo->proximo = n;
    f->ultimo = n;
}
void popFila(Fila *f){
    if (!f->primeiro) return;
    NoFila *tmp = f->primeiro;
    f->primeiro = tmp->proximo;
    if (!f->primeiro) f->ultimo = NULL;
    free(tmp);
}
int frontFila(Fila *f){ return f->primeiro->dado; }

void iniciaPilha(Pilha *p){ p->topo = NULL; }
void pushPilha(Pilha *p, int x){
    NoPilha *n = malloc(sizeof(NoPilha));
    n->dado = x; n->proximo = p->topo;
    p->topo = n;
}
void popPilha(Pilha *p){
    if (!p->topo) return;
    NoPilha *tmp = p->topo;
    p->topo = tmp->proximo;
    free(tmp);
}
int topPilha(Pilha *p){ return p->topo->dado; }

PQueue* criaPQueue(){
    PQueue *pq = malloc(sizeof(PQueue));
    pq->qtd = 0;
    return pq;
}
void sobe(PQueue *pq, int i){
    while(i>0){
        int pai=(i-1)/2;
        if(pq->dados[pai].prioridade>=pq->dados[i].prioridade) break;
        Item tmp=pq->dados[i]; pq->dados[i]=pq->dados[pai]; pq->dados[pai]=tmp;
        i=pai;
    }
}
void desce(PQueue *pq, int i){
    int filho=2*i+1;
    while(filho<pq->qtd){
        if(filho+1<pq->qtd && pq->dados[filho+1].prioridade>pq->dados[filho].prioridade)
            filho++;
        if(pq->dados[i].prioridade>=pq->dados[filho].prioridade) break;
        Item tmp=pq->dados[i]; pq->dados[i]=pq->dados[filho]; pq->dados[filho]=tmp;
        i=filho; filho=2*i+1;
    }
}
void pushPQ(PQueue *pq, int x){ pq->dados[pq->qtd].dado=x; pq->dados[pq->qtd].prioridade=x; sobe(pq, pq->qtd++); }
void popPQ(PQueue *pq){ pq->dados[0]=pq->dados[--pq->qtd]; desce(pq,0); }
int topPQ(PQueue *pq){ return pq->qtd?pq->dados[0].dado:0; }

int main(void){
    int n;
    while(scanf("%d", &n)!=EOF){
        Fila f; Pilha p; PQueue *pq = criaPQueue();
        iniciaFila(&f); iniciaPilha(&p);

        int stackOk=1, queueOk=1, pqOk=1;
        for(int i=0;i<n;i++){
            int cmd,x;
            scanf("%d %d",&cmd,&x);
            if(cmd==1){
                pushFila(&f,x); pushPilha(&p,x); pushPQ(pq,x);
            } else {
                if(!p.topo || topPilha(&p)!=x) stackOk=0; else popPilha(&p);
                if(!f.primeiro || frontFila(&f)!=x) queueOk=0; else popFila(&f);
                if(pq->qtd==0 || topPQ(pq)!=x) pqOk=0; else popPQ(pq);
            }
        }
        int sum = stackOk + queueOk + pqOk;
        if(sum==0) printf("impossible\n");
        else if(sum>1) printf("not sure\n");
        else if(stackOk) printf("stack\n");
        else if(queueOk) printf("queue\n");
        else printf("priority queue\n");

        free(pq);
    }
    return 0;
}
