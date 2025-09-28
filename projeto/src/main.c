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
    }else if(categU == 5){
        printf("====|CONVERSOR DE VELOCIDADE|====\n");
        printf("1. Metro por segundo(m/s)\n2. Quilometro por hora(km/h)\n");
        printf("3. Milha por hora(mhp)\n4. Milha nautica por hora(knot)\n");
    }
}

int max_unidades(int categU){
    if(categU == 1){
        return 9;
    }else if(categU == 2){
        return 8;
    }else if(categU == 3){
        return 3;
    }else if(categU == 4){
        return 5;
    }else if(categU == 5){
        return 4;
    }
}

double lervalor(){
    double valor;
    printf("Digite o valor que vai ser convertido:\n");
    scanf("%f", &valor);

    return valor;
}

double lerUnidadeDe(){
    double unidadede;
    printf("Converter de(escolha um numero das opcoes de conversao):\n");
    scanf("%f", &unidadede);

    return unidadede;
}

double lerUnidadePara(){
    double unidadepara;
    printf("Para(escolha um numero das opcoes de conversao):\n");
    scanf("%f", &unidadepara);

    return unidadepara;
}

int validar_unidade(int categU, int unidadede, int unidadepara){
    int maxunidades = max_unidades(categU);

    if(unidadede<1 || unidadede>maxunidades){
        printf("Unidade invalida. Digite uma opcao valida.\n");
        return 0;
    }
    return 1;
}


double converterComprimento(int valor_base, int de, int para){
    double fatores[9] = {1.0, 1000.0, 100.0, 10.0, 0.01, 0.001, 0.3048, 0.0254, 1.609};
    char m[4] = "m";
    char km[4] = "km";
    char hm[4] = "hm";
    char dam[4] = "dam";
    char cm[4] = "cm";
    char mm[4] = "mm";
    char ft[4] = "ft";
    char in[4] = "in";
    char mi[4] = "mi";

    double metros = valor_base * fatores[de-1];

    double resultado = metros / fatores[para-1];

    if(de == 1){
        printf("Resultado: %.4f %s para ", valor_base, m);
    }else if(de == 2){
        printf("Resultado: %.4f %s para ", valor_base, km);
    }else if(de == 3){
        printf("Resultado: %.4f %s para ", valor_base, hm);
    }else if(de == 4){
        printf("Resultado: %.4f %s para ", valor_base, dam);
    }else if(de == 5){
        printf("Resultado: %.4f %s para ", valor_base, cm);
    }else if(de == 6){
        printf("Resultado: %.4f %s para ", valor_base, mm);
    }else if(de == 7){
        printf("Resultado: %.4f %s para ", valor_base, ft);
    }else if(de == 8){
        printf("Resultado: %.4f %s para ", valor_base, in);
    }else if(de == 9){
        printf("Resultado: %.4f %s para ", valor_base, mi);
    }


    if(para == 1){
        printf("%4.f %s", resultado, m);
    }else if(para == 2){
        printf("%4.f %s", resultado, km);
    }else if(para == 3){
        printf("%4.f %s", resultado, hm);
    }else if(para == 4){
        printf("%4.f %s", resultado, dam);
    }else if(para == 5){
        printf("%4.f %s", resultado, cm);
    }else if(para == 6){
        printf("%4.f %s", resultado, mm);
    }else if(para == 7){
        printf("%4.f %s", resultado, ft);
    }else if(para == 8){
        printf("%4.f %s", resultado, in);
    }else if(para == 9){
        printf("%4.f %s", resultado, mi);
    }


    return resultado;
}

