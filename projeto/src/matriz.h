#ifndef MATRIZ_H
#define MATRIZ_H

void ler_matriz(double *matriz, int linha, int coluna);

double *alocarmatriz(int linha, int coluna);

double *soma_matricial(double *matriz1, double *matriz2, int l1, int l2, int c1, int c2);

double *subtracao_matricial(double *matriz1, double *matriz2, int l1, int l2, int c1, int c2);

double *multiplicacao_matricial(double *matriz1, double *matriz2, int l1, int l2, int c1, int c2);

void imprimir_matriz_resultado(double *matrizresultado, int linha, int coluna);

void matriz_historico(char *entrada, double *matrizresultado, int linha, int coluna);

#endif