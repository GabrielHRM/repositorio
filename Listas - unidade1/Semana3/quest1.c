#include <stdio.h>
#include <math.h>

int main(){
    float peso, altura, imc;

    printf("Digite a altura e o peso: \n");
    scanf("%f %f", &peso, &altura);

    imc = peso/pow(altura,2);
    if(imc < 18.5){
        printf("Abaixo do peso");
    } else if(imc >= 18.5 && imc <=24.9){
        printf("Peso normal");
    } else if(imc >= 25.0 && imc <= 29.9){
        printf("Sobrepeso");
    } else{
        printf("Obesidade");
    }

    return 0;
}