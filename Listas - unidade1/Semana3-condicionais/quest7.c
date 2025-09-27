#include <stdio.h>
#include <math.h>

int main(){
    int a, b, c, delta;
    float r1, r2;

    printf("Digite os 3 coeficientes: ");
    scanf("%d %d %d",&a, &b, &c);

    if(a == 0){
        printf("Nao eh uma equacao de grau 2");
        return 0;
    }

    delta = pow(b,2) - (4*a*c);
    r1 = (-b + sqrt(delta))/(2*a);
    r2 = (-b - sqrt(delta))/(2*a);

    if(delta > 0){
        printf("Possui duas raizes reais distintas: %.2f e %.2f", r1, r2);
    }else if(delta == 0){
        r1 = r2;
        printf("Possui uma unica raiz: %.2f", r1);
    }else{
        printf("Nao possui raizes");
    }
    
    return 0;
}