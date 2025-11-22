#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "fatorial.h"
#include "historico.h"

/*O int padrão da linguagem c aguenta armazenar apenas até o resultado
do fatorial 12!, qualquer coisa além disse é necessário o long int ou 
long long int, para inteiros maiores*/
long long int fatinicial(long long int x){
    long long int i = x-1, resultado = x;
    if(x == 0 || x == 1){
        return 1;
    }
    while(i>=1){
        resultado = resultado*i;
        i--;
    }
    return resultado;
}

char *fatoracao_primos(long long int n){
    int i = 2;
    int j = 0;
    int k;
    int potencia;
    int *primos = (int*)malloc(2000*sizeof(int));
    char *entrada = (char*)malloc(2000*sizeof(char));
    char *string_final = (char*)malloc(2000*sizeof(char));
    int *potencia_primos = (int*)malloc(2000*sizeof(int));
    
    
    entrada[0] = '\0';
    string_final[0] = '\0';

    sprintf(string_final, "%lld = ", n);
    while(n>1){
        potencia = 0;
        while(n%i == 0){
            potencia++;
            n = n/i;
        }
        if(potencia > 0){
            primos[j] = i;
            potencia_primos[j] = potencia;
            j++;
        }
        i++;
    }

    long int tamanho = j;

    for(k = 0; k<tamanho; k++){
        sprintf(entrada, "%d^%d", primos[k], potencia_primos[k]);
        strcat(string_final, entrada);
        if(k < tamanho - 1){
            strcat(string_final, " x ");
        }
    }

    free(primos);
    free(potencia_primos);
    free(entrada);
    return string_final;
}