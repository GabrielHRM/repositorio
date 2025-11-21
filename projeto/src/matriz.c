#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "matriz.h"
#include "historico.h"
#include "estrutura.h"

void ler_matriz(double *matriz, dimensao tamanho){
    int i, j;
    for(i = 0; i<tamanho.linha; i++){
        for(j = 0; j < tamanho.coluna; j++){
            scanf("%lf", &matriz[i * tamanho.coluna + j]);
        }
    }
}

double *alocarmatriz(dimensao tamanho){
    double *matriz = (double*)malloc(tamanho.linha*tamanho.coluna*sizeof(double));

    return matriz;
}

double *alocarmatrizmult(dimensao tamanho1, dimensao tamanho2){
    double *matriz = (double*)malloc(tamanho1.linha*tamanho2.coluna*sizeof(double));

    return matriz;
}

double *soma_matricial(double *matriz1, double *matriz2, dimensao tamanho1, dimensao tamanho2){
    int i, j;
    double *resultado;

    if(tamanho1.linha == tamanho2.linha && tamanho1.coluna == tamanho2.coluna){
        resultado = alocarmatriz(tamanho1);
        for(i = 0; i<tamanho1.linha; i++){
            for(j = 0; j < tamanho1.coluna; j++){
                resultado[i * tamanho1.coluna + j] = matriz1[i * tamanho1.coluna + j] + matriz2[i * tamanho1.coluna + j];
            }
        }
        return resultado;
    }
    return NULL;
}

double *subtracao_matricial(double *matriz1, double *matriz2, dimensao tamanho1, dimensao tamanho2){
    int i, j;
    double *resultado;

    if(tamanho1.linha == tamanho2.linha && tamanho1.coluna == tamanho2.coluna){
        resultado = alocarmatriz(tamanho1);
        for(i = 0; i<tamanho1.linha; i++){
            for(j = 0; j < tamanho1.coluna; j++){
                resultado[i * tamanho1.coluna + j] = matriz1[i * tamanho1.coluna + j] - matriz2[i * tamanho1.coluna + j];
            }
        }
        return resultado;
    }
    return NULL;
}


double *multiplicacao_matricial(double *matriz1, double *matriz2, dimensao tamanho1, dimensao tamanho2){
    int i, j, k;
    double *resultado;

    if(tamanho1.coluna == tamanho2.linha){
        resultado = alocarmatrizmult(tamanho1, tamanho2);
        /*
          resultado[i][j] += m1[i][k] * m2[k][j]
          resultado[i*c2+j] += m1[i*c1 + k] * m2[k*c2 + j]
        */

        for(i = 0; i<tamanho1.linha; i++){
            for(j = 0; j<tamanho2.coluna; j++){
                for(k = 0; k<tamanho1.coluna; k++){
                    //tamanho2.coluna tamanho1.coluna tamanho2.coluna
                    resultado[i * tamanho2.coluna + j] += matriz1[i * tamanho1.coluna + k] * matriz2[k * tamanho2.coluna + j];
                }
            }
        }
        return resultado;
    }
    return NULL;
}

void imprimir_matriz_resultado(double *matrizresultado, dimensao tamanho){
    int i, j;

    for(i = 0; i< tamanho.linha; i++){
        printf("|");
        for(j = 0; j < tamanho.coluna; j++){
            printf("%7.2lf ", matrizresultado[i * tamanho.coluna + j]);
        }
        printf("|\n");
    }
}

void matriz_historico(char *entrada, double *matrizresultado, dimensao tamanho){
    int i, j;
    char matrizstr[50];
    entrada[0] = '\0';

    for(i = 0; i< tamanho.linha; i++){
        strcat(entrada, "|");
        for(j = 0; j < tamanho.coluna; j++){
            sprintf(matrizstr, "%7.2lf ", matrizresultado[i * tamanho.coluna + j]);
            strcat(entrada, matrizstr);
        }
        strcat(entrada, "|\n");
    }
    strcat(entrada, "\n");
    
}