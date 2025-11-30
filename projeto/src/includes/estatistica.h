#ifndef ESTATISTICA_H
#define ESTATISTICA_H

void insertion_short(double *v, long int n);

void ler_vetor_numero(double *v, long int n);

double *alocar(int n);

double media(double *v, long int n);

double mediana(double *v, long int n);

double moda(double *v, long int n);

double desvio_padrao(double *v, long int n);

#endif