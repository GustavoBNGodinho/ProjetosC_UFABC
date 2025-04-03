#include "fila.h"
#include <stdlib.h>
#include <stdio.h>

// Estrutura do Nó (privada, apenas dentro de fila.c)
typedef struct no {
    Cliente *c;
    struct no *prox;
} No;

// Definição da estrutura da Fila (agora está apenas aqui!)
struct fila {
    No *inicio;
    No *fim;
    int tamanho;
};

// Função para criar uma fila vazia
Fila* fila_cria() {
    Fila *f = (Fila*)malloc(sizeof(Fila));
    if (f == NULL) {
        printf("Erro ao alocar memória para a fila.\n");
        exit(1);
    }
    f->inicio = f->fim = NULL;
    f->tamanho = 0;
    return f;
}

// Função para verificar se a fila está vazia
int fila_vazia(Fila *f) {
    return (f->tamanho == 0);
}

// Adiciona um cliente à fila
void fila_insere(Fila *f, Cliente *c) {
    No *novo = (No*)malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro ao alocar memória para o nó da fila.\n");
        exit(1);
    }
    novo->c = c;
    novo->prox = NULL;

    if (fila_vazia(f)) {
        f->inicio = f->fim = novo;
    } else {
        f->fim->prox = novo;
        f->fim = novo;
    }
    f->tamanho++;
}

// Remove e retorna um cliente da fila
Cliente* fila_remove(Fila *f) {
    if (fila_vazia(f)) {
        printf("Fila vazia! Nenhum cliente para remover.\n");
        return NULL;
    }

    No *removido = f->inicio;
    Cliente *c = removido->c;  // Pegamos o cliente antes de liberar o nó

    f->inicio = removido->prox;
    if (f->inicio == NULL) {
        f->fim = NULL;
    }

    free(removido);  // Liberamos apenas o nó, o cliente será tratado pelo chamador
    f->tamanho--;
    return c;
}

// Libera a fila e todos os clientes nela
void fila_libera(Fila *f) {
    while (!fila_vazia(f)) {
        Cliente *c = fila_remove(f);
        liberar_cliente(c);  // Agora liberamos cada cliente corretamente
    }
    free(f);
}

// Atende os clientes e exibe o relatório
float atendimentoCaixaBanco(Fila *f, int *clientesAtendidos) {
    float totalDepositos = 0;
    printf("Relatório de atendimento\n");
    for(int i = 0; i<*clientesAtendidos; i++) {
        Cliente* cliente = fila_remove(f);
        char nome[TAM_NOME];
        float deposito = 0;

        obter_dados_cliente(cliente, nome, &deposito);
        totalDepositos = totalDepositos + deposito;
        printf("Posição: %d | Cliente: %s | Deposito: %.2f\n", i, nome, deposito);
    }
    
    return totalDepositos;
}