double converterMassa(int valor_base, int de, int para){
    double fatores[8] = {1.0, 1000.0, 100.0, 10.0, 0.01, 0.001, 0.453592, 0.0283495};
    char g[4] = "g";
    char kg[4] = "kg";
    char hg[4] = "hg";
    char dag[4] = "dag";
    char cg[4] = "cg";
    char mg[4] = "mg";
    char lb[4] = "lb";
    char oz[4] = "oz";

    double metros = valor_base * fatores[de-1];

    double resultado = metros / fatores[para-1];

    if(de == 1){
        printf("Resultado: %.4f %s para ", valor_base, g);
    }else if(de == 2){
        printf("Resultado: %.4f %s para ", valor_base, kg);
    }else if(de == 3){
        printf("Resultado: %.4f %s para ", valor_base, hg);
    }else if(de == 4){
        printf("Resultado: %.4f %s para ", valor_base, dag);
    }else if(de == 5){
        printf("Resultado: %.4f %s para ", valor_base, cg);
    }else if(de == 6){
        printf("Resultado: %.4f %s para ", valor_base, mg);
    }else if(de == 7){
        printf("Resultado: %.4f %s para ", valor_base, lb);
    }else if(de == 8){
        printf("Resultado: %.4f %s para ", valor_base, oz);
    }


    if(para == 1){
        printf("%4.f %s", resultado, g);
    }else if(para == 2){
        printf("%4.f %s", resultado, kg);
    }else if(para == 3){
        printf("%4.f %s", resultado, hg);
    }else if(para == 4){
        printf("%4.f %s", resultado, dag);
    }else if(para == 5){
        printf("%4.f %s", resultado, cg);
    }else if(para == 6){
        printf("%4.f %s", resultado, mg);
    }else if(para == 7){
        printf("%4.f %s", resultado, lb);
    }else if(para == 8){
        printf("%4.f %s", resultado, oz);
    }


    return resultado;
}

double converterTeperatura(int valor_base, int de, int para){
    double resultado;
    double celsius;

    char c[4] = "°C";
    char f[4] = "°F";
    char k[4] = "K";

    /*Transformando o valor base, que é um numero qualquer, 
    em sua versão em celsius apartir de uma formula direta
    como base na opçcao escolhida pelo usuario*/
    if(de == 1){
        celsius = valor_base;
    }else if(de == 2){
        celsius = (valor_base - 32) * (5.0/9.0);
    }else if(de == 3){
        celsius = valor_base - 273.15;
    }

    /*Em seguida o valor base, que foi transofrmado em celsius, é convertido 
    para a versão da temperatura cuja qual o usuario deseja converter 
    seguindo uma formula matematica direta
    como base na opçcao escolhida pelo usuario*/

    printf("De %f para ", valor_base);

    if(para == 1){
        resultado = celsius;
        printf("%4.f %s", resultado, c);
    }else if(para == 2){
        resultado = (celsius * (9.0/5.0)) + 32;
        printf("%4.f %s", resultado, f);
    }else if(para == 3){
        resultado = celsius + 273.15;
        printf("%4.f %s", resultado, k);
    }


    return resultado;
}

double converterVolume(int valor_base, int de, int para){
    double fatores[5] = {1.0, 1000.0, 100.0, 10.0, 0.01, 0.001, 0.453592, 0.0283495};
    char g[4] = "g";
    char kg[4] = "kg";
    char hg[4] = "hg";
    char dag[4] = "dag";
    char cg[4] = "cg";
    char mg[4] = "mg";
    char lb[4] = "lb";
    char oz[4] = "oz";

    double metros = valor_base * fatores[de-1];

    double resultado = metros / fatores[para-1];

    if(de == 1){
        printf("Resultado: %.4f %s para ", valor_base, g);
    }else if(de == 2){
        printf("Resultado: %.4f %s para ", valor_base, kg);
    }else if(de == 3){
        printf("Resultado: %.4f %s para ", valor_base, hg);
    }else if(de == 4){
        printf("Resultado: %.4f %s para ", valor_base, dag);
    }else if(de == 5){
        printf("Resultado: %.4f %s para ", valor_base, cg);
    }else if(de == 6){
        printf("Resultado: %.4f %s para ", valor_base, mg);
    }else if(de == 7){
        printf("Resultado: %.4f %s para ", valor_base, lb);
    }else if(de == 8){
        printf("Resultado: %.4f %s para ", valor_base, oz);
    }


    if(para == 1){
        printf("%4.f %s", resultado, g);
    }else if(para == 2){
        printf("%4.f %s", resultado, kg);
    }else if(para == 3){
        printf("%4.f %s", resultado, hg);
    }else if(para == 4){
        printf("%4.f %s", resultado, dag);
    }else if(para == 5){
        printf("%4.f %s", resultado, cg);
    }else if(para == 6){
        printf("%4.f %s", resultado, mg);
    }else if(para == 7){
        printf("%4.f %s", resultado, lb);
    }else if(para == 8){
        printf("%4.f %s", resultado, oz);
    }


    return resultado;
}

int main(){
    int opcao;

    printf("============|CONVERSOR DE UNIDADES|============\n");
    printf("====|Bem-vindo ao seu sitema de conversao|=====\n");
    printf("\n");
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