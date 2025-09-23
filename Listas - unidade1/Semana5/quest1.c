#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void ronda(int hora, int minuto, int formato){
    if(formato == 0){
        if(hora>23){
            if(minuto >=0 && minuto<=59){
                hora = hora%24;
                printf("Horario desta honda: %02d:%02d\n", hora, minuto);
            }else{
                hora = (hora%24) + (minuto/60);
                minuto = minuto%60;
                printf("Horario desta honda: %02d:%02d\n", hora, minuto);
            }
        }else{
            if(minuto >=0 && minuto<=59){
                printf("Horario desta honda: %02d:%02d\n", hora, minuto);
            }else{
                hora = (hora%24) + (minuto/60);
                minuto = minuto%60;
                printf("Horario desta honda: %02d:%02d\n", hora, minuto);
            }
        }
    }else if(formato == 1){
        if(hora > 12){
            if(minuto>=0 && minuto<=59){
                hora = hora-12;
                printf("Horario desta honda: %02d:%02d PM\n", hora, minuto);
            }else{
                hora = (hora-12) + (minuto/60);
                minuto = minuto%60;
                printf("Horario desta honda: %02d:%02d PM\n", hora, minuto);
            }
        }else{
            if(minuto>=0 && minuto<=59){
                printf("Horario desta honda: %02d:%02d AM\n", hora, minuto);
            }else{
                hora = (hora-12) + (minuto/60);
                minuto = minuto%60;
                printf("Horario desta honda: %02d:%02d AM\n", hora, minuto);
            }
        }
    }
}


int main(){
    int h, m, formato;

    printf("Digite o horario de inicio e o formato: ");
    scanf("%d %d %d", &h, &m, &formato);

    printf("Ronda 1:\n");
    ronda(h,m,formato);

    printf("Ronda 2:\n");
    ronda(h+1,m,formato);

    printf("Ronda 3:\n");
    ronda(h+2,m+10,formato);

    printf("Ronda 4:\n");
    ronda(h+4,m+40,formato);

    printf("Ronda 5:\n");
    ronda(h+12,m+5,formato);


    return 0;
}