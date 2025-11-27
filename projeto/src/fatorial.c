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

int *alocar_vetor(long int n){
    int *primos_potencias = (int*)malloc(n*sizeof(int));
    if(primos_potencias == NULL){
        return NULL;
    }

    return primos_potencias;
}

char *alocar_str_vetor(long int n){
    char *primos_str = (char*)malloc(2000*sizeof(char));
    if(primos_str == NULL){
        return NULL;
    }
    primos_str[0] = '\0';
    return primos_str;
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
    int *primos;
    int *potencia_primos;
    primos = alocar_vetor(20000);
    potencia_primos = alocar_vetor(20000);
    /*Alocação de memoria das strings que serão manipuladas para levar
    o resultado até o histórico*/
    char *entrada;
    char *string_final;
    entrada = alocar_str_vetor(20000);
    string_final = alocar_str_vetor(20000);

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
        //Medida de segurança para que menos o ultimo indice da string tenha o ' x '
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