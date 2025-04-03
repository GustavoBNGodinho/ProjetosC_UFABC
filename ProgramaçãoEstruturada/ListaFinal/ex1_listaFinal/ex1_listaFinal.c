#include <stdio.h>
#include "bib.h"
#define VALOR_MAXIMO 20 

/*Olá, Carlos. Primeitamente, sobre o tamanho do vetor, eu sei
que podemos resolver esse problema de várias formas. Na minha visão
a forma mais robusta é fazendo alocação dinâmica para aumentar o
tamanho do vetor ao passo que os números são inseridos. Todavia,
entendo que alocação dinâmica não é um requisito desse exercício.
Dessa forma, vou optar por fazer um array de tamanho máximo para
comportar todas as possibilidades.*/

int main() {
    int v[VALOR_MAXIMO] = {0};
    int i = 0;
    int count = 0;

    while(1) {
        scanf("%d", &v[i]); 
        count++;
        if (v[i] == 0) {
            break;
        }
        i++;
    }

    int a[count];
    for (int j = 0; j < count; j++) {
        a[j] = v[j];
    }
    int intervalo[3];
    i = 0;
    while(a[i + 2] != 0) {
        
        intervalo[0] = a[i];
        intervalo[1] = a[i + 1];
        intervalo[2] = a[i + 2];
        printf("%d\n", mediana(intervalo, 3));
        i++;
    }
}