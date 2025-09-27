#include <stdio.h>
#include <math.h>
#include <stdlib.h>




int main(){
    int n1, n2, n3, soma;

    printf("Digite o preco da mercadoria do primeiro e segundo fornecedor e qtde de mercadoria:\n");
    scanf("%d %d %d", &n1, &n2, &n3);

    soma = n3;

    
    for(int i = 0; i<9; i++){
        for(int j = 0; j<=9; j++){
            printf("COmprando %d do primeiro e %d do segundo, resta: %d\n", i, j, n3);
            n3 = n3 - abs(i*n1 + j*n2);
        }
    }


    return 0;
}