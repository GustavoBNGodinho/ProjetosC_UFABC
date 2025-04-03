#include <stdio.h>
#include "bib.h"

int ordena(int v[],int tam) {
    for(int base = 0; base < tam - 1; base++) {
        for(int topo = base + 1; topo < tam; topo++){
            if(v[base] > v[topo] && v[topo] != 0) {
                int aux = v[topo];
                v[topo] = v[base];
                v[base] = aux;
            }
        }
    }
    return 1;
}

int mediana(int v[], int tam) {
    ordena(v, tam);
    int mediana = 0;
    if (tam%2 == 0) {
        //é par
        int meio = tam/2;
        mediana = (v[meio] + v[meio + 1])/2;
    } else {
        int meio = tam/2 - 1;
        mediana = v[meio + 1];
        //é impar
    }
    return mediana;
}