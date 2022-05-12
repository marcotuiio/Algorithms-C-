#include <stdio.h>

int main(){
    float pi, div;
    pi = 0;

    for(div=1; div<=40000; div+=4){   //a aproximação deve ser feita enquanto a divisão <= 0.0001,
        pi = pi + (4 / div);          //ou seja, 4 dividido por 40000.
    }
    for(div=3; div<=40000; div+=4){
        pi = pi - (4 / div);
    }

    printf("O valor obtido de PI: %f", pi);    

    return 0;
}