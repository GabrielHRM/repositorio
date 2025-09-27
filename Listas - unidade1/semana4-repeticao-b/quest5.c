#include <stdio.h>
#include <math.h>
#include <stdlib.h>



int main(){
    int n, i, j;
    printf("Digite o numero de linhas:\n");
    scanf("%d", &n);

    for(i = 1; i<=n; i++){
        for(j = 1; j<=i; j++){
            printf("%d ", j);
        }
        printf("\n");
    }


    return 0;
}