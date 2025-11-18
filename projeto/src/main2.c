#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

char *alocarhistorico(int tamanho){

    char *vetorhist = (char*)malloc(tamanho*sizeof(char));
    if(vetorhist == NULL){
        return NULL;
    }
    vetorhist[0] = '\0';
    return vetorhist;
}

double *alocarmatriz(int linha, int coluna){
    double *matriz = (double*)malloc(linha*coluna*sizeof(double));

    return matriz;
}

char *adicionarhistorico(char *hist, char *entrada, int *espacousado, int *tamanho){
    int espaconecessario = *espacousado + strlen(entrada) + 2;

    if(espaconecessario > *tamanho){
        int novotamanho = *tamanho + 100;
        char *novohist = alocarhistorico(novotamanho);

        if(novohist == NULL){
            return hist;
        }

        strcpy(novohist, hist);
        free(hist);
        hist = novohist;
        *tamanho = novotamanho;
    }
    strcat(hist,entrada);
    strcat(hist, "\n");

    *espacousado = strlen(hist);

    return hist;

}

void mostrarhistorico(char *hist){
    printf("===== HISTORICO =====\n");
    printf("%s\n", hist);
}

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

double operacoesbasicas(char *hist, int *espacousado, int *tamanho){
    printf("\n=== OPERACOES BASICAS ===\n");
    printf("1. Soma(+)\n");
    printf("2. Subitracao(-)\n");
    printf("3. Divisao(/)\n");
    printf("4. Multiplicacao(x)\n\n");
    printf("Selecione uma opcao do menu:\n");

    int opcao;
    scanf("%d", &opcao);
    if(opcao < 1 || opcao >4){
        printf("Opcao invalida. Tente novamente.");
        return operacoesbasicas(hist, espacousado, tamanho);
    }

    double n1, n2, resultado;
    printf("Digite 2 numeros para a operacao desejada:\n");
    scanf("%lf %lf", &n1, &n2);

    char operacao;
    char entrada[200];
    

    switch (opcao){
        case 1:
            resultado = n1+n2;
            operacao = '+';
            printf("%lf %c %lf = %lf\n", n1, operacao, n2, resultado);
            break;
        case 2:
            resultado = n1-n2;
            operacao = '-';
            printf("%lf %c %lf = %lf\n", n1, operacao, n2, resultado);
            break;
        case 3:
            if(n2 != 0){
                resultado = n1/n2;
                operacao = '/';
                printf("%lf %c %lf = %lf\n", n1, operacao, n2, resultado);
            }else if(n1==0 && n2 == 0){
                printf("Erro: Indeterminação(0/0)!!\n");
            }else if(n1 != 0 && n2 == 0){
                printf("Erro: Indefinação(%lf/0)!!\n", n1);
            }
            break;
        case 4:
            resultado = n1*n2;
            operacao = 'x';
            printf("%lf %c %lf = %lf\n", n1, operacao, n2, resultado);
            break;
        default:
            break;
    }
    sprintf(entrada, "%lf %c %lf = %lf", n1, operacao, n2, resultado);
    hist = adicionarhistorico(hist, entrada, espacousado, tamanho);

    return resultado;
}


double potenciaseraizes(char *hist, int *espacousado, int *tamanho){
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
    char *operacao;
    char entrada[200];

    switch (opcao){
        case 1:
            printf("Digite a base e o expoente(x e y):\n");
            scanf("%d %d", &x, &y);
            resultado = pow(x, y);
            operacao = "^";
            printf("%d %s %d = %.2f", x, operacao, y, resultado);
            sprintf(entrada, "%d %s %d = %.2f", x, operacao, y, resultado);
            break;
        case 2:
            printf("Digite a base:\n");
            scanf("%d", &x);
            resultado = sqrt(x);
            operacao = "sqrt";
            printf("%s(%d) = %.2f", operacao, x, resultado);
            sprintf(entrada, "%s%d = %.2f", operacao, x, resultado);
            break;
        case 3:
            printf("Digite a base:\n");
            scanf("%d", &x);
            resultado = cbrt(x);
            operacao = "cbrt";
            printf("%s(%d) = %.2f", operacao, x, resultado);
            sprintf(entrada, "%s%d = %.2f", operacao, x, resultado);
            break;
        case 4:
            printf("Digite a base e a ordem da raiz:\n");
            scanf("%d %d", &x, &y);
            resultado = pow(x, 1.0/y);
            operacao = "^";
            printf("%d %s (1/%d) = %.2f", x, operacao, y, resultado);
            sprintf(entrada, "%d %s (1/%d) = %.2f", x, operacao, y, resultado);
        default:
            break;
    }
    
    hist = adicionarhistorico(hist, entrada, espacousado, tamanho);

    return resultado;
}

