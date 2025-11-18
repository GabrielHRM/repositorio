#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

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