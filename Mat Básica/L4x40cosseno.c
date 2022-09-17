#include <stdio.h>
#include <math.h>
#define pi 3.14159265

int fatorial(int x);
float auxiliar(float ang);
float numerador(float base, int exp);
float converteRad(float ang);

void main(){
    float num, den, cosseno, x, rad;
    int i, sinal;
    sinal = -1;

    printf("Informe o angulo X que deseja o cosseno: ");
    scanf("%f", &x); 
    rad = converteRad(x);
    cosseno = 1;

    for(i=2; i<=12; i+=2){         //o laço vai percorrer os 6 primeiros depois do primeiro que é fixado em 1
        num = numerador(rad, i);
        den = fatorial(i);                               //essa sequencia so dá certo quando recebe 
        cosseno = sinal * num / den + cosseno;           //um angulo em radianos 
        sinal = sinal * (-1);
    }

    printf("O valor aproximado do cos%.2f = %.2f\n", x, cosseno);
    printf("O cosseno de %.2f = %.2f", x, auxiliar(rad));
      
}

float auxiliar(float ang){
    float teste;                 //verificador que calcula o cosseno diretamente graças a math.h
    teste = cos (ang);
    return (teste);
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

float numerador(float base, int exp){
    float x;
    x = pow(base, exp);
    return (x);
}

float converteRad(float ang){
    float rad;
    rad = ang * pi / 180;
    return (rad);
}
