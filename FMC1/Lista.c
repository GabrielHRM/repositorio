#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void menu_principal(){
    printf("1. Funcao piso\n");
    printf("2. Funcao teto\n");
    printf("3. Funcao div\n");
    printf("4. Funcao mod\n");
    printf("5. Funcao primo\n");
    printf("6. Funcao MDC\n");
    printf("7. Funcao calendario\n");
}
/*----------------------------Questão 1----------------------------*/
/*----------Questão 1.1 - Função piso-------------*/
int piso(float n){
    int fpiso = 0;
    if(n>=0){
        while(fpiso + 1 <= n){
            fpiso++;
        }
        return fpiso;
    }else{
        while(fpiso > n){
            fpiso--;
        }
        return fpiso;
    }
}


/*----------Questão 1.1 - Função teto-------------*/
int teto(float n){
    int fteto = 0;
    if(n >= 0){
        while(fteto <= n){
            fteto++;
        }
        return fteto;
    }else{
        while(fteto - 1 > n){
            fteto--;
        }
        return fteto;
    }
}

/*----------Questão 1.2 - Função div-------------*/
int fdiv(int n2, int n3){
    int quociente=0, dividendo = abs(n2), divisor = abs(n3);
    if(n3 != 0){
        while(dividendo >= divisor){
            dividendo -= divisor;
            quociente++;
        }
        if(n2 < 0 || n3 < 0){
            quociente = -quociente;
        }
        return quociente;
    }
    return 0;
}
/*----------Questão 1.2 - Função Mod-------------*/
int funmod(int n2, int n3){
    return n2 - (n3 * fdiv(n2, n3));
}

/*----------Questão 1.3 - Função do Crivo de Eratóstenes-------------*/
void primo(int n2, int n3){
    int ehprimo, n2abs = abs(n2), n3abs = abs(n3), i, j, inicio, fim;
    printf("[");
    
    if(n2abs < n3abs){
        inicio = n2abs;
        fim = n3abs;
    }else if(n3abs < n2abs){
        inicio = n3abs;
        fim = n2abs;
    }



    for(i = inicio; i<=fim; i++){
        ehprimo = 1;

        if(i == 1){
            ehprimo = 0;
        }else if(i == 2){
            ehprimo = 1;
        }else if(funmod(i, 2)==0){
            ehprimo = 0;
        }else{
            for(j = 3; j<=sqrt(i); j+=2){
                if(funmod(i, j) == 0){
                    ehprimo = 0;
                    break;
                }
            }
        }

        if(ehprimo){
            printf("%d ", i);
        }
    }
    printf("]");  
}
/*-----------------------------------------------------------------*/

/*------------------Questão 2------------------*/
void MDC(int a, int b){
    int passo = 1, ainicial = a, binicial = b;

    int sa = 1, ta = 0;
    int sb = 0, tb = 1;
    /*Ex: MDC(147, 19)
    147 = 1*147 + 0*19
    19 = 0*147 + 1*19*/


    while(b!=0){
        int q = fdiv(a, b);
        int r = funmod(a, b);

        printf("Passo %d:\n", passo);
        printf("%d = %d x %d + (%d)\n", a, b, q, r);
        printf("%d = %d - (%d x %d)\n", r, a, b, q);
        
        /*Ex: MDC(147, 19)
        147 = 7*19 + 14
        14 = 147 - 19*7
        14 = (1*147 + 0*19) - 7*(0*147 + 1*19)
        
        novos = 1 - 7*0 = 1
        novot = 0 - 7*1 = -7

        novos = 1 e novot = -7 para que 14 = 147 - 19*7 seja valida pela identidade de bezout

        Proximo:
        19 = 14*1 + 5
        5 = 19 - 14*1
        5 = 19 - (147 - 7*19)
        5 = -147 + 8*19

        q atual = 1
        sa = sb ; ta = tb ; sb = novos ; tb = novot
        sa = 0    ta = 1    sb = 1       tb = -7 
        
        novos = sa - q x sb
        novot = ta - q x tb

        novos = 0 - 1x1 = -1
        novot = 1 - 1x(-7) = 8

        novos = -1 e novot = 8 para que 5 = -147 + 8*19 seja valida pela identidade de bezout
        */

        int novos = sa - q*sb;
        int novot = ta - q*tb;

        if(r!=0){
          printf("Valores atuais de s e t: %d, %d\n\n", novos, novot);
        }
        

        sa = sb;
        ta = tb;
        sb = novos;
        tb = novot;

        a = b;
        b = r;
        passo++;

    }
    printf("\nMDC(%d, %d) = %d\n", ainicial, binicial, a);
    printf("Valores de s e t pela identidade de bezout: %d, %d", sa, ta);
}
/*-----------------------------------------------*/

/*------------------Questão 3------------------*/
const char *calendario(int d, int m, int a){
    int dia, mes_ajustado, ano_seculo, seculo;
    const char* dias_da_semana[] = {"Domingo", "Segunda-feira", "Terça-feira", "Quarta-feira", "Quinta-feira", "Sexta-feira", "Sabado"};

    if(m<3){
        m+=12;
        a--;
    }

    mes_ajustado = piso(fdiv(13*(m+1), 5));
    
    ano_seculo = funmod(a, 100);
    
    seculo = fdiv(a, 100);
    

    dia = d + mes_ajustado + ano_seculo + piso(ano_seculo/4) + piso(seculo/4) -2*seculo;
    dia = funmod(dia - 1, 7);

    return dias_da_semana[dia];
}

/*-----------------------------------------------*/

void valida(int opcao, float n, int n2, int n3, int d, int m, int a){
    int resultado;
    const char *dia;

    if(opcao == 1){
        resultado = piso(n);
        printf("Piso de %.2f = %d\n", n, resultado);
    } 
    else if(opcao == 2){
        resultado = teto(n);
        printf("Teto de %.2f = %d\n", n, resultado);
    } 
    else if(opcao == 3){
        resultado = fdiv(n2, n3);
        printf("Quociente inteiro de %d e %d = %d", n2, n3, resultado);
    } 
    else if(opcao == 4){
        resultado = funmod(n2, n3);
        printf("Resto inteiro da divisao de %d e %d = %d", n2, n3, resultado);
    }
    else if(opcao == 5){
        printf("Sequencia de primos:\n");
        primo(n2, n3);
    }
    else if(opcao == 6){
        printf("Algoritmo de euclides e identidade de Bezout:\n\n");
        MDC(n2, n3);
    }
    else if(opcao == 7){
        printf("Dia da semana corrpondente a %d/%d/%d:\n\n", d, m, a);
        dia = calendario(d, m, a);
        printf("%s", dia);
    }
}


int main(){
    float n;
    int n2, n3;
    int opcao;
    int d, m, a;

    printf("Entre com um numero real qualquer para as funcoes piso e teto:\n");
    scanf("%f", &n);
    printf("Entre com 2 inteiros para as funcoes div, mod, primo e mdc\n");
    scanf("%d %d", &n2, &n3);
    printf("Entre com uma data para a funcao calendario:\n");
    scanf("%d %d %d", &d, &m, &a);

    printf("Escolha uma opcao do menu principal:\n");
    menu_principal();
    scanf("%d", &opcao);
    valida(opcao, n, n2, n3, d, m, a);

    return 0;
}