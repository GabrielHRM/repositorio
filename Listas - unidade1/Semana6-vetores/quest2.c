#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void figurinhas_possui(int n, int possui[]){
    int i;

    for(i = 0; i<n; i++){
        scanf("%d", &possui[i]);
    }
}


void validar_colecao(int m, int n, int possui[]){
    int i, j, encontrou;

    for(i = 1; i<=m; i++){
        encontrou = 0;

        for(j = 0; j<n; j++){
            if(possui[j] == i){
                encontrou = 1;
                break;
            }
        }
        if(encontrou == 0){
            printf("%d ", i);
        }
    }
}




int main(){
    int m, n;
    printf("Entre com os valores da qtde de figurinhas da colecao completa e as que sao possuidas: ");
    scanf("%d %d", &m, &n);

    if(m <= 1000 && n<=m){
        int possui[n];

        printf("Quais as que voce possui?\n");
        figurinhas_possui(n, possui);

        validar_colecao(m, n, possui);

    }
    
    return 0;
}