#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(){
    int i = 1, n1, n2, div1 = 0, div2 = 0;
    printf("Digite os 2 numeros: ");
    scanf("%d %d", &n1, &n2);

    if(n1 != n2){
        if(n1 > n2){
            do{
                if(n1 % i == 0){
                    div1+=i;
                }
                if(i<n2){
                    if(n2 % i == 0){
                        div2+=i;
                    }
                }
                i++;
            }while(i < n1);
        }else if(n1 < n2){
            do{
                if(i < n1){
                    if(n1 % i == 0){
                        div1+=i;
                    }
                }
                if(n2 % i == 0){
                    div2+=i;
                }
                i++;
            }while(i < n2);
        }
    }

    if(div1 == n2 && div2 == n1){
        printf("%d e %d sao amigos", n1, n2);
    }else if(abs(div1 - n2)<=2 && (abs(div2 - n1)<=2)){
        printf("%d e %d sao colegas", n1, n2);
    }else{
        printf("%d e %d nao sao amigos ou colegas", n1, n2);
    }

    return 0;
}