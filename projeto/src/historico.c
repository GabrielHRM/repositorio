#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "historico.h"

char *alocarhistorico(int tamanho){

    char *vetorhist = (char*)malloc(tamanho*sizeof(char));
    if(vetorhist == NULL){
        return NULL;
    }
    vetorhist[0] = '\0';
    return vetorhist;
}

char *adicionarhistorico(char *hist, char *entrada, int *espacousado, int *tamanho){
    int espaconecessario = *espacousado + strlen(entrada) + 2;

    if(espaconecessario > *tamanho){
        int novotamanho = *tamanho + 100;
        char *novohist = alocarhistorico(novotamanho);

        if(novohist == NULL){
            return hist;
        }

        strcpy(novohist, hist);
        free(hist);
        hist = novohist;
        *tamanho = novotamanho;
    }
    strcat(hist,entrada);
    strcat(hist, "\n");

    *espacousado = strlen(hist);

    return hist;

}

void mostrarhistorico(char *hist){
    printf("===== HISTORICO =====\n");
    printf("%s\n", hist);
}