#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int main(){
    float p, q, maior_razao = -1.0, razao, receita_empresa, custo_empresa;
    int xm, ym;
    printf("Digite os precos:\n");
    scanf("%f %f", &p, &q);

    for(int x = 1; x<=10; x++){
        for(int y = 1; y<x; y++){
            razao = (float)x/y;
            receita_empresa = y*p;
            custo_empresa = x*q;
            if(receita_empresa >= custo_empresa){
                if(razao > maior_razao){
                    maior_razao = razao;
                    xm = x;
                    ym = y;
                }
            }
        }
    }
    printf("A melhor promocao eh: leve %d pague %d", xm, ym);


    return 0;
}