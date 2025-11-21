#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "historico.h"

/*Alocação dinamica de memoria da string de histórico*/
char *alocarhistorico(int tamanho){ 

    char *vetorhist = (char*)malloc(tamanho*sizeof(char));

    /*Retorna NULL caso não haja espaço na memoria ram para aumentar o tamanho*/
    if(vetorhist == NULL){
        return NULL;
    }

    /*Inicia o primeiro byte do historico com um espaço
    de memoria previamente alocado como \0, já que eu criei um ponteiro para um
    endereço de memoria contendo lixo, não a string propriamente dita*/
    vetorhist[0] = '\0';
    return vetorhist;
}

char *adicionarhistorico(char *hist, char *entrada, int *espacousado, int *tamanho){
    //espaço necessário do histórico para cada operação realizada
    /*algoritmo: espaço necessario = espaço já usado + tamanho da operação realizada
    + 2(\n e \0)*/
    int espaconecessario = *espacousado + strlen(entrada) + 2;

    /*Se o espaço necessário é maior que o tamanho atual do histórico,
    então faz uma multiplicação de 100 em 100 e cria o ponteiro novohist com
    o tamanho atualizado, sendo esse novohist o historico com o novo tamanho*/
    if(espaconecessario > *tamanho){
        int novotamanho = *tamanho * 100;
        char *novohist = alocarhistorico(novotamanho);

        /*Se não houver mais espaço na memoria ram para mais operações, é retornado
        o historico independentemente se houver ou não novas operações devido às 
        limitações na minha maquina, no meu caso são 16 gigas ou aproximadamente 
        17.18 Bilhões de bytes*/
        if(novohist == NULL){
            return hist;
        }

        /*Copia o conteudo antigo do histórico com o tamanho antigo
        para o histórico com tamanho novo, libera o espaço de memoria alocado
        anteriormente redefine o novo tamanho do histórico*/
        strcpy(novohist, hist);
        free(hist);
        hist = novohist;
        /*Atualiza o valor da variável tamanho para o valor da
        variavel novo tamanho, pelo endereço de memoria da variável tamanho*/
        *tamanho = novotamanho;
    }

    /*Por fim, concatena a string das operações realizadas ao histórico + uma 
    quebra de linha e o espaço usado atual do histórico é redefinido com o 
    novo tamanho*/
    strcat(hist,entrada);
    strcat(hist, "\n");

    *espacousado = strlen(hist);

    return hist;

}

//Limpa o histórico colocando o valor inicial do histórico como \0
char *limparhistorico(char *hist){
    hist[0] = '\0';

    return hist;
}

//Printao histórico
void mostrarhistorico(char *hist){
    printf("===== HISTORICO =====\n");
    printf("%s\n", hist);
}