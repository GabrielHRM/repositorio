#include <stdio.h>
#include <math.h>

int main(){
    char d1, d2, d3, d4;

    printf("Tem febre?");
    scanf(" %c", &d1);
    printf("Tem dor de cabeca?");
    scanf(" %c", &d2);
    printf("Tem dor no corpo?");
    scanf(" %c", &d3);
    printf("Tem tosse?");
    scanf(" %c", &d4);

    if(d1 == 'S' || d1 == 's'){
        if((d2 == 'S' || d2 == 's') && (d3 == 'S' || d3 == 's')){
            printf("Possivel gripe");
        }else if(d4 == 'S' || d4 == 's'){
            printf("Possivel resfriado");
        }else{
            printf("Consulte um medico");
        }
    }else if(d2 == 'S' || d2 == 's'){
        if(d1 == 'N'|| d1 == 'n'){
            if(d3 == 'N' || d3 == 'n'){
                if(d4 == 'N' || d4 == 'n'){
                    printf("Possivel enxaqueca");
                }
            }
        }
    } else if(d2 == 'N' || d2 == 'n'){
        if(d1 == 'N'|| d1 == 'n'){
            if(d3 == 'N' || d3 == 'n'){
                if(d4 == 'N' || d4 == 'n'){
                    printf("Voce parece estar bem");
                }
            }
        }
    } else{
        printf("Consulte um medico para avaliacao");
    }

    return 0;
}