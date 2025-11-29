#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "matriz.h"
#include "historico.h"
#include "estrutura.h"

//leitura das dimensões da matriz1 e matriz2
void ler_matriz(double *matriz, dimensao tamanho){
    int i, j;
    for(i = 0; i<tamanho.linha; i++){
        for(j = 0; j < tamanho.coluna; j++){
            scanf("%lf", &matriz[i * tamanho.coluna + j]);
        }
    }
}

/*alocação de memoria da matriz1, matriz2 e matriz resultado da soma matricial e da
subitração matricial*/
double *alocarmatriz(dimensao tamanho){
    /*Como estou alocando dinamicamente a matriz, a matriz que antes ficava
    m[0][0] fica só m[0]*/

    /*Ex: matriz 2x2: m[0][0] m[0][1] -> m[0] m[1]
                      m[1][0] m[1][1]    m[2] m[3]

    Visualmente e na memoria alocada, fica parecido com um vetor comum,
    o proprio compilador acha que é um vetor, mas ele é trabalhado
    usando os principios de matrizes, sendo, para todos os propósitos, uma matriz.*/
    double *matriz = (double*)malloc(tamanho.linha*tamanho.coluna*sizeof(double));

    if(matriz == NULL){
        return NULL;
    }

    return matriz;
}

/*alocação de memoria da matriz resultado multiplicação matricial,
já que envolve */
double *alocarmatrizmult(dimensao tamanho1, dimensao tamanho2){
    double *matriz = (double*)malloc(tamanho1.linha*tamanho2.coluna*sizeof(double));

    if(matriz == NULL){
        return NULL;
    }

    return matriz;
}

double *soma_matricial(double *matriz1, double *matriz2, dimensao tamanho1, dimensao tamanho2){
    int i, j;
    double *resultado;

    if(tamanho1.linha == tamanho2.linha && tamanho1.coluna == tamanho2.coluna){
        resultado = alocarmatriz(tamanho1);
        for(i = 0; i<tamanho1.linha; i++){
            for(j = 0; j < tamanho1.coluna; j++){
                resultado[i * tamanho1.coluna + j] = matriz1[i * tamanho1.coluna + j] + matriz2[i * tamanho1.coluna + j];
            }
        }
        return resultado;
    }
    return NULL;
}

double *subtracao_matricial(double *matriz1, double *matriz2, dimensao tamanho1, dimensao tamanho2){
    int i, j;
    double *resultado;

    if(tamanho1.linha == tamanho2.linha && tamanho1.coluna == tamanho2.coluna){
        resultado = alocarmatriz(tamanho1);
        for(i = 0; i<tamanho1.linha; i++){
            for(j = 0; j < tamanho1.coluna; j++){
                resultado[i * tamanho1.coluna + j] = matriz1[i * tamanho1.coluna + j] - matriz2[i * tamanho1.coluna + j];
            }
        }
        return resultado;
    }
    return NULL;
}


double *multiplicacao_matricial(double *matriz1, double *matriz2, dimensao tamanho1, dimensao tamanho2){
    int i, j, k;
    double *resultado;

    if(tamanho1.coluna == tamanho2.linha){
        resultado = alocarmatrizmult(tamanho1, tamanho2);

        for(i = 0; i<tamanho1.linha; i++){
            for(j = 0; j < tamanho1.coluna; j++){
                resultado[i * tamanho1.coluna + j] = 0;
            }
        }
        /*
          A lógica padrão é:  
          resultado[i][j] += m1[i][k] * m2[k][j]
          Mas, como foi alocado dinamicamente, fica: 
          resultado[i*c2+j] += m1[i*c1 + k] * m2[k*c2 + j]
        */

        for(i = 0; i<tamanho1.linha; i++){
            for(j = 0; j<tamanho2.coluna; j++){
                for(k = 0; k<tamanho1.coluna; k++){
                    //tamanho2.coluna tamanho1.coluna tamanho2.coluna
                    resultado[i * tamanho2.coluna + j] += matriz1[i * tamanho1.coluna + k] * matriz2[k * tamanho2.coluna + j];
                }
            }
        }
        return resultado;
    }
    return NULL;
}

