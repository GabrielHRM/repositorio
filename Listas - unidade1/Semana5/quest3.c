#include <stdio.h>
#include <math.h>
#include <stdlib.h>


float altura_pouso(float x, float y){
    return sin(cos(y) + x) + cos(sin(x) + y);
}

int valida_pouso(float altura){
    if(altura >= 0 && altura <= 2){
        return 1;
    }
    return 0;
}

void calss_ponto(int pontos){
    if(pontos == 0 || pontos == 1){
        printf("Inseguro");
    }else if(pontos == 2 || pontos == 3){
        printf("Relativamente seguro");
    }else if(pontos == 4){
        printf("Seguro");
    }
}



int main(){
    float x, y, altura[9];
    int valida[9], i, cont = 0;
    printf("Leia a coordenada de pouso da sonda:\n");
    scanf("%f %f", &x, &y);

    altura[0] = altura_pouso(x, y);
    altura[1] = altura_pouso(x+0.2, y+0.2);
    altura[2] = altura_pouso(x-0.2, y-0.2);
    altura[3] = altura_pouso(x+0.2, y-0.2);
    altura[4] = altura_pouso(x-0.2, y+0.2);

    altura[5] = altura_pouso(x+2,y);
    altura[6] = altura_pouso(x-2,y);
    altura[7] = altura_pouso(x,y+2);
    altura[8] = altura_pouso(x,y-2);

    for(i = 0; i<=4;i++){
        valida[i] = valida_pouso(altura[i]);
        if(valida[i] != 0){
            cont++;
        }
    }
    if(cont == 5){
        cont = 0;
        for(i = 5; i <= 8; i++){
            valida[i] = valida_pouso(altura[i]);
            if(valida[i] != 0){
                cont++;
            }
        }
        calss_ponto(cont);
    }else{
        printf("Trocar de localizacao");
    }


    return 0;
}