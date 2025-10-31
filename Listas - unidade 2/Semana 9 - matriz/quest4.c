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


int main(){
    
}