//Função para printar a matriz resultado
void imprimir_matriz_resultado(double *matrizresultado, dimensao tamanho){
    int i, j;

    for(i = 0; i< tamanho.linha; i++){
        printf("|");
        for(j = 0; j < tamanho.coluna; j++){
            printf("%7.2lf ", matrizresultado[i * tamanho.coluna + j]);
        }
        printf("|\n");
    }
}

//Função para transformar a matriz resultado em uma string para o historico
void matriz_historico(char *entrada, double *matrizresultado, double *m1, double*m2, dimensao tamanho1, dimensao tamanho2, dimensao tamanho3, int opcao){
    int i, j;
    char matrizstr[5000];
    char resultado[50000];
    /*inicia o ponteiro entrada como uma string qualquer para
    transformar o resultado matricial em uma string para o*/
    entrada[0] = '\0';

    int max_linhas = tamanho1.linha;
    if(tamanho2.linha > max_linhas){
        max_linhas = tamanho2.linha;
    }
    if(tamanho3.linha > max_linhas){
        max_linhas = tamanho3.linha;
    }

    /*Um unico for para percorrer de uma vez, linha por linha, de cada matriz e assim formatar no 
    historico dessa forma: matriz 1 "operador" matriz 2 = matriz resultado*/
    for(i = 0; i< max_linhas; i++){
        /*Sequencia de condicionais para verificar o tamanho da coluna das 3 matrizes
        (o mesmo se aplica as outras 3 matrizes)*/
        if(i < tamanho1.linha){
            strcat(entrada, "|");
                for(j = 0; j < tamanho1.coluna; j++){
                    /*Formatação dos núemros da matriz. 7.2lf == " 100.00"
                    " 100.00" tem 7 caracteres(os numeros + o espaço antes do número)*/
                    sprintf(resultado, "%7.2lf", m1[i * tamanho1.coluna + j]);
                    strcat(entrada, resultado);
                    if(j < tamanho1.coluna - 1){
                        strcat(entrada, " ");
                }
            }
            strcat(entrada, "|");
        }else{
            //Verifica as colunas de cada matriz
            /*8 como medida de segurança para a formatação 7.2lf e 1 apenas para a formatação
            não sair desalinhada*/
            int espaco_coluna = 1 + (8 * tamanho1.coluna);
            int k;
            for(k = 0; k<espaco_coluna; k++){
                strcat(entrada, " ");
            }
        }
        

        /*Coloca o operador apenas na primeira linha lida(i = 0) e 3 espaços vazios para
        organização*/
        if(i == 0){
            switch (opcao){
                case 1:
                    strcat(entrada, " + ");
                    break;
                case 2:
                    strcat(entrada, " - ");
                    break;
                case 3:
                    strcat(entrada, " * ");
                    break;
                default:
                    break;
            }
        }else{
            strcat(entrada, "   ");
        }
        
        if(i < tamanho2.linha){
            strcat(entrada, "|");
            for(j = 0; j < tamanho2.coluna; j++){
                sprintf(resultado, "%7.2lf", m2[i * tamanho2.coluna + j]);
                strcat(entrada, resultado);
                if(j < tamanho2.coluna - 1){
                    strcat(entrada, " ");
                }
            }
            strcat(entrada, "|");
        }else{
            int espaco_coluna = 1 + (8 * tamanho2.coluna);
            int k;
            for(k = 0; k<espaco_coluna; k++){
                strcat(entrada, " ");
            }
        }

        /*Coloca o dinal de igual apenas na primeira linha lida(i = 0) e 3 espaços vazios para
        organização*/
        if(i == 0){
            strcat(entrada, " = ");
        }else{
            strcat(entrada, "   ");
        }

        if(i < tamanho3.linha){
            strcat(entrada, "|");
            for(j = 0; j < tamanho3.coluna; j++){
                sprintf(matrizstr, "%7.2lf", matrizresultado[i * tamanho3.coluna + j]);
                strcat(entrada, matrizstr);
                if(j < tamanho3.coluna - 1){
                    strcat(entrada, " ");
                }
            }
            strcat(entrada, "|");
        }else{
            int espaco_coluna = 1 + (8 * tamanho3.coluna);
            int k;
            for(k = 0; k<espaco_coluna; k++){
                strcat(entrada, " ");
            }
        }

        if(i < max_linhas - 1){
            strcat(entrada, "\n");
        }
    }
    strcat(entrada, "\n");
}