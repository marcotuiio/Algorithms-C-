#include <stdio.h>
#include <math.h>

float diagL(int x, int y);
float diagD(float x, int y);

void main(){
    int a, b, c;

    printf("Considere um paralelepipedo de lados A(comprimento), B(largura) e C(altura)\n");
    printf("Informe o valor para o lado A: ");
    scanf("%d", &a);
    printf("Informe o valor para o lado B: ");
    scanf("%d", &b);
    printf("Informe o valor para o lado C: ");
    scanf("%d", &c);

    printf("O valor da diagonal L = %.2f\n", diagL(a, b));
    printf("O valor da diagonal D = %.2f", diagD(diagL(a, b), c));

}

float diagL(int x, int y){
    float l;
    l = sqrt(x*x + y*y);
    return (l);
}

float diagD(float x, int y){
    float d;
    d = sqrt(x*x + y*y);
    return (d);
}