double trigonometricos(char *hist, int *espacousado, int *tamanho){
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
    char entrada[200];

    printf("Digite o valor do angulo em graus:\n");
    scanf("%lf", &graus);


    switch (opcao){
        case 1:
            radianos = graus * (pi/180.0);
            resultado = sin(radianos);
            strcpy(operacao, "sen");
            printf("Resultado: %s(%f) = %.2f", operacao, radianos, resultado);
            sprintf(entrada, "%s(%f) = %.2f", operacao, radianos, resultado);
            break;
        case 2:
            radianos = graus * (pi/180.0);
            resultado = cos(radianos);
            strcpy(operacao, "cos");
            printf("Resultado: %s(%f) = %.2f", operacao, radianos, resultado);
            sprintf(entrada, "%s(%f) = %.2f", operacao, radianos, resultado);
            break;
        case 3:
            radianos = graus * (pi/180.0);
            resultado = tan(radianos);
            strcpy(operacao, "tan");
            printf("Resultado: %s(%f) = %.2f", operacao, radianos, resultado);
            sprintf(entrada, "%s(%f) = %.2f", operacao, radianos, resultado);
            break;
        case 4:
            radianos = graus * (pi/180.0);
            resultado = (1/cos(radianos));
            strcpy(operacao, "sec");
            printf("Resultado: %s(%f) = %.2f", operacao, radianos, resultado);
            sprintf(entrada, "%s(%f) = %.2f", operacao, radianos, resultado);
            break;
        case 5:
            radianos = graus * (pi/180.0);
            resultado = (1/sin(radianos));
            strcpy(operacao, "coss");
            printf("Resultado: %s(%f) = %.2f", operacao, radianos, resultado);
            sprintf(entrada, "%s(%f) = %.2f", operacao, radianos, resultado);
            break;
        case 6:
            radianos = graus * (pi/180.0);
            resultado = (1/tan(radianos));
            strcpy(operacao, "cotg");
            printf("Resultado: %s(%f) = %.2f", operacao, radianos, resultado);
            sprintf(entrada, "%s(%f) = %.2f", operacao, radianos, resultado);
            break;
        default:
            break;
    }
    
    hist = adicionarhistorico(hist, entrada, espacousado, tamanho);

    return resultado;
}

double logaritimos(double *resultado2, char *hist, int *espacousado, int *tamanho){
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
        return logaritimos(resultado2, hist, espacousado, tamanho);
    }

    long int b, x, y, n;
    double resultado;
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
            resultado = log10(x);
            *resultado2 = log10(y);
            printf("log10(%ld) = %.2lf\nlog10(%ld) = %.2lf\n\n", x, resultado, y, *resultado2);
            sprintf(entrada, "log10(%ld) = %.2lf | log10(%ld) = %.2lf", x, resultado, y, *resultado2);
            break;
        case 2:
            resultado = log(x*y)/log(b);
            printf("log_%ld(%ld x %ld) = %.2lf\n\n", b, x, y, resultado);
            sprintf(entrada, "log_%ld(%ld x %ld) = %.2lf", b, x, y, resultado);
            break;
        case 3:
            resultado = log((double)x/y)/log(b);
            printf("log_%ld(%ld / %ld) = %.2lf\n\n", b, x, y, resultado);
            sprintf(entrada, "log_%ld(%ld / %ld) = %.2lf", b, x, y, resultado);
            break;
        case 4:
            resultado = n * (log(x)/log(b));
            *resultado2 = n * (log(y)/log(b));
            printf("log_%ld(%ld^%ld) = %.2lf\n", b, x, n, resultado);
            printf("log_%ld(%ld^%ld) = %.2lf\n\n", b, y, n, *resultado2);
            sprintf(entrada, "log_%ld(%ld^%ld) = %.2lf | log_%ld(%ld^%ld) = %.2lf", b, x, n, resultado, b, y, n, *resultado2);
            break;
        case 5:
            resultado = ((double)1/n)*(log(x)/log(b));
            *resultado2 = ((double)1/n)*(log(y)/log(b));
            printf("log_%ld^%ld(%ld) = %.2lf\n", b, n, x, resultado);
            printf("log_%ld^%ld(%ld) = %.2lf\n\n", b, n, y, *resultado2);
            sprintf(entrada, "log_%ld^%ld(%ld) = %.2lf | log_%ld^%ld(%ld) = %.2lf", b, n, x, resultado, b, n, y, *resultado2);
            break;
        case 6:
            resultado = log(x);
            *resultado2 = log(y);
            printf("ln(%ld) = %.2lf", x, resultado);
            printf("ln(%ld) = %.2lf", y, *resultado2);
            sprintf(entrada, "ln(%ld) = %.2lf | ln(%ld) = %.2lf", x, resultado, y, *resultado2);
            break;
        default:
            break;
        }

    hist = adicionarhistorico(hist, entrada, espacousado, tamanho);
    return resultado;
}

