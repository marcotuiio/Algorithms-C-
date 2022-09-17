#include <stdio.h>

int main(){
   int LadoA, LadoB, LadoC;

    printf("Insira o lado A do trinagulo: ");
    scanf("%d", &LadoA);
    printf("Insira o lado B do trinagulo: ");
    scanf("%d", &LadoB);
    printf("Insira o lado C do trinagulo: ");
    scanf("%d", &LadoC);
    
    if(LadoA + LadoB >= LadoC && LadoA + LadoC >= LadoB && LadoC + LadoB >= LadoA){
        if(LadoA == LadoB && LadoA == LadoC && LadoC == LadoB){
            printf("Triangulo Equilatero");
        } 
        else if(LadoA == LadoB || LadoA == LadoC || LadoB == LadoC){
            printf("Triangulo Isosceles");
        } 
        else if(LadoA != LadoB && LadoA != LadoC && LadoC != LadoB){
            printf("Triangulo Escaleno");
        }
    }     
    else
        printf("Valores invalidos para um triangulo");
    
    return 0;
}