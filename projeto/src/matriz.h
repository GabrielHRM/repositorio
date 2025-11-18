#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "historico.h"

void ler_matriz(double *matriz, int linha, int coluna){
    int i, j;
    for(i = 0; i<linha; i++){
        for(j = 0; j < coluna; j++){
            scanf("%lf", &matriz[i * coluna + j]);
        }
    }
}

double *alocarmatriz(int linha, int coluna){
    double *matriz = (double*)malloc(linha*coluna*sizeof(double));

    return matriz;
}

double *soma_matricial(double *matriz1, double *matriz2, int l1, int l2, int c1, int c2){
    int i, j;
    double *resultado;

    if(l1 == l2 && c1 == c2){
        int linha = l1, coluna = c1;
        resultado = alocarmatriz(linha, coluna);
        for(i = 0; i<linha; i++){
            for(j = 0; j < coluna; j++){
                resultado[i * coluna + j] = matriz1[i * coluna + j] + matriz2[i * coluna + j];
            }
        }
        return resultado;
    }
    printf("Matrizes com dimensoes diferente. Tente novamente.\n");
    return NULL;
}
double *subtracao_matricial(double *matriz1, double *matriz2, int l1, int l2, int c1, int c2){
    int i, j;
    double *resultado;

    if(l1 == l2 && c1 == c2){
        int linha = l1, coluna = c1;
        resultado = alocarmatriz(linha, coluna);
        for(i = 0; i<linha; i++){
            for(j = 0; j < coluna; j++){
                resultado[i * coluna + j] = matriz1[i * coluna + j] - matriz2[i * coluna + j];
            }
        }
        return resultado;
    }
    printf("Matrizes com dimensoes diferente. Tente novamente.\n");
    return NULL;
}


double *multiplicacao_matricial(double *matriz1, double *matriz2, int l1, int l2, int c1, int c2){
    int i, j, k;
    double *resultado;
    resultado = alocarmatriz(l1, c2);

    if(c1 == l2){
        /*
          resultado[i][j] += m1[i][k] * m2[k][j]
          resultado[i*c2+j] += m1[i*c1 + k] * m2[k*c2 + j]
        */

        for(i = 0; i<l1; i++){
            for(j = 0; j<c2; j++){
                for(k = 0; k<c1; k++){
                    resultado[i * c2 + j] += matriz1[i * c1 + k] * matriz2[k * c2 + j];
                }
            }
        }
    }
    return resultado;
}

void imprimir_matriz_resultado(double *matrizresultado, int linha, int coluna){
    int i, j;

    for(i = 0; i< linha; i++){
        printf("|");
        for(j = 0; j < coluna; j++){
            printf("%7.2lf ", matrizresultado[i * coluna + j]);
        }
        printf("|\n");
    }
}

void matriz_historico(char *entrada, double *matrizresultado, int linha, int coluna){
    int i, j;
    char matrizstr[50];
    entrada[0] = '\0';

    for(i = 0; i< linha; i++){
        strcat(entrada, "|");
        for(j = 0; j < coluna; j++){
            sprintf(matrizstr, "%7.2lf ", matrizresultado[i * coluna + j]);
            strcat(entrada, matrizstr);
        }
        strcat(entrada, "|\n");
    }
    
}