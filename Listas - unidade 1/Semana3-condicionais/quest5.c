#include <stdio.h>
#include <math.h>

int main(){
    float valor;
    
    printf("Valor do produto:\n");
    scanf("%f", &valor);

    if(valor <=100.0){
        printf("Valor do prod com desc: %.2f", valor);
    } else if(valor >= 100.01 && valor <= 500.0){
        valor = valor * (1-0.10);
        printf("Valor do prod com desc: %.2f", valor);
    } else if(valor >= 500.01 && valor <= 1000.0){
        valor = valor * (1-0.15);
        printf("Valor do prod com desc: %.2f", valor);
    } else{
        valor = valor * (1-0.20);
        printf("Valor do prod com desc: %.2f", valor);
    }

    return 0;
}