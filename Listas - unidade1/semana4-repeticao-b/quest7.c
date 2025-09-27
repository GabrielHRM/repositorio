#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int main(){
    int a, b, i, primo, j;
    printf("Leia a e b:\n");
    scanf("%d %d", &a, &b);

    if(a > b){
        for(i = b; i<=a; i++){
            primo = 1;

            if(i <= 1){
                primo = 0;
            }else{
                for(j = 2; j*j<=i; j++){
                    if(i%j == 0){
                        primo = 0;
                        break;
                    }
                }
            }
            if(primo){
                printf("%d ", i);
            }
        }
    }




    return 0;
}