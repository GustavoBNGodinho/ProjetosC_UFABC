#ifndef CLIENTE_H
#define CLIENTE_H

#define TAM_NOME 80

// Declaração do tipo
typedef struct cliente Cliente;

// Funcionalidades
Cliente* criar_cliente(char nome[], float deposito);
void liberar_cliente(Cliente *c);
void obter_dados_cliente(Cliente *c, char nome[], float *deposito);

#endif // CLIENTE_H
