#include <stdio.h>
#include <math.h>

int main(){
    int a, b, c, a2, b2, c2;

    printf("Digite os lados do triangulo: ");
    scanf("%d %d %d", &a, &b, &c);

    a2 = pow(a,2);
    b2 = pow(b,2);
    c2 = pow(c,2);

    if(((a + b )>c) && ((a + c) > b) && ((b + c) > a)){
        printf("Eh um triangulon\n");
        if((a == b) && (a == c)){
            printf("Triangulo equilatero\n");
        }else if((a == b) || (a == c) || (b == c)){
            printf("Triangulo isoceles\n");
        }else{
            printf("Triangulo escaleno\n");
        }

        if((a>b) && (a>c)){
            if(a2 == (b2+c2)){
                printf("Triangulo Retangulo\n");
            }
        }
        if(a2 <(b2 + c2)){
            printf("Triangulo Acutangulo\n");
        }else{
            printf("Triangulo Obtusangulo\n");
        }
    }else{
        printf("Nao eh um triangulo\n");
        return 0;
    }
    

    return 0;
}