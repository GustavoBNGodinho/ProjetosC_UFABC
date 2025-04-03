#include <stdlib.h>
#include <stdio.h>

typedef struct lista Lista;

Lista* criaLista();

Lista* insereLista(Lista* l, int valor);

Lista* retiraLista(Lista* l, int valor);

Lista* separa(Lista* l, int valor);

Lista* concatena(Lista* l1, Lista* l2);

Lista* constroi(int* v, int tamanho);

Lista* inverte(Lista* l);

void printLista(Lista* l, int n);

Lista* insere_ultimo(Lista* l, int valor);