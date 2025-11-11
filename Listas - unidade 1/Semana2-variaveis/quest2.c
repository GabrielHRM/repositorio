#include <stdio.h>
#include <math.h>

int main(){
    float temp, f, k;

    printf("Digite o valor da temperatura: \n");
    scanf("%f", &temp);

    f = (temp * (9/5))+32;
    k = temp + 273.15;

    printf("Fahrenheit: %.1f\n", f);
    printf("Kelvin: %.1f\n", k);


    return 0;
}