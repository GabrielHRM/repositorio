#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

void chuvas(int vet1[]){
    int i;
    for(i = 0; i<12; i++){
        scanf("%d", &vet1[i]);
    }
}

void maior(int vet[12], char vet2[12][10]){
    int i, j, temp;
    char temp_mes[10];

    for(i = 0; i<12; i++){
        for(j = 0; j<(12-i-1); j++){
            if(vet[j] < vet[j+1]){
                temp = vet[j];
                vet[j] = vet[j+1];
                vet[j+1] = temp;

                strcpy(temp_mes, vet2[j]);
                strcpy(vet2[j], vet2[j+1]);
                strcpy(vet2[j+1], temp_mes);
                
            }
        }
    }
}

int main(){
    int chuva[12];
    char meses[12][10] = {"Janeiro", "Fevereiro", "Março", "Abril","Maio", "Junho", "Julho", "Agosto","Setembro", "Outubro", "Novembro", "Dezembro"};

    chuvas(chuva);
    maior(chuva, meses);

    for(int i=0;i<12;i++){
        printf("%s: %d\n", meses[i], chuva[i]);
    }




    return 0;
}