#include <stdio.h>

int main(){
    int x, div, soma;
    soma = 0;

    for(x=1; x<500; x++){
        for(div=1; div<=(x/2); div++){
            if((x % div) == 0){
                soma = soma + div;
            }
        }
        if(soma == x){
            printf("O numero %d e perfeito\n", x);
        }
        soma = 0;
    }

    return 0;
}