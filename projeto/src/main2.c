#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

char *alocarhistorico(int *tamanho){
    int tamanho_inical = 20;
    char *vetorstr = (char*)malloc(tamanho_inical * 100 * sizeof(char));

    for(int i = 0;i<tamanho_inical;i++){
        char *pos = vetorstr + (i * 100);
        *pos = '\0';
    }

    *tamanho = tamanho_inical;

    return vetorstr;
}

void adicionar_ao_historico(char *historico, int *ihistorico, char *resultado_str) {
    char *pos = historico + (*ihistorico * 100);
    char *src = resultado_str;
    
    while(*src != '\0') {
        *pos = *src;
        pos++;
        src++;
    }
    *pos = '\0';
    (*ihistorico)++;
}

void mostrar_historico(char *historico, int total_calculos) {
    printf("\n=== HISTORICO (%d calculos) ===\n", total_calculos);
    if(total_calculos == 0) {
        printf("Nenhum calculo realizado.\n");
        return;
    }
    
    for(int i = 0; i < total_calculos; i++) {
        char *calc = historico + (i * 100);
        printf("%d. %s\n", i + 1, calc);
    }
}

void menuprincipal(){
    printf("\n=== CALCULADORA CIENTIFICA ===\n");
    printf("1. Operacoes Basicas\n");
    printf("2. Potencias e Raizes\n");
    printf("3. Funcoes Trigonometricas\n");
    printf("4. Logaritmos\n");
    printf("5. Fatorial\n");
    printf("6. Mostrar Historico\n");
    printf("7. Limpar Historico\n");
    printf("0. Sair\n\n");
    printf("Selecione uma opcao do menu principal:\n");
}

char *operacoesbasicas(char *historico, int *ihistorico, int *capacidade){
    printf("\n=== OPERACOES BASICAS ===\n");
    printf("1. Soma(+)\n");
    printf("2. Subitracao(-)\n");
    printf("3. Divisao(/)\n");
    printf("4. Multiplicacao(x)\n\n");
    printf("Selecione uma opcao do menu:\n");

    int opcao;
    scanf("%d", &opcao);

    double n1, n2, resultado;
    printf("Digite 2 numeros para a operacao desejada:\n");
    scanf("%lf %lf", &n1, &n2);

    char operacao;
    char *hist = (char*)malloc(100 * sizeof(char));
    

    switch (opcao){
        case 1:
            resultado = n1+n2;
            operacao = '+';
            break;
        case 2:
            resultado = n1-n2;
            operacao = '-';
            break;
        case 3:
            if(n2 != 0){
                resultado = n1/n2;
                operacao = '/';
            }else{
                printf("Divisão por zero!!\n");
            }
            break;
        case 4:
            resultado = n1*n2;
            operacao = 'x';
            break;
        default:
            break;
    }

    printf("Resultado: %f %c %f = %.2f\n", n1, operacao, n2, resultado);
    sprintf(hist, "%f %c %f = %.2f", n1, operacao, n2, resultado);

    adicionar_ao_historico(historico, ihistorico, hist);
    free(hist);
    return historico;
}


char *potenciaseraizes(char *historico, int *ihistorico, int *capacidade){
    printf("\n=== OPERACOES DE POTENCIAS E RAIZES ===\n");
    printf("1. Potencia(x^y)\n");
    printf("2. Raiz Quadrada(x^(1/2))\n");
    printf("3. Raiz Cubica(x^(1/3))\n");
    printf("4. Raiz Enesima(x^(1/n))\n\n");

    printf("Selecione uma opcao do menu:\n");
    int opcao;
    scanf("%d", &opcao);

    int x, y;
    double resultado;
    char operacao;
    char *hist = (char*)malloc(100 * sizeof(char));

    switch (opcao){
        case 1:
            printf("Digite a base e o expoente(x e y):\n");
            scanf("%d %d", &x, &y);
            resultado = pow(x, y);
            operacao = '^';
            printf("%d %c %d = %.2f", x, operacao, y, resultado);
            sprintf(hist, "%d %c %d = %.2f", x, operacao, y, resultado);
            break;
        case 2:
            printf("Digite a base:\n");
            scanf("%d", &x);
            resultado = sqrt(x);
            operacao = '√';
            printf("%c%d = %.2f", operacao, x, resultado);
            sprintf(hist, "%c%d = %.2f", operacao, x, resultado);
            break;
        case 3:
            printf("Digite a base:\n");
            scanf("%d", &x);
            resultado = cbrt(x);
            operacao = '∛';
            printf("%c%d = %.2f", operacao, x, resultado);
            sprintf(hist, "%c%d = %.2f", operacao, x, resultado);
            break;
        case 4:
            printf("Digite a base e a ordem da raiz:\n");
            scanf("%d %d", &x, &y);
            resultado = pow(x, 1.0/y);
            operacao = '^';
            printf("%d %c (1/%d) = %.2f", x, operacao, y, resultado);
            sprintf(hist, "%d %c (1/%d) = %.2f", x, operacao, y, resultado);
        default:
            break;
    }
    adicionar_ao_historico(historico, ihistorico, hist);
    free(hist);
    return historico;
}

