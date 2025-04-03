#include <stdlib.h>
#include <stdio.h>
#include "lista.h"

struct lista {
    Lista* prox;
    int valor;
};

Lista* criaLista() {
    return NULL;
}

Lista* insereLista(Lista* l, int valor) {
    Lista* p = (Lista*)malloc(sizeof(Lista));
    p->prox = l;
    p->valor = valor;
    return p;
}

Lista* retiraLista(Lista* l, int valor) {
    Lista* p = l;
    Lista* a = NULL;
    while(p->prox != NULL && p->valor != valor) {
        a = p;
        p = p->prox;
    }
    printf("valor = %d", p->valor);
    if(p->valor == valor) {
        a->prox = p->prox;
        free(p);
        return l;
    } else {
        if(a == NULL);
        l = p->prox;
        return l;
    }
}

Lista* insere_ultimo(Lista* l, int valor) {
    Lista* p = l;
    for(int i = 0; p->prox != NULL; i++) {
        p = p->prox;
    }
    printf("%d\n", p->valor);
    Lista* novo = (Lista*)malloc(sizeof(Lista));
    novo->valor = valor;
    novo->prox = NULL;
    p->prox = novo;
    return l;
}

Lista* concatena(Lista* l1, Lista* l2) {
    Lista* p1 = l1;
    while(p1->prox != NULL){
        p1 = p1->prox;
    }
    p1->prox = l2;
    l2 = NULL;
    return l1;
}

Lista* inverte(Lista* l) {
    Lista* p = l;
    Lista* novaLista = criaLista();
    while(p->prox != NULL){
        printf("oi");
        novaLista = insereLista(novaLista, p->valor);
        int vNoRetirado = p->valor;
        p = p->prox;
        l = retiraLista(l, vNoRetirado);
    }
    return novaLista;

}

void printLista(Lista* l, int n) {
    Lista* p = l;
    for(int i = 0; p->prox != NULL; i++) {
        p = p->prox;
        printf("Valor do nó da lista %d = %d\n", n, p->valor);
    }
}