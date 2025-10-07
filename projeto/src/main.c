#include <stdio.h>
#include <stdlib.h>

void MenuPrincipal(){
    //Função para a tela principal de conversões e a opção de sair
    printf("Escolha qual o tipo de conversao eh desejada ou digite 0 para sair:\n");
    printf("1. Comprimento\n");
    printf("2. Massa\n");
    printf("3. Temperatura\n");
    printf("4. Volume\n");
    printf("5. Velocidade\n");
    printf("6. Tempo\n");
    printf("7. Area\n");
    printf("0. Sair\n");
}

void MenuDeUnidades(int categU){
    //Menu de cada unidade de medida e as opções de conversão dentro delas
    if(categU == 1){
        printf("====|CONVERSOR DE COMPRIMENTO|====\n");
        printf("1. Metro\n2. Quilometro\n3. Hectometro\n4. Decametro\n");
        printf("5. Centimetro\n6. Milimetro\n7. Pe(ft)\n8. Polegada\n9. Milha\n");
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
    }else if(categU == 6){
        printf("====|CONVERSOR DE TEMPO|====\n");
        printf("1. Segundo\n2. Minuto\n3. Hora\n");
        printf("4. Dia\n5. Mes\n6. Ano\n");
    }else if(categU == 7){
        printf("====|CONVERSOR DE AREA|====\n");
        printf("1. Metro quadrado\n2. Quilometro quadrado\n");
        printf("3. Centimetro quadrado\n4. Milimetro quadrado\n");
        printf("5. Hectare\n6. Acre\n7. Pe quadrado\n");
        printf("8. Polegada quadrada\n9. Milha quadrada\n");
    }
}

int max_unidades(int categU){
    /*Função criada para retornar a quantidade de medidas dentro de uma 
    categoria de unidade de medida*/
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
    }else if(categU == 6){
        return 6;
    }else if(categU == 7){
        return 9;
    }
    return 0;
}

double lervalor(){
    //Função que vai ler o valor digitdado pelo usuario que será convertido
    double valor;
    printf("Digite o valor(numero real qualquer) que vai ser convertido:\n");
    scanf("%lf", &valor);

    return valor;
}

/*As funções LerUnidadeDe e lerUnidadePara estão no contexto de:
de Metro para Kilometro, Litro para Galão, ect. Ou seja, a unidade
ao qual deseja-se começar e a unidade para o qual o valor resultante, que
é baseado no valor de partida, será convertido.*/

int lerUnidadeDe(){
    //Função que vai ler o valor da opção de conversão de partida, com base nas categorias de conversão
    int unidadede;
    printf("Converter de(escolha um numero das opcoes de conversao):\n");
    scanf("%d", &unidadede);

    return unidadede;
}

int lerUnidadePara(){
    //Valor para o qual o valor será convertido, dependendo da opção de partida
    int unidadepara;
    printf("Para(escolha um numero das opcoes de conversao):\n");
    scanf("%d", &unidadepara);

    return unidadepara;
}

int validar_unidade(int categU, int unidadede, int unidadepara){
    /*Função para a validação das unidades escolhidas:
    se elas estão dentro dos valores possiveis de serem escolhidos,
    diferentes de zero, para conversão*/
    int maxunidades = max_unidades(categU);

    if(unidadede<1 || unidadede>maxunidades || unidadepara < 1 || unidadepara>maxunidades){
        printf("Unidade invalida. Digite uma opcao valida.\n");
        return 0;
    }
    return 1;
}

/*As proximas 7 funções seguem o mesmo padrão logico para conversão:
como o valor inicial digitado pelo usuario não tem, inicialmente, qualquer valor de
unidade, sendo apenas um número real(double) qualquer,
então é necessario converte-lo em um valor base para ser,
então, convertidos aos demais. Em comprimento o metro é o valor base, em massa grama,
em temperatura o celsius e assim vai. Todos inicialmente convertidos seguindo o SI.*/

