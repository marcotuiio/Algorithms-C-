#include <stdio.h>
#include <math.h>
#define PI 3.14159265
int main(){
    int TipoConta;

    printf("Digite 1 para seno, 2 para cosseno e 3 para tangente: ");
    scanf("%d", &TipoConta);

    if(TipoConta < 1 || TipoConta > 3){
       printf("VALOR INVALIDO");
       return 0;
    }   
    
    if(TipoConta == 1){
        double result1;
        int param;

        printf("Define the angle for seno in degrees: ");
        scanf("%d", &param);
        
        result1 = sin (param * PI / 180);
        
        printf("The seno for %d degrees is %lf.\n", param, result1 );

    }else if(TipoConta == 2){
        double result2;
        int param;

        printf("Define the angle for cosseno in degrees: ");
        scanf("%d", &param);

        result2 = cos (param * PI / 180);

        printf("The cosseno for %d degrees is %lf.\n", param, result2);

    }else{
        double result3;
        int param;

        printf("Define the angles for tangente in degrees: ");
        scanf("%d", &param);

        result3 = tan (param * PI / 180);

        printf("The tangente for %d degrees is %lf.\n", param, result3);

    }

    return 0;
}