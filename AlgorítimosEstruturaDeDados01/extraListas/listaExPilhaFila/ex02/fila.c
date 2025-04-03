#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

#define N 50

struct fila {
    int n; /* número de elementos na fila */
    int ini; /* posição do próximo elemento a ser retirado da fila */
    float vet[N];
    };

void combina_filas(Fila* f_res, Fila* f1, Fila* f2) {
    int MaiorTamanho = 0;
    if(f1->n > f2->n) {
        MaiorTamanho = f1->n;
    }
    for(int i = 0;i<MaiorTamanho; i++){
        if(!fila_vazia(f1)) {
            float aux = fila_retira(f1);
            fila_insere(f_res, aux);
        }
        if(!fila_vazia(f2)) {
            float aux = fila_retira(f2);
            fila_isere(f_res, aux);
        }
    }
}