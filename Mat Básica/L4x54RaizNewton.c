#include <stdio.h>

float calcX(float x, float y);
float sqroot(double num);

void main(){
    float y, x;
    int n;

    printf("Insira um valor para calcular sua raiz quadrada: ");  
    scanf("%f", &y);
    x = y/2;

    for(n=2; n<=30; n++){
        x = calcX(x, y);
    }
    // x = sqroot(y);

    printf("A raiz aproximada para %.f == %f", y, x);
}

float calcX(float x, float y){
    float proX; 
    proX = (x*x + y) / (2*x);            //aproximação de raizes quadradas por Newton
    return (proX);
}

float sqroot(double num) {
    float root = num / 3;
    int i;
    if (num <= 0) return 0;
    for (i = 0; i < 64; i++) {
        root = (root + num / root) / 2;
        printf("%f\n", root);
    }
    return root;
}
