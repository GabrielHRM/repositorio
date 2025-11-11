#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int primo(int n){
    int i;

    for(i = 2; i<n; i++){
        if(n%i==0){
            return 0;
        }
    }
    return 1;
}

int main(){
    int n = 50000;

    for(int i = 5; i<=n-6; i++){
        if(primo(i) && primo(i+2) && primo(i+6)){
            printf("(%d, %d, %d)\n", i, i+2, i+6);
        }
    }

    return 0;
}