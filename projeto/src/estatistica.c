#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "fatorial.h"
#include "estatistica.h"
#include "historico.h"

//Ordenação: insertion short
void insertion_short(double *v, long int n){
    for (int i = 1; i < n; ++i) {
        int chave = v[i];
        int j = i - 1;


        while (j >= 0 && v[j] > chave) {
            v[j + 1] = v[j];
            j = j - 1;
        }
        v[j + 1] = chave;
    }
}

//Ler sequencia de números
void ler_vetor_numero(double *v, long int n){
    int i;
    for(i = 0; i < n; i++){
        scanf("%lf", &v[i]);
    }
}

//Calculo da média
double media(double *v, long int n){
    int i;
    double soma = 0.0;

    for(i = 0; i<n;i++){
        soma += (double)v[i];
    }

    double m = soma/n;

    return m;
}

//Calculo da mediana
double mediana(double *v, long int n){
    int i;
    double mdi;
    if(n%2 == 0){
        mdi = v[(n/2) - 1] + v[(n/2)];
        mdi = mdi/2.0;
    }else if(n%2 != 0){
        mdi = v[n/2];
    }

    return mdi;
}

//Calculo da moda
double moda(double *v, long int n){
    int i, j;
    double *v2 = (double*)malloc(n*sizeof(double));

    for(i = 0; i<n; i++){
        v2[i] = 0;
    }

    for(i = 0; i<n; i++){
        for(j = 0; j<n; j++){
            if(v[i] == v[j]){
                v2[i] = v2[i] + 1;
            }
        }
    }
    
    int maior = 0, imaior;
    for(i = 0; i<n; i++){
        if(v2[i] > maior){
            maior = v2[i];
            imaior = i;
        }
    }
    if(maior <= 1){
        return 0.0;
    }

    double mda = v[imaior];
    free(v2);

    return mda;
}

double desvio_padrao(double *v, long int n){
    int i;
    double md = media(v, n), soma = 0.0, dp;
    if(n <= 1){
        return 0.0;
    }

    for(i = 0; i<n; i++){
        soma = pow((v[i] - md), 2) + soma;
    }

    dp = sqrt(soma/n);

    return dp;
}