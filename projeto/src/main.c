#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void menuprincipal(){
    printf("Escolha qual o tipo de conversao eh desejada ou digite 0 para sair:\n");
    printf("1. Comprimento\n");
    printf("2. Massa\n");
    printf("3. Temperatura\n");
    printf("4. Volume\n");
    printf("5. Velocidade\n");
    printf("0. Sair\n");
}

void menunidade(int categU){
    if(categU == 1){
        printf("====|CONVERSOR DE COMPRIMENTO|====\n");
        printf("1. Metro\n2. Quilometro\n3. Hectometro\n4. Decametro\n");
        printf("5. Centimetro\n6. Milimetro\n7. Pe(ft)\n8. Polegada\n9. Milha");
    }else if(categU == 2){
        printf("====|CONVERSOR DE MASSA|====\n");
        printf("1. Grama\n2. Quilograma\n3. Hectograma\n4. Decagrama\n");
        printf("5. Centigrama\n6. Miligrama\n7. Libra\n8. Once\n");
    }else if(categU == 3){
        printf("====|CONVERSOR DE TEMPERATURA|====\n");
        printf("1. Celsius\n2. Fahrenheit\n3. Kelvin\n");
    }else if(categU == 4){
        printf("====|CONVERSOR DE VOLUME|====\n");
        printf("1. Litro\n2. Decilitro\n3. Metro cubico\n4. Mililitro\n");
        printf("5. Galao\n");
    }else if(categU){
        printf("====|CONVERSOR DE VELOCIDADE|====\n");
        printf("1. Metro por segundo(m/s)\n2. Quilometro por hora(km/h)\n");
        printf("4. Milha por hora(mhp)\n6. Milha nautica por hora(knot)\n");
    }
}

int main(){
    int opcao;

    printf("============|CONVERSOR DE UNIDADES|============\n");
    printf("====|Bem-vindo ao seu sitema de conversao|=====\n");

    do{
        menuprincipal();
        scanf("%d", &opcao);

        if(opcao == 0){
            printf("Obrigado por usar o conversor! Ate mais!\n");
            break;
        }

        if(opcao < 1 || opcao >5){
            printf("Opcao invalida! Tente novamente.\n");
            continue;
        }
    }while(1);




    return 0;
}