#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

void ler_matriz(int matriz[][100], int m){
    int i, j;

    for(i = 0; i<m; i++){
        for(j = 0; j<m; j++){
            scanf("%d", &matriz[i][j]);
        }
    }
}

void sugestao(int matriz[][100], int m, int x){
    int i, j, tem_amigo;
    int sugestao[100], cont = 0;


    for(i = 0; i<m; i++){
        tem_amigo = 0;
        if(i!=x && matriz[x][i] == 0){
            for(j = 0; j<m; j++){
                if(matriz[x][j] == 1 && matriz[i][j] == 1){
                    tem_amigo = 1;
                    break;
                }
            }
            if(tem_amigo){
                sugestao[cont] = i;
                cont++;
            }  
        } 
    }
    for(i = 0; i<m; i++){
        for(j = 0; j<(cont - i - 1); j++){
            if(sugestao[j] > sugestao[j+1]){
                int temp = sugestao[j];
                sugestao[j] = sugestao[j+1];
                sugestao[j+1] = temp;
            }
        }
    }

    for(i = 0; i<cont; i++){
        printf("%d ", sugestao[i]);
    }
    
}


int main(){
    int m, x;
    printf("Sugestão e tamanho da matriz:\n");
    scanf("%d %d", &x, &m);
    int amizade[m][m];

    ler_matriz(amizade, m);
    sugestao(amizade, m, x);


    return 0;
}