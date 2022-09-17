#include <stdio.h>

void main(){

    int i;
    int a[10];
    int b[10];

    for (i=0; i<10; i++){
        a[i] = (i + 1) * 10;
        b[i] = (i + 1) * 100 + 1;
        printf("a[%d] = %d   b[%d] = %d\n", i, a[i], i, b[i]);
    }
    printf("\n");

    printf("vetor a: %x\n", a); //imprime na forma hexadecimal
    printf("a[9] = %d  *** a[10] = %d a[11] = %d\n", a[9], a[10], a[11]);
    // como voce explica os valores de a[10] e a[11]? 

    //R: Os valores da posição 10 e 11 em 'a' não foram declarados nessa variável,
    //portanto seus valores e posições PODEM apresentar conflitos no programa.

    printf("vetor b: %x\n", b); //imprime na forma hexadecimal
    printf("b[0] = %d  b[9] = %d  *** b[-1] = %d b[10] = %d b[11] = %d\n", b[0], b[9], b[-1], b[10], b[11]);
    // como vc explica os valores de b[-1], b[10] e b[11]? 

    //R: Os valores da posição 10 e 11 em 'b' não foram declarados nessa variável,
    //portanto seus valores e posições PODEM apresentar conflitos no programa.
    //Quanto a posição de indice -1, o valor apresentado é o que se encontra na 
    //posição anterior ao início do vetor
}