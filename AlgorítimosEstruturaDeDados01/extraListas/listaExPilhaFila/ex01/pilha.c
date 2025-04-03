#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

#define N 50

struct pilha {
    int n;
    int v[N];
};

void printaPilha(Pilha* p) {
    for(int i = 0;i<p->n; i++) {
        printf("%d\n", p->v[i]);
    }
}

Pilha* pilhaCria() {
    Pilha* p = (Pilha*)malloc(sizeof(Pilha));
    p->n = 0;
    return p;
}

void pilhaPush(Pilha* p, int valor) {

    if (p->n == N) { /* capacidade esgotada */
        printf("Capacidade da pilha estourou.\n");
        exit(1); /* aborta programa */
    }
    p->v[p->n] = valor;
    p->n++;
}

int pilhaPop(Pilha* p) {

    if (pilhaVazia(p)) { 
        printf("Pilha vazia.\n");
        exit(1); 
    } /* aborta programa */
    int aux = p->v[p->n - 1];
    p->n--;
    return aux;
}

int pilhaVazia(Pilha* p) {
    if(p->n == 0) {
        return 1;
    } else {
        return 0;
    }
}

int topo(Pilha* p) {
    return p->v[p->n - 1];
}

void concatenaPilha(Pilha* p1, Pilha* p2){
        int aux = pilhaPop(p2);
        pilhaPush(p1, aux);
        if(p2->n != 0){
            concatenaPilha(p1, p2);
        }
}

Pilha* copiaPilha(Pilha* p) {
    Pilha* pResult = pilhaCria();
    pilhaPush(pResult, pilhaPop(p));
    if(p->n != 0) {
        
        copiaPilha(p);
    }
    return pResult;
}


