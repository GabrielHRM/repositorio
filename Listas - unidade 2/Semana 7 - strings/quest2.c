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
    fgets(placa, 8, stdin);

    int len = strlen(placa);
    printf("%d\n", len);
    
    if(len == 8 && placa[3] == '-'){
        for(i = 0; i < 3; i++){
            if(!isalpha(placa[i]) || !isupper(placa[i])){
                valida = 0;
                break;
            }
        }

        for(i = 4; i < 8; i++){
            if(!isdigit(placa[i])){
                valida = 0;
                break;
            }
        }

        if(valida){
            printf("Brasileira\n");
        }
    }

    return 0;
}