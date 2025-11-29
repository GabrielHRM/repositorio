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

void viagem_custo(int cidade[][100], int m, int x, int z){
    int y;

    int custo_direto = cidade[x][z];
    int melhor_custo = custo_direto;
    //Força um valor para futura comparação
    int melhory = -1;

    for(y = 0; y<m; y++){
        if(y != x && y != z){
            //Custo = (CA -> CB) + (CB + CC)
            int custo = cidade[x][y] + cidade[y][z];
            //Comparação simples para saber qual custo é maior
            if(custo < melhor_custo){
                melhor_custo = custo;
                melhory = y;
            }
        }
    }

    if(melhor_custo == cidade[x][z]){
        printf("%d-%d R$%d", x, z, melhor_custo);
    }else if(melhory != -1){
        printf("%d-%d-%d R$%d", x, melhory, z, melhor_custo);
    }

    
}


int main(){
    int m, x, z;

    scanf("%d", &m);

    int viagem[m][m];
    ler_matriz(viagem, m);
    
    scanf("%d %d", &x, &z);

    viagem_custo(viagem, m, x, z);
}