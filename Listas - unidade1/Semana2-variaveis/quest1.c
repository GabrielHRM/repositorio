#include <stdio.h>
#include <math.h>

int main(){
    float peso, altura, imc;

    printf("Digite a altura e o peso: \n");
    scanf("%f %f", &peso, &altura);

    imc = peso/pow(altura,2);
    printf("O IMC eh: %.2f", imc);

    return 0;
}