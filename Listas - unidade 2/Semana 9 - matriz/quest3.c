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

void times_empate(int matriz[][100], int m){
    int i, j;
    int empate = 0;

    for(i = 0; i<m; i++){
        for(j = i+1; j<m; j++){
            if(matriz[i][j] == matriz[j][i])
                empate++;
        }
    }
    printf("%d", empate);
}

int main(){
    int m;
    scanf("%d", &m);
    int times[m][m];

    ler_matriz(times, m);
    times_empate(times, m);


    return 0;
}