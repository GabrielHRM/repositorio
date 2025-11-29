#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>


int main(){
    char minado[100];
    int i, cont = 0;

    printf("Escolhas do campo minado: \n");
    fgets(minado, 20, stdin);

    int len = strlen(minado);

    printf("Indece na string: \n");
    scanf("%d", &i);

    if(minado[i] == 'x'){
        printf("BUM!!\n");
    }else{
        if(i == 0){
            if(minado[i+1] == 'x'){
                cont++;
            }
        }else if(i > 0 && i < len - 1){
            if(minado[i+1] == 'x'){
                cont++;
            }
            if(minado[i-1] == 'x'){
                cont++;
            }
        }else if(i == len - 1){
            if(minado[i] == 'x'){
                cont++;
            }
        }
    }

    printf("Numero de bombas adjacentes: %d", cont);

    return 0;
}