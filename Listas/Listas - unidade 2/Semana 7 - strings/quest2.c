#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int main(){
    char placa[100];
    int valida = 1;
    int i;

    printf("Placa do carro:\n");
    fgets(placa, 9, stdin);

    int len = strlen(placa);

    //Outra forma para garantir o terminador \0 no final da string
    if(placa[len-1] == '\n')
        len--;
    
    //Placa brasileira
    if(len == 8 && placa[3] == '-'){
        for(i = 0; i < 3; i++){
            /*Verifica se a placa não faz parte do alfabeto ou não é maiuscula*/
            if(!isalpha(placa[i]) || !isupper(placa[i])){
                valida = 0;
                break;
            }
        }

        for(i = 4; i < 8; i++){
            //Verifica se não é digito
            if(!isdigit(placa[i])){
                valida = 0;
                break;
            }
        }

        if(valida){
            printf("Brasileira\n");
            return 0;
        }
    //Placa Mercosul
    }else if(len == 7){
        if(!isdigit(placa[3])){
            valida = 0;
        }
        if(!isalpha(placa[4]) || !isupper(placa[4])){
            valida = 0;
        }

        for(i = 0; i<3;i++){
            if(!isalpha(placa[i]) || !isupper(placa[i])){
                valida = 0;
                break;
            }
        }

        if(!isdigit(placa[5]) || !isdigit(placa[6])){
            valida = 0;
        }

        if(valida){
            printf("Mercosul\n");
            return 0;
        }
    }
    printf("Invalido\n");

    return 0;
}