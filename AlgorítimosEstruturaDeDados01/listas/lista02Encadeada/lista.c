//////////////////////////////////////////////////////////////////////////////////////////////////////
//Implementacao do TAD Lista simplesmente encadeada para armazenar dados do TAD Estudante    //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#include <stdlib.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "estudante.h"
#include "lista.h"

struct lista {
    Estudante *aluno;
    struct lista *prox;
};

Lista* criaLista (){
    return NULL;
}

Estudante* getAluno(Lista* l) {
    return l->aluno;
}

// Insere um estudante no início da lista
Lista* insere(Lista *l, Estudante *e) {
    Lista *novo = (Lista*) malloc(sizeof(Lista));
    if (!novo) return l;  // Retorna a lista original se falhar

    novo->aluno = e;
    novo->prox = l;
    return novo;  // Retorna o novo primeiro nó
}

// Remove um estudante pelo nome
Lista* retira(Lista *l, const char *nome) {
    if (!l) return NULL;

    Lista *atual = l, *anterior = NULL;

    while (atual) {
        if (strcmp(getNome(atual->aluno), nome) == 0) {
            if (!anterior) {
                Lista *novo_inicio = atual->prox; // Atualiza o primeiro nó
                destroiEstudante(atual->aluno);
                free(atual);
                return novo_inicio;
            } else {
                anterior->prox = atual->prox;
                destroiEstudante(atual->aluno);
                free(atual);
                return l; // Retorna o início original
            }
        }
        anterior = atual;
        atual = atual->prox;
    }
    return l; // Retorna o início original se não encontrar o nome
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

//---------------------Novas funções----------------

// Retorna o nó da lista em que está o estudante com o nome "nome"
Lista* busca(Lista* l, char* nome) {
    Lista* p = l;
    for (int i = 0; i<tamanho(l); i++) {
        if (strcmp(getNome(p->aluno),nome) == 0 || p == NULL){
            return p;
        } else {
            p = p->prox;
        }
    }
    free(p);
}

// Retorna o comprimento da lista
int tamanho(Lista *l){
    int count = 0;
    Lista *p = l;
    while(p!=NULL) {
        count++;
        p = p->prox;
    }
    return count;
    free(p);
}
// Imprime a lista de estudantes
void imprime(Lista *l) {
    Lista* p = l;
    Lista* a = l;
    while(p->prox != NULL){
        p = p->prox;
    }
    while(p!=l) {
        while(a->prox != p) {
            // printf("entrou no segundo while");
            a = a->prox;
        }
        imprimeEstudante(getAluno(p));
        p = a;
        a = l;
    }
    imprimeEstudante(getAluno(p));
}
