#include <stdio.h>
#include <math.h>

float calculardis(float x1, float x2, float y1, float y2){
    return sqrt(pow(x2-x1, 2) + pow(y2-y1, 2));
}

int validacao(int n2){
    if(n2 == 0){
        return 1;
    } else{
        return 0;
    }
}


int main(){
    float ax, ay, xi, yi, ct;
    int n, i, cont2 = 0;

    printf("Insira os parametros: ");
    scanf("%f %f %f %d", &xi, &yi, &ct, &n);

    float distancia = calculardis(xi, ax, yi, ay);

    for (i = 0; i < n; i++){
        printf("Cordenadas do alvo %d \n", i+1);
        scanf("%f %f", &ax, &ay);
        

        if(distancia <= ct){
            xi = 2*ax - xi;
            yi = ay;
            distancia = calculardis(xi, ax, yi, ay);
        }else{
            cont2++;
        }
    }
    if(validacao(cont2) == 1){
        printf("S");
    }else{
        printf("N - %d alvo(s) n alcancado(s)",cont2);
    }

    return 0;
}