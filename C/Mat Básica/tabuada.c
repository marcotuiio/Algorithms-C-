#include <stdio.h>
int main(){
    int i, x; 

    do{
        printf("Defina um valor de 1 a 10 para ver a tabuada: ");
        scanf("%d", &x);
    }while(x<1 || x>10);

    for(i=x; i<=100; i+=x){
        printf("%d\n", i);

    }
    return 0;
}