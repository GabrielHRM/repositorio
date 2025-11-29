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

            /*Os primos são, para essa questão, todos os numeros acima de 1
            por isso, se i for <= 1, ele não eh primo*/
            if(i <= 1){
                primo = 0;
            }else{
                /*Definição matematica: para determinar se um número é primo,
                basta testar a divisibilidade por todos os números primos 
                menores ou iguais à sua raiz quadrada: j²<=i, j<=√i. Exemplo:
                se i = 36, j ira iterar de 2 até 6, casa por casa.
                Caso quociente de i e j tenha resto zero, o segundo for para é
                dado inicio a uma nova iteração em i*/

                /*a = 36 e b = 30, i = 30: iteração j = 2, 3, 4, 5.
                (limite maximo do for j é o inteiro da raiz de i). 
                30 será divido por todos esses 4 numeros,
                se ele for divisivel por plmns 1 deles, significa que que 30 não eh primo*/
                for(j = 2; j<=sqrt(i); j++){
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