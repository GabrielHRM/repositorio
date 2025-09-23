#include <stdio.h>
#include <math.h>
#include <stdlib.h>

float distancia(int x, int y, int x2, int y2){
    return sqrt(pow(x2-x, 2) + pow(y2-y, 2)); 
}

float pontuacao(float dis){
    if(dis >= 0.0 && dis <= 1.0){
        return 10.0;
    }else if(dis > 1.0 && dis <=2.0){
        return 6.0;
    }else if(dis > 2.0 && dis <=3.0){
        return 4.0;
    }else{
        return 0.0;
    }
}

float pontuacaob(float dis){
    if(dis >= 0.0 && dis <= 1.0){
        return 5.0;
    }else if(dis > 1.0 && dis <=2.0){
        return 3.0;
    }else if(dis > 2.0 && dis <=3.0){
        return 2.0;
    }else{
        return 0.0;
    }
}

int main(){
    float x, y, dist, xc = 0.0, yc = 0.0, pt, pp, pb;
    float xanterior, yanterior, distanter;
    printf("Coloque as coordenadas iniciais: ");
    scanf("%f %f", &x, &y);

    dist = distancia(x,y,xc,yc);
    pt = pontuacao(dist);
    printf("Pontuacao total do primeiro lancamento: %.2f\n", pt);
    
    for(int i = 2; i <= 10; i++){
        xanterior = x;
        yanterior = y;
        printf("Digite os novos valor de x e y para o lancamento %d: \n", i);
        scanf("%f %f", &x, &y);

        dist = distancia(x, y, xc, yc);
        distanter = distancia(x, y, xanterior, yanterior);
        pp = pontuacao(dist);
        pb = pontuacaob(distanter);

        pt = pt + pp + pb;
    }

    printf("%.2f", pt);

    return 0;
}