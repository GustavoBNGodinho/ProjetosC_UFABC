#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bib.h"

/*Códigos da lista encadeada foram inspirados nos slides disponibilizados*/

Celula* novoNumero(char numero[], char ddd[]) {
    Celula* cel = malloc(sizeof(Celula));
    strcpy(cel -> numero, numero);
    strcpy(cel -> ddd, ddd);
    cel -> prox = 0;
    return cel;
}

Celula* novaLista() {
    Celula* cabeca = malloc(sizeof(Celula));
    cabeca -> prox = 0;
    return cabeca;
}

void insere(char numeroIn[], char dddIn[], Celula* cabeca) {
    Celula* p = (Celula*)malloc(sizeof(Celula));
    strcpy(p -> numero, numeroIn);
    strcpy(p -> ddd, dddIn);
    p -> prox = cabeca -> prox;
    cabeca -> prox = p;
}

int busca_e_remove(char numeroRmove[], char dddRmove[], Celula* cabeca) {
    Celula *p, *q;
    p = cabeca;
    q = p -> prox;

    while (q != 0) {
        if ((strcmp(q -> numero, numeroRmove) == 0 && strcmp(q -> ddd, dddRmove) == 0)) {
            break;
        }
        p = q;
        q = q -> prox;
    }
    if (q != 0) {
        p -> prox = q -> prox;
        free (q);
        return 1;
    }
    return 0;

}

void formaVetor(Celula v[], Celula* cabeca) {
    Celula* q;
    q = cabeca;
    int i = -1;
    while (q != 0) {
        if (q != cabeca) {
            v[i] = *q;
        }
        q = q -> prox;
        i++;
    }
}

void formaVetorCpy(Celula v[], Celula* cabeca, int qtd) {
    Celula* q;
    q = cabeca -> prox;
    for (int i = 0; i < qtd; i++) {
        Celula* cpyCelula = malloc(sizeof(Celula));
        strcpy(cpyCelula -> ddd, q -> ddd);
        strcpy(cpyCelula -> numero, q -> numero);
        cpyCelula -> prox = NULL;
        q = q -> prox;
        v[i] = *cpyCelula;
    }
}

void ordena(Celula v[], int tam) {
    for (int base = 0; base < tam - 1; base++) {
        for (int topo = base + 1; topo < tam; topo++){
            if(strcmp(v[base].ddd, v[topo].ddd) > 0) {
                Celula aux = v[topo];
                v[topo] = v[base];
                v[base] = aux;
            } else if (strcmp(v[base].ddd, v[topo].ddd) == 0) {
                if (strcmp(v[base].numero, v[topo].numero) > 0) {
                    Celula aux = v[topo];
                    v[topo] = v[base];
                    v[base] = aux;
                }
            }
        }
    }
}

void printVetor(Celula* v, int qtd) {
    printf("%d\n", qtd);
    for (int i = 0; i < qtd; i++) {
        printf("%s\n", v[i].ddd);
        printf("%s\n", v[i].numero);
    }
}

void printList(Celula* cabeca) {
    Celula* p = cabeca;
    while (p != 0) {
        printf("ddd: %s\n", p->ddd);
        printf("numero: %s\n", p->numero);
        printf("----------------\n");
        p = p -> prox;
    }
}


