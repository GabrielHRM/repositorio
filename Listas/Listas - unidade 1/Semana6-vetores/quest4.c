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
    //Todos os 10 valores do vetor para verificar as ilhas visitadas são todos 0 inicialmente
    //Um vetor boleano
    int visitado[10] = {0};

    //Pela questão, a ilha inicial é sempre a ilha 0 e a proxima ilha é baseada na ilha atual
    int ilha_atual = 0, proxima_ilha;

    /*Como a ilha 0 é o ponto de partida(primeira ilha), ela é considerada visitada,
    portanto, a posição zero do vetor leva o valor 1*/
    visitado[0] = 1;

    /*Laço de repetição que será executado para verificar qual ilha é visitado uma segunda vez
    primeiro*/
    while(1){
        /*proxima_ilha = tesouro[0], se proxima_ilha for 5, por exemplo,
        a proxima ilha sera: tesouro[5] e assim por diante */
        proxima_ilha = tesouro[ilha_atual];
        /*Se a proxima ilha já tiver sido visitado, é retornado o valor da variavel e o laço
        vai parar*/
        if(visitado[proxima_ilha] == 1){
            return proxima_ilha;
        }

        //atualização constante dos valores no laço
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