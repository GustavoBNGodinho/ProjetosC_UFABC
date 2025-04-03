#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bib.h"

int main() {
    int numeroOperacoes = 0;
    char nomeArquivoEntrada[50];
    char nomeArquivoSaida[50];
    FILE *arquivoEntrada, *arquivoSaida;

    printf("Digite o nome do arquivo TXT de entrada: ");
    scanf("%s", nomeArquivoEntrada);

    printf("Digite o nome do arquivo TXT de saída: ");
    scanf("%s", nomeArquivoSaida);

    arquivoEntrada = fopen(nomeArquivoEntrada, "r");
    if (arquivoEntrada == NULL) {
        printf("Erro ao abrir o arquivo %s\n", nomeArquivoEntrada);
        return 1;
    }

    arquivoSaida = fopen(nomeArquivoSaida, "w");
    if (arquivoSaida == NULL) {
        printf("Erro ao abrir o arquivo %s\n", nomeArquivoSaida);
        fclose(arquivoEntrada);
        return 1;
    }

    fscanf(arquivoEntrada, "%d", &numeroOperacoes);
    int qtd = 0;

    Celula* cabeca = novaLista();

    for (int i = 0; i < numeroOperacoes; i++) {
        char operacao;
        char ddd[3];
        char numero[9];
        fscanf(arquivoEntrada, " %c", &operacao);
        fscanf(arquivoEntrada, "%2s", ddd);
        fscanf(arquivoEntrada, "%8s", numero);
        if (operacao == 'I') {
            insere(numero, ddd, cabeca);
            qtd++;
        } else {
            int aux = busca_e_remove(numero, ddd, cabeca);
            if (aux) {
                qtd--;
            }
        }
    }

    fclose(arquivoEntrada);

    Celula* v = malloc(sizeof(Celula) * qtd);
    formaVetor(v, cabeca);
    ordena(v, qtd);

    fprintf(arquivoSaida, "%d\n", qtd);
    for (int i = 0; i < qtd; i++) {
        fprintf(arquivoSaida, "%s\n", v[i].ddd);
        fprintf(arquivoSaida, "%s\n", v[i].numero);
    }

    fclose(arquivoSaida);

    return 0;
}
