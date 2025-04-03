#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
#include <string.h>

int main() {
    Pilha* p1 = pilhaCria();
    Pilha* p2 = pilhaCria();
    pilhaPush(p1, 1);
    pilhaPush(p1, 2);
    pilhaPush(p1, 3);
    pilhaPush(p2, 7);
    pilhaPush(p2, 6);
    pilhaPush(p2, 5);
    pilhaPush(p2, 4);
    int resultado = topo(p1);
    printf("%d\n", resultado);
    // printaPilha(p1);
    concatenaPilha(p1, p2);
    // printaPilha(p1);
    Pilha* p3 = copiaPilha(p1);
    printf("pilha copiada\n");
    printaPilha(p3);
}