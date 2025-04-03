#ifndef _BIB_H_
#define _BIB_H_
#include <stdio.h>
#include <stdlib.h>

typedef struct Celula {
    char ddd[3];
    char numero[9];
    struct Celula* prox;
} Celula;

Celula* novoNumero(char numero[], char ddd[]);

Celula* novaLista();

void insere(char numero[], char ddd[], Celula* cabeca);

int busca_e_remove(char numeroRmove[], char ddd[], Celula* cabeca);

void formaVetor(Celula v[], Celula* cabeca);

void ordena(Celula v[], int tam);

void printVetor(Celula* v, int qtd);

void printList(Celula* cabeca);

#endif