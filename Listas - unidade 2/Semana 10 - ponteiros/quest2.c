#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>


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


int *buscaNoVetor(int *v, int n, int valor, int *qtd){
    int i, cont = 0, *vetor_de_indices;

    for(i = 0; i < n; i++){
        if(v[i] == valor){
            cont++;
        }
    }

    if(cont == 0){
        *qtd = 0;
        return NULL;
    }

    vetor_de_indices = alocarvetor(cont);

    if(vetor_de_indices == NULL){
        *qtd = 0;
        return NULL;
    }

    int posicao = 0;
    for(i = 0; i<n; i++){
        if(v[i] == valor){
            vetor_de_indices[posicao] = i;
            posicao++;
        }
    }

    *qtd = cont;

    return vetor_de_indices;

}

int main(){
    int n, *v, valor, qtd, *indice;
    printf("Digite a dimensão do vetor:\n");
    scanf("%d", &n);

    v = alocarvetor(n);
    lervetor(v, n);

    printf("Leia o valor a ser pesquisado:\n");
    scanf("%d", &valor);


    indice = buscaNoVetor(v, n, valor, &qtd);

    if(indice == NULL){
        printf("Nenhuma ocorrencia.");
    }else{
        printf("%d\n", qtd);

        printf("Indices:");
        for(int i = 0; i<qtd; i++){
            printf(" %d", indice[i]);
        }
        free(indice);
    }
    free(v);

    return 0;
}