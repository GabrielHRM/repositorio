#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>


void ler_vet(int vet[], int n){
    int i;
    for(i = 0; i<n; i++){
        scanf("%d", &vet[i]);
    }
}

void posicao(int vet1[], int vet2[], int n){
    int i, j, pos_largada = 0, pos_chegada = 0, maior_ganho = 0, ganho, pos_vencedor, empate;

    for(i = 1; i<=n; i++){
        for(j = 0; j < n; j++){
            if(vet1[j] == i){
                pos_largada = j+1;
                break;
            }
        }
        for(j = 0; j < n; j++){
            if(vet2[j] == i){
                pos_chegada = j+1;
                break;
            }
        }

        ganho = pos_largada - pos_chegada;

        if(ganho > maior_ganho){
            maior_ganho = ganho;
            pos_vencedor = i;
            empate = 0;
        }else if(ganho == maior_ganho && ganho >0){
            empate = 1;
        }
    }

    if(maior_ganho <=0 || empate){
        printf("Empate\n");
    }else{
        printf("%d\n", pos_vencedor);
    }
    
}

int main(){
    int n;
    printf("Digite o numero de participantes:\n");
    scanf("%d", &n);

    int largada[n], chegada[n]; 

    if(n>=1 && n<=20){
        ler_vet(largada, n);
        ler_vet(chegada, n);
        posicao(largada, chegada, n);
    }



    return 0;
}