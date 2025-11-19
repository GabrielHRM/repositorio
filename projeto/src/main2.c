#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "matriz.h"
#include "fatorial.h"
#include "historico.h"
#include "estrutura.h"

void menuprincipal(){
    printf("\n=== CALCULADORA CIENTIFICA ===\n");
    printf("1. Operacoes Basicas\n");
    printf("2. Potencias e Raizes\n");
    printf("3. Funcoes Trigonometricas\n");
    printf("4. Logaritmos\n");
    printf("5. Fatorial\n");
    printf("6. Matrizes\n");
    printf("7. Mostrar Historico\n");
    printf("0. Sair\n\n");
    printf("Selecione uma opcao do menu principal:\n");
}

char *operacoesbasicas(char *hist, double *resultado, int *espacousado, int *tamanho){
    printf("\n=== OPERACOES BASICAS ===\n");
    printf("1. Soma(+)\n");
    printf("2. Subitracao(-)\n");
    printf("3. Divisao(/)\n");
    printf("4. Multiplicacao(x)\n\n");
    printf("Selecione uma opcao do menu:\n");

    int opcao;
    scanf("%d", &opcao);
    if(opcao < 1 || opcao > 4){
        printf("Opcao invalida. Tente novamente.");
        return operacoesbasicas(hist, resultado, espacousado, tamanho);
    }

    double n1, n2;
    printf("Digite 2 numeros para a operacao desejada:\n");
    scanf("%lf %lf", &n1, &n2);

    char operacao;
    char entrada[200];
    

    switch (opcao){
        case 1:
            *resultado = n1+n2;
            operacao = '+';
            printf("%lf %c %lf = %lf\n", n1, operacao, n2, *resultado);
            break;
        case 2:
            *resultado = n1-n2;
            operacao = '-';
            printf("%lf %c %lf = %lf\n", n1, operacao, n2, *resultado);
            break;
        case 3:
            if(n2 != 0){
                *resultado = n1/n2;
                operacao = '/';
                printf("%lf %c %lf = %lf\n", n1, operacao, n2, *resultado);
            }else if(n1==0 && n2 == 0){
                printf("Erro: Indeterminação(0/0)!!\n");
            }else if(n1 != 0 && n2 == 0){
                printf("Erro: Indefinação(%lf/0)!!\n", n1);
            }
            break;
        case 4:
            *resultado = n1*n2;
            operacao = 'x';
            printf("%lf %c %lf = %lf\n", n1, operacao, n2, *resultado);
            break;
        default:
            break;
    }
    sprintf(entrada, "%lf %c %lf = %lf\n", n1, operacao, n2, *resultado);
    hist = adicionarhistorico(hist, entrada, espacousado, tamanho);

    return hist;
}


char *potenciaseraizes(char *hist, double *resultado, int *espacousado, int *tamanho){
    printf("\n=== OPERACOES DE POTENCIAS E RAIZES ===\n");
    printf("1. Potencia(x^y)\n");
    printf("2. Raiz Quadrada(x^(1/2))\n");
    printf("3. Raiz Cubica(x^(1/3))\n");
    printf("4. Raiz Enesima(x^(1/n))\n\n");

    printf("Selecione uma opcao do menu:\n");
    int opcao;
    scanf("%d", &opcao);
    if(opcao < 1 || opcao > 4){
        printf("Opcao invalida. Tente novamente.");
        return operacoesbasicas(hist, resultado, espacousado, tamanho);
    }

    int x, y;
    char entrada[200];

    switch (opcao){
        case 1:
            printf("Digite a base e o expoente(x e y):\n");
            scanf("%d %d", &x, &y);
            *resultado = pow(x, y);
            printf("%d ^ %d = %.2lf", x, y, *resultado);
            sprintf(entrada, "%d ^ %d = %.2lf\n", x, y, *resultado);
            break;
        case 2:
            printf("Digite a base:\n");
            scanf("%d", &x);
            *resultado = sqrt(x);
            printf("sqrt(%d) = %.2lf", x, *resultado);
            sprintf(entrada, "sqrt(%d) = %.2lf\n", x, *resultado);
            break;
        case 3:
            printf("Digite a base:\n");
            scanf("%d", &x);
            *resultado = cbrt(x);
            printf("cbrt(%d) = %.2lf", x, *resultado);
            sprintf(entrada, "cbrt(%d) = %.2lf\n", x, *resultado);
            break;
        case 4:
            printf("Digite a base e a ordem da raiz:\n");
            scanf("%d %d", &x, &y);
            *resultado = pow(x, 1.0/y);
            printf("%d ^ (1/%d) = %.2lf", x, y, *resultado);
            sprintf(entrada, "%d ^ (1/%d) = %.2lf\n", x, y, *resultado);
        default:
            break;
    }
    
    hist = adicionarhistorico(hist, entrada, espacousado, tamanho);

    return hist;
}

