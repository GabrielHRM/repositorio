#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>



int main(){
    int m, n, cont = 0, i, j;

    printf("Digite os valores de m e n:\n");
    scanf("%d %d", &m, &n);

    int sorteado[m], apostados[n];

    if(m>=1 && m<=30){
        if(n>=m && n<=50){
            for(i = 0; i < m; i++){
                scanf("%d", &sorteado[i]);
            }
            for(i = 0; i<n; i++){
                scanf("%d", &apostados[i]);
            }

            for(i = 0; i<m; i++){
                for(j = 0; j<n; j++){
                    if(apostados[j] == sorteado[i]){
                        cont++;
                    }
                }
            }
        }
    }

    printf("Numeros iguais: %d\n", cont);

    return 0;
}