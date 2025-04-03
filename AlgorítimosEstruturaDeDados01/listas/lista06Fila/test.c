#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"

// Lê dados dos clientes e os adiciona à fila
void ler_clientes(Fila *fila, int n) {
    char nome[80];
    float deposito;
    int i = 0;
    while (i < n) {//leitura dos clientes
        scanf(" %s %f", nome, &deposito);
        Cliente *c =  criar_cliente(nome, deposito);
        fila_insere(fila, c);
        i++;
    }
}

// Função principal
int main() {
    Fila *fila = fila_cria();
    int n_clientes; //numero de clientes a serem lidos
    int totalAtendidos = 2;
    scanf("%d", &n_clientes);
    // Lendo n_clientes do teclado
    ler_clientes(fila, n_clientes);
    // Atendendo clientes
    float totalDepositos = atendimentoCaixaBanco(fila, &totalAtendidos);
    // Exibir resumo final
    printf("\nTotal de clientes atendidos: %d\n", totalAtendidos);
    printf("Total dos depositos: %.2f\n", totalDepositos);

    // Liberar memória
    fila_libera(fila);

    return 0;
}

