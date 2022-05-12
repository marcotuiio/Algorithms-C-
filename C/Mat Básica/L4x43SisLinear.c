#include <stdio.h>

float calcXY(float num1, float num2, float a, float b, float c, float d, float u, float v);

void main(){
    float a, b, c, d, u, v, x, y;

    printf("Informe a: ");
    scanf("%f", &a);
    printf("Informe b: ");
    scanf("%f", &b);
    printf("Informe c: ");
    scanf("%f", &c);
    printf("Informe d: ");
    scanf("%f", &d);

    while(a!=0 || b!=0 || c!=0 || d!=0){
        printf("Informe u: ");
        scanf("%f", &u);
        printf("Informe v: ");
        scanf("%f", &v);
        x = calcXY(d, -1*b, a, b, c, d, u, v);
        y = calcXY(-1*c, a, a, b, c, d, u, v);
        printf("O valor obtido para x = %.2f\n", x);
        printf("O valor obtido para y = %.2f\n", y);
            printf("Informe a: ");
            scanf("%f", &a);
            printf("Informe b: ");
            scanf("%f", &b);
            printf("Informe c: ");
            scanf("%f", &c);
            printf("Informe d: ");
            scanf("%f", &d);
            printf("Informe u: ");
            scanf("%f", &u);
            printf("Informe v: ");
            scanf("%f", &v);
    }
}

float calcXY(float num1, float num2, float a, float b, float c, float d, float u, float v){
    float resp, den;
    den = a*d - b*c;
    resp = (num1/den) * u + (num2/den) * v;
    return (resp);
}