#include <stdio.h>

int fatorial(int x);

void main(){
    int n;

    printf("Informe um valor para calcular seu fatorial: ");
    scanf("%d", &n);

    printf("%d! = %d", n, fatorial(n));
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