#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void enem(int n, int resposta[]){
    int i = 0;

    for(i=0; i<n; i++){
        scanf("%d", &resposta[i]);
    }
}

void verificaresposta(int n, int resposta[], int gabarito[]){
    int i, cont = 0;

    for(i = 0; i<n; i++){
        if(resposta[i] == gabarito[i]){
            cont++;
        }
    }
    printf("Acertos: %d", cont);
}


int main(){
    int n;
    printf("Entre com o numero de questoes:\n");
    scanf("%d", &n);

    if(n>=1 && n<=20){
        int resposta[n], gabarito[n];
        printf("Digite o gabarito:\n");
        enem(n, gabarito);

        printf("Digite a resposta do aluno:\n");
        enem(n, resposta);
        
        verificaresposta(n, resposta, gabarito);

    }

    return 0;
}