char *trigonometricos(char *hist, double *resultado, int *espacousado, int *tamanho){
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
    if(opcao < 1 || opcao > 6){
        printf("Opcao invalida. Tente novamente.");
        return operacoesbasicas(hist, resultado, espacousado, tamanho);
    }

    double graus, radianos;
    long double pi = 3.14159265358979323846;
    char operacao[20];
    char entrada[200];

    printf("Digite o valor do angulo em graus:\n");
    scanf("%lf", &graus);


    switch (opcao){
        case 1:
            radianos = graus * (pi/180.0);
            *resultado = sin(radianos);
            strcpy(operacao, "sen");
            printf("Resultado: %s(%f) = %.2f", operacao, radianos, *resultado);
            sprintf(entrada, "%s(%f) = %.2f\n", operacao, radianos, *resultado);
            break;
        case 2:
            radianos = graus * (pi/180.0);
            *resultado = cos(radianos);
            strcpy(operacao, "cos");
            printf("Resultado: %s(%f) = %.2f", operacao, radianos, *resultado);
            sprintf(entrada, "%s(%f) = %.2f\n", operacao, radianos, *resultado);
            break;
        case 3:
            radianos = graus * (pi/180.0);
            *resultado = tan(radianos);
            strcpy(operacao, "tan");
            printf("Resultado: %s(%f) = %.2f", operacao, radianos, *resultado);
            sprintf(entrada, "%s(%f) = %.2f\n", operacao, radianos, *resultado);
            break;
        case 4:
            radianos = graus * (pi/180.0);
            *resultado = (1/cos(radianos));
            strcpy(operacao, "sec");
            printf("Resultado: %s(%f) = %.2f", operacao, radianos, *resultado);
            sprintf(entrada, "%s(%f) = %.2f\n", operacao, radianos, *resultado);
            break;
        case 5:
            radianos = graus * (pi/180.0);
            *resultado = (1/sin(radianos));
            strcpy(operacao, "coss");
            printf("Resultado: %s(%f) = %.2f", operacao, radianos, *resultado);
            sprintf(entrada, "%s(%f) = %.2f\n", operacao, radianos, *resultado);
            break;
        case 6:
            radianos = graus * (pi/180.0);
            *resultado = (1/tan(radianos));
            strcpy(operacao, "cotg");
            printf("Resultado: %s(%f) = %.2f", operacao, radianos, *resultado);
            sprintf(entrada, "%s(%f) = %.2f\n", operacao, radianos, *resultado);
            break;
        default:
            break;
    }
    
    hist = adicionarhistorico(hist, entrada, espacousado, tamanho);

    return hist;
}

