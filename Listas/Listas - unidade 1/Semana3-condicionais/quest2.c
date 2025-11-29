#include <stdio.h>
#include <math.h>

int main(){
    char consumidor;
    float valor, consumo;

    printf("Digite o consumo e tipo de consumidor: ");
    scanf("%f %c", &consumo, &consumidor);

    if(consumidor == 'r' || consumidor == 'R'){
        valor = (0.6*consumo) + 15;
        printf("Valor total: %.2f", valor);
    }else if(consumidor == 'c' || consumidor == 'C'){
        valor = (0.48*consumo) + 15;
        printf("Valor total: %.2f", valor);
    } else if(consumidor == 't' || consumidor == 'T'){
        valor = (1.29*consumo) + 15;
        printf("Valor total: %.2f", valor);
    }

    return 0;
}