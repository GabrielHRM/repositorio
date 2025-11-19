#ifndef MATRIZ_H
#define MATRIZ_H

void ler_matriz(double *matriz, dimensao tamanho);

double *alocarmatriz(dimensao tamanho);

double *soma_matricial(double *matriz1, double *matriz2, dimensao tamanho1, dimensao tamanho2);

double *subtracao_matricial(double *matriz1, double *matriz2, dimensao tamanho1, dimensao tamanho2);

double *multiplicacao_matricial(double *matriz1, double *matriz2, dimensao tamanho1, dimensao tamanho2);

void imprimir_matriz_resultado(double *matrizresultado, dimensao tamanho);

void matriz_historico(char *entrada, double *matrizresultado, dimensao tamanho);

#endif