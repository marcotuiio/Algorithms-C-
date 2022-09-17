#include <stdio.h>
#include <math.h>

int fatorial(int x);
int potencia(int base, int exp);

void main(){
    float A, senA, antSenA, erro, den, num;
    int sinal, n, t;

    for(A=0; A<=3.1; A+=0.1){
        senA = A;
        sinal = -1;
        erro = 1;
        n = 3;
        antSenA = senA;
        t = 1;
        while(erro > 0.0001){
            num = potencia(A, n);
            den = fatorial(n);
            senA = senA + sinal * num/den;
            sinal = sinal * -1;
            n = n + 2;
            erro = fabsf(senA - antSenA);
            antSenA = senA;
            t = t + 1;
        }
        printf("A=%f T=%d senA=%f erro=%f\n", A, t, senA, erro);
    }
}

int potencia(int base, int exp){
    int x;
    x = pow(base, exp);
    return (x);
}
int fatorial(int x){
    int aux, fat;
    fat = 1;

    if(x > 1){
        for(aux=x; aux>1; aux--){
            fat = fat * aux;
        }
    }
    return (fat);
}