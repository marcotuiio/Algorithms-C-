#include <stdio.h>

int main(){
    int n, i, aux, aux2;
    aux = 1;
    aux2 = 0;

    printf("Insira um valor superior a 2: ");
    scanf("%d", &n);

    printf("0  1 ");   //como os dois primeiros termos são, por padrão, 0 e 1, eles sempre
                      //são imprimidos antes da estrutura de repetição 
    for(i=1; i<=(n-2); i++){
      aux = aux + aux2;       //os dois primeiros termos são foram definidos, logo i deve ir até n-2
      aux2 = aux - aux2;      //ex: n=4, i vai até 2, ou seja, vai calcular o 3º e 4º termos
      printf(" %d ", aux);    
    }

    return 0;
}    