double converterComprimento(double valor_base, int de, int para){
    /*Utilização de vetores para caracteres e valores em double para
    facilitar calculo das medidas e manter a função menos poluida*/
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

    /*Valor inicial calculado como o produto do valor digitado pelo usuario
    pelo fator de conversão apontado pela variavel de
    (com base na função que a define)*/
    double metros = valor_base * fatores[de-1];

    /*Resultado final calculado como o quociente do valor incial encontrado anteriormente
    pelo fator de conversão apontado pela variavel para(com base na função que a define)*/
    double resultado = metros / fatores[para-1];

    //Quem será convertido e sua unidade
    if(de == 1){
        printf("Resultado: %.4lf %s para ", valor_base, m);
    }else if(de == 2){
        printf("Resultado: %.4lf %s para ", valor_base, km);
    }else if(de == 3){
        printf("Resultado: %.4lf %s para ", valor_base, hm);
    }else if(de == 4){
        printf("Resultado: %.4lf %s para ", valor_base, dam);
    }else if(de == 5){
        printf("Resultado: %.4lf %s para ", valor_base, cm);
    }else if(de == 6){
        printf("Resultado: %.4lf %s para ", valor_base, mm);
    }else if(de == 7){
        printf("Resultado: %.4lf %s para ", valor_base, ft);
    }else if(de == 8){
        printf("Resultado: %.4lf %s para ", valor_base, in);
    }else if(de == 9){
        printf("Resultado: %.4lf %s para ", valor_base, mi);
    }

    //O valor convertido e sua nova unidade
    if(para == 1){
        printf("%.4lf %s", resultado, m);
    }else if(para == 2){
        printf("%.4lf %s", resultado, km);
    }else if(para == 3){
        printf("%.4lf %s", resultado, hm);
    }else if(para == 4){
        printf("%.4lf %s", resultado, dam);
    }else if(para == 5){
        printf("%.4lf %s", resultado, cm);
    }else if(para == 6){
        printf("%.4lf %s", resultado, mm);
    }else if(para == 7){
        printf("%.4lf %s", resultado, ft);
    }else if(para == 8){
        printf("%.4lf %s", resultado, in);
    }else if(para == 9){
        printf("%.4lf %s", resultado, mi);
    }

    return resultado;
}

double converterMassa(double valor_base, int de, int para){
    double fatores[8] = {1.0, 1000.0, 100.0, 10.0, 0.01, 0.001, 0.453592, 0.0283495};
    char g[4] = "g";
    char kg[4] = "kg";
    char hg[4] = "hg";
    char dag[4] = "dag";
    char cg[4] = "cg";
    char mg[4] = "mg";
    char lb[4] = "lb";
    char oz[4] = "oz";

    double grama = valor_base * fatores[de-1];

    double resultado = grama / fatores[para-1];

    if(de == 1){
        printf("Resultado: %.4lf %s para ", valor_base, g);
    }else if(de == 2){
        printf("Resultado: %.4lf %s para ", valor_base, kg);
    }else if(de == 3){
        printf("Resultado: %.4lf %s para ", valor_base, hg);
    }else if(de == 4){
        printf("Resultado: %.4lf %s para ", valor_base, dag);
    }else if(de == 5){
        printf("Resultado: %.4lf %s para ", valor_base, cg);
    }else if(de == 6){
        printf("Resultado: %.4lf %s para ", valor_base, mg);
    }else if(de == 7){
        printf("Resultado: %.4lf %s para ", valor_base, lb);
    }else if(de == 8){
        printf("Resultado: %.4lf %s para ", valor_base, oz);
    }


    if(para == 1){
        printf("%.4lf %s", resultado, g);
    }else if(para == 2){
        printf("%.4lf %s", resultado, kg);
    }else if(para == 3){
        printf("%.4lf %s", resultado, hg);
    }else if(para == 4){
        printf("%.4lf %s", resultado, dag);
    }else if(para == 5){
        printf("%.4lf %s", resultado, cg);
    }else if(para == 6){
        printf("%.4lf %s", resultado, mg);
    }else if(para == 7){
        printf("%.4lf %s", resultado, lb);
    }else if(para == 8){
        printf("%.4lf %s", resultado, oz);
    }


    return resultado;
}

double converterTeperatura(double valor_base, int de, int para){
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
        printf("%.4lf %s", resultado, c);
    }else if(para == 2){
        resultado = (celsius * (9.0/5.0)) + 32;
        printf("%.4lf %s", resultado, f);
    }else if(para == 3){
        resultado = celsius + 273.15;
        printf("%.4lf %s", resultado, k);
    }


    return resultado;
}

