#include <stdio.h>
int main(){
    float valor[10];
    int valoraux[10] = {0};
    float media, mediana;
    int i, j;

    for(i=0; i<10; i++){
       printf("Defina o valor #%d: ", i+1);
       scanf("%f", &valor[i]);

    }
    /*MEDIA*/ 

    media=0;

    for(i=0; i<10; i++){

       media = media + valor[i];

    }
media = media / 10.0;

    /*MEDIANA*/

    mediana = (valor[4] + valor [5]) / 2;

    /*MODA*/

    for(i=0; i<10; i++){

        for(j=i + 1; j<10; j++){

             if(valor[i] == valor[j]){

                 valoraux[i] = valoraux[i] + 1;
             }
        }

    }
    int aux2, posicao;
    aux2 = 0;

    for(i=0; i<10; i++){

        if(valoraux[i] > aux2){
            aux2 = valoraux[i]; 
            posicao = i;

        }
    }

    printf("A media foi de %.2f\n", media);
    printf("A mediana foi de %.2f\n", mediana);
    printf("A moda foi de %f\n", valor[posicao]);
    
    return 0;
}