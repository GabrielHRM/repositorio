#include <stdio.h>
#include <math.h>
#include <stdlib.h>


void ler_alturas_terreno(int n, int altura[]){
    int i;

    for(i = 0; i<n; i++){
        scanf("%d", &altura[i]);
    }
}

int altura_max(int n, int altura[]){
    int i, alturamax = altura[0];

    for(i = 1; i<n; i++){
        if(altura[i] > alturamax){
            alturamax = altura[i];
        }
    }
    return alturamax;
}


int ocorrencia(int n, int altura[], int altura_max){
    int i, pos[2], dist, cont = 0;

    for(i = 0; i<n; i++){
        if(altura_max == altura[i]){
            pos[cont] = i;
            cont++;
        }
    }

    dist = abs(pos[1] - pos[0] - 1);

    return dist;
}

int main(){
    int n, altmax, dist;

    printf("Leia o qtde de alturas:\n");
    scanf("%d", &n);

    if(n <= 30 && n>0){
        int altura[n];
        ler_alturas_terreno(n, altura);

        altmax = altura_max(n, altura);

        dist = ocorrencia(n, altura, altmax);

        printf("Distancia: %d", dist);

    }

    return 0;
}