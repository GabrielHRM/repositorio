#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


void lernome(char nome[11]){

    printf("Digite o nome do aluno:\n");
    fgets(nome, 11, stdin);

    //Garante que a string tenha o terminador final \0
    int len = strlen(nome);
    if(len > 0 && nome[len-1] == '\n'){
        nome[len-1] = '\0';
    }
}

void lerfreq(char freq[1001]){
    printf("Digite a frequencia:\n");
    fgets(freq, 1001, stdin);
    
    //Garante que a string tenha o terminador final \0
    int len = strlen(freq);
    if(len > 0 && freq[len-1] == '\n'){
        freq[len-1] = '\0';
    }
}

int vericia(char nome[11], char freq[1001]){
    int presente = 0, aulas = 0;
    int len = strlen(freq);

    /*Ponterio para segimentar a string de frequencia, 
    utilizando o espaço vazio (" ") como limitador*/
    char *pres = strtok(freq, " ");


    while(pres != NULL){
        //Verifica as datas(quantidade de dias com presença registrada)
        if(strlen(pres) == 5 && pres[2] == '/'){
            if(isdigit(pres[0]) && isdigit(pres[1]) && isdigit(pres[3]) && isdigit(pres[4])){
                aulas++;
            }
        //Verifica, através da comparação entre segmentos destrings, se o aluno estav presente
        }else if(strcmp(nome, pres) == 0){
            presente++;
        }
        //É obtido o proximo segmento da string dividida
        pres = strtok(NULL, " ");
    }
    return aulas - presente;

}

int main(){
    char nome[11], freq[1001];
    int frequencia;

    lernome(nome);
    lerfreq(freq);
    frequencia = vericia(nome, freq);

    printf("Quantas vezes faltou: %d\n", frequencia);
    
    
    return 0;
}