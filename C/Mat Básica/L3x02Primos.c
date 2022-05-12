#include <stdio.h>

int main(){
    int n, i, div;
    int contador = 0;

    printf("Defina o fim do intervalo [1, N] para calcular os primos: ");
    scanf("%d", &n);

        if(n == 1){                                         //um número primo tem apenas 2 divisores, 
            printf("NAO existem primos nesse intervalo");   //e 1 possui somente um divisor, logo não é primo
        }else if(n == 2){                                  
            printf("2 e o unico primo nesse intervalo");    //o primeiro primo é o 2
        }else{
            for(i=2; i<=n; i++){
                for(div=2; div<i; div++){
                    if(i % div != 0){
                        contador = contador + 1;     //caso o número não for divisível por div, contador 
                    }                                //soma 1 para saber quantos números não dividem i
                }
                if(contador == (i-2)){            //para  o numero ser primo, não pode ser divisível por 
                    printf("%d   ", i);           //nenhum número entre 1 e ele mesmo e é isso que o contador
                }                                 //está fazendo
                contador = 0;
            }
        }  

    return 0;
}