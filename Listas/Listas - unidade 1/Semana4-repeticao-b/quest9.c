#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int main(){
    int n1, n2, n3, menor_resto, im, jm;

    printf("Digite o preco da mercadoria do primeiro e segundo fornecedor e qtde de mercadoria:\n");
    scanf("%d %d %d", &n1, &n2, &n3);

    menor_resto = n3;


    for(int i = 0; i<=9; i++){
        for(int j = 0; j<=9; j++){
            int soma = i*n1 + j*n2;
            int resto = n3 - soma;
            if(resto<0){
                break;
            }if(resto < menor_resto){
                menor_resto = resto;
                im = i;
                jm = j;
            }
        }
    }
    printf("Resta menos comprando %d do primeiro e %d do segundo", im, jm);

    return 0;
}