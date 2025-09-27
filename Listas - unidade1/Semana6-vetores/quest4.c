#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void mapa_tesouro(int tesouro[]){
    int i;

    for(i = 0; i<10; i++){
        scanf("%d", &tesouro[i]);
    }
}

int visita_segunda(int tesouro[]){
    int visitado[10] = {0};
    int ilha_atual = 0, proxima_ilha;

    visitado[0] = 1;

    while(1){
        proxima_ilha = tesouro[ilha_atual];

        if(visitado[proxima_ilha] == 1){
            return proxima_ilha;
        }

        visitado[proxima_ilha] = 1;
        ilha_atual = proxima_ilha;

    }

}

int main(){
    int tesouro[10], local;

    printf("Sugestao de onde o tesouro está: ");
    mapa_tesouro(tesouro);

    local = visita_segunda(tesouro);

    printf("%d", local);

    return 0;
}