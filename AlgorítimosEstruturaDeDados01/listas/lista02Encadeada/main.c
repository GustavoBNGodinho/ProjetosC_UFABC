#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include "estudante.h"

// Funcao principal para testes
int main() {
    Lista *lista = criaLista();

    lista = insere(lista, criaEstudante("Alice", 20, 8.5));
    lista = insere(lista, criaEstudante("Bob", 22, 7.8));
    lista = insere(lista, criaEstudante("Carlos", 19, 9.2));

    imprime(lista);
    printf("\n");
    lista = retira(lista, "Bob");
    imprime(lista);
    printf("\n");
    lista = retira(lista, "Alice");
    imprime(lista);
    printf("\n");
    lista = retira(lista, "Carlos");
    imprime(lista);
    printf("\n");
    lista = retira(lista, "Daniel");
    imprime(lista);
    printf("\n");
    destroiLista(lista);

    return 0;
}
