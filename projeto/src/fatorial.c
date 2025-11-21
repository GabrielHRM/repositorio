#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "fatorial.h"

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