#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
/*-------------------------------------*/
/*O projeto foi modularizado, então foram criadas 3 arquivos.h e 3 arquivos.c
com as respectivas funções que eram desnecessarias ficarem no aquivo main2.c
devido a poluição visual e a quantidade absurda de linhas*/
#include "matriz.h" 
#include "fatorial.h"
#include "historico.h"
#include "estrutura.h"
#include "estatistica.h"
#include "menus.h"
/*-------------------------------------*/

/*Função para processar as opções do menu principal*/
void processar_opcao(int opcao, char *hist, int *espacousado, int *tamanho){
    double resposta, resposta2;
    switch (opcao){
        case 1:
            hist = operacoesbasicas(hist, &resposta, espacousado, tamanho);
            break;
        case 2:
            hist = potenciaseraizes(hist, &resposta, espacousado, tamanho);
            break;
        case 3:
            hist = trigonometricos(hist, &resposta, espacousado, tamanho);
            break;
        case 4:
            hist = logaritimos(&resposta2, &resposta, hist, espacousado, tamanho);
            break;
        case 5:
            hist = fatorial(&resposta2, &resposta, hist, espacousado, tamanho);
            break;
        case 6:
            hist = operacao_com_matrizes(hist, espacousado, tamanho);
            break;
        case 7:
            hist = fatoracao_em_primos(hist, espacousado, tamanho);
            break;
        case 8:
            hist = operacoes_estatisticas(hist, espacousado, tamanho);
            break;
        case 9:
            mostrarhistorico(hist);
            break;
        case 10:
            hist = limparhistorico(hist);
            break;
        default:
            break;
    }
}

int main(){
    /*Tamanho inicial da alocação dinamica de memoria do historico definido por 1000,
    que será feito um produtorio de 100 em 100, para cortar a necessidade 
    de muitas alterações no tamanho. Também é para definir um tamanho 
    inicial grande o suficiente para não retornar lixo de memoria 
    caso digite uma matriz grande demais ou multiplas matrizes, já que uma matriz 
    simples double 5x5 já tem que armazenar plmns 200 bytes, fora as outras
    operações*/
    int tamanho_inicial_historico = 1000;
    /*espaço inicial ocupado pelo historico. Como inicialmente ela está vazia, 
    espacousado = 0*/
    int espacousado = 0;
    int opcao;
    //alocação dinamica do histórico
    char *historico = alocarhistorico(tamanho_inicial_historico);

    printf("Selecione uma opcao do menu principal:\n");
    /*Laço de repetição que irá perpetuar até que opção seja diferente de zero*/
    do{
        menuprincipal();
        scanf("%d", &opcao);
        /*espaço o ponteiro do histórico e os endereços de memoria 
        serão "arrastados" para as outras funções pois serão constantemente 
        atualizados conforme as operações sejam feitas*/
        processar_opcao(opcao, historico, &espacousado, &tamanho_inicial_historico);
    }while(opcao != 0);
    
    /*Liberação do espaço na memoria alocado para o historico que 
    só será feito quadno o usuario digitar 0*/
    free(historico);



    return 0;
}