char *logaritimos(double *resultado2, double *resultado, char *hist, int *espacousado, int *tamanho){
    printf("\n=== OPERACOES LOGARITMICAS ===\n");
    printf("1. Logaritimo de base 10.\n");
    printf("2. Multiplicacao(base igual).\n");
    printf("3. Divisao(base igual).\n");
    printf("4. Enesima potencia do logatimimando.\n");
    printf("5. Enesima potencia da base.\n");
    printf("6. Logaritimo natural(ln).\n\n");

    printf("Selecione uma opcao do menu:\n");
    int opcao;
    scanf("%d", &opcao);
    if(opcao < 1 || opcao >6){
        printf("Opcao invalida. Tente novamente.");
        return logaritimos(resultado2, resultado, hist, espacousado, tamanho);
    }

    long int b, x, y, n;
    char entrada[200];

    do{
        printf("Digite os valores da base e dos dos logaritimandos:\n");
        scanf("%ld %ld %ld",&b, &x, &y);
        printf("Escolha agora um expoente(opcoes 4 e 5):\n");
        scanf("%ld", &n);
        if(x < 0 || y < 0 || b<=0 || b == 1){
            printf("Valores invalidos. Digite novos valores.\n\n");
        }
        
    } while (x < 0 || y < 0 || b<=0 || b == 1);
    

    switch (opcao){
        case 1:
            *resultado = log10(x);
            *resultado2 = log10(y);
            printf("log10(%ld) = %.2lf\nlog10(%ld) = %.2lf\n\n", x, *resultado, y, *resultado2);
            sprintf(entrada, "log10(%ld) = %.2lf | log10(%ld) = %.2lf\n", x, *resultado, y, *resultado2);
            break;
        case 2:
            *resultado = log(x*y)/log(b);
            printf("log_%ld(%ld x %ld) = %.2lf\n\n", b, x, y, *resultado);
            sprintf(entrada, "log_%ld(%ld x %ld) = %.2lf\n", b, x, y, *resultado);
            break;
        case 3:
            *resultado = log((double)x/y)/log(b);
            printf("log_%ld(%ld / %ld) = %.2lf\n\n", b, x, y, *resultado);
            sprintf(entrada, "log_%ld(%ld / %ld) = %.2lf\n", b, x, y, *resultado);
            break;
        case 4:
            *resultado = n * (log(x)/log(b));
            *resultado2 = n * (log(y)/log(b));
            printf("log_%ld(%ld^%ld) = %.2lf\n", b, x, n, *resultado);
            printf("log_%ld(%ld^%ld) = %.2lf\n\n", b, y, n, *resultado2);
            sprintf(entrada, "log_%ld(%ld^%ld) = %.2lf | log_%ld(%ld^%ld) = %.2lf\n", b, x, n, *resultado, b, y, n, *resultado2);
            break;
        case 5:
            *resultado = ((double)1/n)*(log(x)/log(b));
            *resultado2 = ((double)1/n)*(log(y)/log(b));
            printf("log_%ld^%ld(%ld) = %.2lf\n", b, n, x, *resultado);
            printf("log_%ld^%ld(%ld) = %.2lf\n\n", b, n, y, *resultado2);
            sprintf(entrada, "log_%ld^%ld(%ld) = %.2lf | log_%ld^%ld(%ld) = %.2lf\n", b, n, x, *resultado, b, n, y, *resultado2);
            break;
        case 6:
            *resultado = log(x);
            *resultado2 = log(y);
            printf("ln(%ld) = %.2lf", x, *resultado);
            printf("ln(%ld) = %.2lf", y, *resultado2);
            sprintf(entrada, "ln(%ld) = %.2lf | ln(%ld) = %.2lf\n", x, *resultado, y, *resultado2);
            break;
        default:
            break;
        }

    hist = adicionarhistorico(hist, entrada, espacousado, tamanho);
    return hist;
}

char *fatorial(double *resultado2, double *resultado, char *hist, int *espacousado, int *tamanho){
    printf("\n=== OPERACOES FATORIAIS ===\n");
    printf("1. Permutacao.\n");
    printf("2. Arranjo.\n");
    printf("3. Combinacao.\n\n");

    printf("Selecione uma opcao do menu:\n");
    int opcao;
    scanf("%d", &opcao);
    if(opcao < 1 || opcao >3){
        printf("Opcao invalida. Tente novamente.");
        return fatorial(resultado2, resultado, hist, espacousado, tamanho);
    }

    long long int x, y;

    do{
        printf("Digite os valores a serem fatorados\n");
        scanf("%lld %lld", &x, &y);
        if(x < 0 || y < 0){
            printf("Valores invalidos. Tente Novamente.");
        }
    }while(x < 0 || y < 0);

    long long int maior = y, menor = x;
    if(x > y){
        maior = x;
        menor = y;
    }

    char entrada[200];

    switch (opcao){
        case 1:
            *resultado = fatinicial(x);
            *resultado2 = (double)fatinicial(y);
            printf("%lld! = %.0lf.\n", x, *resultado);
            printf("%lld! = %.0lf.\n\n", y, *resultado2);
            sprintf(entrada, "%lld! = %.0lf | %lld! = %.0lf\n", x, *resultado, y, *resultado2);
            break;
        case 2:
            *resultado = fatinicial(maior)/fatinicial(maior-menor);
            printf("A(%lld, %lld) = %.0lf.\n", maior, menor, *resultado);
            sprintf(entrada, "A(%lld, %lld) = %.0lf.\n", maior, menor, *resultado);
            break;
        case 3:
            *resultado = fatinicial(maior)/(fatinicial(menor)*fatinicial(maior-menor));
            printf("C(%lld, %lld) = %lf.\n", maior, menor, *resultado);
            sprintf(entrada, "C(%lld, %lld) = %.0lf.\n", maior, menor, *resultado);
        default:
            break;
    }
    
    hist = adicionarhistorico(hist, entrada, espacousado, tamanho);

    return hist;
}

