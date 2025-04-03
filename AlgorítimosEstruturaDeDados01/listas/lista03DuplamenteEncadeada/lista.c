//////////////////////////////////////////////////////////////////////////////////////////////////////
//Implementacao do TAD Lista duplamente encadeada para armazenar dados do TAD Estudante    //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "estudante.h"
#include "lista.h"


/* Observe que a interface será a mesma (lista.h) de lista simplemente encadeada mas a mplementação do tipo (struct + funções - lista.c) precisam corresponder a litta duplamente encadeada*/

struct lista {
    Estudante *aluno;
    struct lista *ant;
    struct lista *prox;
};


Lista* criaLista (){
    return NULL;
}

// Insere um estudante no início da lista
Lista* insere(Lista *l, Estudante *e) {
    Lista *novo = (Lista*) malloc(sizeof(Lista));
    if (!novo) return l;

    novo->aluno = e;
    novo->prox = l;
    novo->ant = NULL;

    if (l) l->ant = novo;

    return novo; // Retorna o novo início da lista
}

// Remove um estudante pelo nome
Lista* retira(Lista *l, const char *nome) {
    Lista *atual = l;
    while (atual) {
        if (strcmp(getNome(atual->aluno), nome) == 0) {
            if (atual->ant)
                atual->ant->prox = atual->prox;
            else
                l = atual->prox; // Atualiza o início da lista

            if (atual->prox)
                atual->prox->ant = atual->ant;

            destroiEstudante(atual->aluno);
            free(atual);
            return l;
        }
        atual = atual->prox;
    }
    return l;
}


// Destroi a lista, liberando memória
void destroiLista(Lista *l) {
    Lista *atual = l;
    while (atual) {
        Lista *temp = atual;
        atual = atual->prox;
        destroiEstudante(temp->aluno);
        free(temp);
    }
}

//-----------------Novas funções-------------------
// Implementar função para imprimir toda a lista de estudantes
void imprime(Lista *l) {
    Lista* p = l;
    while(p->prox != NULL) {
        p = p->prox;
    }
    while(p->ant != NULL) {
        imprimeEstudante(p->aluno);
        p = p->ant;
    }
    imprimeEstudante(p->aluno);
}
// Implementar função para imprimir somente um nó da lista de estudantes apontado por p
void imprimeNo(Lista *p){
    imprimeEstudante(p->aluno);
}
// Implementar função de busca um estudante pelo nome, retorna o ponteiro para o nó, se encontrado e, NULL, caso contrário
Lista* busca(Lista *l, char* nome) {
    Lista* p = l;
    for(int i = 0;i<tamanho(l);i++) {
        printf("NOME: %s\n", getNome(p->aluno));
        if(strcmp(getNome(p->aluno),nome) == 0) {
            return p;
        }
        if(p->prox != NULL){
            p = p->prox;
        }
    }
    return NULL;
}
// Implementar função de retorna o comprimento da lista
int tamanho(Lista *l){
    if(l == NULL) {
        return 0;
    }
    Lista* p = l;
    int count = 0;
    while(p->prox != NULL) {
        count++;
        p = p->prox;
    }
    return count + 1;
}

/*Errei coisa basica
    * sempre lembrar de avançar a lista/pilha ou derivados a cada loop
    * strcmp para comparar strings
    *  */