long long int fatinicial(long long int x){
    long long int i = x-1, resultado = x;
    if(x == 0 || x == 1){
        return 1;
    }
    while(i>=1){
        resultado = resultado*i;
        i--;
    }
    return resultado;
}

long long int fatorial(double *resultado2, char *hist, int *espacousado, int *tamanho){
    printf("\n=== OPERACOES FATORIAIS ===\n");
    printf("1. Permutacao.\n");
    printf("2. Arranjo.\n");
    printf("3. Combinacao.\n\n");

    printf("Selecione uma opcao do menu:\n");
    int opcao;
    scanf("%d", &opcao);
    if(opcao < 1 || opcao >3){
        printf("Opcao invalida. Tente novamente.");
        return fatorial(resultado2, hist, espacousado, tamanho);
    }

    long long int x, y, resultado;

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
            resultado = fatinicial(x);
            *resultado2 = (double)fatinicial(y);
            printf("%lld! = %lld.\n", x, resultado);
            printf("%lld! = %.0lf.\n\n", y, *resultado2);
            sprintf(entrada, "%lld! = %lld | %lld! = %.0lf", x, resultado, y, *resultado2);
            break;
        case 2:
            resultado = fatinicial(maior)/fatinicial(maior-menor);
            printf("A(%lld, %lld) = %lld.\n", maior, menor, resultado);
            sprintf(entrada, "A(%lld, %lld) = %lld.", maior, menor, resultado);
            break;
        case 3:
            resultado = fatinicial(maior)/(fatinicial(menor)*fatinicial(maior-menor));
            printf("C(%lld, %lld) = %lld.\n", maior, menor, resultado);
            sprintf(entrada, "A(%lld, %lld) = %lld.", maior, menor, resultado);
        default:
            break;
    }
    
    hist = adicionarhistorico(hist, entrada, espacousado, tamanho);

    return resultado;
}

void ler_matriz(double *matriz, int linha, int coluna){
    int i, j;
    for(i = 0; i<linha; i++){
        for(j = 0; j < coluna; j++){
            scanf("%lf", &matriz[i * coluna + j]);
        }
    }
}

void imprimir_matriz_resultado(double *matrizresultado, int linha, int coluna){
    int i, j;

    for(i = 0; i< linha; i++){
        printf("|");
        for(j = 0; j < coluna; j++){
            printf("%7.2lf ", matrizresultado[i * coluna + j]);
        }
        printf("|\n");
    }
}

void matriz_historico(char *entrada, double *matrizresultado, int linha, int coluna){
    int i, j;
    char matrizstr[50];
    entrada[0] = '\0';

    for(i = 0; i< linha; i++){
        strcat(entrada, "|");
        for(j = 0; j < coluna; j++){
            sprintf(matrizstr, "%7.2lf ", matrizresultado[i * coluna + j]);
            strcat(entrada, matrizstr);
        }
        strcat(entrada, "|\n");
    }
    
}

double *soma_matricial(double *matriz1, double *matriz2, int l1, int l2, int c1, int c2){
    int i, j;
    double *resultado;

    if(l1 == l2 && c1 == c2){
        int linha = l1, coluna = c1;
        resultado = alocarmatriz(linha, coluna);
        for(i = 0; i<linha; i++){
            for(j = 0; j < coluna; j++){
                resultado[i * coluna + j] = matriz1[i * coluna + j] + matriz2[i * coluna + j];
            }
        }
        return resultado;
    }
    printf("Matrizes com dimensoes diferente. Tente novamente.\n");
    return NULL;
}

