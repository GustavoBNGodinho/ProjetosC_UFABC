#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
#include <string.h>
 
/*Protótipo da função */
int parenthesis_balance (char* s) {
    int abreParenteses = 0;
    int fechaParenteses = 0;
    Pilha* p = pilha_cria();
        for(int i = 0; s[i] != '\0'; i++) {
            if(s[i] == '(') {
                pilha_push(p, 0);
                abreParenteses++;
            }
            if(s[i] == ')') {
                fechaParenteses++;
                if(pilha_vazia(p) == 1) {
                    break;
                } else {
                    pilha_pop(p);
                }
            }
        }
        if (pilha_vazia(p) == 1 && abreParenteses == fechaParenteses) {
            printf("correct\n");
        } else {
            printf("incorrect\n");
        }
        free(p);
    };  

int main() {
    int n = 0;
    scanf("%d", &n);
    //alocar memória para o array de strings
    char* expressoes[n];
    getchar();
    for(int i = 0; i<n; i++) {
        expressoes[i] = (char*)malloc(100 * sizeof(char));

        if(expressoes == NULL) {
            printf("Deu ruim alocação dos strings");
            return 1;
        }
        printf("Digite as %d° expressão:", i + 1);
        scanf("%99[^\n]", expressoes[i]);

        /*versão fgets
        fgets(espressoes[i], 100, stdin);
        expressoes[i][strcspn(expressoes[i], "\n")] = 0; --> strcspn(arr, str) retorna o indice da sub string*/
        getchar();
    }
    for (int i = 0; i < n; i++) {
        parenthesis_balance(expressoes[i]);
    }
    return 0;
}