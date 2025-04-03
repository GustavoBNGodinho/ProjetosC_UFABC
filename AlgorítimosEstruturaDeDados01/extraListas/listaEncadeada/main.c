#include <stdlib.h>
#include <stdio.h>
#include "lista.h"

int main() {
    Lista* l1 = criaLista();
    Lista* l2 = criaLista();


    l1 = insereLista(l1, 5);
    l1 = insereLista(l1, 4);
    l1 = insereLista(l1, 3);
    l1 = insereLista(l1, 2);
    l1 = insereLista(l1, 1);
    l2 = insereLista(l2,10);
    l2 = insereLista(l2, 9);
    l2 = insereLista(l2, 8);
    l2 = insereLista(l2, 7);
    l2 = insereLista(l2, 6);
    printLista(l2, 0);
    l2 = insere_ultimo(l2, 100);

    printLista(l2, 1);
    printf("===========================");
    l1 = concatena(l1, l2);
    printLista(l1, 2);
    l1 = retiraLista(l1, 100);
    printLista(l1,3);
    l1 = inverte(l1);
    printLista(l1, 4);
    


}