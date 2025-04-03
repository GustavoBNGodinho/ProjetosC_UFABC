#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"
#include <ctype.h>

#define N 50

int main(){
    char expressao[N];
    scanf("%49[^\n]", expressao);
    getchar();
    printf("Essa é a sua expressão: %s\n", expressao);

    Pilha* p = pilha_cria();

    for(int i = 0; expressao[i] != '\0'; i++) {
        char s = expressao[i];
        if(isdigit(s)) {
            pilha_push(p, (float)(s - '0'));
            printf("%.2f\n", (float)(s - '0'));
        } if (isdigit(s) == 0 && s != ' ') {
            float digito1 = 0;
            float digito2 = 0;
            float digitoResult = 0;
            if (s == '+') {
                digito1 = pilha_pop(p);
                digito2 = pilha_pop(p);
                digitoResult = digito1 + digito2;
            }
            if (s == '-') {
                digito1 = pilha_pop(p);
                digito2 = pilha_pop(p);
                digitoResult = digito2 - digito1;
            }
            if (s == '*') {
                digito1 = pilha_pop(p);
                digito2 = pilha_pop(p);
                digitoResult = digito1 * digito2;
            }
            if (s == '/') {
                digito1 = pilha_pop(p);
                digito2 = pilha_pop(p);
                digitoResult = digito2 / digito1;
            }
            pilha_push(p, digitoResult);
            printf("%.2f\n", digitoResult);
        }
    }
    return 1;
}