char *operacao_com_matrizes(char *hist, int *espacousado, int *tamanho){
    printf("\n=== OPERACOES MATRICIAIS ===\n");
    printf("1. Soma matrcial.\n");
    printf("2. Subitracao matricial.\n");
    printf("3. Multiplicacao matricial.\n");
    printf("4. Multiplicação escalar\n\n");

    int opcao;
    printf("Selecione uma opção do menu:\n");
    scanf("%d", &opcao);
    if(opcao < 1 || opcao > 4){
        printf("Opcao invalida. Tente novamente.");
        return operacao_com_matrizes(hist, espacousado, tamanho);
    }

    dimensao tamanho1, tamanho2, tamanho3;
    double *matriz1, *matriz2, *resultado;
    char matrizhistorico[5000];

    do{
        printf("Digite a ordem das matrizes(linha x coluna):\n");
        scanf("%d %d %d %d", &tamanho1.linha, &tamanho1.coluna, &tamanho2.linha, &tamanho2.coluna);
        if(tamanho1.linha <= 0 || tamanho1.coluna <= 0 || tamanho2.linha <= 0|| tamanho2.coluna <= 0){
            printf("Ordem invalida. Tente Novamente.\n");
        }
    }while(tamanho1.linha <= 0 || tamanho1.coluna <= 0 || tamanho2.linha <= 0|| tamanho2.coluna <= 0);

    matriz1 = alocarmatriz(tamanho1);
    matriz2 = alocarmatriz(tamanho2);
    printf("Porfavor, leia as matrizes:\n");
    ler_matriz(matriz1, tamanho1);
    ler_matriz(matriz2, tamanho2);


    switch(opcao){
        case 1:
            printf("\n");
            printf("Resultado:\n");
            resultado = soma_matricial(matriz1, matriz2, tamanho1, tamanho2);
            if(resultado != NULL){
                imprimir_matriz_resultado(resultado, tamanho3);
                matriz_historico(matrizhistorico, resultado, tamanho3);
                hist = adicionarhistorico(hist, matrizhistorico, espacousado, tamanho);
                free(resultado);
            }else{
                printf("Opcao invalida. Tente novamente.");
                return operacao_com_matrizes(hist, espacousado, tamanho);
            }
            break;
        case 2:
            printf("Resultado:\n");
            resultado = subtracao_matricial(matriz1, matriz2, tamanho1, tamanho2);
            if(resultado != NULL){
                imprimir_matriz_resultado(resultado, tamanho3);
                matriz_historico(matrizhistorico, resultado, tamanho3);
                hist = adicionarhistorico(hist, matrizhistorico, espacousado, tamanho);
                free(resultado);
            }else{
                printf("Opcao invalida. Tente novamente.");
                return operacao_com_matrizes(hist, espacousado, tamanho);
            }
            break;
        case 3:
            printf("Resultado:\n");
            resultado = multiplicacao_matricial(matriz1, matriz2, tamanho1, tamanho2);
            if(resultado != NULL){
                imprimir_matriz_resultado(resultado, tamanho3);
                matriz_historico(matrizhistorico, resultado, tamanho3);
                hist = adicionarhistorico(hist, matrizhistorico, espacousado, tamanho);
                free(resultado);
            }else{
                printf("Opcao invalida. Tente novamente.");
                return operacao_com_matrizes(hist, espacousado, tamanho);
            }
            break;
        default:
            break;
            
    } 
    free(matriz1);
    free(matriz2);
    return hist;
}

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
            mostrarhistorico(hist);
        default:
            break;
    }
}

int main(){
    int tamanho_inicial_historico = 100;
    int espacousado = 0;
    int opcao;
    char *historico = alocarhistorico(tamanho_inicial_historico);

    printf("Selecione uma opcao do menu principal:\n");
    do{
        menuprincipal();
        scanf("%d", &opcao);
        processar_opcao(opcao, historico, &espacousado, &tamanho_inicial_historico);
    }while(opcao != 0);
    
    free(historico);



    return 0;
}