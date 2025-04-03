#include <stdio.h>
#include "pilha.h"
#include <stdlib.h>

#define N 50

struct pilha {
    int n; // primeira posição livre do vetor e tamanho da pilha;
    float v[N];
};


Pilha* pilha_cria() {
    Pilha* p = (Pilha*)malloc(sizeof(Pilha));
    p->n = 0;
    return p;
}

float pilha_pop(Pilha* p) {
    if(pilha_vazia(p) == 1){
        printf("Pilha vazia\n");
        exit(1);
    } else {
        float valor = p->v[p->n - 1];
        p->n--;
        return valor;
    }
}

void pilha_push(Pilha* p, float valor) {
    if(p->n == 51) {
        printf("Pilha cheia\n");
        exit(1);
    } else {
        p->v[p->n] = valor;
        p->n++; 
    }
}

int pilha_vazia(Pilha* p) {
    return p->n == 0; //retorna 1 se pilha vazia;
}

void pilha_libera(Pilha* p) {
    free(p);
}