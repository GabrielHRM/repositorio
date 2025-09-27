#include <stdio.h>
#include <math.h>

int main(){
    int n1, n2, s, di, mul;
    float div;

    scanf("%d %d", &n1, &n2);
    s = n1 + n2;
    di = n1 - n2;
    mul = n1 * n2;
    div = (float)n1/(float)n2;

    printf("Resultados: \n%d \n%d \n%d \n%.2f",s,di,mul,div);

    return 0;
}