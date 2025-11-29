#include <stdio.h>
#include <math.h>

int main(){
    char j1, j2;

    printf("Jogada do J1 e J2:\n");
    scanf("%c %c", &j1, &j2);

    /*P = pedra, A = papel e T = tesoura*/

    if(j1 == 'P' || j1 == 'p'){
        if(j2 == 'A' || j2 == 'a'){
            printf("J2 ganhou!");
        } else if(j2 =='T' || j2 == 't'){
            printf("J1 ganhou!");
        } else{
            printf("Empate!");
        }
    } else if(j1 == 'A' || j1 == 'a'){
        if(j2 == 'P' || j2 == 'p'){
            printf("J1 ganhou!");
        } else if(j2 =='T' || j2 == 't'){
            printf("J2 ganhou!");
        } else{
            printf("Empate!");
        }
    } else{
        if(j2 == 'P' || j2 == 'p'){
            printf("J2 ganhou!");
        } else if(j2 =='A' || j2 == 'a'){
            printf("J1 ganhou!");
        } else{
            printf("Empate!");
        }
    }

    return 0;
}