double converterVolume(double valor_base, int de, int para){
    double fatores[5] = {1.0, 0.1, 1000.0, 0.001, 3.785};
    char l[4] = "L";
    char dl[4] = "dL";
    char m3[4] = "m³";
    char ml[4] = "ml";
    char gal[4] = "gal";

    double litro = valor_base * fatores[de-1];

    double resultado = litro / fatores[para-1];

    if(de == 1){
        printf("Resultado: %.4lf %s para ", valor_base, l);
    }else if(de == 2){
        printf("Resultado: %.4lf %s para ", valor_base, dl);
    }else if(de == 3){
        printf("Resultado: %.4lf %s para ", valor_base, m3);
    }else if(de == 4){
        printf("Resultado: %.4lf %s para ", valor_base, ml);
    }else if(de == 5){
        printf("Resultado: %.4lf %s para ", valor_base, gal);
    }


    if(para == 1){
        printf("%.4lf %s", resultado, l);
    }else if(para == 2){
        printf("%.4lf %s", resultado, dl);
    }else if(para == 3){
        printf("%.4lf %s", resultado, m3);
    }else if(para == 4){
        printf("%.4lf %s", resultado, ml);
    }else if(para == 5){
        printf("%.4lf %s", resultado, gal);
    }


    return resultado;
}

double converterVelocidae(double valor_base, int de, int para){
    double fatores[4] = {1.0, 0.2780, 0.4470, 0.5144};
    char ms[6] = "m/s";
    char kmh[6] = "km/h";
    char mhp[6] = "mhp";
    char no[6] = "knot";

    double velocidade = valor_base * fatores[de-1];

    double resultado = velocidade / fatores[para-1];

    if(de == 1){
        printf("Resultado: %.4lf %s para ", valor_base, ms);
    }else if(de == 2){
        printf("Resultado: %.4lf %s para ", valor_base, kmh);
    }else if(de == 3){
        printf("Resultado: %.4lf %s para ", valor_base, mhp);
    }else if(de == 4){
        printf("Resultado: %.4lf %s para ", valor_base, no);
    }


    if(para == 1){
        printf("%.4lf %s", resultado, ms);
    }else if(para == 2){
        printf("%.4lf %s", resultado, kmh);
    }else if(para == 3){
        printf("%.4lf %s", resultado, mhp);
    }else if(para == 4){
        printf("%.4lf %s", resultado, no);
    }

    return resultado;
}

double converterArea(double valor_base, int de, int para){
    double fatores[9] = {1.0, 1000000.0, 0.0001, 0.000001, 10000.0, 4046.86, 0.092903, 0.00064516, 2589988.11};

    char m2[4] = "m²";
    char km2[4] = "km²";
    char cm2[4] = "cm²";
    char mm2[4] = "mm²";
    char hectare[4] = "ha";
    char acre[4] = "ac";
    char ft2[4] = "ft²";
    char in2[4] = "in²";
    char mi2[4] = "mi²";

    double metros2 = valor_base * fatores[de-1];

    double resultado = metros2 / fatores[para-1];

    if(de == 1){
        printf("Resultado: %.4lf %s para ", valor_base, m2);
    }else if(de == 2){
        printf("Resultado: %.4lf %s para ", valor_base, km2);
    }else if(de == 3){
        printf("Resultado: %.4lf %s para ", valor_base, cm2);
    }else if(de == 4){
        printf("Resultado: %.4lf %s para ", valor_base, mm2);
    }else if(de == 5){
        printf("Resultado: %.4lf %s para ", valor_base, hectare);
    }else if(de == 6){
        printf("Resultado: %.4lf %s para ", valor_base, acre);
    }else if(de == 7){
        printf("Resultado: %.4lf %s para ", valor_base, ft2);
    }else if(de == 8){
        printf("Resultado: %.4lf %s para ", valor_base, in2);
    }else if(de == 9){
        printf("Resultado: %.4lf %s para ", valor_base, mi2);
    }


    if(para == 1){
        printf("%.4lf %s", resultado, m2);
    }else if(para == 2){
        printf("%.4lf %s", resultado, km2);
    }else if(para == 3){
        printf("%.4lf %s", resultado, cm2);
    }else if(para == 4){
        printf("%.4lf %s", resultado, mm2);
    }else if(para == 5){
        printf("%.4lf %s", resultado, hectare);
    }else if(para == 6){
        printf("%.4lf %s", resultado, acre);
    }else if(para == 7){
        printf("%.4lf %s", resultado, ft2);
    }else if(para == 8){
        printf("%.4lf %s", resultado, in2);
    }else if(para == 9){
        printf("%.4lf %s", resultado, mi2);
    }


    return resultado;
}

