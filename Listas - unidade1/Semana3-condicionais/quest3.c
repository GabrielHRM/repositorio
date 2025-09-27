#include <stdio.h>
#include <math.h>

int main(){
    float n1, n2, n3, media, soma, nf;

    printf("Digite as notas: \n");
    scanf("%f %f %f", &n1, &n2, &n3);

    soma = n1+n2+n3;
    media = soma/3;

    if(media >= 7.0){
        printf("Aprovado");
    } else if(media < 4.0){
        printf("Reprovado");
    } else if(media >= 4.0 && media < 7.0){
        printf("Recuperacao\n");
        nf = 10.0 - media;
        printf("Nota final necessaria para aprovacao na recuperacao: %.1f", nf);
    }

    return 0;
}