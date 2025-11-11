#include <stdio.h>
#include <math.h>

int main(){
    float ci,montante,taxa;
    int temp;

    printf("Digite o capital inicial(ci), taxa de juros(taxa) e o tempo(temp):\n");
    scanf("%f %f %d",&ci,&taxa,&temp);

    taxa = taxa/100.0;

    montante = (ci * pow(1.0+taxa,(float)temp));
    printf("Montante: %.2f", montante);

    return 0;
}