double converterTempo(double valor_base, int de, int para){
    double fatores[7] = {1.0, 60.0, 3600.0, 86400.0, 604800.0, 2592000.0, 31536000.0};

    char s[12] = "segundo(s)";
    char m[12] = "minuto(s)";
    char h[12] = "hora(s)";
    char d[12] = "dia(s)";
    char se[12] = "semana(s)";
    char me[12] = "Mes(es)";
    char an[12] = "Ano(s)";

    double tempo = valor_base * fatores[de-1];

    double resultado = tempo / fatores[para-1];

    if(de == 1){
        printf("Resultado: %.4lf %s para ", valor_base, s);
    }else if(de == 2){
        printf("Resultado: %.4lf %s para ", valor_base, m);
    }else if(de == 3){
        printf("Resultado: %.4lf %s para ", valor_base, h);
    }else if(de == 4){
        printf("Resultado: %.4lf %s para ", valor_base, d);
    }else if(de == 5){
        printf("Resultado: %.4lf %s para ", valor_base, se);
    }else if(de == 6){
        printf("Resultado: %.4lf %s para ", valor_base, me);
    }else if(de == 7){
        printf("Resultado: %.4lf %s para ", valor_base, an);
    }


    if(para == 1){
        printf("%.4lf %s", resultado, s);
    }else if(para == 2){
        printf("%.4lf %s", resultado, m);
    }else if(para == 3){
        printf("%.4lf %s", resultado, h);
    }else if(para == 4){
        printf("%.4lf %s", resultado, d);
    }else if(para == 5){
        printf("%.4lf %s", resultado, se);
    }else if(para == 6){
        printf("%.4lf %s", resultado, me);
    }else if(para == 7){
        printf("%.4lf %s", resultado, an);
    }

    return resultado;
}

void RealizarConversao(int categU, double valor_base, int de, int para){
    /*Função implementada para realizar as conversões com base na opção
    escolhida pelo usuario*/
    if(categU == 1){
        converterComprimento(valor_base, de, para);
    }else if(categU == 2){
        converterMassa(valor_base, de, para);
    }else if(categU == 3){
        converterTeperatura(valor_base, de, para);
    }else if(categU == 4){
        converterVolume(valor_base, de, para);
    }else if(categU == 5){
        converterVelocidae(valor_base, de, para);
    }else if(categU == 6){
        converterTempo(valor_base, de, para);
    }else if(categU == 7){
        converterArea(valor_base, de, para);
    }
}

void ProcessarDados(int categU){
    /*Função implementada para processar os dados digitados pelo usuario*/
    int de, para;
    double valorbase;
    valorbase = lervalor();

    MenuDeUnidades(categU);

    de = lerUnidadeDe();
    para = lerUnidadePara();

    if(validar_unidade(categU, de, para)){
        RealizarConversao(categU, valorbase, de, para);
    }
}

int main(){
    int opcao;
    double valor_base;

    printf("=============|CONVERSOR DE UNIDADES BRAZUCA|=============\n");
    printf("=========|Bem-vindo ao seu sitema de conversao|=========\n");
    printf("\n");

    /*Abaixo será chamado continuamente o menu principal e fará o usuario escolher
    as opções presentes nele, continuando o laço caso nenhuma 
    das opções disponiveis for escolhida e parando imediatamente o laço caso ele escolha 0
    e em seguida chamando funções dentro de funções para realizar as
    conversões desejadas*/
    do{
        MenuPrincipal();
        scanf("%d", &opcao);


        if(opcao < 0 || opcao >7){
            printf("Opcao invalida! Tente novamente.\n");
            continue;
        }

        if(opcao == 0){
            printf("Obrigado por usar o conversor! Ate mais!\n");
            break;
        }

        ProcessarDados(opcao);
        printf("\n==========================================\n");

    }while(1);

    return 0;
}