#include "cliente.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// Definição completa da struct Cliente (visível apenas neste arquivo)
struct cliente {
    char nome[TAM_NOME];
    float deposito;
};

// Implementação da função para criar um cliente
Cliente* criar_cliente(char nome[], float deposito) {
    Cliente *c = (Cliente*)malloc(sizeof(Cliente));
    if (c == NULL) {
        printf("Erro ao alocar memória para cliente.\n");
        exit(1);
    }
    strncpy(c->nome, nome, TAM_NOME - 1); // Semelhante a função strcpy mas copia a string até o número de caracteres em TAM_NOME ou a quebra de linha
    c->nome[TAM_NOME - 1] = '\0'; // Garante terminação da string
    c->deposito = deposito;
    return c;
}

// Função para liberar memória do cliente
void liberar_cliente(Cliente *c) {
    free(c);
}

// Função para obter os dados do cliente
void obter_dados_cliente(Cliente *c, char nome[], float *deposito) {
    strncpy(nome, c->nome, TAM_NOME); 
    *deposito = c->deposito;
}