char *trigonometricos(char *historico, int *ihistorico, int *capacidade){
    printf("\n=== OPERACOES TRIGONOMETRICAS ===\n");
    printf("1. Seno\n");
    printf("2. Cosseno\n");
    printf("3. Tangente\n");
    printf("4. Secante\n");
    printf("5. Cossecante\n");
    printf("6. Cotangente\n\n");

    printf("Selecione uma opcao do menu:\n");
    int opcao;
    scanf("%d", &opcao);

    double resultado, graus, radianos;
    long double pi = 3.14159265358979323846;
    char operacao[20];
    char *hist = (char*)malloc(100 * sizeof(char));

    printf("Digite o valor do angulo em graus:\n");
    scanf("%lf", &graus);


    switch (opcao){
        case 1:
            radianos = graus * (pi/180.0);
            resultado = sin(radianos);
            strcpy(operacao, "sen");
            printf("Resultado: %s(%f) = %.2f", operacao, radianos, resultado);
            sprintf(hist, "%s(%f) = %.2f", operacao, radianos, resultado);
            break;
        case 2:
            radianos = graus * (pi/180.0);
            resultado = cos(radianos);
            strcpy(operacao, "cos");
            printf("Resultado: %s(%f) = %.2f", operacao, radianos, resultado);
            sprintf(hist, "%s(%f) = %.2f", operacao, radianos, resultado);
            break;
        case 3:
            radianos = graus * (pi/180.0);
            resultado = tan(radianos);
            strcpy(operacao, "tan");
            printf("Resultado: %s(%f) = %.2f", operacao, radianos, resultado);
            sprintf(hist, "%s(%f) = %.2f", operacao, radianos, resultado);
            break;
        case 4:
            radianos = graus * (pi/180.0);
            resultado = (1/cos(radianos));
            strcpy(operacao, "sec");
            printf("Resultado: %s(%f) = %.2f", operacao, radianos, resultado);
            sprintf(hist, "%s(%f) = %.2f", operacao, radianos, resultado);
            break;
        case 5:
            radianos = graus * (pi/180.0);
            resultado = (1/sin(radianos));
            strcpy(operacao, "coss");
            printf("Resultado: %s(%f) = %.2f", operacao, radianos, resultado);
            sprintf(hist, "%s(%f) = %.2f", operacao, radianos, resultado);
            break;
        case 6:
            radianos = graus * (pi/180.0);
            resultado = (1/tan(radianos));
            strcpy(operacao, "cotg");
            printf("Resultado: %s(%f) = %.2f", operacao, radianos, resultado);
            sprintf(hist, "%s(%f) = %.2f", operacao, radianos, resultado);
            break;
        default:
            break;
    }
    adicionar_ao_historico(historico, ihistorico, hist);
    free(hist);
    return historico;
}

char *logaritimos(char* historico, int* ihistorico, int* capacidade){
    printf("\n=== OPERACOES TRIGONOMETRICAS ===\n");
    printf("1. Soma(bases diferentes).\n");
    printf("2. Subitração(bases diferentes).\n");
    printf("3. Logaritimo de base 10.\n");
    printf("4. Divisao(base igual).\n");
    printf("5. Multiplicacao(base igual).\n");
    printf("6. Logaritimo natural(ln).\n\n");

    printf("Selecione uma opcao do menu:\n");
    int opcao;
    scanf("%d", &opcao);

    


}

char *processar_opcao(int opcao, char* historico, int* ihistorico, int* capacidade){
    switch (opcao){
        case 1:
            historico = operacoesbasicas(historico, ihistorico, capacidade);
            break;
        case 2:
            historico = potenciaseraizes(historico, ihistorico, capacidade);
            break;
        case 3:
            historico = trigonometricos(historico, ihistorico, capacidade);
            break;
        default:
            break;
    }
    return historico;
}

int main(){
    int capacidade_historico = 0, calculostotais = 0, opcao;
    char *historico;

    historico = alocarhistorico(&capacidade_historico);

    if(historico == NULL){
        printf("Impossivel iniciar a calculadora!\n");
    }

    printf("Selecione uma opcao do menu principal:\n");
    do{
        menuprincipal();
        scanf("%d", &opcao);
        historico = processar_opcao(opcao, historico, &calculostotais, &capacidade_historico);
    }while(opcao != 0);
    
    free(historico);



    return 0;
}