double *subtracao_matricial(double *matriz1, double *matriz2, int l1, int l2, int c1, int c2){
    int i, j;
    double *resultado;

    if(l1 == l2 && c1 == c2){
        int linha = l1, coluna = c1;
        resultado = alocarmatriz(linha, coluna);
        for(i = 0; i<linha; i++){
            for(j = 0; j < coluna; j++){
                resultado[i * coluna + j] = matriz1[i * coluna + j] - matriz2[i * coluna + j];
            }
        }
        return resultado;
    }
    printf("Matrizes com dimensoes diferente. Tente novamente.\n");
    return NULL;
}


double *multiplicacao_matricial(double *matriz1, double *matriz2, int l1, int l2, int c1, int c2){
    int i, j, k;
    double *resultado;
    resultado = alocarmatriz(l1, c2);

    if(c1 == l2){
        /*
          resultado[i][j] += m1[i][k] * m2[k][j]
          resultado[i*c2+j] += m1[i*c1 + k] * m2[k*c2 + j]
        */

        for(i = 0; i<l1; i++){
            for(j = 0; j<c2; j++){
                for(k = 0; k<c1; k++){
                    resultado[i * c2 + j] += matriz1[i * c1 + k] * matriz2[k * c2 + j];
                }
            }
        }
    }
    return resultado;
}


double operacao_com_matrizes(char *hist, int *espacousado, int *tamanho){
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

    int linha, coluna, linha2, coluna2;
    double *matriz1, *matriz2, *resultado;
    char matrizhistorico[200];

    do{
        printf("Digite a ordem das matrizes(linha x coluna):\n");
        scanf("%d %d %d %d", &linha, &coluna, &linha2, &coluna2);
        if(linha <= 0 || coluna <= 0 || linha2 <= 0|| coluna2 <= 0){
            printf("Ordem invalida. Tente Novamente.\n");
        }
    }while(linha <= 0 || coluna <= 0 || linha2 <= 0|| coluna2 <= 0);

    matriz1 = alocarmatriz(linha, coluna);
    matriz2 = alocarmatriz(linha2, coluna2);
    printf("Porfavor, leia as matrizes:\n");
    ler_matriz(matriz1, linha, coluna);
    ler_matriz(matriz2, linha2, coluna2);


    switch(opcao){
        case 1:
            printf("\n");
            printf("Resultado:\n");
            resultado = soma_matricial(matriz1, matriz2, linha, linha2, coluna, coluna2);
            if(resultado != NULL){
                imprimir_matriz_resultado(resultado, linha, coluna);
                matriz_historico(matrizhistorico, resultado, linha, coluna);
                hist = adicionarhistorico(hist, matrizhistorico, espacousado, tamanho);
                free(resultado);
            }else{
                printf("Opcao invalida. Tente novamente.");
                return operacao_com_matrizes(hist, espacousado, tamanho);
            }
            break;
        case 2:
            printf("Resultado:\n");
            resultado = subtracao_matricial(matriz1, matriz2, linha, linha2, coluna, coluna2);
            if(resultado != NULL){
                imprimir_matriz_resultado(resultado, linha, coluna);
                matriz_historico(matrizhistorico, resultado, linha, coluna);
                hist = adicionarhistorico(hist, matrizhistorico, espacousado, tamanho);
                free(resultado);
            }else{
                printf("Opcao invalida. Tente novamente.");
                return operacao_com_matrizes(hist, espacousado, tamanho);
            }
            break;
        case 3:
            printf("Resultado:\n");
            resultado = multiplicacao_matricial(matriz1, matriz2, linha, linha2, coluna, coluna2);
            if(resultado != NULL){
                imprimir_matriz_resultado(resultado, linha, coluna2);
                matriz_historico(matrizhistorico, resultado, linha, coluna2);
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
    return 0;
}

void processar_opcao(int opcao, char *hist, int *espacousado, int *tamanho){
    double resposta, resposta2;
    switch (opcao){
        case 1:
            resposta = operacoesbasicas(hist, espacousado, tamanho);
            printf("%.2lf", resposta);
            break;
        case 2:
            resposta = potenciaseraizes(hist, espacousado, tamanho);
            printf("%.2lf", resposta);
            break;
        case 3:
            resposta = trigonometricos(hist, espacousado, tamanho);
            printf("%.2lf", resposta);
            break;
        case 4:
            resposta = logaritimos(&resposta2, hist, espacousado, tamanho);
            break;
        case 5:
            resposta = fatorial(&resposta2, hist, espacousado, tamanho);
            break;
        case 6:
            resposta = operacao_com_matrizes(hist, espacousado, tamanho);
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