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

void viagem(int matriz[][100], int m, int x, int z){
    int y;

    int custo_direto = matriz[x][z];
    int melhor_custo = custo_direto;
    int melhory = -1;

    for(y = 0; y<m; y++){
        if(y != x && y != z){
            int custo = matriz[x][y] + matriz[y][z];
            if(custo < melhor_custo){
                melhor_custo = custo;
                melhory = y;
            }
        }
    }

    if(melhor_custo == matriz[x][z]){
        printf("%d-%d", x, z);
    }else if(melhory != -1){
        printf("%d-%d-%d", x, y, z);
    }

    
}


int main(){
    int m, x, z;

    scanf("%d", &m);
    int viagem[m][m];
    scanf("%d %d", &x, &z);

    ler_matriz(viagem, m);
}