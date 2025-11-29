#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

//Função para alocação dinamica de memoria
int *alocarvetor(int tamanho){
    int *vetor = (int*)malloc(tamanho*sizeof(int));

    return vetor;
}

void lervetor(int *vet, int tamanho){
    int i;
    for(i = 0; i<tamanho; i++){
        scanf("%d", &vet[i]);
    }
}


int *somavetorial(int *u, int *v, int n1, int n2){
    int *soma, i;
    if(n1 != n2){
        return NULL;
    }
    soma = alocarvetor(n1);

    for(i = 0; i<n1; i++){
        soma[i] = v[i] + u[i];
    }

    return soma;
}

int main(){
    int n1, n2, *u, *v, *soma;
    printf("Digite as dimensões dos vetores:\n");
    scanf("%d %d", &n1, &n2);

    u = alocarvetor(n1);
    v = alocarvetor(n2);

    lervetor(u, n1);
    lervetor(v, n2);

    soma = somavetorial(u, v, n1, n2);

    if(soma == NULL){
        printf("Dimensoes indisponiveis.");
    }else{ 
        printf("Resultado:");
        for(int i = 0; i<n1; i++){
            printf(" %d", soma[i]);
        }
        //Libera o espaço de memoria alocado para o vetor resultado
        free(soma);
    }

    //Libera o espaço de memoria alocado para os 2 vetores da opração
    free(u);
    free(v);
    

    return 0;
}