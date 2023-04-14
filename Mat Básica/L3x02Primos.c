#include "stdio.h"
#include "stdlib.h"

void main () {
    int n = 100; // intervalo

    printf("\n Primos no intervalo 1 - %d:\n\n 2 3", n);

    int atual = 5;
    int divisor = 2;
    while (atual <= n) {
        int check = 0; 
        while (atual - 1 > divisor) {
            int resto = atual % divisor;
            if (resto == 0) {
                check = 1;
                break;
            }
            divisor++;
        }
        if (check == 0) {
            printf(" %d", atual);
        }
        divisor = 2;
        atual++;
    }
    printf("\n");
}
