#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

void ler_matriz(int agro[][100], int m, int n){
    int i, j;

    for(i = 0; i<m; i++){
        for(j = 0; j<n; j++){
            scanf("%d", &agro[i][j]);
        }
    }
}

void fertil(int agro[][100], int m, int n){
    int i, j, cont = 0, cont2 = 0;
    int irrigados[10][10] = {0};

    for(i = 0; i<m; i++){
        for(j = 0; j<n; j++){
            if(agro[i][j] == 2){
                if(i > 0 && i < m-1 && j > 0 && j <n-1){
                    irrigados[i-1][j] = 1;
                    irrigados[i+1][j] = 1;
                    irrigados[i][j-1] = 1;
                    irrigados[i][j+1] = 1;
                }
            }
        }
    }
    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            if(agro[i][j] == 1){
                if(irrigados[i][j] == 1){
                    cont++;
                }else{
                    cont2++;
                }
            }
        }
    }
    printf("%d %d", cont, cont2);

}

int main(){
    int m, n;
    printf("Digite o tamanho das matrizes(MXN):\n");
    scanf("%d %d", &m, &n);

    int agro[m][n];

    if(m > 0 && m <=10){
        if(n > 0 && n<=10){
            ler_matriz(agro, m, n);
            fertil(agro, m, n);
        }
    }

    return 0;
}