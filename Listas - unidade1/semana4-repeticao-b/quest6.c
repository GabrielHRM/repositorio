#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int main(){
    int a, b, c;

    for(a = 1; a<1000; a++){
        for(b=a; b<1000; b++){
            for(c = 1; c<1000; c++){
                if(a*a + b*b == c*c){
                    printf("Trio pitagorico: %d, %d, %d\n", a, b, c);
                }
            }
        }     
    }
    return 0;
}