#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

void lernome(char nome[101]){

    fgets(nome, 101, stdin);

    int len = strlen(nome);
    if(len > 0 && nome[len-1] == '\n'){
        nome[len-1] = '\0';
    }
}


char *alocarstr(int tamanho){
    char *vetor = (char*)malloc(tamanho*sizeof(char));

    return vetor;
}

char *misturar(char *str1, char *str2){
    int i = 0, j = 0, k = 0, str3len = (strlen(str1) + strlen(str2) + 1);
    char *str3 = alocarstr(str3len);
    
    while(str1[i] != '\0' || str2[j] != '\0'){
        if(str1[i] != '\0'){
            str3[k] = str1[i];
            k++;
            i++;
        }
        if(str2[j] != '\0'){
            str3[k] = str2[j];
            k++;
            j++; 
        }
    }
    str3[k] = '\0';
    return str3;
}

int main(){
    char str1[101], str2[101], *str3;

    printf("Leia a primeira string:\n");
    lernome(str1);
    printf("Leia a segunda string:\n");
    lernome(str2);

    str3 = misturar(str1, str2); 
    printf("Resultado: %s\n", str3);

    free(str3);


    return 0;
}