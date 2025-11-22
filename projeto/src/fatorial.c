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
    /*3 indices: 1 para os fatores primos, outro para os indices dos vetores
    das potencias dos fatores primos e das potencias e o ultimo é para
    percorrer os 2 vetores e transofrma-los em strings*/
    int i = 2;
    int j = 0;
    int k;
    int potencia;
    /*Alocação de memoria dos vetores dos fatores primos e suas potencia.*/
    int *primos = (int*)malloc(2000*sizeof(int));
    int *potencia_primos = (int*)malloc(2000*sizeof(int));
    /*Alocação de memoria das strings que serão manipuladas para levar
    o resultado até o histórico*/
    char *entrada = (char*)malloc(2000*sizeof(char));
    char *string_final = (char*)malloc(2000*sizeof(char));

    
    entrada[0] = '\0';
    string_final[0] = '\0';

    sprintf(string_final, "%lld = ", n);
    /*O esquema é ir reduzindo o valor de n até 1 por divisões.
    Enquanto o resto de divisão de n pelo i inicial(i = 2) for zero
    n será dividido por i até que o resto seja != 0*/
    while(n>1){
        potencia = 0;
        while(n%i == 0){
            potencia++;
            n = n/i;
        }
        /*Caso a potencia seja maior que zero, é guardado os respectivos valores
        nos vetores previamente alocados*/
        if(potencia > 0){
            primos[j] = i;
            potencia_primos[j] = potencia;
            j++;
        }
        //Por fim, o indice i é atualizado
        i++;
    }

    long int tamanho = j;

    for(k = 0; k<tamanho; k++){
        //Preenchendo a string entrada com o resultado da fatoração
        sprintf(entrada, "%d^%d", primos[k], potencia_primos[k]);
        //Concatena a string entrada para string final que será retornada
        strcat(string_final, entrada);
        //Medida de segurança para menos o ultimo indice da string tenha o ' x '
        if(k < tamanho - 1){
            strcat(string_final, " x ");
        }
    }

    //libera os espaços de memoria das strings usadas, menos a string_final.
    //Essa vai ser liberado posteriormente.
    free(primos);
    free(potencia_primos);
    free(entrada);
    return string_final;
}