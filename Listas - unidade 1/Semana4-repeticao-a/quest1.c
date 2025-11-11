#include <stdio.h>
#include <math.h>

int main(){
    float cf, lf, cb;
    int cont = 0;
    printf("Digite o comprimento e largura da folha, alem do comprimento do bolso: ");
    scanf("%f %f %f", &cf, &lf, &cb);

    do{
        if(cf > lf){
            cf = cf/2;
        }else if(lf > cf){
            lf = lf/2;
        }
        cont++;
    } while (cf>cb && lf>cb);

    printf("Quantidade de dobradas: %d", cont);
    


    return 0;
}