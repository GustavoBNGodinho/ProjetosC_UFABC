#ifndef FILA_H  //Evita recarregar o arquivo fila.h. Como fazemos essa inclusao de cabeçalho em vários arquivos, o que pode ocasionar erros de redefições de tipos e funções
#define FILA_H

#include "cliente.h"

// Declaração do tipo Fila
typedef struct fila Fila;

// Funções da Fila
Fila* fila_cria();                          // Cria uma fila vazia
int fila_vazia(Fila *f);                     // Verifica se a fila está vazia
void fila_insere(Fila *f, Cliente *c);       // Adiciona um cliente na fila
Cliente* fila_remove(Fila *f);               // Remove e retorna um cliente da fila
void fila_libera(Fila *f);                   // Libera a fila e todos os clientes nela
float atendimentoCaixaBanco(Fila *f, int *clientesAtendidos); // Atende os clientes e exibe o relatório

#endif // FILA_H

